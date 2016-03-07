#include "graph.h"


void graph::init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = 0;
		}
	}
	V = 4 ;
	E = 7;
	finished = 0;
	addedge(0, 1, 1);
	addedge(1, 2, 1);
	addedge(2, 3, 1);


	//articulation
	/*	addedge(0, 1, 1);
	addedge(1, 2, 1);
	addedge(2, 3, 1);
	addedge(3, 4, 1);
	addedge(4, 5, 1);
	addedge(4, 1, 1);
	//addedge(5, 0, 1);
*/

	/*addedge(0, 1, 1,4);
	addedge(0, 7, 1, 8);
	addedge(1, 2, 1, 8);
	addedge(1, 7, 1, 11);
	addedge(2, 3, 1, 7);
	addedge(2, 8, 1, 2);
	addedge(2, 5, 1, 4);
	addedge(3, 4, 1, 9);
	addedge(3, 5, 1, 14);
	addedge(4, 5, 1, 10);
	addedge(5, 6, 1, 2);
	addedge(6, 7, 1, 1);
	addedge(6, 8, 1, 6);
	addedge(7, 8, 1, 7);
	*/

	//Inout for bellman-ford
	/*addedge(0, 1, 1,4);
	addedge(0, 7, 1, 8);
	addedge(1, 2, 1, 8);
	addedge(1, 7, 1, 11);
	addedge(2, 3, 1, 7);
	addedge(2, 8, 1, 2);
	addedge(2, 5, 1, 4);
	addedge(3, 4, 1, 9);
	addedge(3, 5, 1, 14);
	addedge(4, 5, 1, 10);
	addedge(5, 6, 1, 2);
	addedge(6, 7, 1, 1);
	addedge(6, 8, 1, 6);
	addedge(7, 8, 1, 7);
	*/

	//Input for BFS
	/*addedge(0, 1, 1);
	addedge(0, 4, 1);
	addedge(0, 5, 1);
	addedge(1, 2, 1);
	addedge(1, 4, 1);
	addedge(2, 3, 1);
	addedge(3, 4, 1);
	*/

	//Input for topo`sorting(update V and E)



	//Input for DAG with cycles(update V = 4 and E=7 )
	/*addedge(0, 1, 0);
	addedge(0, 2, 0);
	addedge(1, 2, 0);
	addedge(1, 0, 0);
	addedge(2, 0, 0);
	addedge(2, 3, 0);
	addedge(3, 3, 0);*/



	//input for test-case (update V=5 and E=7)
	//dfs for undirected graph with cycles
	/*addedge(0, 1,1);
	addedge(0,4, 1);
	addedge(1, 2, 1);
	addedge(1, 3, 1);
	addedge(1, 4, 1);
	addedge(2, 3, 1);
	addedge(3, 4, 1);*/

}

void graph::addedge(int i, int j, int directed,int w) {
	//TODO check boundary

	int c = 1;
	if (w)
		c = w;
	arr[i][j] = c;
	if (directed)
		arr[j][i] = c;
}

void graph::print() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			printf("%d ", arr[i][j]);

		}
		printf("\n");
	}
}


void graph::print_parent() {
	for (int i = 0; i < V; i++) {
		printf("parent of %d = %d \n", i, parent[i]);
	}
}

void graph::print_distance() {
	for (int i = 0; i < V; i++) {
		printf("distance of %d = %d \n", i, dist[i]);
	}
}

void graph::print_time() {
	printf("\n");
	for (int i = 0; i < V; i++) {
		printf("%d : entry_time = %d  exit time = %d \n", i, entry[i],exit[i]);
	}
}

//TREE = 0 BACK =1 FORWARD=2 CROSS=3
int graph::edge_classification(int x, int y) {
	if (parent[y] == x) {
		return 0;
	}
	if (visited[y] && !processed[y]) {
		return 1;
	}
	//TODO remaining
}

void graph::process_edge(int v, int u) {
	cout << "processing edge " << v <<" " << u << endl;
	int cl = edge_classification(v, u);
	
	//FOR toposort below condition
	/*if (cl == 1) {
		cout << "loop" << endl;
		//finished
	}*/
	
	//For directed graph below condition is enough to check back edge 
	/*if (cl == 1) {
	cout << "loop" << endl;
	//finished
	}*/

	if (cl == 0) {
		printf("tree edge %d - %d \n", v, u);
		degree[v] = degree[v] + 1;
	}

	if (cl == 1 && (parent[v] != u || directed)) {
		printf("cycle/back edge found from %d - %d \n", v, u);
		//finished = 1;
		if (entry[u] < entry[reachable[v]]) {
			reachable[v] = u;
			printf("reachable of %d is %d \n", v, u);
		}
	}
}

