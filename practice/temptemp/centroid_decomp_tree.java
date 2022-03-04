static Graph centroid(Graph g, int[] par) {
    int n = g.size(), sz[] = new int[n];
    Graph cg = graph(n);
    centroid_dfs(g, 0, -1, sz);
    centroid_decompose(g, 0, -1, sz, cg, par, new boolean[n]);
    return cg;
}

static void centroid_decompose(Graph g, int i, int p, int[] sz, Graph cg, int[] par, boolean[] assigned) {
    if (sz[i] > 2) {
        boolean found = true;
        int next = -1;
        while(found) {
            found = false;
            for(int j : g.get(i)) {
                if(!assigned[j] && sz[j] * 2 > sz[i]) {
                    next = j;
                    found = true;
                    break;
                }
            }
            if(found) {
                sz[i] -= sz[next];
                sz[next] += sz[i];
                i = next;
            }
        }
    }
    if (p != -1) {
        cg.cto(p, i);
    }
    par[i] = p;
    assigned[i] = true;
    for (int j : g.get(i)) {
        if (!assigned[j]) {
            centroid_decompose(g, j, i, sz, cg, par, assigned);
        }
    }
}

static void centroid_dfs(Graph g, int i, int p, int[] sz) {
    sz[i] = 1;
    for (int j : g.get(i)) {
        if (j != p) {
            centroid_dfs(g, j, i, sz);
            sz[i] += sz[j];
        }
    }
}