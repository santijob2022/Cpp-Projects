#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H

#include "create_rgraph_matrix.h"
#include "List.h"
//#include "shortestPath.h"

class graph_class
{
public:
    List neighbors; // This variable is public since it must be know to user and many other methods.

    graph_class( int nodes_number_gc=0, const float max_weight = -1 ):
        graph(new bool*[nodes_number_gc]),nodes_number_gc(nodes_number_gc), max_weight(max_weight),
        weights(new float*[nodes_number_gc])
    {
    for(int i=0; i<nodes_number_gc; i++){
        graph[i] = new bool[nodes_number_gc];
        //if( max_weight!= -1)// if asked reserve memory for the weights
        weights[i] = new float[nodes_number_gc];
        for(int j=0; j<nodes_number_gc; j++)
        { graph[i][j] = false; weights[i][j]=-1;}
    }
    };
    graph_class(class create_rgraph_matrix *G, const float max_weight = -1):
        graph(G->graph),nodes_number_gc(G->nodes_number),max_weight(max_weight){};

    int V();// returns the number of vertices
    int E();// returns the number of edges
    bool adjacent(int x, int y);// checks wether vertice x and y are adjacent
    void get_neighbors(int x);// does not consider loops
    void add_edge(int x, int y){graph[y][x] = graph[x][y] = true;} // add edge from x to y
    void random_graph_fill(const float randomness); // fills an empty graph with random edges and weights
    void printf();
    void delete_edge(int x, int y); // delete edge from vertex x to y
    float get_edge_value(int x, int y){return weights[x][y];} // get the weight associated
    void set_edge_value(int x, int y, float weight){weights[x][y]=weights[y][x]=weight;} // set edge value undirected

private:
    bool **graph;
    float **weights;
    class create_rgraph_matrix *G;
    int nodes_number_gc;
    const float max_weight;
    friend class shortestPath;
};

#endif
