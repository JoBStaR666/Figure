#pragma once
#include <QRectF>
#include <QPolygonF>

namespace MH {

class MathHelper
{
public:
    static QRectF calcCircumscribingByPolygon(const QPolygonF &polygon);
    static double squareByGauss(const QPolygonF& polygon);
    static double getLengthByCoordinates(const QPointF& p1, const QPointF&  p2);
    static double getPerimetrByCoordinates(const QPolygonF& polygon);
    static QPointF getVectorCoord(const QPointF& pFrom, const QPointF& pTo);
    static double scalarMultiplyVec(const QPointF& vec1, const QPointF& vec2);
    static double getVecLength(const QPointF& vec);
    //    static QPointF getCenterMassOfPolygon(const QPolygonF& polygon);
    static void sortPolygonByPerimetr(QPolygonF& polygon);
};

}

