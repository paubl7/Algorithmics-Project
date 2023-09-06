#include "components.h"


void DFS(int x, set<int>& visited, const GrafL &adjlist){
	visited.insert(x);
	auto it = adjlist.find(x);
	set<int>::iterator itset;
	for (itset= (*it).second.begin(); itset != (*it).second.end(); ++itset){
		if (visited.find(*itset)== visited.end()){
			DFS(*itset, visited, adjlist);
		}
	}

}

int connect_graph(const GrafL &adjlist){
	set<int> visited;
	auto it = visited.begin();
	int count = 0;
	for(auto it_adjlist = adjlist.begin(); it_adjlist != adjlist.end(); ++it_adjlist){
			int x = (*it_adjlist).first;
			if (visited.find(x) == visited.end()){
				DFS(x,visited, adjlist);
				count+=1;
			}
	}
	return count;
}
