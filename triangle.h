#pragma once
#include "figure.h"
#include <QPoint>


class Triangle : public PolygonFigure
{
public:
    Triangle(QPointF&& x1, QPointF&& x2, QPointF&& x3) noexcept;
    Triangle(const QPointF& x1, const QPointF& x2, const QPointF& x3) noexcept;

    // QGraphicsItem interface
public:

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // PolygonFigure interface
    virtual double getPerimetr() const override;
private:
    double calcHalfPerimetr();
};


