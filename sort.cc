#include <algorithm>
#include <cmath>
#include <iostream>
#include <time.h>
#include <vector>

#define DEBUG 0
using namespace std;
#if 0
// this can be used only with a function pointer
template <typename T>
using Comparator = bool(*)(const T& e1, const T& e2);
#endif
template<typename T>
void
swap (vector<T>& data,
    int64_t p1,
    int64_t p2)
{
    auto tmp = data.at(p1);
    data.at(p1) = data.at(p2);
    data.at(p2) = tmp;
}

template<typename T, typename FunctorComp>
int64_t
partition(vector<T>& data,
        FunctorComp& comp,
        int64_t start,
        int64_t end)
{
    const T& pivot = data[end];
    auto j = end - 1;   // right side index. It moves left
    auto i = start;     // left side index. It moves right
    while (i < j)       // loop until the indices meet
    {
        if (!comp(data[i], pivot)) {
            swap (data, i, j);
            j--;
            continue;
        }
        i++;
    }
    // last comparison to decide position of pivotted element
    if (!comp(data[i], pivot)) {
        swap (data, i, end);
        return i;
    } else {
        swap (data, i + 1, end);
        return i + 1;
    }
}

template <typename T, typename FunctorComp>
void
quickSort (vector<T>& data,
        FunctorComp& comp,
        int64_t start,
        int64_t end)
{
    if (start >= end) { return; }
    auto pivotPos = partition(data, comp, start, end);
#if DEBUG
    cout << endl << "Intermediate stage: ";
    for_each (data.begin(), data.end(), [](T x) {cout << x << ",";});
#endif
    quickSort(data, comp, start, pivotPos - 1);
    quickSort(data, comp, pivotPos + 1, end);
}

template <typename T, typename FunctorComp>
void
bubbleSort (vector<T>& data,
        FunctorComp& comp)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = 0; j < data.size() - i - 1; j++)
        {
            if (!comp(data[j], data[j + 1])) { swap(data, j , j + 1); }
        }
    }
}

template <typename T>
class LessThan
{
public:
    LessThan()
        : cnt(0)
        {}
    bool
    operator()(const T& a, const T& b)
    {
        cnt++;
        return a < b;
    }
    int
    numCalls()
    {
        return cnt;
    }
private:
        int cnt;
};

bool
compInt (const int &a,const int &b)
{
    return a > b;
}

bool
compChar (const char& c1, const char& c2)
{
    return tolower(c1) < tolower(c2);
}

// Ascending order comparison. Returns true if first float value < second float value
bool
compFloat (const float& a, const float& b)
{
    return (abs(a) < abs(b));
}

int
main (int argc, char *argv[])
{
    cout << "Enter the number of elements you need for sorting" << endl;
    int numElems = 0;
    cin >> numElems;
    srand(time(NULL));

    cout << "++++ Sorting integers in descending order ++++" << endl;
    vector<int> vi;
    for (size_t i {}; i < numElems; i++)
    {
        vi.push_back(rand() % 100);
    }
    cout << "Input Data ";
    for_each (vi.begin(), vi.end(), [](int x) {cout << x << ",";});
    quickSort(vi, compInt, 0, vi.size() - 1);
    cout << endl << "Output data ";
    for_each (vi.begin(), vi.end(), [](int x) {cout << x << ",";});
    cout << endl;

    cout << "++++ Sorting characters alphabetically (ignoring case) ++++" << endl;
    vector<char> vc;
    for (size_t i {}; i < numElems; i++)
    {
        int n1 = rand() % 26;
        int n2 = rand() % 2;
        n1 += (n2 == 0) ? 65 : 97;
        vc.push_back(n1);
    }
    cout << "Input Data ";
    for_each (vc.begin(), vc.end(), [](char x) {cout << x << ",";});
    quickSort(vc, compChar, 0, vc.size() - 1);
    cout << endl << "Output data ";
    for_each (vc.begin(), vc.end(), [](char x) {cout << x << ",";});
    cout << endl;

    cout << "++++ Sorting floating point numbers in ascending order (absolute values)" << endl;
    vector<float> vf;
    for (size_t i {}; i < numElems; i++)
    {
        int num = static_cast<float>(rand() % 100) / static_cast<float>(rand() % 100);
        if (rand() % 2 == 0) { num = -num;}
        vf.push_back(num);
    }
    cout << "Input Data ";
    for_each (vf.begin(), vf.end(), [](float x) {cout << x << ",";});
    quickSort(vf, compFloat, 0, vf.size() - 1);
    cout << endl << "Output data ";
    for_each (vf.begin(), vf.end(), [](float x) {cout << x << ",";});
    cout << endl;

    cout << "==== Bubble Sort. Sort int in ascending order ====" << endl;
    vi.clear();
    for (size_t i {}; i < 100; i++)
    {
        vi.push_back(rand() % 100);
    }
    auto vi2 = vector<int>(vi);
    cout << "Input Data ";
    for_each (vi.begin(), vi.end(), [](int x) {cout << x << ",";});
    LessThan<int> lessThan;
    bubbleSort(vi, lessThan);
    cout << endl << "Output data ";
    for_each (vi.begin(), vi.end(), [](int x) {cout << x << ",";});
    cout << endl << "Num of comparisons: " << lessThan.numCalls() << endl;

    cout << "==== Quicksort for the same data ====" << endl;
    LessThan<int> lessThan2;
    quickSort(vi2, lessThan2, 0, vi2.size() - 1);
    cout << "Output data " << endl;
    for_each (vi2.begin(), vi2.end(), [](int x) {cout << x << ",";});
    cout << endl << "Num of comparisons: " << lessThan2.numCalls() << endl;
}
