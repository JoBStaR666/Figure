#pragma once

#include "parallelogramm.h"

class Rectangle : public Parallelogramm
{
public:
    Rectangle(QPointF topLeft, QPointF bottomRight) noexcept;
    Rectangle(QPointF topLeft, double width, double height) noexcept;
};

