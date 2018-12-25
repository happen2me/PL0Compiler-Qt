#include <iostream>
#include "Interpreter.h"
#include <stdlib.h>
#include <QThread>
#include <QTextStream>
#include <QInputDialog>
#include <QDir>

#define DEBUG 0

Interpreter::Interpreter():
	log_ostream(std::cout)
{
}

Interpreter::Interpreter(std::vector<Instruction> pcodes) :
	instructions(pcodes),
	pc(0),
	bp(1),
	sp(0),
	log_ostream(std::cout),
	text_edit(nullptr)
{
}

Interpreter::Interpreter(std::vector<Instruction> pcodes, std::ostream& log_ostream, QTextEdit* textEdit):
	instructions(pcodes),
	pc(0),
	bp(1),
	sp(0),
	log_ostream(log_ostream),
	text_edit(textEdit)
{
}

Interpreter::Interpreter(std::vector<Instruction> pcodes, QTextEdit * textEdit):
	Interpreter(pcodes)
{
	this->text_edit = textEdit;
}


Interpreter::~Interpreter()
{
}

void Interpreter::run()
{
	int time = 0;
	if(DEBUG)
		log_ostream << "\nline\top\tl\tm\tpc\tbp\tsp\tstack(before execution)" << std::endl;
	while (bp != 0 && time < 10000) {
		time++;
		fetch();
		
		if (DEBUG) {
			log_ostream << time << "\t";
			snapshotStack(log_ostream);
		}
		exe();
	}
	if (DEBUG) {
		log_ostream << "\t\t\t\t";
		log_ostream << pc << "\t" << bp << "\t" << sp << "\t";
		for (int i = 0; i <= sp; i++) {
			log_ostream << data[i] << " ";
		}
		log_ostream << std::endl;
	}
	
}

void Interpreter::exe()
{
	int x;
	QString word;
	bool ok = false;
	switch (ir.op)
	{
	case Instruction::LIT:
		push(ir.m);
		break;
	case Instruction::OPR:
		opr((Instruction::OperationType)ir.m);
		break;
	case Instruction::LOD:
		push(data[base(bp, ir.l) + ir.m]);
		break;
	case Instruction::STO:
		data[base(bp, ir.l) + ir.m] = pop();
		break;
	case Instruction::CALL:
		data[sp + 1] = base(bp, ir.l); // static link
		data[sp + 2] = bp; // dynamic link
		data[sp + 3] = pc; // pc points to next instruction to execute
		pc = ir.m;
		bp = sp + 1; // bp moves to the top of original stack pointer
		break;
	case Instruction::INC:
		sp += ir.m;
		break;
	case Instruction::JMP:
		pc = ir.m;
		break;
	case Instruction::JPC:
		if (pop() == 0) {
			pc = ir.m;
		}
		break;
	case Instruction::WRT:
		x = pop();
		//log_ostream << "\033[1;33m";
		//log_ostream << x << "\033[0m\n" << std::endl;
		log_ostream << x << std::endl;
		/*if (text_edit) {
			text_edit->moveCursor(QTextCursor::End);
			text_edit->insertPlainText(QString::number(x));
			text_edit->insertPlainText("\n");
			text_edit->moveCursor(QTextCursor::End);
		}*/
		break;
	case Instruction::RED:
		while (!ok)
		{
			x = QInputDialog::getInt(text_edit, tr("QInputDialog::getInteger()"),
				tr("Please input a const:"), 0, 0, 100000, 1, &ok);
		}
		push(x);
		break;
	default:
		log_ostream << "undefined operater type" << std::endl;
		break;
	}
}

void Interpreter::opr(Instruction::OperationType opr_type)
{
	int a, b, stored_bp;
	switch (opr_type)
	{
	case Instruction::OT_RET:
		pc = data[bp + 2]; // return address
		stored_bp = bp;
		bp = data[bp + 1]; //dynamic link
		sp = stored_bp - 1; // original stack pointer
		break;
	case Instruction::OT_NEG:
		push(-pop());
		break;
	case Instruction::OT_ADD:
		a = pop();
		b = pop();
		push(a + b);
		break;
	case Instruction::OT_SUB:
		a = pop();
		b = pop();
		push(b - a);
		break;
	case Instruction::OT_MUL:
		a = pop();
		b = pop();
		push(a*b);
		break;
	case Instruction::OT_DIV:
		a = pop();
		b = pop();
		push(b / a);
		break;
	case Instruction::OT_ODD:
		push(pop() % 2);
		break;
	case Instruction::OT_MOD:
		a = pop();
		b = pop();
		push(b % a);
		break;
	case Instruction::OT_EQL:
		a = pop();
		b = pop();
		push(a == b);
		break;
	case Instruction::OT_NEQ:
		a = pop();
		b = pop();
		push(a != b);
		break;
	case Instruction::OT_LSS:
		a = pop();
		b = pop();
		push(b < a);
		break;
	case Instruction::OT_LEQ:
		a = pop();
		b = pop();
		push(b <= a);
		break;
	case Instruction::OT_GTR:
		a = pop();
		b = pop();
		push(b > a);
		break;
	case Instruction::OT_GEQ:
		a = pop();
		b = pop();
		push(b >= a);
		break;
	default:
		break;
	}
}

int Interpreter::base(int b_ptr, int level)
{
	for (int i = 0; i < level; i++) {
		b_ptr = data[b_ptr]; // static link is stored at base pointer
	}
	return b_ptr;
}

void Interpreter::push(int x)
{
	sp += 1;
	data[sp] = x;
}

int Interpreter::pop()
{
	int x = data[sp];
	sp -= 1;
	return x;
}

bool Interpreter::fetch()
{
	if (pc >= (int)instructions.size()) {
		return false;
	}
	ir = instructions[pc];
	pc++;
	return true;
}

void Interpreter::snapshotStack(std::ostream& out)
{
	if (ir.op == Instruction::OPR) {
		out << Instruction::translator[ir.op] << "\t" << ir.l << "\t" << Instruction::op_translator[(Instruction::OperationType)ir.m] << "\t";
	}
	else {
		out << Instruction::translator[ir.op] << "\t" << ir.l << "\t" << ir.m << "\t";
	}
	out << pc << "\t" << bp << "\t" << sp << "\t";
	for (int i = 0; i <= sp; i++) {
		out << data[i] << " ";
	}
	out << std::endl;
}

void Interpreter::handleUserInput(const QString & text)
{
	line_read = true;
}
