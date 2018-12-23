#include "Pl0CompilerQt.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

Pl0CompilerQt::Pl0CompilerQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
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
	grammarAnalyzer.runCompile();
	instructions = grammarAnalyzer.getResults();
}

void Pl0CompilerQt::buildRun()
{
	build();
	Interpreter interpreter(instructions);
	interpreter.run();
}
