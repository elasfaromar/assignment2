#ifndef CUWINDOW_H
#define CUWINDOW_H

#include "PanelArray.h"
#include "FlowPanel.h"
#include <X11/Xlib.h>

class CuWindow {
    public:
        CuWindow(string name, int width, int height, RGB background);
        ~CuWindow();

        bool addPanel(FlowPanel* panel);
        FlowPanel* removePanel(const std::string& id);
        FlowPanel* getPanel(const std::string& id) const;

        void draw();
        void print() const;
        void printPanels() const;
        void printPanelTextAreas() const;

    private:
        std::string name;
        int width;
        int height;
        RGB background;
        PanelArray panels;
        Display* display;
        Window window;
        GC graphicsContext;  
};

#endif