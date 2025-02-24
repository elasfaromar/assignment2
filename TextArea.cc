#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border): 
    dimensions((Rectangle){.x = x, .y = y, .width = width, .height = height}), id(id), text(label), fill(fill), border(border) {}
    
TextArea::TextArea(Rectangle rect, std::string id, std::string label, RGB fill, RGB border): 
    dimensions(rect), id(id), text(label), fill(fill), border(border) {}

TextArea::TextArea(): 
    dimensions((Rectangle){.x = 0, .y = 0, .width = 25, .height = 25}), id("Default"), text("Default"), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& ta): 
    dimensions(ta.dimensions), id(ta.id), text(text), fill(ta.fill), border(ta.border) {}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    if (!display) return;
    
    // Set the fill color
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    // Set the border color and draw the border
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    // Set text color (assuming black for visibility)
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
        
    // Draw text inside the rectangle
    int text_x = x + 5;  // Padding from the left
    int text_y = y + 15; // Padding from the top
    int max_width = dimensions.width - 10; // Ensure text stays within bounds
        
    // Break text into multiple lines if needed
    size_t text_length = text.length();
    size_t line_start = 0;
    while (line_start < text_length) {
        size_t line_end = line_start;
        int text_width = 0;
        while (line_end < text_length) {
            XCharStruct text_metrics;
            int direction, ascent, descent;
            XTextExtents(XQueryFont(display, XGContextFromGC(gc)), text.substr(line_start, line_end - line_start + 1).c_str(), line_end - line_start + 1, &direction, &ascent, &descent, &text_metrics);
            text_width = text_metrics.width;
            
            if (text_width > max_width) {
                break;
            }
            line_end++;
        }
        
        if (line_end == line_start) {
            break;
        }

        // Draw the substring that fits
        XDrawString(display, win, gc, text_x, text_y, text.substr(line_start, line_end - line_start).c_str(), line_end - line_start);
        text_y += 15; // Move down for next line
        line_start = line_end;
    }
}    

bool TextArea::overlaps(const TextArea& ta) const {
    return dimensions.overlaps((Rectangle&)(ta.dimensions));
}

void TextArea::print() const {
    std::cout << "TextArea id:\t" << id << std::endl;
    std::cout << "Preferred Location:\t" << dimensions.x << ", " << dimensions.y << std::endl;
    std::cout << "Size:\t" << dimensions.width << ", " << dimensions.height << std::endl;
    std::cout << "Text:\t" << text << std::endl;
}
