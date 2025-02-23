#ifndef PANELARRAY_H
#define PANELARRAY_H

#include "FlowPanel.h"

class PanelArray {
  public:
    PanelArray();
    ~PanelArray();

    bool add(FlowPanel*);
    
    FlowPanel* get(const string& name) const;
    FlowPanel* get(int index) const;

    FlowPanel* remove(const string& name);
    FlowPanel* remove(int index);

    bool isFull() const { return size == MAX_COMPONENTS; }
    int getSize() const { return size; }

  private:
    FlowPanel** elements;
    int size;
   
};

#endif

