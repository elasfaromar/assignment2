#ifndef FLOWPANEL_H
#define FLOWPANEL_H

#include "TAArray.h"
#include <X11/Xlib.h>

class FlowPanel {
    friend class PanelArray;
    public:
        FlowPanel(int x, int y, int width, int height, const std::string& id, int xgap = 10, int ygap = 10);
        FlowPanel(Rectangle rect, const std::string& id, int xgap, int ygap);
        FlowPanel(const FlowPanel& panel);
        ~FlowPanel();

        int getX() const { return dimensions.x; };
        int getY() const { return dimensions.y; };
        int getWidth() const { return dimensions.width; };
        int getHeight() const { return dimensions.height; };

        bool addTextArea(TextArea* ta);
        bool addTextArea(TextArea* ta, int index);
        TextArea* getTextArea(const std::string& id) const;
        TextArea* getTextArea(int index) const;
        TextArea* removeTextArea(const std::string& id);
        TextArea* removeTextArea(int index);

        bool overlaps(const FlowPanel& panel) const;
        void draw(Display* display, Window win, GC graphicsContext);

        void print() const;
        void printTextAreas() const;

        bool equals(const std::string& id) const { return this->id == id; };

    private:
        std::string id;
        int xgap, ygap;
        Rectangle dimensions;
        TAArray areas;

};

#endif