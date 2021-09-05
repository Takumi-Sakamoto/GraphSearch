#include <bits/stdc++.h>
#include <Eigen/Dense>
using namespace std;

const long long INF = 1LL << 60;  // difinition of infinity
const int MAX_NODES = 10000;

struct Edge {
    long long to;
    long long cost;
};
using Node = vector<Edge>;
using Graph = vector<Node>;
using P = pair<long, int>;

class GraphEngine{
private:
    vector<long long> dis;
    vector<int> prev;
    Graph G;

    /* dijkstra(G,s,dis,prev)
        input：Graph G, start Node s, dis, prev
    */
    void dijkstra(int start_idx);
    /* get_path(prev, t)
        input：prev, Goal Node t
        output：vector that has idx  
    */
    void get_path(int goal_idx);
    void print_path();

public:
    GraphEngine(const Graph& graph);

    GraphEngine(Eigen::Matrix2d costmat);

    virtual ~GraphEngine();    

    void calc_path_dijkstra(int start_idx, int goal_idx, bool print_flag);

    vector<int> path;
};