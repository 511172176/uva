#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���c������Ψ��v��
struct Edge {
    int u;
    int v;
    int weight;
};

// Union-Find (Disjoint Set Union - DSU) ���O
class UnionFind {
private:
    vector<int> parent;
public:
    // ��l�� DSU�A�`�I�Ƭ� n
    UnionFind(int n) : parent(n + 1) { // ���]�`�I�q 1 �}�l
        for(int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // �d�䶰�X���ڡA�öi����|���Y
    int find_set(int x) {
        if(parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    // �X�֨�Ӷ��X
    void union_set(int x, int y) {
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx != fy)
            parent[fx] = fy;
    }
};

// ����禡�A�Ω�Ƨ���
bool compare_edges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// ���� Kruskal �t��k�ê�^�̤p�ͦ����`�v��
int kruskal(int N, vector<Edge> &edges, UnionFind &uf) {
    // ���v������i��Ƨǡ]�q�p��j�^
    sort(edges.begin(), edges.end(), compare_edges);

    int total_weight = 0;
    for(int i = 0; i < edges.size(); ++i) {
        Edge edge = edges[i];
        // �p�G�䪺��Ӹ`�I�ݩ󤣦P�����X�A�h�[�J�̤p�ͦ���
        if(uf.find_set(edge.u) != uf.find_set(edge.v)) {
            uf.union_set(edge.u, edge.v);
            total_weight += edge.weight;
        }
    }
    return total_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // �ϥ� 0 �N�� nullptr

    int N;
    while(cin >> N) {  // Ū���`�I�� N
        // Ū���F���x�}
        vector<vector<int>> P(N + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= N; ++i) {  // 1-based indexing
            for(int j = 1; j <= N; ++j) {
                cin >> P[i][j];
            }
        }

        // ��l�� Union-Find
        UnionFind uf(N);

        // Ū���w�g�s������� M �æX�ֳo����
        int M;
        cin >> M;
        for(int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            uf.union_set(a, b);
        }

        // �����Ҧ���A�קK���ơ]�L�V�ϡ^
        vector<Edge> edges;
        for(int i = 1; i <= N; ++i) {
            for(int j = i + 1; j <= N; ++j) { // j �q i+1 �}�l�קK����
                if(P[i][j] > 0) { // ���] 0 ��ܨS����
                    edges.push_back(Edge{ i, j, P[i][j] });
                }
            }
        }

        // ���� Kruskal �t��k�H�p��̤p�ͦ����`�v��
        int total_MST_weight = kruskal(N, edges, uf);

        // �ϥ� std::endl �H�T�O�C�Ӵ��ծרҫ�ߧY��X
        cout << total_MST_weight << endl;
    }
    return 0;
}

/*
�d�ҿ�J:
3
0 990 692
990 0 179
692 179 0
1
1 2

�w����X:
179
*/
