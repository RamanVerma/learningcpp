#include <iostream>
#include <sstream>

using namespace std;

int
main (int argc, char *argv[])
{
    cout << "Enter the numbers. End with #" << endl;
    string input;
    getline(cin, input, '#');
    stringstream ss {input};
    int total = 0;
    int num = 0;
    while (ss) {
        ss >> num;
        total += num;
        cout << num << endl;
    }
    cout << "Total: " << total << endl;
}
