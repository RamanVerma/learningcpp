/* unit tests for graph library */
#include "graph.h"

using namespace std;

/* Create the following graph and print it
 * (o)---------(1)
 *   \        /
 *     \ (4) /
 *     /     \
 *    /       \
 * (2)----------(3)
 */
void test_graph_creation()
{
	cout << "TEST BEGIN: " << __PRETTY_FUNCTION__ << endl;
	Graph g(5, false);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 4, 2);
	g.addEdge(1, 0, 2);
	g.addEdge(1, 4, 2);
	g.addEdge(2, 4, 2);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 2);
	g.addEdge(4, 0, 2);
	g.addEdge(4, 1, 2);
	g.addEdge(4, 2, 2);
	g.addEdge(4, 3, 2);
	g.print();
}

void
test_random_directed_graph_creation()
{
	cout << "TEST BEGIN: " << __PRETTY_FUNCTION__ << endl;
	// create random Directed graph with 5 nodes and edge density of 0.25
	auto g = Graph::generateRandomGraph(5, true, 0.25);
	g->print();
}

void
test_random_undirected_graph_creation()
{
	cout << "TEST BEGIN: " << __PRETTY_FUNCTION__ << endl;
	// create random UnDirected graph with 5 nodes and edge density of 0.25
	auto g = Graph::generateRandomGraph(5, false, 0.25);
	g->print();
}

void
test_is_connected()
{
	cout << "TEST BEGIN: " << __PRETTY_FUNCTION__ << endl;
	// test if a random raph is connected or not
	auto g = Graph::generateRandomGraph(5, true, 0.25);
	g->print();
	cout << "Graph is" << (g->is_connected() ? " ":" not ") << "connected" << endl;
	g.reset();
	g = Graph::generateRandomGraph(5, false, 0.25);
	g->print();
	cout << "Graph is" << (g->is_connected() ? " ":" not ") << "connected" << endl;

}

int
main() {
	test_graph_creation();
	test_random_directed_graph_creation();
	test_random_undirected_graph_creation();
	test_is_connected();
}

