#include "shortestPath.h"

#include  <iostream>
using namespace std;

bool shortestPath::path(  )
{
    min_heap min_heap_class(nodes_number_gc);
    min_heap_struct top;

    return creating_heap(min_heap_class, path_init,top);
    //print_keep_tops();
}

bool shortestPath::creating_heap(min_heap min_heap_class, int vertex, min_heap_struct top)
{
    G->get_neighbors(vertex);
    G->neighbors.printf();
    list_element* h = G->neighbors.head;
    //G->printf();

    if( min_heap_class.get_heap_size() == 0 ){
        while( h!= nullptr ){
            min_heap_class.insert_element( vertex, h->d, G->weights[ vertex ][ h->d ] );
            h = h->next;
        }
    }

    if( min_heap_class.get_heap_size() > 0 ){
        int index;
        while( h!= nullptr ){
            //index = min_heap_class.contains( top );// get index if the neighbor is already in the heap
            if(!contained_keep_tops( h->d )){
            index = min_heap_class.contains( h->d );
            //cout <<endl<< "List of neighbors: "<< h->d <<endl;
            //cout << "heap contains this neighbor already?: "<< index <<endl;
            if(  index == -1){ // I took out this condition: (h->d)!= path_init
              //  cout <<endl<< "Inside index == -1 (Not in heap, not path_init) "<<index <<endl;
                min_heap_class.insert_element( vertex, h->d, top.weight_accum + G->weights[vertex][h->d] );
            }
            else if(
            //else if( !contained_keep_tops( min_heap_class.MHS[index].neighbor ) &&
                    min_heap_class.MHS[index].weight_accum > top.weight_accum + G->weights[vertex][h->d] ){
                //cout <<endl<< "Substitute: "<<index <<"********************************************"<<endl;
                min_heap_class.MHS[index] = min_heap_class.MHS[0]; // interchange with the top
                min_heap_class.remove_top(); // remove the now false top and returns the real top
                // now insert the sustitution
                min_heap_class.insert_element( vertex, h->d, top.weight_accum + G->weights[vertex][h->d] );
                //cout <<endl<< "After substitute: "<<index <<endl;
            }
            }// this if checks if the vertex is not already in the keep_tops
            h = h->next;
            //else{cout<<"Not aggregatted (Still inside while)"<<endl; cin.get();}// THIS IS FOR TESTING!!!!!
        }
    }
    top = min_heap_class.remove_top();// getting the top element
    insert_keep_tops( top.vertex, top.neighbor, top.weight_accum );
    //cout<< endl<<"After deletion of the top heap (this must appear in the keep_tops)"<<endl;
    //min_heap_class.printf();
    //print_keep_tops();
    //cout<<endl<<"min_heap_class.get_heap_size(): "<<min_heap_class.get_heap_size()<<endl;
    //cout<<"length_keep_tops: "<<length_keep_tops<<endl;// compare with heap_size

    if( top.neighbor == path_end )
        {//cout<<endl<<"The graph contains the path."<<endl;
        return true;}
    if( min_heap_class.get_heap_size() >= nodes_number_gc ){// sure about the equality condition???????????
        cout<<endl<< "Unreachable. Sorry! Sorry! Sorry! Sorry! Sorry! Sorry! Sorry! Sorry!"<<endl;
        return false;
    }
    creating_heap(min_heap_class, top.neighbor, top);// recursivity

}

void shortestPath::insert_keep_tops( int vertex, int neighbor, float weight_accum)
{
    if( length_keep_tops< nodes_number_gc + 1 ){// is this condition ok or should I quit the  +1 ??
        keep_tops[ length_keep_tops ].vertex = vertex;
        keep_tops[ length_keep_tops ].neighbor = neighbor;
        keep_tops[ length_keep_tops ].weight_accum = weight_accum;
        length_keep_tops++;
    }
    else { cout<<endl<< "Full keep_tops: Something wrong"<<endl;}// review thiiss!!!!

}

void shortestPath::print_keep_tops()
{
    cout<<endl<<"These are the tops: "<<endl;
    for(int i=0; i<length_keep_tops ; i++){
        cout<<keep_tops[i].vertex<<" ";
        cout<<keep_tops[i].neighbor<<" ";
        cout<<keep_tops[i].weight_accum<<endl;
    }
}

bool shortestPath::contained_keep_tops( int vertex )
{
    for(int i=0; i<length_keep_tops ; i++){
        if( keep_tops[i].neighbor == vertex )
            return true;
    }
    return false;
}

void shortestPath::get_final_path()
{
    min_heap_struct *final_path= new min_heap_struct[ length_keep_tops ];

    final_path[0] = keep_tops[ length_keep_tops-1 ];
    cout<<endl<<"The Final path is:" << endl;
    int j=0;
    for(int i=length_keep_tops-2; i>=0; i--)
    {
        if( keep_tops[i].neighbor == final_path[j].vertex ){
            cout<< final_path[j].neighbor<<" ";
            final_path[ ++j ] = keep_tops[i];
        }
    }
    cout<< final_path[j].neighbor<<" ";

}




