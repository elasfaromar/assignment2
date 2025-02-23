#ifndef RGB_H
#define RGB_H

#include <iostream>
#include "defs.h"
#define MAX_RGB 255
#define MIN_RGB 0

class RGB {
    public:
        RGB(int r, int g, int b);
        RGB(CuColour col);
        RGB();

        CuColour getColour() const;
        void setColour(CuColour col);
        void print() const;

        RGB static WHITE();
        RGB static BLACK();
        RGB static RED();
        RGB static GREEN();
        RGB static BLUE();
        
    private:
        int r;
        int g;
        int b;
        int validRGB(int val) const;
};

#endif