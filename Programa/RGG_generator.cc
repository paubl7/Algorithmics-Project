#include "RGG_generator.h"



vector<pair<int,int>> vertexs;


void init_graella(int n_vertex, int size_graella){
  vertexs.clear();
  Graf distribucio = false_init(size_graella);
  srand(time(NULL));
  int added_nodes = 0;
  do{
    int randi = rand()%size_graella;
    int randj = rand()%size_graella;
    if(not distribucio[randi][randj]){
      distribucio[randi][randj] = true;
      added_nodes++;
      pair<int,int> pos = {randi,randj};
      vertexs.push_back(pos);
    }
  } while(added_nodes < n_vertex);
}


Graf RGG_generator(int n_vertexs, int size_graella, float r){
  init_graella(n_vertexs, size_graella);
  Graf RGG = false_init(vertexs.size());
  for(int act = 0; act < vertexs.size(); ++act){
      for(int comp = 0; comp < vertexs.size(); ++comp){
        if (act != comp){
          float disti = pow(abs(vertexs[act].first-vertexs[comp].first),2);
          float distj = pow(abs(vertexs[act].second-vertexs[comp].second),2);
          float dist = sqrt(disti+distj);
          if (dist <= r and not RGG[act][comp]) RGG[act][comp] = RGG[comp][act] = true;
        }
      }

  }
  return RGG;
}
