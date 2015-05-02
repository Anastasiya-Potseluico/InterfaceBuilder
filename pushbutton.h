#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "abstractbutton.h"
#include "pushbuttonview.h"
#include <QPoint>

class PushButton : public AbstractButton
{
public:
    PushButton(QPoint&position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    QString getClassname();
    void addWidgetsForSettings();
    void setSettings(QMap<QString, QString> &settings);

private:
    bool _defaultOn;
    bool _flat;


};

#endif // PUSHBUTTON_H
