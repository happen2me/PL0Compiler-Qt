/********************************************************************************
** Form generated from reading UI file 'Pl0CompilerQt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PL0COMPILERQT_H
#define UI_PL0COMPILERQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pl0CompilerQtClass
{
public:
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Close;
    QAction *action_Run;
    QAction *action_Build;
    QAction *action_About;
    QAction *action_Clear;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QFrame *line;
    QTextEdit *textEdit_2;
    QFrame *line_2;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_Run;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Pl0CompilerQtClass)
    {
        if (Pl0CompilerQtClass->objectName().isEmpty())
            Pl0CompilerQtClass->setObjectName(QString::fromUtf8("Pl0CompilerQtClass"));
        Pl0CompilerQtClass->resize(709, 498);
        action_Open = new QAction(Pl0CompilerQtClass);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Save = new QAction(Pl0CompilerQtClass);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Close = new QAction(Pl0CompilerQtClass);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        action_Run = new QAction(Pl0CompilerQtClass);
        action_Run->setObjectName(QString::fromUtf8("action_Run"));
        action_Build = new QAction(Pl0CompilerQtClass);
        action_Build->setObjectName(QString::fromUtf8("action_Build"));
        action_About = new QAction(Pl0CompilerQtClass);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        action_Clear = new QAction(Pl0CompilerQtClass);
        action_Clear->setObjectName(QString::fromUtf8("action_Clear"));
        centralWidget = new QWidget(Pl0CompilerQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(3);
        gridLayout->setVerticalSpacing(4);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 2, 1, 1);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);

        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setContextMenuPolicy(Qt::PreventContextMenu);
        textEdit_2->setTabStopWidth(80);

        gridLayout->addWidget(textEdit_2, 2, 0, 1, 3);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 3);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(2, 2);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        Pl0CompilerQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Pl0CompilerQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 26));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_Run = new QMenu(menuBar);
        menu_Run->setObjectName(QString::fromUtf8("menu_Run"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        Pl0CompilerQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Pl0CompilerQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Pl0CompilerQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Pl0CompilerQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Pl0CompilerQtClass->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_Run->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addAction(action_Close);
        menu_Edit->addAction(action_Clear);
        menu_Run->addAction(action_Run);
        menu_Run->addAction(action_Build);
        menu_Help->addAction(action_About);

        retranslateUi(Pl0CompilerQtClass);

        QMetaObject::connectSlotsByName(Pl0CompilerQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *Pl0CompilerQtClass)
    {
        Pl0CompilerQtClass->setWindowTitle(QApplication::translate("Pl0CompilerQtClass", "Pl0CompilerQt", nullptr));
        action_Open->setText(QApplication::translate("Pl0CompilerQtClass", "&Open", nullptr));
        action_Save->setText(QApplication::translate("Pl0CompilerQtClass", "&Save", nullptr));
        action_Close->setText(QApplication::translate("Pl0CompilerQtClass", "&Close", nullptr));
        action_Run->setText(QApplication::translate("Pl0CompilerQtClass", "Build and &Run", nullptr));
        action_Build->setText(QApplication::translate("Pl0CompilerQtClass", "&Build", nullptr));
        action_About->setText(QApplication::translate("Pl0CompilerQtClass", "&About", nullptr));
        action_Clear->setText(QApplication::translate("Pl0CompilerQtClass", "&Clear", nullptr));
        menu_File->setTitle(QApplication::translate("Pl0CompilerQtClass", "&File", nullptr));
        menu_Edit->setTitle(QApplication::translate("Pl0CompilerQtClass", "&Edit", nullptr));
        menu_Run->setTitle(QApplication::translate("Pl0CompilerQtClass", "&Run", nullptr));
        menu_Help->setTitle(QApplication::translate("Pl0CompilerQtClass", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pl0CompilerQtClass: public Ui_Pl0CompilerQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PL0COMPILERQT_H
