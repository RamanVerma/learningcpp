#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int NUMELEMS = 10;

int
main (int argc, char * argv[])
{
    int start;
    cout << "Give me the number to start with: " << endl;
    cin >> start;
    vector<int> vi = vector<int>(NUMELEMS);
    iota(vi.begin(), vi.end(), start);
    for_each(vi.begin(), vi.end(), [](int x) {cout << x << " ";});
    cout << endl;
}
