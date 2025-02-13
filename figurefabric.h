#pragma once
#include <QRectF>
#include <figuretypes.h>

class Figure;

class FigureFabric
{
public:
    FigureFabric() = default;
    static Figure* getFigure(FigureType type, const QPointF& pointClick) noexcept;
};
