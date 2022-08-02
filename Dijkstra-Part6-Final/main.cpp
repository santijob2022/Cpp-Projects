// Dijkstra Algorithm.
// on a randomly generated graph of 50 nodes with weights ranging from 1.0 to 10.0,
// the node names are from 0 to 49,
// Get an average of the shortest path total weight, computing the Dijkstra algorithm for the 49 paths:
// 0 to 1, 0 to 2, 0 to 3, …, 0 to 49.

// July 25th, 2022. 07:58 p.m.

#include "main.h"

int main()
{
    const int nodes_number_gc = 50, path_init=0;
    const float max_weight = 10;
    float randomness = 0.4;
    srand(time(0));
    float sum = 0,avg;
    int counter = 0, path_end;

    graph_class G(nodes_number_gc, max_weight );
    G.random_graph_fill(randomness);

    for(path_end=1; path_end<nodes_number_gc; path_end++){
        shortestPath S(&G,path_init,path_end);
        if( S.path() ){
            sum += S.get_total_weight();
            counter++;
        }
    }

    avg = sum/(counter*1.0);

    cout<<"Sum: "<<sum<<" Counter: "<<counter<<" Avg: "<< avg <<endl;
    //cout<<endl<<"The total weight spent is: "<< S.get_total_weight() <<endl;// get total weight
    //S.get_final_path(); // get final path with the minimum total weight

    return 0;
}

// overloading swapping
void swapping(min_heap_struct *x, min_heap_struct*y)
{
    min_heap_struct *pivot = new min_heap_struct[1];

    (*pivot).neighbor = (*x).neighbor;
    (*pivot).vertex = (*x).vertex;
    (*pivot).weight_accum = (*x).weight_accum;

    (*x).neighbor = (*y).neighbor;
    (*x).vertex = (*y).vertex;
    (*x).weight_accum = (*y).weight_accum;

    (*y).neighbor = (*pivot).neighbor;
    (*y).vertex = (*pivot).vertex;
    (*y).weight_accum = (*pivot).weight_accum;

}

void swapping(float *x, float*y)
{
    float pivot;
    if( *x>*y){
        pivot = *x;
        *x = *y;
        *y = pivot;
    }
}
