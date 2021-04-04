#include "mousepressableslider.h"

MousePressableSlider::MousePressableSlider(QWidget *parent) : QSlider(parent)
{
}

void MousePressableSlider::mousePressEvent(QMouseEvent *ev)
{
    pressed = true;
    QSlider::mousePressEvent(ev);
}

void MousePressableSlider::mouseReleaseEvent(QMouseEvent *ev)
{
    pressed = false;
    QSlider::mouseReleaseEvent(ev);
}
bool MousePressableSlider::hasPressed()
{
    return pressed;
}

void MousePressableSlider::setValue(int val)
{
    if (!pressed)
    {
        QSlider::setValue(val);
    }
}
