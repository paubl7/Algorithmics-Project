#ifndef PERCOLACIO_GRAFS_H_
#define PERCOLACIO_GRAFS_H_
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <time.h>
#include "auxiliars.h"
using namespace std;


typedef vector<vector<bool>> Graf; // Representem els Grafs com matrius d'adjacència
typedef map<int,set<int>> GrafL; // Representació en llista d'adjacència
typedef float prob_fail;


Graf percolacio_arestes(const Graf &G_org, prob_fail q);

void erase_node (GrafL &G_org, int node);

GrafL percolacio_nodes(const GrafL &G_org, prob_fail q);

#endif
