#include "NxN_Generator.h"

Square assignacio_vertex(int n){
  Square graella (n,vector<int>(n));
//  int n_act = 0;
  for (int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      graella[i][j] = i*n + j;
    }
  }
  return graella;
}


GrafL square_generator(int n){
  Square graella = assignacio_vertex(n);
  GrafL square_list;
  int E,O,N,S,SO,SE,NO,NE;
  int mida = graella.size();
  for (int i = 0; i < mida; ++i){
    for (int j = 0; j < mida; ++j){
      //A partir de fila 1
      set<int> adjacents;
      if (i > 0){
        S = graella[i-1][j];
        adjacents.insert(S);
        if(j < mida-1){
          SE = graella[i-1][j+1];
          adjacents.insert(SE);
        }
      }
      //A partir de la columna 1
      if(j > 0){
        O = graella[i][j-1];
        adjacents.insert(O);
        if (i < mida-1) {
          NO = graella[i+1][j-1];
          adjacents.insert(NO);
        }
        if (i > 0){
          SO = graella[i-1][j-1];
          adjacents.insert(SO);
        }
      }
      //Fins la columna mida
      if (j < mida-1){
        E = graella[i][j+1];
        adjacents.insert(E);
      }
      //Fins la fila mida
      if (i < mida-1){
        N = graella[i+1][j];
        adjacents.insert(N);
        if (j < mida-1){
          NE = graella[i+1][j+1];
          adjacents.insert(NE);
        }
      }
      square_list[graella[i][j]] = adjacents;
      }
    }
    return square_list;
  }
