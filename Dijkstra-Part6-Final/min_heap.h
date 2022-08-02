#ifndef MIN_HEAP_H
#define MIN_HEAP_H

struct min_heap_struct
{
    int vertex, neighbor;
    float weight_accum =0;
};

class min_heap
{
public:
    //min_heap(int capacity = 0):capacity(capacity), heap_size(0),min_heap_array(new float[capacity]){};
    min_heap(int capacity = 0):capacity(capacity), heap_size(0),MHS(new min_heap_struct[capacity])
    {};
    int get_heap_size(){return heap_size;}; // how many elements are there now inside the heap
    min_heap_struct get_top(){ return MHS[0]; }; // return top element of queue, i.e., the minimum, without removing
    //int contains( min_heap_struct );
    int contains( int );
    void insert_element( int, int, float ); // insert at the end and reestructure the heap
    min_heap_struct remove_top(); // returns top and removing
    void change_top( int );
    void printf();

    void set_example(); // erase this, just for testing

    int parent(int i){return (i-1)/2;}; // return the index of the parent
    int left_child(int i){return 2*i +1;}; // returns index left child
    int right_child(int i){return 2*i +2;}; // returns index right child

private:
    int capacity; // maximum number of elements in the heap
    int heap_size; // elements right now in the heap
    //float *min_heap_array; // array containing the values
    min_heap_struct *MHS;
    friend class shortestPath;
};

#endif // MIN_HEAP_H
