#ifndef List_H
#define List_H

#include "list_element.h"

class List{
public:
    List():head(nullptr),cursor(nullptr){}; // default constructor
    List(const int* arr, int Size); // transform constructor
    List(const List& lst); // what is the difference with List(const List* lst);
    ~List();

    void preappend(int data);
    void printf();

private:
    friend class shortestPath;
    list_element* head;
    list_element* cursor;
};
#endif // List_H
