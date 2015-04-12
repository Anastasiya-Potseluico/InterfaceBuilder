#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "abstractwidget.h"

class ProgressBar : public AbstractWidget
{
public:
    ProgressBar(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _textVisible;
    int _value;
    bool _invertedAppearance;
};

#endif // PROGRESSBAR_H
