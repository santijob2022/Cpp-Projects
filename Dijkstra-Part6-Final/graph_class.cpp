
#include "graph_class.h"
#include "List.h"

#include <iostream>
using namespace std;

// **************************** delete Edge undirected ********************************
void graph_class::delete_edge(int x, int y)
{
    graph[y][x] = graph[x][y] = false;
    weights[y][x] = weights[x][y] = -1;
}

// *********************** neighbors of a given vertex ********************************
void graph_class::get_neighbors(int x)// does not consider loops
{
    neighbors.~List();
    //cout <<endl<< "Neighbors of node: "<< x <<endl;
    for(int i=0; i<nodes_number_gc; i++){
        if( i!=x && graph[x][i]==1 ){
            neighbors.preappend(i);
        }
    }
}
// ************************** check for adjacency *************************************
bool graph_class::adjacent(int x, int y)
{

    if(graph[x][y] == 1 && x<nodes_number_gc && y<nodes_number_gc ){
        return true;
    }
    else{
        return false;
    }
}
// ************************** get number of edges *************************************
int graph_class::E()
{
    if(graph == nullptr){
        cout<< endl << "You have an empty graph!" << endl;
        return 0;
    }
    else{
        int e_counter=0;
        for(int i=0; i<nodes_number_gc; i++){// since we have a simmetric matrix we check only the upper half
            for(int j=i+1 ; j<nodes_number_gc; j++){
                if( graph[i][j]==1 )
                    e_counter++;
            }
        }
        cout<< endl << "Your graph has "<< e_counter <<" edges." << endl;
        return e_counter;
    }
}
// ************************* get number of vertices *************************************
int graph_class::V( )
{
    if(graph == nullptr){
        cout<< endl << "You have an empty graph!" << endl;
        return 0;
    }
    else{
        cout<< endl << "Your graph has: "<< nodes_number_gc << " vertices." << endl;
        return nodes_number_gc;

    }
}
//// **************************** print graph ******************************************
void graph_class::printf()
{
    for(int i = 0; i< nodes_number_gc; ++i)
        for(int j = 0; j<nodes_number_gc; ++j)
        {
            cout << graph[i][j] << " ";
            if(j == nodes_number_gc-1) cout << endl;
        }
    //if(max_weight != -1)
        for(int i = 0; i< nodes_number_gc; ++i)
            for(int j = 0; j<nodes_number_gc; ++j)
            {
                cout << weights[i][j]<<"   " << " ";
                if(j == nodes_number_gc-1) cout << endl;
            }

}
// ************************* fill graph with random values ***********************************
void graph_class::random_graph_fill(const float randomness) // creating matrix
{
    for(int i = 0; i<nodes_number_gc; ++i)
        for(int j = i; j<nodes_number_gc; ++j)
            if (i == j)
            {
                graph[i][j] = false;
                if(max_weight != -1)// if user asks random graph with weights
                    weights[i][j] = -1;
            }
            else{
                graph[i][j] = graph[j][i] = ((rand()/(RAND_MAX+1.)) < randomness);
                if(max_weight!=-1 && graph[i][j])// if user asks random graph with weights
                    weights[i][j] = weights[j][i] = 1 + int((1.0*(max_weight)*rand())/(RAND_MAX+1.0));
                else // if user asks random graph with weights
                    weights[i][j] =weights[j][i] = -1;
            }
}
