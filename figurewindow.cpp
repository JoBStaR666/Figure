#include "figurewindow.h"
#include "./ui_figurewindow.h"
#include "scene.h"

FigureWindow::FigureWindow(QWidget *parent) noexcept
    : QMainWindow(parent)
    , ui(std::make_unique<Ui::ShapeWindow>())
    , figureScene(std::make_unique<Scene>(this))
{
    ui->setupUi(this);
    setDefaultPropertyes();
}

FigureWindow::~FigureWindow()
{}


void FigureWindow::setDefaultPropertyes()
{
    this->resize(600,600);
    this->setFixedSize(600,600);
    if(!ui)
        return;
    figureScene->setSceneRect(-270,-270,540,540);
    ui->graphicsView->setScene(figureScene.get());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

