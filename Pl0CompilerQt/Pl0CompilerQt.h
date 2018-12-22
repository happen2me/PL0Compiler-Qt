#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Pl0CompilerQt.h"

class Pl0CompilerQt : public QMainWindow
{
	Q_OBJECT

public:
	Pl0CompilerQt(QWidget *parent = Q_NULLPTR);

private:
	Ui::Pl0CompilerQtClass ui;
};
