/* Graph library */

#include<iostream>
#include<vector>
#include<forward_list>

using namespace std;

/* data type for vertices of a graph */
struct vertex {
public:
  vertex() = delete;  // don't create a vertex with zeroed or random numbered *id* member
  vertex(uint32_t id) : id_(id) { neighbors.clear(); }

  /* add a neighbor to the vertex, along with the cost/distance */
  void addNeighbor(uint32_t n, int cost) { neighbors.emplace_front(n, cost); }

  /* print the vertex and its neighbors */
  friend ostream& operator<<(ostream& out, const struct vertex& v)
  {
    out << v.id_ << " : ";
    for (auto neighbor: v.neighbors) {
      out << "(" << neighbor.first << " " << neighbor.second << ") ";
    }
    return out;
  }
private:
  // identifier for a vertex
  uint32_t id_;
  // list of neighbors to this vertex. list contains pairs of neighbor id and distance
  forward_list<pair<uint32_t, int>> neighbors;
};
typedef struct vertex vertex;

/* abstraction for a graph */
class graph
{
public:
  graph() = delete;
  graph(uint32_t numNodes)
    : numNodes_(numNodes)
  {
    for (size_t i = 0; i < numNodes_; i++) {
      vertices_.emplace_back(i);
    }
  };

  /* add an edge to the graph. returns false if either source or destnation vertex
   * is out of bounds of the vertex ids used by the structure
   */
  bool addEdge(uint32_t src, uint32_t dest, int cost)
  {
    // both source and destination vertices must be part of the graph already
    if (src >= vertices_.size() || dest >= vertices_.size()) {
      return false;
    }
    vertices_.at(src).addNeighbor(dest, cost);
    return true;
  };

  /* prints the graph */
  void print() {
    for (auto v: vertices_) {
      cout << v << endl;
    }
  }
private:
  /* num of vertices in the graph */
  uint32_t numNodes_;
  /* vector containing vertices and their neighbor information */
  vector<vertex> vertices_;
};
