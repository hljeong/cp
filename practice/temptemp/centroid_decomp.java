static int solve(List<? extends Collection<Integer>> g, int i, boolean[] bad) {
    int ans = 0;
    for (int j : g.get(i)) {
        if (!bad[j]) {
            ans += get(g, i, -1, bad);
        }
    }
    return ans;
}

static int get(List<? extends Collection<Integer>> g, int i, int p, boolean[] bad) {
    int ans = 0;
    for (int j : g.get(i)) {
        if (j != p && !bad[j]) {
            ans += get(g, j, i, bad);
        }
    }
    return ans;
}

static int centroid(List<? extends Collection<Integer>> g) {
    int n = g.size(), sz[] = new int[n];
    centroid_dfs(g, 0, -1, sz);
    return centroid_decompose(g, 0, sz, new boolean[n]);
}

static int centroid_decompose(List<? extends Collection<Integer>> g, int i, int[] sz, boolean[] assigned) {
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
    int ans = solve(g, i, assigned);
    assigned[i] = true;
    for (int j : g.get(i)) {
        if (!assigned[j]) {
            ans += centroid_decompose(g, j, sz, assigned);
        }
    }
    return ans;
}

static void centroid_dfs(List<? extends Collection<Integer>> g, int i, int p, int[] sz) {
    sz[i] = 1;
    for (int j : g.get(i)) {
        if (j != p) {
            centroid_dfs(g, j, i, sz);
            sz[i] += sz[j];
        }
    }
}