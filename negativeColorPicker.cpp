/*
*  File: negativeColorPicker.cpp
*  Implements the negative color picker for CPSC 221 PA2.
*
*/

#include "negativeColorPicker.h"

NegativeColorPicker::NegativeColorPicker(PNG& inputimg)
{
    // complete your implementation below
    img = inputimg;
}

HSLAPixel NegativeColorPicker::operator()(PixelPoint p)
{
    // complete your implementation below
    HSLAPixel *pixel = img.getPixel(p.x, p.y);
    double h = pixel->h + 180;
    if (h >= 360) {
        h -= 360;
    }
    return HSLAPixel(h, pixel->s, 1 - pixel->l);
}
