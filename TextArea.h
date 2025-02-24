#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <X11/Xlib.h>
#include "RGB.h"

using namespace std;

class TextArea {
    friend class TAArray;
    friend class FlowPanel;
    public:
        TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(Rectangle rect, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea();
        TextArea(const TextArea& ta);

        void draw(Display *display, Window win, GC gc, int x, int y);
        bool overlaps(const TextArea& ta) const;
        void print() const;

        int getWidth() const { return dimensions.width; }
        int getHeight() const { return dimensions.height; }

        void setFill(const RGB& col) { fill = col; };
        void setBorder(const RGB& col) { border = col; };
        void setText(const std::string& text) { this->text = text; };
        void setHeight(int h) { dimensions.height = h; };

        bool equals(const string& id) const { return this->id == id; };

    private:
        Rectangle dimensions;
        std::string text, id;
        RGB fill, border;
};

#endif