#include "ellipse.h"
#include <QPainter>
#include <randomgenerator.h>
#include <cmath>

Ellipse::Ellipse(const double& rx, const double& ry) noexcept
    :_rx(rx), _ry(ry)
{
    _boundingRect = QRectF(-_rx/2, -_ry/2, _rx, _ry);
}


void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(_brush);
    painter->drawEllipse(boundingRect());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


double Ellipse::getSquare() const
{
    return Pi*_rx*_ry;
}

double Ellipse::getPerimetr() const
{
    return 2*Pi*std::sqrt((std::pow(_rx,2) + std::pow(_ry,2))/2);
}
