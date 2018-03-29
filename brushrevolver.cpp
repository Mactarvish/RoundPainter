#include "brushrevolver.h"

BrushRevolver::BrushRevolver(QObject *parent) : QObject(parent), pi(3.1415926)
{
    num_Section = 60;
    alpha = 2 * pi / num_Section;
    pointSet.resize(num_Section);
}

BrushRevolver::~BrushRevolver()
{

}

void BrushRevolver::CalculatePosition(const QPoint &oriPoint)
{
    float     r = CalculateDistance(oriPoint);
    float theta = CalculateAngle(oriPoint);
    for (int i = 0; i < num_Section; i++)
    {
        float x = cos(theta + i * alpha) * r;
        float y = sin(theta + i * alpha) * r;
        pointSet[i] = QPoint(x, y);
        //qDebug() << pointSet[i];
    }
}

const vector<QPoint>& BrushRevolver::GetPoint() const
{
    return pointSet;
}

const int &BrushRevolver::GetNum_Section() const
{
    return num_Section;
}

float BrushRevolver::CalculateAngle(const QPoint &pos)
{
    float x = pos.x();
    float y = pos.y();
    
    float angle = 0;
    if (x == 0 && y > 0)
    {
        angle = pi / 2;
    }
    else if (x < 0 && y > 0)
    {
        angle = atan(y/x) + pi;
    }
    else if (x < 0 && y == 0)
    {
        angle = pi;
    }
    else if (x < 0 && y < 0)
    {
        angle = atan(y/x) - pi;
    }
    else if (x == 0 && y < 0)
    {
        angle = pi * -1 / 2;
    }
    else
    {
        angle = atan(y/x);
    }

    return angle;
}

