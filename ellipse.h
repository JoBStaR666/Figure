#pragma once

#include "figure.h"

class Ellipse : public Figure
{
public:
    Ellipse(const double& rx, const double& ry) noexcept;

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    //Figure interface
    virtual double getSquare() const override;
    virtual double getPerimetr() const override;
private:
    double _rx;
    double _ry;
};

