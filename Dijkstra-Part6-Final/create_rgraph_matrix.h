
#ifndef CREATE_RGRAPH_MATRIX_H
#define CREATE_RGRAPH_MATRIX_H

class create_rgraph_matrix
{
public:
    create_rgraph_matrix(const int nodes_number = 0, const float max_weight = -1)
    :nodes_number(nodes_number),max_weight(max_weight),graph(new bool*[nodes_number]),
    weights(new float*[nodes_number])
    {
        for(int i = 0; i < nodes_number;++i){
            graph[i] = new bool[nodes_number];
            if( max_weight!= -1)
                weights[i] = new float[nodes_number];
        }
    };

    void random_graph_fill(const float randomness);
    void printf();

private:
    friend class graph_class;
    bool **graph;
    const int nodes_number;
    const float max_weight;// if the user asks a random graph with weights this variable will change from -1
    float **weights;
};

#endif

