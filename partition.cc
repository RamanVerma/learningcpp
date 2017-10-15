#include <algorithm>
#include <iostream>
#include <memory>
#include <time.h>
#include <vector>

using namespace std;

const int NUMELEMS = 20;

unique_ptr<vector<int>>
getEvenNumbers(vector<int> &vi)
{
    auto it = partition(vi.begin(),
                        vi.end(),
                        [] (int x)
                        { 
                            if (x % 2)
                                return false;
                            else
                                return true;
                        });
    auto vo = unique_ptr<vector<int>>( new vector<int>(vi.begin(), it) );
    return vo;
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
    cout << "Input Data" << endl;
    for_each(vi.begin(),
            vi.end(),
            [] (int x) { cout << x << " "; });
    cout << endl;
    auto vo = getEvenNumbers(vi);
    cout << "Output Data" << endl;
    for_each(vo->begin(),
            vo->end(),
            [] (int x) { cout << x << " "; });
    cout << endl;
}
