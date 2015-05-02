#ifndef LABEL_H
#define LABEL_H

#include "abstractwidget.h"
#include "labelview.h"

enum VERTICAL_ALIGNMENT {top, center_v, bottom};
enum HORIZONTAL_ALIGNMENT {left, center_h, right, justify};

class Label : public AbstractWidget
{
public:
    Label(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    QString _text;
    bool _wordWrap;
    VERTICAL_ALIGNMENT _verticalAlignment;
    HORIZONTAL_ALIGNMENT _horizontalAlignment;
};

#endif // LABEL_H
