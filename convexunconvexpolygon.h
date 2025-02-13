#pragma once
#include <figure.h>

class ConvexUnconvexPolygon : public PolygonFigure
{
public:
    ConvexUnconvexPolygon(QPointF p1, QPointF p2, QPointF p3, QPointF p4) noexcept;

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // Figure interface
    virtual double getPerimetr() const override;
protected:
    ConvexUnconvexPolygon() noexcept {};
};
