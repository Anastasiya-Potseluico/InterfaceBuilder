#include <QtGui/QApplication>
//#include <QTest>
#include <QTextCodec>
#include "mainwindow.h"
#include <windows.h>
#include "testgeometricalobjectcollector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestGeometricalObjectCollector test1;
    Sleep( 3000 );
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QTextCodec::setCodecForCStrings(codec);
    //QTest::qExec(&test1);
    MainWindow w;
    w.show();
    
    return a.exec();
}
