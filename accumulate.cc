#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <vector>

using namespace std;

const int NUMELEMS = 10;

template<typename InputIterator, typename T, typename BinaryOp>
T
average(InputIterator first, InputIterator last, T init, BinaryOp bop)
{
    T sum = accumulate(first, last, init, bop);
    int numElems = 0;
    while (first != last) {
        numElems++;
        first++;
    }
    return (sum / numElems);
}

int
main (int argc, char * argv[])
{
    srand(time(NULL));
    vector<int> vi;
    for (size_t i = 0; i < NUMELEMS; i++)
    {
        vi.push_back(rand() % 100);
    }
    cout << "Input data" << endl;
    for_each(vi.begin(), vi.end(), [](int x) {cout << x << " ";});

    int init = 0;
    auto avg1 = average<vector<int>::iterator, int>(vi.begin(), vi.end(), init, std::plus<>());
    auto avg = average(vi.begin(), vi.end(), init, std::plus<>());
    cout << "Average: " << avg1 << " " << avg << endl;
}
