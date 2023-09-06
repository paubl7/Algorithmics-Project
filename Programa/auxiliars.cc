#include "auxiliars.h"

Graf false_init(int size){
  Graf G(size , vector<bool>(size));
  for(int i = 0; i < size; ++i){
    for (int j = 0; j < size; ++j){
      G[i][j] = false;
    }
  }
  return G;
}

GrafL mat_to_list(const Graf &G){
  GrafL convert;
  int n_vertex = G.size();
  for (int i = 0; i < n_vertex; ++i){
    pair<int,set<int>> act_vertex;
    act_vertex.first = i;
    for(int j = 0; j < n_vertex; ++j){
      if (G[i][j]) act_vertex.second.insert(j);
    }
    convert.insert(act_vertex);
  }
  return convert;
}

Graf list_to_mat(const GrafL &G){
  int n_vertex = G.size();
  Graf convert = false_init(n_vertex);
  for (auto key : G){
    for (auto it = key.second.begin(); it != key.second.end(); ++it){
      convert[key.first][(*it)] = true;
    }
  }
  return convert;
}


void showL(const GrafL &G, string nom){
  cout << endl << "LLISTA D'ADJACÈNCIA " << nom << endl;
  for (auto& v : G){
    cout << endl;
    cout << "Vertex:  " <<  v.first << " adjacent a: ";
    for (auto it = v.second.begin(); it != v.second.end(); ++it) cout << (*it) << ", ";
  }
  cout << endl;
}

void showM(const Graf &G, string nom){
  cout << endl <<"MATRIU D'ADJACÈNCIA " << nom << endl;
  for (int i = 0; i < G.size(); ++i){ //(bool i : Graf)
    cout << endl;
    for(int j = 0; j < G[i].size(); ++j){ //(bool j : Graf[i])
      cout << G[i][j] << " ";
    }
  }
  cout << endl;
}
