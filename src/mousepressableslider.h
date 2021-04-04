#ifndef MOUSEPRESSABLESLIDER_H
#define MOUSEPRESSABLESLIDER_H

#include <QWidget>
#include <QSlider>

class MousePressableSlider : public QSlider
{
public:
    MousePressableSlider(QWidget *parent);
    bool hasPressed();
    void setValue(int);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

private:
    bool pressed;
};

#endif // MOUSEPRESSABLESLIDER_H
