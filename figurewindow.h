#pragma once

#include <QMainWindow>
#include <memory>

class Scene;

QT_BEGIN_NAMESPACE
namespace Ui { class ShapeWindow; }
QT_END_NAMESPACE

class FigureWindow : public QMainWindow
{
    Q_OBJECT

public:
    FigureWindow(QWidget *parent = nullptr) noexcept;
    ~FigureWindow();

private:
    void setDefaultPropertyes();

private:
    std::unique_ptr<Ui::ShapeWindow> ui;
    std::unique_ptr<Scene> figureScene;
};

