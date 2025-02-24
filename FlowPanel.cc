#include "FlowPanel.h"

FlowPanel::FlowPanel(int x, int y, int width, int height, const std::string& id, int xgap, int ygap): 
    dimensions(Rectangle{.x=x, .y=y, .width=width, .height = height}), id(id), xgap(xgap), ygap(ygap), areas(TAArray()) {}

FlowPanel::FlowPanel(Rectangle rect, const std::string& id, int xgap, int ygap): 
    dimensions(rect), id(id), xgap(xgap), ygap(ygap), areas(TAArray())  {}

FlowPanel::FlowPanel(const FlowPanel& panel):
    dimensions(Rectangle{.x=panel.dimensions.x,
                         .y=panel.dimensions.y,
                         .width=panel.dimensions.width,
                         .height = panel.dimensions.height}),
    id(panel.id), xgap(panel.xgap), ygap(panel.ygap), areas(TAArray()) {
        for (int i = 0; i < panel.areas.getSize(); ++i) {
            areas.add(new TextArea(*panel.areas.get(i)));
        }
    }

FlowPanel::~FlowPanel() {
    for (int i = 0; i < areas.getSize(); ++i) {
        delete areas.get(i); 
    }
}
    
bool FlowPanel::addTextArea(TextArea* ta) { return areas.add(ta); }

bool FlowPanel::addTextArea(TextArea* ta, int index) { return areas.add(ta, index); }

TextArea* FlowPanel::getTextArea(const std::string& id) const { return areas.get(id); }

TextArea* FlowPanel::getTextArea(int index) const { return areas.get(index); }

TextArea* FlowPanel::removeTextArea(const std::string& id) { return areas.remove(id); }

TextArea* FlowPanel::removeTextArea(int index) { return areas.remove(index); }


bool FlowPanel::overlaps(const FlowPanel& panel) const {
    return dimensions.overlaps(panel.dimensions);
}

void FlowPanel::draw(Display* display, Window win, GC graphicsContext) {
    XDrawRectangle(display, win, graphicsContext, dimensions.x, dimensions.y, dimensions.width, dimensions.height);

    int currentX = dimensions.x + xgap;
    int currentY = dimensions.y + ygap;
    int rowHeight = 0;
    
    for (int i = 0; i < areas.getSize(); ++i) {
        TextArea* ta = areas.get(i);
        if (!ta) continue;
    
        int taWidth = ta->getWidth();
        int taHeight = ta->getHeight();
    
        // Check if the TextArea fits in the current row
        if (currentX + taWidth + xgap > dimensions.x + dimensions.width) {
            // Move to the next row
            currentX = dimensions.x + xgap;
            currentY += rowHeight + ygap;
            rowHeight = 0;
        }
    
        // Check if the TextArea fits within the FlowPanel height
        if (currentY + taHeight + ygap > dimensions.y + dimensions.height) {
            break; // Stop drawing if the next row won't fit
        }
    
        ta->draw(display, win, graphicsContext, currentX, currentY);
    
        // Update rowHeight to track the max height in the current row
        rowHeight = std::max(rowHeight, taHeight);
    
        // Move x position for the next TextArea
        currentX += taWidth + xgap;
    }
}


void FlowPanel::print() const {
    std::cout << "FlowPanel:\t\t" << id << std::endl;
    std::cout << "Position:\t\t" << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:\t\t\t" << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Num TextAreas:\t" << areas.getSize() << std::endl;
}

void FlowPanel::printTextAreas() const {
    std::cout << "TextAreas:" << std::endl;
    for (int i = 0; i < areas.getSize(); ++i) {
        areas.get(i)->print();
    }
}