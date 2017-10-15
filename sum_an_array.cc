#include <iostream>
#include <vector>

const int arraySize = 10;

using namespace std;

template<class T>
T
sum(vector<T> data)
{
    T total = 0;
    for(size_t i = 0; i < data.size(); i++) {
        total += data[i];
    }
    return total;
}

int
main()
{
    vector<double> data;
    for(size_t i = 0; i < arraySize; i++) {
        data.push_back(i);
    }
    cout << "Sum of my array of doubles is " << sum<double>(data) << endl;
    return 0;
}