void graph::pre_process_vertex(int v) {
	cout << "discovered vertex  " << v << endl;
	reachable[v] = v;
}


void graph::post_process_vertex(int v) {
	cout << "processed vertex  " << v << endl;
	//FOR topo below code 
	//add to stack 
	//push(v);

	printf(" V:%d parent :%d reachable:%d reachable[p]: %d degree is %d \n", v, parent[v], reachable[v], reachable[parent[v]],degree[v]);
	int isroot = 0;
	int time_v;
	int time_p;
	if (parent[v] == -1) {
		if (degree[v] > 1) {
			printf("1.Root articulation point %d \n", v);
		}
		return;
	}
	isroot = (parent[parent[v]] == -1);
	if (!isroot) {
		if (reachable[v] == parent[v]) {
			printf("parent cut-node %d \n", parent[v]);
		}
		if (reachable[v] == v) {
			printf("brige cut-node[Parent] %d \n", parent[v]);
			if (degree[v] > 0) {
				printf("brige cut-node[child] %d \n", v);
			}
		}
	}

	time_v = entry[reachable[v]];
	time_p = entry[reachable[parent[v]]];
	if (time_v < time_p) {
		reachable[parent[v]] = reachable[v];
		printf("updating reachable[p]: %d with r[v]: %d is : %d \n", parent[v], v, reachable[v]);
	}
}



void graph::dfsutil(int v) {
	if (finished == 1)
		return;

	visited[v] = 1;
	time = time + 1;
	entry[v] = time;
	pre_process_vertex(v);
	for (int i = 0; i < V; i++) {
		if (arr[v][i] == 1) {
			if (!visited[i]) {
				parent[i] = v;
				process_edge(v, i);
				dfsutil(i);
			} else if (!processed[i] || directed == 1) {
				process_edge(v, i);
			}
		}
		if (finished)
			return;

	}
	post_process_vertex(v);
	time = time + 1;
	exit[v] = time;
	processed[v] = 1;
}


void graph::dfs() {
	visited = new int[V];
	memset(visited, 0, V*sizeof(int));
	processed = new int[V];
	memset(processed, 0, V*sizeof(int));
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));
	entry = new int[V];
	memset(entry, -1, V*sizeof(int));
	exit = new int[V];
	memset(exit, -1, V*sizeof(int));
	time = -1;
	reachable = new int[V];
	memset(reachable, -1, V*sizeof(int));
	degree = new int[V];
	memset(degree, -1, V*sizeof(int));
	for (int i = 0; i < V; i++){
		if (visited[i] == 0) {
			printf("dfs from %d as root \n", i);
			dfsutil(i);
		}
	}
	print_parent();
	print_time();
	delete[] visited;
	delete[] processed;
	delete[] entry;
	delete[] exit;
	delete[] reachable;
	delete[] degree;
}


void graph::topo_sort() {
	visited = new int[V];
	memset(visited, 0, V*sizeof(int));
	processed = new int[V];
	memset(processed, 0, V*sizeof(int));
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));
	entry = new int[V];
	memset(entry, -1, V*sizeof(int));
	exit = new int[V];
	memset(exit, -1, V*sizeof(int));
	time = -1;
	reachable = new int[V];
	memset(reachable, -1, V*sizeof(int));
	degree = new int[V];
	memset(degree, -1, V*sizeof(int));


	//init_stack();
	for (int i = 0; i < V; i++){
		if (visited[i] == 0) {
			printf("dfs from %d as root \n", i);
			dfsutil(i);
		}
	}

	//print_stack();
	print_parent();
	print_time();
	delete[] visited;
	delete[] processed;
	delete[] entry;
	delete[] exit;
	delete[] reachable;
	delete[] degree;
}


void graph::bfsutil(int v) {
	list.push_back(v);
	visited[v] = 1;
	while (list.empty() == false) {
		printf("popped is %d \n", list.front());
		int temp = list.front();
		list.pop_front();
		processed[temp] = 1;
		for (int i = 0; i < V; i++) {
			if (arr[temp][i] == 1) {
				if (visited[i] == 0) {
					list.push_back(i);
					visited[i] = 1;
					parent[i] = temp;
				}
			}
		}
	}
}

