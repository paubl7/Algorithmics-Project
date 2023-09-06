#ifndef RGG_GENERATOR_H_
#define RGG_GENERATOR_H_
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <time.h>
#include <math.h>
#include "auxiliars.h"
using namespace std;

typedef vector<vector<bool>> Graf; // Representem els Grafs com matrius d'adjacència
typedef map<int,set<int>> GrafL; // Representació en llista d'adjacència
typedef float prob_fail;



void init_graella(int n_vertex, int size_graella);

Graf RGG_generator(int n_vertexs, int size_graella, float r);

#endif
