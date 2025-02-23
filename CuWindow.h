#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "FlowPanel.h"
#include <X11/Xlib.h>

class CuWindow {
    public:
        bool addPanel(const FlowPanel& panel);
        FlowPanel removePanel(const std::string& id);
        FlowPanel getPanel(const std::string& id) const;

        void draw();
        void print() const;
        void printPanels() const;
        void printPanelTextAreas() const;

    private:
        std::string name;
        int width;
        int height;
        Display* display;
        Window window;
        GC graphicsContext;
        RGB background;
        
};

#endif