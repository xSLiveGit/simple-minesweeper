/********************************************************************************
** Form generated from reading UI file 'mines1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINES1_H
#define UI_MINES1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mines1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mines1Class)
    {
        if (mines1Class->objectName().isEmpty())
            mines1Class->setObjectName(QStringLiteral("mines1Class"));
        mines1Class->resize(600, 400);
        menuBar = new QMenuBar(mines1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        mines1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mines1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mines1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(mines1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mines1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mines1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mines1Class->setStatusBar(statusBar);

        retranslateUi(mines1Class);

        QMetaObject::connectSlotsByName(mines1Class);
    } // setupUi

    void retranslateUi(QMainWindow *mines1Class)
    {
        mines1Class->setWindowTitle(QApplication::translate("mines1Class", "mines1", 0));
    } // retranslateUi

};

namespace Ui {
    class mines1Class: public Ui_mines1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINES1_H
