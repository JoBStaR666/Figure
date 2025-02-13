#pragma once
#include <QGraphicsObject>
#include "figuretypes.h"
#include "QBrush"
#include <math.h>
#include <type_traits>
#include "mathhelper.h"

class Figure : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Figure() noexcept
        :_insetColor(), _boundingRect(), _brush(_insetColor), Pi(M_PI)
    {};
    void setBrush(const QBrush& brush);
    const QBrush& getBrush() const;
    void setBoundingRect(const QRectF& bRect);
    const QRectF& getBoundingRect() const;
    void setInsetColor(const QColor& color);
    const QColor& getInsetColor() const;
    virtual QRectF boundingRect() const override
    {
        return _boundingRect;
    }
    virtual double getSquare() const = 0;
    virtual double getPerimetr() const = 0;
protected:
    QColor _insetColor;
    QRectF _boundingRect;
    QBrush _brush;
    const double Pi;
};


//template <typename T>
//struct has_manhattanlength
//{
//    static void detect(...);
//    template <typename U>
//    static auto detect(const U&) -> decltype(std::declval<U>().manhattanLength());
//    const static constexpr bool value = std::is_same<int, decltype(detect(std::declval<T>()))>::value;
//};


class PolygonFigure : public Figure
{
public:
    PolygonFigure() noexcept : _polygon(){};
    template<typename ...Args, std::enable_if_t<( std::is_same_v< std::remove_cv_t< std::remove_reference_t < Args > >, QPointF >and... ), bool> = true >
    void setPolygonFigure(Args&&... args)
    {
        (_polygon.push_back(std::forward<Args>(args)), ...);
        _boundingRect = MH::MathHelper::calcCircumscribingByPolygon(_polygon);
    }
    const QPolygonF& getPoligonFigure()
    {
        return _polygon;
    }
    virtual double getSquare() const override
    {
        return MH::MathHelper::squareByGauss(_polygon);
    }

protected:
    QPolygonF _polygon;
};
