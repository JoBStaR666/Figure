#include "scene.h"
#include <QApplication>
#include <QtDebug>
#include "figure.h"
#include "figurefabric.h"
#include "randomgenerator.h"

Scene::Scene(QObject* parent) noexcept
    : QGraphicsScene(parent)
{}

Scene::~Scene()
{

}

void Scene::createRandomFigure(const QPointF& pointClick)
{
    RandomGenerator<unsigned char> genShape(static_cast<unsigned char>(FigureType::Ellipse), static_cast<unsigned char>(FigureType::LastItem_NoUse));

    FigureType figureType = static_cast<FigureType>(genShape());
    //old type Pointer -> scene had OWNERSHIP of them -> doc.qt.io//
    auto ptr = FigureFabric::getFigure(figureType,pointClick);

    addItem(ptr);

    update();

}



void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (event->button()) {
    case Qt::MouseButton::LeftButton:
        createRandomFigure(event->scenePos());
        break;
    case Qt::MouseButton::MiddleButton:
        this->clear();
        update();
        break;
    default:
        break;
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(QApplication::mouseButtons() == Qt::RightButton)
    {
        createRandomFigure(event->scenePos());
    }
}
