#pragma once

class Easing_functions
{
public:
    Easing_functions();
    ~Easing_functions();

    static float quadraticEaseIn(float t, float b, float c, float d); //will be renamed as i figure out how this shit even works
    static float quadraticEaseOut(float t, float b, float c, float d);
    static float quadraticEaseInOut(float t, float b, float c, float d);

};