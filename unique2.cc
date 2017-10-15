#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <time.h>

using namespace std;

template<typename ForwardIterator>
ForwardIterator
myUnique(ForwardIterator begin, ForwardIterator end)
{
    auto it1 = begin;
    auto it2 = begin;
    while (++it1 != end)
    {
        if (!(*it1 == *it2)) {
            *(++it2) = *it1;
        }
    }
    return ++it2;
}

int
main (int argc, char *argv[])
{
    int arr[20];
    srand(time(NULL));

    for_each(begin(arr), end(arr), [] (int &x) { x = rand() % 100; });
    cout << "Input data" << endl;
    for_each(begin(arr), end(arr), [] (const int &x) { cout << x << " "; });
    sort(begin(arr), end(arr), std::greater<int>());
    cout << endl << "Sorted data" << endl;
    for_each(begin(arr), end(arr), [] (const int &x) { cout << x << " "; });
    auto itr = myUnique(begin(arr), end(arr));
    cout << endl << "Sorted Unique data" << endl;
    for_each(begin(arr), itr, [] (const int &x) { cout << x << " "; });
    cout << endl;
}
