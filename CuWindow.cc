#include "CuWindow.h"
#include <unistd.h>


CuWindow::CuWindow(string name, int width, int height, RGB background): 
    name(name), width(width), height(height), background(background), display(XOpenDisplay(nullptr)), panels(PanelArray()) {

    if (display == NULL){
        cerr<<"Cannot open display"<<endl;
        exit(1);
    }

    window = XCreateSimpleWindow(display,  RootWindow(display, 0), 0, 0, width, height,
                                 0, 0x000000, background.getColour());
    XStoreName(display, window, name.c_str());
    graphicsContext = XCreateGC(display, window, 0, NULL);
    XMapWindow(display, window);
    XFlush(display);

    usleep(20000); 
}

CuWindow::~CuWindow(){
    XFreeGC(display, graphicsContext);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    for (int i = 0; i < panels.getSize(); ++i) {
        delete panels.get(i);
    }
}


bool CuWindow::addPanel(FlowPanel* panel){
    if (panel->getX() + panel->getWidth() > width || panel->getY() + panel->getHeight() > height){
        return false;
    }

    for (int i = 0; i < panels.getSize(); ++i) {
        if (panels.get(i)->overlaps(*panel)) {
            return false;
        }
    }

    if (panels.add(panel)) {
        return true;
    }

    return false;
}

FlowPanel* CuWindow::removePanel(const std::string& id){
    return panels.remove(id);
}

FlowPanel* CuWindow::getPanel(const std::string& id) const {
    return panels.get(id);
}

void CuWindow::draw(){
    usleep(100000);
    XSetForeground(display, graphicsContext, background.getColour());
    XFillRectangle(display, window, graphicsContext, 0, 0, width, height);

    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->draw(display, window, graphicsContext);
    }

    XFlush(display);
}

void CuWindow::print() const {
    cout<<"Window:\t"<< name <<endl;
    cout<<"Flowpanels: "<< panels.getSize() <<endl;
}

void CuWindow::printPanels() const {
    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->print();
    }
}

void CuWindow::printPanelTextAreas() const {
    for (int i = 0; i < panels.getSize(); i++){
        panels.get(i)->printTextAreas();
    }
}
