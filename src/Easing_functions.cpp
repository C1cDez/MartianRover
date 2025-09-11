#include "Easing_functions.h"

Easing_functions::Easing_functions()
{

}

Easing_functions::~Easing_functions()
{

}

float Easing_functions::quadraticEaseIn(float t, float b, float c, float d)
{
    return c * (t /= d) * t + b;
}

float Easing_functions::quadraticEaseOut(float t, float b, float c, float d)
{
    return 1 - (-c * (t /= d) * (t - 2)) + b;
}

float Easing_functions::quadraticEaseInOut(float t, float b, float c, float d)
{
    if ((t /= d / 2) < 1)
        return ((c / 2) * (t * t)) + b;

    return 1 - (-c / 2 * (((--t) * (t - 2)) - 1)) + b;
}