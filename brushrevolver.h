#ifndef BRUSHREVOLVER_H
#define BRUSHREVOLVER_H

#include <QObject>
#include <QPoint>
#include <QDebug>
#include <math.h>
#include <malloc.h>
#include <vector>

using namespace std;

class BrushRevolver : public QObject
{
    Q_OBJECT
public:
    explicit BrushRevolver(QObject *parent = 0);
    ~BrushRevolver();

    void CalculatePosition(const QPoint& oriPoint);
    const vector<QPoint> &GetPoint() const;
    const int& GetNum_Section() const;

signals:

public slots:

private:
    float CalculateDistance(const QPoint& pos) {return sqrt(pow(pos.x(), 2) + pow(pos.y(), 2));}
    // Deg
    inline float CalculateAngle(const QPoint& pos);

    int num_Section;
    float alpha;
    const float pi;
    vector<QPoint> pointSet;

};

#endif // BRUSHREVOLVER_H
