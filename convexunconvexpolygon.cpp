#include "convexunconvexpolygon.h"
#include <QPainter>

ConvexUnconvexPolygon::ConvexUnconvexPolygon(QPointF p1, QPointF p2, QPointF p3, QPointF p4) noexcept
{
    setPolygonFigure(std::move(p1), std::move(p2), std::move(p3), std::move(p4));
    MH::MathHelper::sortPolygonByPerimetr(_polygon);
}


void ConvexUnconvexPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(_brush);
    painter->drawConvexPolygon(_polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


double ConvexUnconvexPolygon::getPerimetr() const
{
    return MH::MathHelper::getPerimetrByCoordinates(_polygon);
}
