#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "shortestPath.h"
#include "graph_class.h"
#include "min_heap.h"
#include "List.h"

class shortestPath{
public:
    shortestPath( class graph_class *G, int path_init, int path_end ):
    nodes_number_gc(G->nodes_number_gc), G(G),path_init(path_init),path_end(path_end),
    keep_tops(new min_heap_struct[nodes_number_gc])
    {
        keep_tops[0].vertex = path_init;
        keep_tops[0].neighbor = path_init;
        keep_tops[0].weight_accum = 0;
        length_keep_tops++;
    };

    bool path( );
    bool creating_heap( min_heap, int, min_heap_struct );
    void insert_keep_tops( int, int, float);
    void print_keep_tops();
    bool contained_keep_tops( int );
    float get_total_weight(){return keep_tops[ length_keep_tops-1 ].weight_accum; };
    void get_final_path();


private:
    class graph_class *G;
    int nodes_number_gc, path_init, path_end;
    min_heap_struct *keep_tops;
    int length_keep_tops = 0; // tracks the lenght of the linear min_heap_struct

};

#endif // SHORTESTPATH_H
