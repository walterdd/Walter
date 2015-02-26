#include <vector>
#include <iostream>
#include<deque>

class Graph {

public:
    std::vector<std::vector<int>> neighbours;
};

void DFS_recur(const Graph& graph,
               int start,
               std::vector<bool>* visited) {
    if((*visited)[start]) return;

    std::cout << start << std::endl;
    (*visited)[start] = true;

    for(int neighbour : graph.neighbours[start]) {
        DFS_recur(graph, neighbour, visited);
    }
}

void DFS_recur(const Graph& graph, int start) {
  std::vector<bool> visited(graph.neighbours.size(), false);

  DFS_recur(graph, start, &visited);
}

void DFS(const Graph& graph, int start) {
    std::vector<bool> visited(graph.neighbours.size(), false);

    //(vertex_index, list_index)
    std::vector<int> stack;
    stack.push_back(start);
    while(!stack.empty()) {
      int top = stack.back();
      stack.pop_back();

      if(visited[top]) continue;

      visited[top] = true;
      std::cout << top << std::endl;
      for(int neighbour : graph.neighbours[top]) {
        stack.push_back(neighbour);
      }
    }
}

void BFS(const Graph& graph, int start) {
    std::vector<bool> visited(graph.neighbours.size(), false);

    std::deque<int> queue;
    queue.push_back(start);

    while(!queue.empty()) {
        int front = queue.front();
        queue.pop_front();

        if(visited[front]) continue;

        visited[front] = true;
        std::cout << front << std::endl;

        for(int neighbour : graph.neighbours[front]) {
            queue.push_back(neighbour);
        }
    }
}

int main() {
    Graph graph;
    graph.neighbours.resize(9);
    graph.neighbours[0] = {1, 3};
    graph.neighbours[1] = {0, 2, 4};
    graph.neighbours[2] = {1,};
    graph.neighbours[3] = {0, 6, 7};
    graph.neighbours[4] = {1, 5};
    graph.neighbours[5] = {4,};
    graph.neighbours[6] = {3,};
    graph.neighbours[7] = {3, 8};
    graph.neighbours[8] = {7,};
    DFS(graph, 0);
    std::cout << std::endl;
    DFS_recur(graph, 0);
    std::cout << std::endl;
    BFS(graph, 0);
}
