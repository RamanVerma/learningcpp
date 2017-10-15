#include <algorithm>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

const int NUMELEMS = 20;

void
swap(vector<int>& vi, uint32_t first, uint32_t second)
{
    auto tmp = vi[first];
    vi[first] = vi[second];
    vi[second] = tmp;
}

int
partition(vector<int> &vi, int start, int end)
{
    int pivot = vi[end];
    size_t i = start;
    size_t j = end - 1;
    while (i < j) {
        if (vi[i] < pivot) {
            i++;
            continue;
        } else {
            swap(vi, i, j);
            j--;
        }
    }
    if (vi[i] < pivot) {
        swap(vi, i + 1, end);
        return i + 1;
    } else {
        swap(vi, i, end);
        return i;
    }
}

void
quickSort(vector<int> &vi, int start, int end)
{
    if (start >= end)
        return;
    auto pivotPos = partition(vi, start, end);
    quickSort(vi, start, pivotPos - 1);
    quickSort(vi, pivotPos + 1, end);
}

int
main (int argc, char *argv[])
{
    srand(time(NULL));
    vector<int> vi;
    for (size_t i = 0; i < NUMELEMS; i++)
    {
        vi.push_back(rand() % 100);
    }
    cout << "Input data" << endl;
    for_each(vi.begin(), vi.end(), [](int x) { cout << x << " "; });
    cout << endl;
    quickSort(vi, 0, NUMELEMS - 1);
    cout << "Sorted data" << endl;
    for_each(vi.begin(), vi.end(), [](int x) { cout << x << " "; });
    cout << endl;
    auto itr = unique(vi.begin(), vi.end());
    cout << "Size after running unique: " << vi.size() << endl;
    cout << "Output" << endl;
    for_each(vi.begin(), itr, [](int x) { cout << x << " "; });
    cout << endl;
    cout << "Full data" << endl;
    for_each(vi.begin(), vi.end(), [](int x) { cout << x << " "; });
    cout << endl;
}
