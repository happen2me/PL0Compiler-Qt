#pragma once

#include <QWidget>
#include "ui_SymbolTable.h"

class SymbolTable : public QWidget
{
	Q_OBJECT

public:
	SymbolTable(QWidget *parent = Q_NULLPTR);
	~SymbolTable();

private:
	Ui::SymbolTable ui;
};
