#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    revolver = new BrushRevolver();

    mainPicture = new QPixmap(700, 700);
    mainPicture->fill(Qt::black);
    guideline = new QPixmap(700, 700);
    guideline->fill(QColor(0, 0, 0, 0));
    InitGuideline();

    guidelineLabel = new QLabel(this);
    guidelineLabel->setPixmap(*guideline);
    guidelineLabel->move(0, 0);

    mainPictureLabel = new QLabel(this);
    mainPictureLabel->setPixmap(*mainPicture);
    mainPictureLabel->move(0, 0);

    painter = new QPainter(mainPicture);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->translate(mainPicture->width() / 2, mainPicture->height() / 2);
    painter->drawPoint(0, 0);
    //UpdatePicture();

    guidelineLabel->raise();

    this->setFixedSize(700, 730);


    isMousePressing = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (isMousePressing)
    {
        CoordinateConvert(event->pos());
        DrawDerivedPoint();
        UpdatePicture();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    isMousePressing = true;
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressing = false;
}

void Widget::CoordinateConvert(const QPoint &oriCoordinate)
{
    int offset_x = mainPictureLabel->width() / 2;
    int offset_y = mainPictureLabel->height() / 2;

    QPoint newCoordinate = QPoint(oriCoordinate.x() - offset_x, oriCoordinate.y() - offset_y);
    revolver->CalculatePosition(newCoordinate);
}

void Widget::DrawDerivedPoint() const
{
    for (int i = 0; i < revolver->GetNum_Section(); i++)
    {
        painter->drawPoint(revolver->GetPoint()[i]);
    }
}

void Widget::InitGuideline()
{
    QPainter linePainter(guideline);
    linePainter.translate(guideline->width() / 2, guideline->height() / 2);
    float num_Guideline = revolver->GetNum_Section();
    float alpha = 2 * 3.1415926 / num_Guideline;
    float r = 500;

    linePainter.setPen(QPen(Qt::white, 1));
    for (int i = 0; i < num_Guideline; i++)
    {
        QPoint begin = QPoint(cos(alpha/2 + i*alpha)*50, sin(alpha/2 + i*alpha)*50);
        QPoint   end = QPoint(cos(alpha/2 + i*alpha)*r, sin(alpha /2 + i*alpha)*r);
        linePainter.drawLine(begin, end);
    }
}


