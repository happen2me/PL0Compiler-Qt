#include "Pl0CompilerQt.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "ConsoleStream.h"
#include <iostream>
#include <QDebug>




Pl0CompilerQt::Pl0CompilerQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	MyBuf buff(ui.console);
	//std::stringbuf buff;
	std::ostream stream(&buff);
	stream << "TEST" << std::flush;
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
	WordAnalyzer wordAnalyzer(current_file.toStdString());
	wordAnalyzer.analyze();
	GrammarAnalyzer grammarAnalyzer(wordAnalyzer.getResult());
	qDebug() << "Words num: ";
	qDebug() << grammarAnalyzer.getResults().size() << "\n";
	grammarAnalyzer.runCompile();
	instructions = grammarAnalyzer.getResults();
	qDebug() << grammarAnalyzer.getResults().size();
	
}

void Pl0CompilerQt::buildRun()
{
	std::ofstream ofs("output/log.txt", std::ofstream::out);

	ui.console->moveCursor(QTextCursor::End);
	ui.console->insertPlainText("Start running\n");
	ui.console->moveCursor(QTextCursor::End);
	build();
	Interpreter interpreter(instructions, ofs);

	ofs.close();
	std::cout << "";
	interpreter.run();
	ui.console->moveCursor(QTextCursor::End);
	ui.console->insertPlainText("Program exits.\n");
	ui.console->moveCursor(QTextCursor::End);
}

