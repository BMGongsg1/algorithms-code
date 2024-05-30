class DJset {
public:     
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DJset(int n): parent(n), rank(n), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;   
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            size[rx] += size[ry];
            size[ry] = 0;
            if (rank[rx] == rank[ry]) rank[rx] += 1;
        }
    }
};
