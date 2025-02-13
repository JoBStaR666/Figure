#include "triangle.h"
#include <QPainter>




Triangle::Triangle(QPointF&& x1, QPointF&& x2, QPointF&& x3) noexcept
{
    setPolygonFigure(std::move(x1), std::move(x2), std::move(x3));
}

Triangle::Triangle(const QPointF &x1, const QPointF &x2, const QPointF &x3) noexcept
{
    setPolygonFigure(x1,x2,x3);
}


void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(_brush);
    painter->drawPolygon(_polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


double Triangle::getPerimetr() const
{
    return MH::MathHelper::getPerimetrByCoordinates(_polygon);
}
