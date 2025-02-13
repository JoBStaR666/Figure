#include "figurefabric.h"
#include "randomgenerator.h"
#include "circle.h"
#include "triangle.h"
#include "square.h"

#include <QtDebug>


Figure *FigureFabric::getFigure(FigureType type, const QPointF& pointClick) noexcept
{
    RandomGenerator<int> genColor{0,256};
    RandomGenerator<int> getLength{30,60};
    RandomGenerator<double> genPoint{-20, 20};
    auto generatePoint = [&genPoint]() { return QPointF{genPoint(), genPoint()};};
    Figure* figure;
    switch (type) {
    case FigureType::Ellipse:
        figure = new Ellipse(getLength(), getLength());
        break;
    case FigureType::Circle:
        figure = new Circle(genPoint());
        break;
    case FigureType::Triange:
        figure = new Triangle(generatePoint(),generatePoint(),generatePoint());
        break;
    case FigureType::Quadrilateral:
        figure = new ConvexUnconvexPolygon(generatePoint(), generatePoint(), generatePoint(), generatePoint());
        break;
    case FigureType::Parallelogramm:
        figure = new Parallelogramm(generatePoint(), generatePoint(), generatePoint());
        break;
    case FigureType::Rectangle:
        figure = new Rectangle(generatePoint(), generatePoint());
        break;
    case FigureType::Square:
        figure = new Square(generatePoint(), getLength());
        break;
    default:
        figure = new Triangle(generatePoint(),generatePoint(),generatePoint());
        break;
    }
    figure->setInsetColor(QColor(genColor(), genColor(), genColor(),genColor()));
    figure->setPos(pointClick.x(), pointClick.y());

    return figure;
}
