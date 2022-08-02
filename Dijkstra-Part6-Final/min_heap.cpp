#include "main.h"
#include "min_heap.h"

#include <iostream>
#include <limits>
using namespace std;

min_heap_struct min_heap::remove_top() // does not consider if the heap is empty
{
    min_heap_struct top = MHS[0];
    MHS[0] = MHS[ --heap_size ];
    change_top(0);

    return top;
}
void min_heap::change_top(int i ) // changes the ith element if it is not the minimum of the respective subtree
{
    if( left_child(i)<heap_size && MHS[i].weight_accum>MHS[left_child(i)].weight_accum){
        swapping( &MHS[i], &MHS[left_child(i)] );
        change_top(left_child(i));
    }
    if( right_child(i)<heap_size && MHS[i].weight_accum>MHS[right_child(i)].weight_accum){
        swapping(&MHS[i], &MHS[ right_child(i) ]);
        change_top(right_child(i));
    }


}

void min_heap::insert_element( int vertex, int d, float w )
{

    if( capacity == 0 || heap_size >= capacity){
        cout<<"Full";
        return;
    }

    else{
            MHS[heap_size].vertex = vertex;
            MHS[heap_size].neighbor = d;
            MHS[heap_size].weight_accum = w;
            for(int i=heap_size; i>=0; i=parent(i) ){
                if( MHS[parent(i)].weight_accum>MHS[i].weight_accum ){
                    swapping(&MHS[parent(i)], &MHS[i]);
                }
                else {heap_size++;return;}
            }
    }
    heap_size++; // the heap size has been incremented in 1
}

int min_heap::contains( int neighbor_index )
{

    for(int i=0; i<heap_size; i++){
        if(MHS[i].neighbor == neighbor_index)
            return i;
    }
    return -1;
}
void min_heap::printf()
{
    cout<< endl <<"The heap contains:"<<endl;
    for(int i=0; i<heap_size; i++){
        cout<< "Vertex: "<< MHS[i].vertex <<" ";
        cout<< "Neighbor: "<< MHS[i].neighbor <<" ";
        cout<< "Weight: " << MHS[i].weight_accum <<endl;
    }
    cout <<endl;
}
