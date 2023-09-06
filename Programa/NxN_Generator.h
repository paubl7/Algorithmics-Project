#ifndef NXN_GENERATOR_H_
#define NXN_GENERATOR_H_
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
typedef vector<vector<int>> Square;
typedef float prob_fail;

Square assignacio_vertex(int n);


GrafL square_generator(int n);

#endif
