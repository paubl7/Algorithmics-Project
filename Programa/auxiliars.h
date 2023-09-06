#ifndef AUXILIARS_H_
#define AUXILIARS_H_
#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <time.h>
using namespace std;

typedef vector<vector<bool>> Graf; // Representem els Grafs com matrius d'adjacència
typedef map<int,set<int>> GrafL; // Representació en llista d'adjacència
typedef float prob_fail;

Graf false_init(int size);

GrafL mat_to_list(const Graf &G);

Graf list_to_mat(const GrafL &G);

void showL(const GrafL &G, string nom);

void showM(const Graf &G, string nom);

#endif
