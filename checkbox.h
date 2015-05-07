#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "abstractbutton.h"
#include "checkboxview.h"

class CheckBox : public AbstractButton
{
public:
    CheckBox(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    bool _tristate;
};

#endif // CHECKBOX_H
