#include "TAArray.h"

TAArray::TAArray() {
    arr = new TextArea*[MAX_COMPONENTS];
    count = 0;
}

TAArray::~TAArray() {
    delete[] arr;
}

bool TAArray::add(TextArea* ta) {
   if (count >= MAX_COMPONENTS) return false;
   
   arr[count++] = ta;
   return true;
}

bool TAArray::add(TextArea* ta, int index) {
    if (count >= MAX_COMPONENTS || index < 0 || index > count) return false;
    
    for (int i = count; i > index; i--) {
        arr[i] = arr[i-1];
    }

    arr[index] = ta;
    count++;

    return true;
}

TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < count; i++) {
        if (arr[i]->equals(id)) {
            return arr[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= count) return nullptr;
    return arr[index];
}

TextArea* TAArray::remove(const std::string& number){
    for (int i = 0; i < count; ++i) {
        if (arr[i]->equals(number)) {
            return remove(i);
        }
    }

    return nullptr;
}

TextArea* TAArray::remove(int index){
    if (index<0 || index >= count) return nullptr;

    TextArea *goner = arr[index];

    while (index < count - 1){
        arr[index] = arr[index + 1];
        ++index;
    }
    
    --count;
    return goner;
}
