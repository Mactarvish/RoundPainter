/******
 *
 *
 * all by Mactarvish
 *
 *
 * */
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QImage>
#include <QLabel>
#include <QPushButton>

#include "brushrevolver.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    // Update picture after every change
    void UpdatePicture() {mainPictureLabel->setPixmap(*mainPicture);}
    // Calculate coordinate offset & Conver polar coordinates to rectangular coordinates
    void CoordinateConvert(const QPoint& oriCoordinate);
    void DrawDerivedPoint() const;

    void InitGuideline();


    Ui::Widget *ui;
    QPushButton* button_Clear;
    QPushButton* button_Save;


    QPainter* painter;
    QPixmap* mainPicture;
    QPixmap* guideline;
    QLabel* mainPictureLabel;
    QLabel* guidelineLabel;
    BrushRevolver* revolver;

    bool isMousePressing;
};

#endif // WIDGET_H
