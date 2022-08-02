#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

class list_element{
public:
    list_element(int data=0, list_element* ptr = nullptr):d(data), next(ptr){}

    int d;
    list_element *next;
};


#endif
