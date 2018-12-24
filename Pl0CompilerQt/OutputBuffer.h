#pragma once
#include <QTextEdit>
#include <iostream> 
#include <sstream>
#include <string>

class OutputBuffer : public std::stringbuf
{
public:
	QTextEdit* console;
	OutputBuffer(QTextEdit* textEdit) : std::stringbuf() {
		console = textEdit;
	}
	OutputBuffer() : std::stringbuf() {
		console = nullptr;
	}
	void setConsole(QTextEdit* textEdit) {
		console = textEdit;
	}
	virtual int sync() {
		console->insertPlainText(QString::fromStdString(this->str()));
		this->str("");
		return 0;
	}
};
