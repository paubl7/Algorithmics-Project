#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <map>
#include <stdlib.h>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef map<int, set<int>> GrafL; // Representació en llista d'adjacència


//Fa una depth-first search sobre un graf representat per una llista d'adjacencies
void DFS(int x, set<int>& visited, const GrafL &adjlist);

//Calcula el nombre de component connexes que te un graf
int connect_graph(const GrafL &adjlist);


#endif
