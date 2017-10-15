#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;
int
main (int argc, char *argv[])
{
    vector<unique_ptr<int>> vec;
    for (int i {}; i < 10; i++)
    {
        std::unique_ptr<int> x = make_unique<int>(i);
        vec.push_back(std::move(x));
    }
    int sum = 0;
    std::for_each(vec.begin(),
            vec.end(),
            [&sum] (unique_ptr<int>& i) { sum += *i; } );
    cout << "Sum: " << sum << endl;
    sum = 0;
#if 0
    // Following will fail to compile as they involve calling copy constructor
    // on unique_ptr
    for (auto x: vec)
    {
        sum += *x;
    }
    std::for_each(vec.begin(),
            vec.end(),
            [&sum] (unique_ptr<int> i) { sum += *i; } );
#endif
    for (auto const &x: vec)
    {
        sum += *x;
    }
    cout << "Sum: " << sum << endl;
    sum = 0;
    for (auto &x: vec)
    {
        sum += *x;
    }
    cout << "Sum: " << sum << endl;
    sum = 0;
    for (int i {}; i < vec.size(); i++)
    {
        sum += *vec[i];
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
