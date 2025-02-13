#include "figure.h"

void Figure::setBrush(const QBrush &brush)
{
    _brush=brush;
}

const QBrush &Figure::getBrush() const
{
    return _brush;
}

void Figure::setBoundingRect(const QRectF &bRect)
{
    _boundingRect = bRect;
}


void Figure::setInsetColor(const QColor &color)
{
    _insetColor = color;
    _brush.setColor(_insetColor);
}

const QColor &Figure::getInsetColor() const
{
    return _insetColor;
}

const QRectF &Figure::getBoundingRect() const
{
    return _boundingRect;
}

