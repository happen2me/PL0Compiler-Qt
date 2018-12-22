#include "Pl0CompilerQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Pl0CompilerQt w;
	w.show();
	return a.exec();
}
