#include "ConsoleStream.h"


ConsoleStream::ConsoleStream(std::ostream &stream, QTextEdit* text_edit)
	:std::basic_streambuf<char>()
	, m_stream(stream)


{
	this->log_window = text_edit;
	this->m_old_buf = stream.rdbuf();

	stream.rdbuf(this);

}

ConsoleStream::~ConsoleStream()
{
	this->m_stream.rdbuf(this->m_old_buf);
}

void ConsoleStream::registerMyConsoleMessageHandler()
{
	qInstallMessageHandler(myConsoleMessageHandler);
}


void ConsoleStream::myConsoleMessageHandler(QtMsgType type, const QMessageLogContext &, const QString &msg)
{

	QByteArray localMsg = msg.toLocal8Bit();
	switch (type) {
	case QtDebugMsg:
		// fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtInfoMsg:
		// fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtWarningMsg:
		// fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtCriticalMsg:
		//fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	case QtFatalMsg:
		// fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
		break;
	default:
		std::cout << msg.toStdString().c_str();
		break;

	}
}