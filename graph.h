#include <iostream>
#include <cstdio>
#include <list>
using namespace std;
#define MAX 5000



class graph {
public:
	int V;
	int E;
	int arr[MAX][MAX];
	int *visited;
	int *processed;
	int *parent;
	int directed;
	int finished;
	int *reachable;
	int *degree;
	int *entry;
	int *exit;
	int time;

	list<int> list;
public:
	graph(){};
	graph(int tv, int te,int td) :V(te), E(te),directed(td) {};
	void init();
	void addedge(int, int, int);
	void dfsutil(int);
	void dfs();
	void print();
	void print_parent();
	void print_time();
	void process_edge(int, int);
	void pre_process_vertex(int);
	void post_process_vertex(int);
	int edge_classification(int v,int w);
	void topo_sort();
	void bfsutil(int v);
	void bfs();
};