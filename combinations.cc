#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
using namespace std;

struct Combinations {
    Combinations(int n,
                 int r)
        : n(n),
          r(r)
    {
        if (r >= n) {
            r == n;
        }
        combination = vector<int>();
        for (int i = 0; i < r; i++)
        {
            combination.push_back(i);
        }
        if (r > 1) {
            --(combination[r-1]);
        }
    }

    int
    next()
    {
        for (auto i = r - 1; i >= 0; i--)
        {
            combination[i] = (combination[i] + 1) % n;
            if (combination[i] == 0 ||
                combination[i] > ((n - 1) - (r - 1 - i))) {
                if (i == 0) {
                    return 1;
                }
                continue;
            }
            for (auto j = i + 1; j < r; j++)
            {
                combination[j] = combination[j - 1] + 1;
            }
            break;
        }
        return 0;
    }

    // FIXME Works well till 'n' being 29. fact_1 or fact_2 calculations start
    // to roll over after 29 for some of the combinations.
    uint64_t
    totalCombinations()
    {
        uint64_t fact_1 = 1;
        uint64_t fact_2 = 1;
        auto x = max(r, n - r);
        auto y = min(r, n - r);
        for (int i = 1; i <= n; i++)
        {
            if (i > x) {
                fact_1 = fact_1 * i;
            }
            if (i <= y) {
                fact_2 = fact_2 * i;
            }
        }
        return fact_1 / fact_2;
    }

    friend
    std::ostream&
    operator << (std::ostream &os, const struct Combinations& c)
    {
        for (auto it : c.combination)
        {
            os << it << ",";
        }
        os << endl;
        return os;
    }

    vector<int> combination;
private:
    int n;
    int r;
};
typedef struct Combinations Combinations;

/* 
 * Create all possible combinations for a vector of integers
 * The output is nC1 + nC2 + nC3 + .. + nCn
 */
vector<set<int>>
getCombinations(const vector<int> &a)
{
    vector<set<int>> b;
    vector<set<int>> tmp;
    for (auto i = 0; i < a.size(); i++) {
        for (auto it = b.begin(); it != b.end(); it++)
        {
            auto x = set<int>(*it);
            x.insert(a[i]);
            tmp.push_back(x);
        }
        for (auto it = tmp.begin(); it != tmp.end(); it++)
        {
            b.push_back(*it);
        }
        b.push_back(set<int>{a[i]});
        tmp.clear();
    }
    return b;
}

int
main(int argc, char *argv[])
{
    int n = (argc >= 2) ? atoi(argv[1]) : 10;
    int r = (argc >= 3) ? atoi(argv[2]) : 10;
#if 0
    vector<int> a;
    for (int x {}; x < n; x++)
    {
        a.push_back(x);
    }
    auto b = getCombinations(a);
    for (auto it = b.begin(); it != b.end(); it++)
    {
        for (auto it2 = it->begin(); it2 != it->end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
#endif
#if 0
    Combinations c = Combinations(n, r);
    cout << "Total possible combinations with n: " << n << ", r: " << r
        << " " << c.totalCombinations() << endl;
#endif
    for (r = 1; r <= n; r++)
    {
        Combinations c = Combinations(n, r);
        cout << "Total possible combinations with n: " << n << ", r: " << r
            << " " << c.totalCombinations() << endl;
    //    while(c.next() == 0) {
    //        cout << c;
    //    }
    }
}
