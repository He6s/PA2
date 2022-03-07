/*
*  File: censorColorPicker.cpp
*  Implements the censor color picker for CPSC 221 PA2.
*
*/

#include "censorColorPicker.h"

#include <math.h> // gives access to sqrt function

/*
*  Useful function for computing the Euclidean distance between two PixelPoints
*/
double PointDistance(PixelPoint a, PixelPoint b) {
  unsigned int diff_x, diff_y;
  if (a.x > b.x)
    diff_x = a.x - b.x;
  else
    diff_x = b.x - a.x;
  if (a.y > b.y)
    diff_y = a.y - b.y;
  else
    diff_y = b.y - a.y;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

CensorColorPicker::CensorColorPicker(unsigned int b_width, PixelPoint ctr, unsigned int rad, PNG& inputimage)
{
    // complete your implementation below
    blockwidth = b_width;
    center = ctr;
    radius = rad;
    img = inputimage;
    blockyimg = inputimage;
    double sumh = 0;
    double sums = 0;
    double suml = 0;
    double suma = 0;
    int pixels = 0;
    int height = img.height();
    int width = img.width();
    for (int x1 = 0; x1 <= width / b_width; x1++) {
        for (int y1 = 0; y1 <= height / b_width; y1++) {
            if (x1 == width / b_width && y1 == height / b_width) {
                for (int x2 = 0; x2 < width % blockwidth; x2++) {
                    for (int y2 = 0; y2 < height % blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        sumh += pixel->h;
                        sums += pixel->s;
                        suml += pixel->l;
                        suma += pixel->a;
                        pixels++;
                    }
                }
                for (int x2 = 0; x2 < width % blockwidth; x2++) {
                    for (int y2 = 0; y2 < height % blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        pixel->h = sumh / pixels;
                        pixel->s = sums / pixels;
                        pixel->l = suml / pixels;
                        pixel->a = suma / pixels;
                    }
                }
            } else if (x1 == width / b_width) {
                for (int x2 = 0; x2 < width % blockwidth; x2++) {
                    for (int y2 = 0; y2 < blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        sumh += pixel->h;
                        sums += pixel->s;
                        suml += pixel->l;
                        suma += pixel->a;
                        pixels++;
                    }
                }
                for (int x2 = 0; x2 < width % blockwidth; x2++) {
                    for (int y2 = 0; y2 < blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        pixel->h = sumh / pixels;
                        pixel->s = sums / pixels;
                        pixel->l = suml / pixels;
                        pixel->a = suma / pixels;
                    }
                }
            } else if (y1 == height / b_width) {
                for (int x2 = 0; x2 < blockwidth; x2++) {
                    for (int y2 = 0; y2 < height % blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        sumh += pixel->h;
                        sums += pixel->s;
                        suml += pixel->l;
                        suma += pixel->a;
                        pixels++;
                    }
                }
                for (int x2 = 0; x2 < blockwidth; x2++) {
                    for (int y2 = 0; y2 < height % blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        pixel->h = sumh / pixels;
                        pixel->s = sums / pixels;
                        pixel->l = suml / pixels;
                        pixel->a = suma / pixels;
                    }
                }
            } else {
                for (int x2 = 0; x2 < blockwidth; x2++) {
                    for (int y2 = 0; y2 < blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        sumh += pixel->h;
                        sums += pixel->s;
                        suml += pixel->l;
                        suma += pixel->a;
                        pixels++;
                    }
                }
                for (int x2 = 0; x2 < blockwidth; x2++) {
                    for (int y2 = 0; y2 < blockwidth; y2++) {
                        HSLAPixel *pixel = blockyimg.getPixel(x1 * blockwidth + x2, y1 * blockwidth + y2);
                        pixel->h = sumh / pixels;
                        pixel->s = sums / pixels;
                        pixel->l = suml / pixels;
                        pixel->a = suma / pixels;
                    }
                }
            }
            pixels = 0;
            sumh = 0;
            sums = 0;
            suml = 0;
            suma = 0;
        }
    }
}

HSLAPixel CensorColorPicker::operator()(PixelPoint p)
{
    // complete your implementation below
    if (PointDistance(center, p) > radius) {
        return *img.getPixel(p.x, p.y);
    }
    return *blockyimg.getPixel(p.x, p.y);
}
