include

bool has_cycle_dfs(List* G, int n){
	if (n<3) return false;
	bool * M new bool [n];
	for Iint i=0; i<n; i++) M[i] = false;
	for (int v=0;v<n; v++){
		if(!M[v]){
			if(dfs_has_cycle(G,M,v,-1)){
				delete[] M;
				return true;
			}
		}
	}
	delete[] M;
	return false;
}

//w is the vertex where v came from i.e w is the parent
bool dfs_has_cyc;e(List* G, bool* M, int v, int w){
	M[v]=true;
	for(List p= G[v]; p!= nullptr; p=p->next){
		int u = p->vertex;
		if(u!= w && (M[u] || dfs_has_cycle(G,M,u,v)))
			return true;
	}
	return false;
}

/*for(int i = 0; i < n; i++) done[i] = false;
//create an empty headp H of (vertex, distance)
//                  sorted on distance min heap

//insert(s, 0) into heap H
i=0 //counter
while( i<n and H is not empty do{
	extract(v,w) from H (with minimum w)
	if !done[v] then next
		d[v] = w;
	done[v]=true
	for (each vertex u adjacent to v with weight x do)
		if !done[u]
			insert(u,w+x) into H
	i++*/
		
