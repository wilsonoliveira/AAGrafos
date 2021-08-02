#include <stdio.h>
#include<stdlib.h>

#define vertex int

int ** MATRIXinit(int r, int c, int val){
    int **m = (int **) malloc(r * sizeof(int *));
    for(vertex i = 0; i < r; ++i)
        m[i] = (int *) malloc(c * sizeof(int));
    
    for (vertex i = 0; i < r; i++)
        for (vertex j = 0; j < c; ++j)
            m[i][j] = val;
    
    return m;
}

struct graph{
    int V;
    int A;
    int **adj;
};

typedef struct graph *Graph;

Graph GRAPHinit (int V){
    Graph G = malloc(sizeof *G);
    G -> V = V;
    G -> A = 0;
    G -> adj = MATRIXinit(V, V, 0);
    return G;
}


void GRAPHinsertArc(Graph G, vertex v, vertex w){
    if(G -> adj[v][w] == 0){
        G -> adj[v][w] = 1;
        G -> A++;
    }
}

void GRAPHremovetArc(Graph G, vertex v, vertex w){    
    if(G -> adj[v][w] == 1){
        G -> adj[v][w] = 0;
        G -> A--;
    }
}

Graph readGRAPH(){
    FILE *arq;
    arq = fopen("grafo.txt", "r");
    int V; 
    fscanf(arq, "%d", &V);

    Graph G;  
    G =  GRAPHinit(V);
    for(int i =0; i < V; i++){
        for(int j =0; j < V; j++){
            int v;
            fscanf(arq, "%d", &v);
            
            if(v == 1){
                GRAPHinsertArc(G, i, j);
            }
        }
    }
    return G;
}

void GRAPHshow(Graph G){
    for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w){
         if (G->adj[v][w] == 1){
             printf( " %2d", w);        
        }
      }
      printf( "\n");
   }
}

int main(){
    Graph G = readGRAPH();
    GRAPHshow(G);
    return 0;
}