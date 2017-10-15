#include <vector>
struct combinations {
    typedef std::vector<int> combination_t;

    combinations(int n, int r)
        : n(n),
        r(r)
    {
        // initialize the value of curr
        for (auto i = 0; i < r; i++)
        {
            curr.push_back(i);
        }
        --curr[r - 1];
    }
public:
    combination_t
    next_combination()
    {
        for (auto i = r - 1; i > 0; i--)
        {
            curr[i] = ++curr[i] % n;
            if (curr[i] != 0) {
                break;
            }
        }
        return curr;
    }
private:
    combination_t curr;
    int n;  // total number of items
    int r;  // number of items to combinee at a given time
};

int
main (int argc, char *argv[])
{
    return 0;
}
