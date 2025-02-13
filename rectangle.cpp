#include "rectangle.h"

Rectangle::Rectangle(QPointF topLeft, QPointF bottomRight) noexcept
    :Parallelogramm(topLeft, {topLeft.x(), bottomRight.y()}, {bottomRight.x(), topLeft.y()}, bottomRight)
{}

Rectangle::Rectangle(QPointF topLeft, double width, double height) noexcept
    :Parallelogramm(topLeft, {topLeft.x() + width, topLeft.y()}, {topLeft.x() + width, topLeft.y() - height, }, {topLeft.x(), topLeft.y() - height})
{}
