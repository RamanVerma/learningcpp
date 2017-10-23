/* unit tests for graph library */
#include "graph.h"

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
  graph g(5);
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

int
main() {
  test_graph_creation();
}