void graph::bfs() {
	visited = new int[V];
	memset(visited, 0, V*sizeof(int));
	processed = new int[V];
	memset(processed, 0, V*sizeof(int));
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));
	entry = new int[V];
	memset(entry, -1, V*sizeof(int));
	exit = new int[V];
	memset(exit, -1, V*sizeof(int));
	time = -1;
	reachable = new int[V];
	memset(reachable, -1, V*sizeof(int));
	degree = new int[V];
	memset(degree, -1, V*sizeof(int));


	//init_stack();
	for (int i = 0; i < V; i++){
		if (visited[i] == 0) {
			printf("bfs from %d as root \n", i);
			bfsutil(i);
		}
	}

	//print_stack();
	print_parent();
	print_time();
	delete[] visited;
	delete[] processed;
	delete[] entry;
	delete[] exit;
	delete[] reachable;
	delete[] degree;


}

int graph::getmin() {
	int d = INT_MAX;
	int v = 0;
	for (int i = 0; i < V; i++) {
		if ((intree[i] == 0) && (d> dist[i])) {
			d = dist[i];
			v = i;
		}
	}
	return v;

}

void graph::shortestpath(int s) {
	dist = new int[V];
	intree = new int[V];
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		intree[i] = 0;
	}


	dist[s] = 0;
	int v = s;

	while (intree[v] == 0) {
		intree[v] = 1;
		printf("concluded vertex is %d \n", v);
		for (int i = 0; i < V; i++) {
			if (arr[v][i] > 0) {
				int old = dist[i];
				int next = dist[v] + arr[v][i];
				if (next < old) {
					dist[i] = next;
					parent[i] = v;
				}
			}
		}

		v = getmin();
	}


	print_parent();
	print_distance();
}


void graph::bellmanford() {
	dist = new int[V];
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
	}

	dist[0] = 0;
	int v = 0;


	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < V; k++) {
				if (arr[j][k] != 0) {
					int old = dist[k];
					int next = dist[j] + arr[j][k];
					if (next < old) {
						dist[k] = next;
						parent[k] = j;
					}
				}
			}
		}
	}

	print_parent();
	print_distance();

}



void graph::primsmst(int start) {
	dist = new int[V];
	parent = new int[V];
	memset(parent, -1, V*sizeof(int));
	intree = new int[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		intree[i] = 0;
	}

	dist[start] = 0;
	int v = start;

	while (intree[v]==0) {
		intree[v] = 1;
		printf("picked vertext : %d \n", v);
		for (int j = 0; j < V; j++) {
			if (arr[v][j] && intree[j] == 0) {
				int old = dist[j];
				int next = arr[v][j];
				if (next < old) {
					dist[j] = next;
					parent[j] = v;
					printf("update distance of vertext : %d(%d) with parent %d\n", j,dist[j],v);

				}
			}
		}
		v = getmin();
	}

	print_parent();
	print_distance();
}


void graph::artutil(int v) {

	visited[v] = 1;
	time = time + 1;
	entry[v] = time;
	pre_process_vertex(v);
	for (int u = 0; u < V; u++) {
		if (arr[v][u]) {
			if (visited[u] == 0) {
				parent[u] = v;
				process_edge(v, u);
				visited[u] = 1;
				artutil(u);
			}
			else if (processed[u] == 0 || directed) {
				process_edge(v, u);
			}
		}
	}
	post_process_vertex(v);
	time = time + 1;
	exit[v] = time;
	processed[v] = 1;
} 


void graph::art() {
	visited = new int[V];
	memset(visited, 0, V*sizeof(int));

	processed = new int[V];
	memset(processed, 0, V*sizeof(int));

	parent = new int[V];
	memset(parent, -1, V*sizeof(int));

	entry = new int[V];
	memset(entry, -1, V*sizeof(int));

	exit = new int[V];
	memset(exit, -1, V*sizeof(int));

	time = -1;

	reachable = new int[V];
	memset(reachable, -1, V*sizeof(int));

	degree = new int[V];
	memset(degree, 0, V*sizeof(int));

	int start = 0;
	printf("art from  from %d \n", start);
	artutil(start);

	printf("finished \n");

	print_parent();
	//print_time();
	delete[] visited;
	delete[] processed;
	delete[] entry;
	delete[] exit;
	delete[] reachable;
	delete[] degree;


}
int main() {
	graph *g1 = new graph(5, 7, 0);
	g1->init();
	g1->print();
	//g1->dfs();
	//g1->bfs();
	/*int begin1 = clock();
	g1->shortestpath(0);
	int end1 = clock();
	double time1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	printf("time spen1 in disktra %f \n", time1);
	printf("2nd one \n");
	int begin2 = clock();
	g1->bellmanford();
	int end2 = clock();
	double time2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("time spen1 in bellman %f \n", time2);
	*/

	//g1->primsmst(0);

	g1->art();
	return 0;
}