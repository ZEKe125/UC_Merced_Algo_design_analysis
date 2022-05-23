#include <iostream>
#include <vector>
//#include <limit>
#include <queue>
#include <algorithm>
using namespace std;

int V; // no. of vertices
int E; // no. of edges


  int ExtractMin(int *key ,bool* MSTset){
       
     // Initialize min value to inf
     int min = 1000000; 
     int min_i;
     
     for (int v = 0; v < V; v++) {
          // not part of MST
          if ( MSTset[v] == false ){
               if( key[v] < min ){
                    
                    min = key[v]; 
                    min_i = v;
               }
          }
     }
     // return min index
     return min_i;
     }

  

int main(int argc, char **argv){

// read in number of verticies and edges 
  cin>>V;
  cin>>E;
  
// declare a MSTset for members of the MST  
  bool * MSTset = new bool [V];
  
// declare a weight matrix for cost from vertex to vertex     
  int** W = new int*[V];
  for(int i = 0; i < V; i++){
    W[i] = new int[V];
  }

  //vector<int>* G = new vector<int>[V];
  
// read in values for vertex u, vertex v and cost W[][]  
  for(int i = 0; i < E; i++){
     int u,v,w;
     cin>>u>>v>>w;
     W[u][v] = w;
     W[v][u] = w;
     //G[u].push_back(v);
     //G[v].push_back(u);
  }
  

     //vector<int> Q;
     
     
     
     // declare and intialize parents and keys arrays
     int* parents = new int[V];
     int* keys = new int[V];
     for(int i = 0; i < V; i++){
          parents[i] = -1;
          keys[i] = 1000000;
          MSTset[i] = false;
     }

     // set root keys[0] to 0
     keys[0] = 0;
     
     
 
     for (int i = 0; i < V - 1; i++){
          
          // get minimum index u
          int u = ExtractMin(keys, MSTset);
          // cout << " u = " << u << endl;
          // change mst status of vertex
          MSTset[u] = true;
          
          for(int v = 0; v < V; v++){
               // check if there is a path between u and v
               if( W[u][v] ){
                    // check if v is already in the MST
                    if( MSTset[v] == false){
                         // check of new cost is less than previous cost
                         if(W[u][v] < keys[v]){
                              // u becomes parent of v
                              parents[v] = u;
                              // key equals new cost
                              keys[v] = W[u][v];
                         }   
                    } 
               }
          } 
     } 
 
 
 
  
  // print parents from index 1
  for(int i = 1; i < V; i++){
       cout << parents[i] << endl;
  }

  return 0;
}








