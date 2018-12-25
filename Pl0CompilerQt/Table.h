#pragma once

#include <QWidget>
#include "ui_Table.h"

class Table : public QWidget
{
	Q_OBJECT

public:
	Table(QWidget *parent = Q_NULLPTR);
	~Table();

private:
	Ui::Table ui;
};
