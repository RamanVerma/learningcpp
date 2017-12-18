/* Graph library */

#pragma once

#include <forward_list>
#include <iostream>
#include <memory>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/* data type for vertices of a graph */
struct Vertex {
public:
  Vertex() = delete;  // don't create a vertex with zeroed or random numbered *id* member
  Vertex(uint32_t id) : id_(id) { neighbors_.clear(); }

  ~Vertex() { neighbors_.clear(); }

  /* get the vertex id*/
  const uint32_t id() {return id_;}

  /* returns const reference to neighbor list */
  const forward_list<pair<uint32_t, uint32_t>> &
  neighbors() { return neighbors_;}

  /* add a neighbor to the vertex, along with the cost/distance */
  void addNeighbor(uint32_t n, uint32_t cost) { neighbors_.emplace_front(n, cost); }


  /* print the vertex and its neighbors */
  friend ostream& operator<<(ostream& out, const struct Vertex& v)
  {
    out << v.id_ << " : ";
    for (auto neighbor: v.neighbors_) {
      out << "(" << neighbor.first << ", cost: " << neighbor.second << ") ";
    }
    return out;
  }
private:
  // identifier for a vertex
  uint32_t id_;
  // list of neighbors to this vertex. list contains pairs of neighbor id and distance
  forward_list<pair<uint32_t, uint32_t>> neighbors_;
};
typedef struct Vertex Vertex;

class Graph;
typedef std::shared_ptr<Graph> GraphPtr;
/* abstraction for a graph */
class Graph
{
private:
	static const int32_t MAX_COST = 100;
public:
  Graph() = delete;

  Graph(uint32_t numNodes, bool directed)
    : numNodes_(numNodes),
	directed_(directed)
  {
    for (size_t i = 0; i < numNodes_; i++) {
      vertices_.emplace_back(i);
    }
  };

  ~Graph()
  {
	  vertices_.clear();
  }

	/* static method to create a random sized Graph. 
	 * @param nodes [in] number of nodes for the graph
	 * @param directed [in] bool value to indicate if the graph is directed, true for directed
	 * @param density [in] density factor for graph. should be between 0 and 1
	 * @return shared pointer to the graph
	 */
	static GraphPtr
	generateRandomGraph(int numNodes = 10,
						bool directed = false,
						float density = 0.20)
	{
		srand(time(NULL));
		if (directed) {
			return randomDirectedGraph(numNodes, density);
		} else {
			return randomUnDirectedGraph(numNodes, density);
		}
	}

  /* add an edge to the graph. slot at which a vertex is saved is denoted by
   * the vertex's id. so, source and destination ids are supposed to be an
   * unsigned int value bounded by the number of vertices
   * @return false if either source or destnation vertex
   * is out of bounds of the number of vertices used by the structure; true in
   * case the edge is added successfully
   */
	bool
	addEdge(const uint32_t src,
			const uint32_t dest,
			int cost)
	{
		if (src >= vertices_.size() || dest >= vertices_.size()) {
		  return false;
		}
		vertices_.at(src).addNeighbor(dest, cost);
		if (!directed_) {
			vertices_.at(dest).addNeighbor(src, cost);
		}
		return true;
	};

  uint32_t numNodes() {
  	return numNodes_;
  }

  const vector<Vertex>& vertices() {
  	return vertices_;
  }

  /* determine if all the nodes are connected
   * @return true if connected; false otherwise
   */
  bool is_connected() {
	  if(numNodes_ <= 1) { return true; }

	  bool visited[numNodes_];
	  for (size_t i = 0; i < numNodes_; i++) {visited[i] = false;}
	  queue<uint32_t> q;
	  q.push(0);

	  while(!q.empty()) {
		auto id = q.front();
		q.pop();
		if (visited[id]) { // this vertex has already been visited
			continue;
		}
		visited[id] = true;
		auto neighbors = vertices_.at(id).neighbors();
		for (auto it=neighbors.begin(); it != neighbors.end(); it++) {
			if (!visited[it->first]) {
				q.push(it->first);
			}
		}
	  }
	  uint32_t count = 0;
	  for (size_t i = 0; i < numNodes_; i++) {
		  if (visited[i]) { count++; }
	  }
	  return (count == numNodes_);
  }

  /* prints the graph */
  friend ostream& operator<<(ostream& out, Graph& g) {
    for (auto v: g.vertices()) {
      cout << v << endl;
    }
  }
private:
  /*
   * generates an integer in the range (1 ... MAX_COST) depending on a chance/probability
   * provided as input parameter
   * @param probability [in] probablity that an integer within the range above will
   * 	be created. It must be in the range 0.0 and 1.0
   * @return an integer in the range (1...MAX_COST), OR 0
   */
  	static int32_t
	flipCoin (float probability)
	{
		auto randomNum = (double)rand(); /*0.0 <= randomNum <= (double)RAND_MAX*/
		if ((randomNum / RAND_MAX) <= probability) {
			return ((rand() % MAX_COST) + 1);
		}
		return 0;
	}
	/* static method to create a random sized Directed Graph. 
	 * @param nodes [in] number of nodes for the graph
	 * @param density [in] density factor for graph. should be between 0 and 1
	 * @return shared pointer to the graph
	 */
	static GraphPtr
	randomDirectedGraph(int numNodes = 10,
						float density = 0.20)
	{
		GraphPtr g = std::make_shared<Graph>(Graph(numNodes, true /*directed*/));
		for (auto it = g->vertices_.begin(); it != g->vertices_.end(); it++)
		{
			for (auto it2 = g->vertices_.begin(); it2 != g->vertices_.end(); it2++)
			{
				if (it2->id() == it->id() /* no edge where src and dest are same*/) {
					continue;
				}
				auto cost = flipCoin(density);
				if (cost > 0) {
					g->addEdge(it->id(), it2->id(), cost);
				}
			}
		}
		return g;
	}
	/* static method to create a random sized UnDirected Graph. 
	 * @param nodes [in] number of nodes for the graph
	 * @param density [in] density factor for graph. should be between 0 and 1
	 * @return shared pointer to the graph
	 */
	static GraphPtr
	randomUnDirectedGraph(int numNodes = 10,
						float density = 0.20)
	{
		GraphPtr g = std::make_shared<Graph>(Graph(numNodes, false /*directed*/));
		for (auto it = g->vertices_.begin(); it != g->vertices_.end(); it++)
		{
			for (auto it2 = std::next(it, 1); it2 != g->vertices_.end(); it2++)
			{
				auto cost = flipCoin(density);
				if (cost > 0) {
					g->addEdge(it->id(), it2->id(), cost);
				}
			}
		}
		return g;
	}
  /* num of vertices in the graph */
  uint32_t numNodes_;
  /* vector containing vertices and their neighbor information */
  vector<Vertex> vertices_;
  /* indicates if the graph is directed*/
  bool directed_;
};
