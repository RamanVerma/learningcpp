#include <iostream>
#include <cctype>

using namespace std;

int
main (int argc, char *argv[])
{
    string sentence;
    string key;
    cout << "Enter the string" << endl;
    std::getline(std::cin, sentence);
    cout << "Enter the keyword to be hidden" << endl;
    cin >> key;
    for (auto &x: sentence)
    {
        x = std::tolower(x);
    }
    for (auto &x: key)
    {
        x = std::tolower(x);
    }
    std::size_t indx {};
    while(true) {
        indx = sentence.find(key, ++indx);  // FIXME this may overflow
        if (indx == std::string::npos) {
            break;
        }
        if ((indx != 0) && isalpha(sentence[indx - 1])) {
            continue;
        }
        auto end_indx = indx + key.length();
        if ((end_indx != sentence.length()) && (isalpha(sentence[end_indx]))) {
            continue;
        }
        sentence.replace(indx, key.length(), key.length(), '*');
    };
    cout << sentence << endl;
}
