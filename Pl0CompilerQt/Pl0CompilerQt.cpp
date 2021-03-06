#include "Pl0CompilerQt.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include "Table.h"
bool ok_;
Pl0CompilerQt::Pl0CompilerQt(QWidget *parent)
	: QMainWindow(parent),
	buffer(),
	console_stream(&buffer)
{
	ui.setupUi(this);
	buffer.setConsole(ui.console);
}

void Pl0CompilerQt::loadFile() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"Documents",
		tr("Text (*.txt *.pl0);;All Files(*)"));

	if (fileName.isEmpty())
		return;
	else {
		current_file = fileName;
		QFile file(fileName);
		file.open(QIODevice::ReadOnly);
		QTextStream textStream(&file);
		QString line = textStream.readAll();
		file.close();
		ui.textEdit->setText(line);
	}
}

void Pl0CompilerQt::save()
{
	QString fileName;
	if (current_file.isEmpty()) {
		fileName = QFileDialog::getSaveFileName(this,
			tr("Save Code"), "",
			tr("PL0 source code (*.pl0);;All Files (*)"));
	}
	else {
		fileName = current_file;
	}
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::information(this, tr("Unable to open file"),
			file.errorString());
		return;
	}
	QTextStream out(&file);
	out << ui.textEdit->toPlainText();
	current_file = fileName;
}

void Pl0CompilerQt::build()
{
	if (current_file.isEmpty()) {
		save();
	}
	if (current_file.isEmpty()) {
		QMessageBox::information(this, tr("Build Error"), tr("Failed to save file"));
		return;
	}
	WordAnalyzer wordAnalyzer(current_file.toStdString(), console_stream);
	try {		
		wordAnalyzer.analyze();
		qDebug() << "Token num: " << wordAnalyzer.getResult().size() << "\n";		
	}
	catch (std::exception e) {
		qDebug() << e.what() << "\n";
		ui.console->append(e.what());
		return;
	}

	GrammarAnalyzer grammarAnalyzer(wordAnalyzer.getResult(), console_stream);
	if (wordAnalyzer.getErrorCount() != 0) {
		ui.console->append(QString::number(wordAnalyzer.getErrorCount()) + " errors detected in word analysis\n");
	}
	try {
		grammarAnalyzer.runCompile();
	}
	catch (std::exception e) {
		qDebug() << e.what() << "\n";
		ui.console->append(e.what());
		return;
	}

	instructions = grammarAnalyzer.getResults();
	qDebug() << grammarAnalyzer.getResults().size();
	ui.tableWidget->setRowCount(instructions.size());
	QStringList labels;
	for (unsigned int i = 0; i < instructions.size(); i++) {
		labels << QString::number(i);
		for (unsigned int column = 0; column < 3; column++) {
			QTableWidgetItem* newItem = new QTableWidgetItem();
			switch (column)
			{
			case 0:
				newItem->setText(QString::fromStdString(Instruction::translator[instructions[i].op]));
				ui.tableWidget->setItem(i, column, newItem);
				break;
			case 1:
				newItem->setText(QString::number(instructions[i].l));
				ui.tableWidget->setItem(i, column, newItem);
				break;
			case 2:
				if (instructions[i].op == Instruction::OPR)
					newItem->setText(QString::fromStdString(Instruction::op_translator[(Instruction::OperationType)instructions[i].m]));
				else
					newItem->setText(QString::number(instructions[i].m));
				ui.tableWidget->setItem(i, column, newItem);
				break;
			default:
				break;
			}

		}
	}
	ui.tableWidget->setVerticalHeaderLabels(labels);

	symbol_table = grammarAnalyzer.getSymbolTable();
	//displaySymbolTable();
	console_stream << wordAnalyzer.getErrorCount() + grammarAnalyzer.getErrorCount() << " error(s) detected" << std::endl;

	if (grammarAnalyzer.getErrorCount() > 0) {
		ok_ = false;
	}
	else {
		ok_ = true;
	}
}

void Pl0CompilerQt::buildRun()
{
	//std::ofstream ofs("output/log.txt", std::ofstream::out);

	ui.console->moveCursor(QTextCursor::End);
	ui.console->insertPlainText("\nStart running\n");
	ui.console->moveCursor(QTextCursor::End);
	build();
	if (instructions.size() > 0 && ok_) {
		Interpreter interpreter(instructions, console_stream, ui.console);

		//ofs.close();
		std::cout << "";
		interpreter.run();
		ui.console->moveCursor(QTextCursor::End);
		ui.console->insertPlainText("Program exits.\n");
		ui.console->moveCursor(QTextCursor::End);
	}	
}

void Pl0CompilerQt::promptAbout()
{
	QMessageBox::about(this, "Pl0 Compiler (Qt)", "Author: Yuanchun Shen");
}

void Pl0CompilerQt::displaySymbolTable()
{
	QMainWindow* window = new QMainWindow(this);

	QWidget* wdg = new Table(this);
	QTableWidget* table = wdg->findChild<QTableWidget*>("tableWidget");
	QStringList headerLabels;
	headerLabels << "Type" << "Name" << "Value" << "Level" << "Address";
	if (table) {
		table->setColumnCount(5);
		table->setRowCount(symbol_table.size());
		table->verticalHeader()->setVisible(false);
		table->setHorizontalHeaderLabels(headerLabels);
		for (size_t row = 0; row < symbol_table.size(); row++) {
			table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(Symbol::translator[symbol_table[row].type])));
			table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(symbol_table[row].name)));
			if (symbol_table[row].type == Symbol::CONST) {
				table->setItem(row, 2, new QTableWidgetItem(QString::number(symbol_table[row].val)));
			}
			else {
				table->setItem(row, 3, new QTableWidgetItem(QString::number(symbol_table[row].level)));
				table->setItem(row, 4, new QTableWidgetItem(QString::number(symbol_table[row].address)));
			}
		}
		window->setWindowTitle("Symbol table");
		window->setCentralWidget(wdg);
		window->show();
	}
	else
	{
		console_stream << "Initial symbol table failed" << endl;
	}
}

