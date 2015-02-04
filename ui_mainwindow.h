/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 4. Feb 22:39:41 2015
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *interfaceWidget;
    QWidget *maket_interface;
    QWidget *scheme_interface;
    QWidget *both_interface;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1203, 615);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        interfaceWidget = new QTabWidget(centralWidget);
        interfaceWidget->setObjectName(QString::fromUtf8("interfaceWidget"));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        interfaceWidget->setFont(font);
        interfaceWidget->setAutoFillBackground(false);
        interfaceWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"border-radius: 7px;\n"
"padding: 1px;\n"
"background-color: #E6E6E3;\n"
"}\n"
" /* Style the tab using the tab sub-control. Note that\n"
"     it reads QTabBar _not_ QTabWidget */\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 5ex;\n"
"     padding: 2px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     b"
                        "order-bottom-color: #C2C7CB; /* same as pane color */\n"
" }"));
        interfaceWidget->setTabPosition(QTabWidget::East);
        interfaceWidget->setTabShape(QTabWidget::Triangular);
        interfaceWidget->setMovable(true);
        maket_interface = new QWidget();
        maket_interface->setObjectName(QString::fromUtf8("maket_interface"));
        interfaceWidget->addTab(maket_interface, QString());
        scheme_interface = new QWidget();
        scheme_interface->setObjectName(QString::fromUtf8("scheme_interface"));
        interfaceWidget->addTab(scheme_interface, QString());
        both_interface = new QWidget();
        both_interface->setObjectName(QString::fromUtf8("both_interface"));
        interfaceWidget->addTab(both_interface, QString());

        gridLayout->addWidget(interfaceWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1203, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        interfaceWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        interfaceWidget->setTabText(interfaceWidget->indexOf(maket_interface), QApplication::translate("MainWindow", "\320\234\320\260\320\272\320\265\321\202 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260", 0, QApplication::UnicodeUTF8));
        interfaceWidget->setTabText(interfaceWidget->indexOf(scheme_interface), QApplication::translate("MainWindow", "\320\241\321\205\320\265\320\274\320\260 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260", 0, QApplication::UnicodeUTF8));
        interfaceWidget->setTabText(interfaceWidget->indexOf(both_interface), QApplication::translate("MainWindow", "\320\236\320\261\320\260 \320\262\320\260\321\200\320\270\320\260\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
