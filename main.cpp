#include <QtGui/QApplication>
#include <QTest>
#include <QTextCodec>
#include "mainwindow.h"
#include <windows.h>
#include "testgeometricalprimitivescollector.h"
#include "testshaperecognizer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestGeometricalPrimitivesCollector test1;
    TestShapeRecognaizer test2;

    Sleep( 3000 );
    QTextCodec *codec = QTextCodec::codecForName("cp1251");
    QTextCodec::setCodecForCStrings(codec);
    QTest::qExec(&test1);
    QTest::qExec(&test2);
    MainWindow w;
    w.show();
    
    return a.exec();
}
