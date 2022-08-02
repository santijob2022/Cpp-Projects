#include "List.h"

#include <iostream>
using namespace std;

List::~List()
{
    for(cursor = head;cursor != nullptr;)
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

List::List(const List& lst)
{
    //cout<<"Inside copy constructor 1 " <<endl;
    if (lst.head == nullptr)
    {
        head = nullptr;
        cursor = nullptr;
    }
    else
    {
        list_element* h = new list_element();
        list_element* previous;

        head = h;
        h->d = lst.head->d;

        for(cursor = lst.head->next;cursor!= nullptr;)
        {
            previous = h;
            h = new list_element();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
        }
        cursor = head;
    }
}

void List::preappend(int data)
{
    if(head == nullptr)
        cursor = head = new list_element(data);
    else
        head = new list_element(data,head);
}

void List::printf()
{
    list_element* h = head;
    //cout<< "List: ";
    while(h != nullptr)
    {
      //  cout<< h->d<< " ";
        h = h->next;
    }
    //cout<< endl;
}

