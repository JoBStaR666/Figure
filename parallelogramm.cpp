#include "parallelogramm.h"


Parallelogramm::Parallelogramm(QPointF p1, QPointF p2, QPointF p3) noexcept
    :ConvexUnconvexPolygon(p1, p2, p3, generatePoint(p1, p2, p3))
{
    calcAngle();
}


Parallelogramm::Parallelogramm(QPointF p1, QPointF p2, QPointF p3, QPointF p4) noexcept
    :ConvexUnconvexPolygon(p1, p2, p3, p4)
{
    calcAngle();
}

QPointF Parallelogramm::generatePoint(const QPointF &p1, const QPointF &p2, const QPointF &p3) const
{
    return {p1.x() + p3.x() - p2.x(), p1.y() + p3.y() - p2.y()};
}

void Parallelogramm::calcAngle()
{
    auto vec1Coord = MH::MathHelper::getVectorCoord(_polygon[0], _polygon[1]);
    auto vec2Coord = MH::MathHelper::getVectorCoord(_polygon[3], _polygon[1]);
    auto cosFi = MH::MathHelper::scalarMultiplyVec(vec1Coord, vec2Coord) / MH::MathHelper::getVecLength(vec1Coord) / MH::MathHelper::getVecLength(vec2Coord);
    angle = std::acos(cosFi);
}
