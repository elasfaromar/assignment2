#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <X11/Xlib.h>
#include "RGB.h"

using namespace std;

class TextArea {
    public:
        TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(Rectangle rect, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea();
        TextArea(const TextArea& ta);

        void draw(Display *display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;

        void setFill(RGB col);
        void setBorder(RGB col);

        int getWidth() const { dimensions.width; }
        int getHeight() const { dimensions.height; }

        bool equals(const string& id) const;

    private:
        Rectangle dimensions;
        std::string text, id;
        RGB fill, border;
};

#endif