#include "mathhelper.h"
#include "cmath"
#include <algorithm>



QRectF MH::MathHelper::calcCircumscribingByPolygon(const QPolygonF &polygon)
{
    if(!polygon.size())
        return {};
    QPointF topLeft = polygon.at(0), bottomRight = polygon.at(0);
    for(const auto& point : polygon)
    {
        topLeft.setX(std::min(topLeft.x(), point.x()));
        topLeft.setY(std::min(topLeft.y(), point.y()));
        bottomRight.setX(std::max(bottomRight.x(), point.x()));
        bottomRight.setY(std::max(bottomRight.y(), point.y()));
    }
    return QRectF(topLeft, bottomRight);
}

double MH::MathHelper::squareByGauss(const QPolygonF &polygon)
{
    if (polygon.size() < 3)
        return 0.f;
    double area = 0;
    for(int i = 0; i < polygon.size()-1; ++i)
    {
        area += polygon[i].x() * polygon[i + 1].y();
        area -= polygon[i].y() * polygon[i + 1].x();
    }
    area = area + polygon.last().x() * polygon[0].y() - polygon.last().y() * polygon[0].x();
    if(area)
        return area / 2;
    return std::fabs(area) / 2;
}

double MH::MathHelper::getLengthByCoordinates(const QPointF &p1, const QPointF &p2)
{
    return std::sqrt(std::pow((p1.x() - p2.x()),2) + std::pow((p1.y() - p2.y()),2));
}

double MH::MathHelper::getPerimetrByCoordinates(const QPolygonF &polygon)
{
    if(polygon.size() < 3)
        return 0;
    double perimetr = 0;
    for(int i = 0; i < polygon.size()-1; ++i)
    {
        perimetr += getLengthByCoordinates(polygon[i], polygon[i+1]);
    }
    perimetr += getLengthByCoordinates(polygon.last(), polygon[0]);
    return perimetr;
}

QPointF MH::MathHelper::getVectorCoord(const QPointF& pFrom, const QPointF& pTo)
{
    return {pTo.x() - pFrom.x(), pTo.y() - pFrom.y()};
}

double MH::MathHelper::scalarMultiplyVec(const QPointF &vec1, const QPointF &vec2)
{
    return vec1.x()*vec2.x() + vec1.y()*vec2.y();
}

double MH::MathHelper::getVecLength(const QPointF &vec)
{
    return std::sqrt(std::pow(vec.x(),2)+ std::pow(vec.y(),2));
}

void MH::MathHelper::sortPolygonByPerimetr(QPolygonF &polygon)
{
    QRectF boundingRect = calcCircumscribingByPolygon(polygon);
    QPointF centerBR = boundingRect.center();

    std::sort(polygon.begin(), polygon.end(), [&centerBR](auto p1 , auto p2){
        auto vec1Coord = getVectorCoord(centerBR, p1);
        auto vec2Coord = getVectorCoord(centerBR, p2);
        auto vec1Tan = atan2(-vec1Coord.y(), -vec1Coord.x());
        auto vec2Tan = atan2(-vec2Coord.y(), -vec2Coord.x());
        if (vec1Tan == vec2Tan)
            return getVecLength(vec1Coord) <= getVecLength(vec2Coord);
        return vec1Tan < vec2Tan;
    });
}


//QPointF MH::MathHelper::getCenterMassOfPolygon(const QPolygonF &polygon)
//{
//    double area = 0.f;
//    double partOfArea = 0.f;
//    QPointF center{0.f,0.f};
//    for(int i = 0; i < polygon.size()-1; ++i)
//    {
//        partOfArea =  polygon[i].x() * polygon[i + 1].y() - polygon[i].y() * polygon[i + 1].x();
//        area += partOfArea;
//        center.rx() += (polygon[i].x() + polygon[i+1].x())*partOfArea;
//        center.ry() += (polygon[i].y() + polygon[i+1].y())*partOfArea;
//    }
//    partOfArea =  polygon.last().x() * polygon[0].y() - polygon.last().y() * polygon[0].x();
//    area += partOfArea;
//    center.rx() += (polygon.last().x() + polygon[0].x())*partOfArea;
//    center.ry() += (polygon.last().y() + polygon[0].y())*partOfArea;


//    area *= 0.5;
//    center.rx() /= (6.0*area);
//    center.ry() /= (6.0*area);

//    return center;
//}
