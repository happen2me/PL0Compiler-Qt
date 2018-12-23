#pragma once

#include <QtWidgets/QMainWindow>
#include <string>
#include "ui_Pl0CompilerQt.h"

class Pl0CompilerQt : public QMainWindow
{
	Q_OBJECT

public:
	Pl0CompilerQt(QWidget *parent = Q_NULLPTR);
	
public slots:
	void loadFile();
	void save();

private:
	Ui::Pl0CompilerQtClass ui;
	QString current_file;
};
