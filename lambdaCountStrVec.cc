#include <iostream>
#include <vector>

using namespace std;

int
main (int argc, char *argv[])
{
    vector<string> strs {"Ron", "John", "Jay", "Jack", "Abby"};
    auto lambda = [strs] (char x) -> int {
        int cnt = 0;
        for (auto& str: strs)
        {
            if (str[0] == x) { cnt++; }
        }
        return cnt;
    };
    cout << "Num of strings starting with J: " << lambda('J') << endl;
    cout << "Num of strings starting with R: " << lambda('R') << endl;
    cout << "Num of strings starting with A: " << lambda('A') << endl;
    cout << "Num of strings starting with B: " << lambda('B') << endl;
}
