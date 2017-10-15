#include <cctype>
#include <iostream>
#include <string>

using namespace std;
int
main (int argc, char *argv[])
{
    string sentence;
    string keys;
    cout << "Enter the first sentence." << endl;
    getline (cin, sentence);
    cout << "Enter the key lettes that you want to use for search" << endl;
    cin >> keys;
    bool check = true;
    bool found = false;
    size_t indx = 0;
    size_t length = 0;
    for (size_t i {} ; i < sentence.length(); i++)
    {
        if (isspace(sentence[i])) {
            if (found) {
                cout << sentence.substr(indx, length) << endl;
            }
            check = true;
            indx = 0;
            length = 0;
            continue;
        }
        if (check) {
            for (auto c: keys)
            {
                if (tolower(sentence[i]) == tolower(c)) {
                    indx = i;
                    length = 1;
                    found = true;
                    break;
                } else {
                    found = false;
                }
            }
            check = false;
            continue;
        }
        if (found) {
            length++;
        }
    }
    if (found) {
        cout << sentence.substr(indx, length) << endl;
    }
}
