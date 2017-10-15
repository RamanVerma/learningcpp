#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int
main (int argc, char *argv[])
{
    string sentence;
    string word;
    cout << "Enter the integers one at a time. End with \"#\"" << endl;
    do {
        cin >> word;
        sentence += " ";
        sentence += word;
    } while (word.compare("#") != 0);
    int total = 0;
    int indx = 0;
#if 0
    bool started = false;
    int length = 0;

    for (size_t i {}; i < sentence.length(); i++)
    {
        if (isdigit(sentence[i])) {
            if (started) {
                length++;
            } else {
                started = true;
                indx = i;
                length = 1;
            }
        } else {
            if (length > 0) {
                auto num = atoi(sentence.substr(indx, length).c_str());
                cout << num << endl;
                total += num;
            }
            started = false;
        }
    }
#endif
    int start = 0;
    do {
        if ((indx = sentence.find(" ", start)) == std::string::npos) {
            indx = sentence.length();
        }
        auto num_str = sentence.substr(start, indx - start);
        if (!num_str.empty()) {
            auto num = atoi(num_str.c_str());
            cout << num << endl;
            total += num;
        }
        start = indx + 1;
    } while ((indx != std::string::npos) && (start < sentence.length()));
    cout << "Total: " << total << endl;
}
