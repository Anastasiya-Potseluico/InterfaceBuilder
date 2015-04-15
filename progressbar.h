#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "abstractwidget.h"
#include "progressbarview.h"

class ProgressBar : public AbstractWidget
{
public:
    ProgressBar(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _textVisible;
    int _value;
    bool _invertedAppearance;
    int _minValue;
    int _maxValue;
};

#endif // PROGRESSBAR_H
