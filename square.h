#pragma once
#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square(QPointF topLeft, double sideSize) noexcept;

};
