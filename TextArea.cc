#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border): 
    dimensions((Rectangle){.x = x, .y = y, .width = width, .height = height}), id(id), text(label), fill(fill), border(border) {}
    
TextArea::TextArea(Rectangle rect, std::string id, std::string label, RGB fill, RGB border): 
    dimensions(rect), id(id), text(label), fill(fill), border(border) {}

TextArea::TextArea(): 
    dimensions((Rectangle){.x = 0, .y = 0, .width = 25, .height = 25}), id("Default"), text("Default"), fill(RGB::WHITE()), border(RGB::BLACK()) {}

TextArea::TextArea(const TextArea& ta): 
    dimensions(ta.dimensions), id(ta.id), text(ta.text), fill(ta.fill), border(ta.border) {}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) {
    if (!display) return;
    
    XSetForeground(display, gc, fill.getColour());
    XFillRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    XSetForeground(display, gc, border.getColour());
    XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
    
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
        
    // Define a fixed letter width (assumed average letter width)
    int letter_width = 7; 
    int letter_height = 14;
    
    // Draw text inside the rectangle
    int text_x = x + 5;  // Padding from the left
    int text_y = y + 15; // Padding from the top

    int max_lines = dimensions.height / letter_height;

    // Break text into multiple lines if needed
    int text_length = text.length();
    int line_start = 0;
    int line_count = 0;

    while (line_start < text_length) {
        int line_end = line_start;
        int text_width = 0;
        
        // Calculate the width of the text one character at a time
        while (line_end < text_length) {
            text_width = (line_end - line_start + 1) * letter_width;
            
            if (text_width > dimensions.width) {
                break;
            }
            line_end++;
        }
        
        if (line_end == line_start || line_count >= max_lines) {
            break;
        }

        // Draw the substring that fits
        XDrawString(display, win, gc, text_x, text_y, text.substr(line_start, line_end - line_start).c_str(), line_end - line_start);
        text_y += letter_height; // Move down for the next line
        line_count++; // Incement line count
        line_start = line_end; // Restart counters
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
