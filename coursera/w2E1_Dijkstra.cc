#include <iostream>
#include <limits>
#include <unordered_set>
#include "graph.h"

const int NUM_NODES = 6;
const int MAX_COST = numeric_limits<int>::max();

using namespace std;

uint32_t
nextClosestVertex(shared_ptr<vector<int>> dist, unordered_set<uint32_t>& a)
{
	int minCost = MAX_COST, minIndex = 0;
	for (size_t i = 0; i < dist->size(); i++) {
		if ((dist->at(i) < minCost) && (a.find(i) == a.end())) {
			minCost = dist->at(i);
			minIndex = i;
		}
	}
	return minIndex;
}

/*
 * Dijkstra's Shortest Distance algorithm. Finds the shortest distance for all
 * nodes from a single source node
 */
shared_ptr<vector<int>>
shortestDistance(GraphPtr g, uint32_t src)
{
	// create unordered sets and distance vector
	unordered_set<uint32_t> a, b;
	auto dist = make_shared<vector<int>>(g->numNodes());
	for (auto vertex: g->vertices()) {
		auto i = vertex.id();
		b.emplace(i);
		if (i == src) {
			dist->at(i) = 0;
		} else {
			dist->at(i) = MAX_COST;
		}
	}

	while(a.size() < g->numNodes()) {
		auto id = nextClosestVertex(dist, a);
		if (dist->at(id) == MAX_COST) {
			break; // disconnected graph
		}
		auto v = g->vertices().at(id);
		a.emplace(id);
		for (auto neighbor: v.neighbors()) {
			if (a.find(neighbor.first) != a.end()) {
				continue;
			}
			if (dist->at(neighbor.first) > (dist->at(id) + neighbor.second)) {
				dist->at(neighbor.first) = (dist->at(id) + neighbor.second);
			}
		}
	}
	return dist;
}

int
main()
{
	auto g = Graph::generateRandomGraph(5, false, 0.5);
	cout << g;
	int src = 0;
	auto dist = shortestDistance(g, src);
	cout << "Source Vertex: " << src << endl;
	for (int i = 0; i < dist->size(); i++) {
		cout << "Dest Vertex: " << i << ", Distance:" << dist->at(i) << endl;
	}
}
