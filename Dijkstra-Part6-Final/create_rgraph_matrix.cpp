
#include "create_rgraph_matrix.h"

#include <iostream>
using namespace std;

void create_rgraph_matrix::printf()// print
{
    for(int i = 0; i< nodes_number; ++i)
        for(int j = 0; j<nodes_number; ++j)
        {
            cout << graph[i][j] << " ";
            if(j == nodes_number-1) cout << endl;
        }
    if(max_weight != -1){
        for(int i = 0; i< nodes_number; ++i)
            for(int j = 0; j<nodes_number; ++j)
            {
                cout << weights[i][j]<<"   " << " ";
                if(j == nodes_number-1) cout << endl;
            }
        }
}

void create_rgraph_matrix::random_graph_fill(const float randomness) // creating matrix
{
    for(int i = 0; i<nodes_number; ++i)
        for(int j = i; j<nodes_number; ++j)
            if (i == j)
            {
                    graph[i][j] = false;
                    if(max_weight != -1)// if user asks random graph with weights
                        weights[i][j] = -1;
            }
            else{
                graph[i][j] = graph[j][i] = ((rand()/(RAND_MAX+1.)) > randomness);
                if(max_weight!=-1 && graph[i][j])// if user asks random graph with weights
                    weights[i][j] = weights[j][i] = 1 + int((1.0*(max_weight)*rand())/(RAND_MAX+1.0));
                else // if user asks random graph with weights
                    weights[i][j] =weights[j][i] = -1;
            }
}

