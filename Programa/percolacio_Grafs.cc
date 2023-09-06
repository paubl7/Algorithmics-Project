#include "percolacio_Grafs.h"


/*****************************
***********GENERAR************
**Grafs Geomètrics Aleatoris**
***Graelles n*n aleatòries****
*****************************/


/**Graf percolacio(Graf &G, prob_fail q, bool perc_nodes){ //es determina si es computa una percolació per nodes(1) o per arestes(0)
  if(perc_nodes) percolacio_nodes(G,q);
  percolacio_arestes(G,q);
}*/

Graf percolacio_arestes(const Graf &G_org, prob_fail q){
	Graf G=  G_org;
	int n_vertex = G.size();
	Graf G_aux = false_init(n_vertex);//per marcar visitats
	srand(time(NULL));
	for (int i = 0; i < n_vertex; ++i){ //(bool i : Graf)
		for(int j = 0; j < n_vertex; ++j){ //(bool j : Graf[i])
			if(G[i][j] and not G_aux[j][i]){
				float n = ((float)(rand()%100))/100;
				if (n <= q){
					G[i][j] = false;
					G[j][i] = false;
				}
				G_aux[j][i] = true; // marquem l'aresta com visitada
			}
		}
	}
	return G;
}


void erase_node(GrafL &G, int node){
  G.erase(G.find(node)); //l'eliminem com a clau
  for (auto& vertex : G){
    auto node_adj = vertex.second.find(node);
    if (node_adj != vertex.second.end()) vertex.second.erase(node_adj); // l'eliminem de les llistes dels vertex als que era adjacent
  }
}


GrafL percolacio_nodes(const GrafL &G_org, prob_fail q){
	GrafL G = G_org;
  vector<bool> nodes_to_delete(G.size());
  srand(time(NULL));

  for (int i = 0; i < G.size(); ++i){
      float n = (float)(rand() % 100) / 100;
      if (n < q){
          nodes_to_delete[i] = true;
      }
  }
  for (int i = 0; i < nodes_to_delete.size(); ++i){
    if(nodes_to_delete[i]) erase_node(G,i);

  }
  return G;
}
