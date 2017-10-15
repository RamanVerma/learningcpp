#include <queue>

using namespace std;

bool
is_connected()
{
    bool visited[numNodes_];
    for (auto i = 0; i < numNodes_; i++) { visited[i] = false; }

    queue<int> q;
    q.push(0);

    while (q.size() > 0) {
        // pop the first element from the queue
        auto id = q.pop();
        // check if the element is not been visited yet
        if (visited[id] == true) {
            continue;
        }
        // if not visited yet, mark it visited and iterate over its netigbor list
        visited[id] = true;
        while ((neighbor = g.next_neighbor(id)) != nullptr) {
            // add neighbors to the queue, if they have not been visited yet.
            if (visited[neighbor.first] == false) {
                q.push(neighbor.first);
            }
        }
    }
    // check the number of elements to have been visited
    int nodesVisited = 0;
    for (auto i = 0; i < numNodes_; i++) {
        if (visited[i] = true) {
            nodesVisited++;
        }
    }
    return (nodesVisited == numNodes_);
}
