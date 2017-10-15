/*
 * This program helps understand memory allocation for a vector vs the number
 * of elements in the vector at a given time
 */
#include<iostream>
#include<vector>

using namespace std;

void
print(const vector<uint16_t>& vec)
{
    cout << "Vector:: Capacity: " << vec.capacity()
            << " Size: " << vec.size()
            << "\n";
}

int
main()
{
    vector<uint16_t> vec;
    vector<uint16_t> v2;
    print(vec);
    int i = 0;
    for (i = 0; i < 10; i++) {
        vec.push_back(i);
        v2.push_back(i + 10);
        print(vec);
    }
    cout << "Insert vector" << endl;
    v2.insert(v2.end(), vec.begin(), vec.end());
    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Printing vector" << endl;
    for (auto it = vec.begin(); it != vec.end();)
    {
        cout << *it  << " ";
        ++it;
    }
    cout << endl;
}
