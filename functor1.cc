#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

const int NUMELEMS = 10;

template<typename T, typename Func>
vector<T>
findEligible(const vector<T>& data, Func f)
{
    vector<T> v;
    if (!f) {
        return v;
    }
    for (auto& elem : data)
    {
        if (f(elem)) { v.push_back(elem); }
    }
    return v;
}

class greaterThan
{
public:
    greaterThan(int num)
        : num(num)
    {}
    bool
    operator()(const int x)
    {
        return x > num;
    }
private:
    int num;
};

bool
isPalindrome(const string& str)
{
    if (str.length() < 2) {
        return true;
    }
    size_t j = str.length() - 1;
    for(size_t i = 0; i < j; i++, j--)
    {
        if (str[i] != str[j]) {
            return false;
        }
        return true;
    }
}

bool
isUpperCase(const char& x)
{
    return isupper(x);
}

int
main(int argc, char *argv[])
{
    srand(time(NULL));

    std::function<bool(const int)> func;
    std::function<bool(const string)> func2;

    cout << "++++ Find integers greater than a user specified integer, using functor ++++" << endl;
    int in;
    vector<int> vi;
    for (size_t i {}; i < NUMELEMS; i++)
    {
        vi.push_back(rand() % 100);
    }
    cout << "Input Data " << endl;
    for_each (vi.begin(), vi.end(), [](int x) {cout << x << ",";});
    cout << endl << "Enter the number you want to compare with."<< endl;
    cin >> in;
    func = greaterThan(in);
    auto result = findEligible(vi, func);
    cout << endl << "Output " << endl;
    for_each (result.begin(), result.end(), [](int x) {cout << x << ",";});
    cout << endl;

    cout << "++++ Find uppercase letter using function pointer ++++" << endl;
    vector<char> vc;
    for (size_t i {}; i < NUMELEMS; i++)
    {
        int n1 = rand() % 26;
        int n2 = rand() % 2;
        n1 += (n2 == 0) ? 65 : 97;
        vc.push_back(n1);
    }
    cout << "Input Data " << endl;
    for_each (vc.begin(), vc.end(), [](char x) {cout << x << ",";});
    func = isUpperCase;     // isUpperCase takes a char argument but function<> will implicit case it to int
    auto res2 = findEligible(vc, func);
    cout << endl << "Output " << endl;
    for_each (res2.begin(), res2.end(), [](char x) {cout << x << ",";});
    cout << endl;

    cout << "++++ Find palindrome usinf function pointer ++++" << endl;
    vector<string> vs {"param", "raman", "bat", "bob", "mom"};
    cout << "Input Data " << endl;
    for_each (vs.begin(), vs.end(), [](string& x) {cout << x << ",";});
    func2 = isPalindrome;
    auto res3 = findEligible(vs, func2);
    cout << endl << "Output " << endl;
    for_each (res3.begin(), res3.end(), [](string& x) {cout << x << ",";});
    cout << endl;
}
