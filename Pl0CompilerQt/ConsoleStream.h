#pragma once
#include<iostream>
#include<string>
#include <QtWidgets/QMainWindow>
#include <QTextEdit>

class ConsoleStream : public std::basic_streambuf<char>
{

public:
	ConsoleStream(std::ostream &stream, QTextEdit* text_edit);

	virtual ~ConsoleStream();
	static void registerMyConsoleMessageHandler();

private:

	static void myConsoleMessageHandler(QtMsgType type, const QMessageLogContext &, const QString &msg);

protected:


	// Diese Funktion wird aufgerufen wenn std::endl im Stream erscheint
	virtual int_type overflow(int_type v)
	{
		if (v == '\n')
		{
			log_window->append("");
		}
		return v;
	}

	virtual std::streamsize xsputn(const char *p, std::streamsize n)
	{
		m_string.append(p, p + n);

		int pos = 0;
		while (pos != std::string::npos)
		{
			pos = m_string.find('\n');
			if (pos != std::string::npos)
			{
				std::string tmp(m_string.begin(), m_string.begin() + pos);
				log_window->append(tmp.c_str());
				m_string.erase(m_string.begin(), m_string.begin() + pos + 1);
			}
		}

		return n;
	}

private:

	std::ostream &m_stream;
	std::streambuf *m_old_buf;
	std::string m_string;
	QTextEdit* log_window;

};
