#include <iostream>
#include <string>
#include <vector>

using namespace std;
int
main (int argc, char * argv[])
{
    int num {0};
    cout << "How many students info you want to enter?";
    cin >> num;
    if (num < 0) {
        num = 6;
    }
    string fname;
    string grade_str;
    uint16_t grade;
    uint32_t total {0};
    vector<pair<string, int>> studentData;
    for (auto i = 0; i < num; i++)
    {

        cout << "Enter first name";
        cin >> fname;
        do {
            cout << "Enter grade (out of 100)";
            cin >> grade_str;
            grade = atoi(grade_str.c_str());
        } while (grade < 0 || grade > 100);
        total += grade;
        studentData.emplace_back(fname, grade);
    }
    int row = 0;
    for(auto it = studentData.begin(); it != studentData.end(); it++, row++)
    {
        cout << it->first << ": " << it->second;
        if ((row + 1) % 3 == 0) {
            cout << endl;
        } else {
            cout << ", ";
        }
    }
    cout << "Average grade: " << total / studentData.size() << endl;
}
