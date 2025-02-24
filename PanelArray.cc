#include "PanelArray.h"

PanelArray::PanelArray(){
    std::cout << "con PanelArray" << std::endl;
    size = 0;
    elements = new FlowPanel*[MAX_COMPONENTS];
}

PanelArray::~PanelArray(){
    std::cout << "des PanelArray" << std::endl;
    for (int i = 0; i < size; i++) {
        delete elements[i];
    }
    delete [] elements;
}


bool PanelArray::add(FlowPanel* s){
    if (size >= MAX_COMPONENTS)return false;

    elements[size++] = s;

    return true;    
}

FlowPanel* PanelArray::get(const string& id) const {
    for (int i = 0; i < size; ++i){
        if (elements[i]->equals(id)){
            return elements[i];
        }
    }
    return nullptr;
}

FlowPanel* PanelArray::get(int index) const {
    if (index < 0 || index >= size) return NULL;
    return elements[index];
}

FlowPanel* PanelArray::remove(const string& number){
    for (int i = 0; i < size; ++i) {
        if (elements[i]->equals(number)) {
            return remove(i);
        }
    }

    return nullptr;
}

FlowPanel* PanelArray::remove(int index){
    if (index<0 || index >=size) return nullptr;

    FlowPanel *goner = elements[index];

    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    
    --size;
    return goner;
}
