#pragma once

#include <QtWidgets/QMainWindow>
#include <string>
#include <vector>
#include <sstream>
#include "ui_Pl0CompilerQt.h"
#include "WordAnalyzer.h"
#include "GrammarAnalyzer.h"
#include "Interpreter.h"

class MyBuf : public std::stringbuf
{
public:
	QTextEdit* console;
	MyBuf(QTextEdit* textEdit) : std::stringbuf() {
		console = textEdit;
	}
	virtual int sync() {
		console->append(QString::fromStdString(this->str()));
		return 0;
	}
};

class Pl0CompilerQt : public QMainWindow
{
	Q_OBJECT

	

public:
	Pl0CompilerQt(QWidget *parent = Q_NULLPTR);
	
public slots:
	void loadFile();
	void save();
	void build();
	void buildRun();

private:
	Ui::Pl0CompilerQtClass ui;
	QString current_file;
	std::vector<Symbol> symbol_table;
	std::vector<Instruction> instructions;
};
