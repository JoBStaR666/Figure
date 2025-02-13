#include "square.h"

Square::Square(QPointF topLeft, double sideSize) noexcept
    : Rectangle(topLeft, {topLeft.x() + sideSize, topLeft.y() + sideSize})
{}

