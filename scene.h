#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


class Figure;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene (QObject* parent) noexcept;
    ~Scene();

signals:
    void signalTargetCoordinate(QPointF point);
    void signalCreateShapeInRandomPosition(QRectF rectScene);
private:

    void createRandomFigure(const QPointF& pointClicl);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};
