#include <stdio.h>
#include "graph.h"
#include <Eigen/Dense>

int main(void){
  // Graph G;
  // Node node_0, node_1, node_2, node_3;
  // Edge edge_0_1, edge_0_2, edge_1_2, edge_2_1, edge_1_3, edge_2_3;
  // edge_0_1.to = 1; edge_0_1.cost = 2;
  // edge_0_2.to = 2; edge_0_2.cost = 3;
  // edge_1_2.to = 2; edge_1_2.cost = 1;
  // edge_2_1.to = 1; edge_2_1.cost = 4;
  // edge_1_3.to = 3; edge_1_3.cost = 7;
  // edge_2_3.to = 3; edge_2_3.cost = 3;
  // node_0.insert(node_0.end(), {edge_0_1, edge_0_2});
  // node_1.insert(node_1.end(), {edge_1_2, edge_1_3});
  // node_2.insert(node_2.end(), {edge_2_1, edge_2_3});
  // G.insert(G.end(), {node_0, node_1, node_2, node_3});
  
  // GraphEngine GE(G);
  // GE.calc_path_dijkstra(0, 3, true);

  Eigen::Matrix2d mat(4,4);
  mat <<  INF, 2, 3, INF,
          INF, INF, 1, 7,
          INF, 4, INF, 3,
          INF, INF, INF, INF;
  GraphEngine GE(mat);
  GE.calc_path_dijkstra(0, 3, true);
  return 0;
}