#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

GraphEngine::GraphEngine(const Graph& graph){
    G = graph;
}

GraphEngine::GraphEngine(Eigen::Matrix2d costmat){
    unsigned int row_size = costmat.rows();
    unsigned int col_size = costmat.cols();
    if (row_size != col_size){
        std::cout << "the cost matrix has invalid shape!" << std::endl;
        G.resize(0);
    }
    G.reserve(row_size);
    for(unsigned int i=0; i<row_size; i++){
        Node node_i;
        node_i.reserve(row_size);
        for (unsigned int j=0; j<row_size; j++){
            Edge edge_i_to_j;
            edge_i_to_j.to = j; edge_i_to_j.cost = costmat(i,j);
            node_i[j] = edge_i_to_j;
        }
    }
}

GraphEngine::~GraphEngine(){}

void GraphEngine::print_path(){
    for (const auto& idx : path) {
        std::cout << idx << ", " ;
    }
    std::cout<<std::endl;
}

void GraphEngine::dijkstra(int start_idx) {
    int N = G.size();
    dis.resize(N, INF);  // initialize
    prev.resize(N, -1);  // initialize
    priority_queue<P, vector<P>, greater<P>> pq; 
    dis[start_idx] = 0;
    pq.emplace(dis[start_idx], start_idx);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

void GraphEngine::get_path(int goal_idx) {
    for (int cur = goal_idx; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // reverse
}

void GraphEngine::calc_path_dijkstra(int start_idx, int goal_idx, bool print_flag) {
    dijkstra(start_idx);
    get_path(goal_idx);
    if(print_flag){
        print_path();
    }
}