#pragma once
#include "convexunconvexpolygon.h"

class Parallelogramm : public ConvexUnconvexPolygon
{
public:
    Parallelogramm(QPointF p1, QPointF p2, QPointF p3) noexcept;

protected:
    Parallelogramm(QPointF p1, QPointF p2, QPointF p3, QPointF p4) noexcept;
    double angle;
private:
    QPointF generatePoint(const QPointF& p1, const QPointF& p2, const QPointF& p3) const;
    void calcAngle();
};

