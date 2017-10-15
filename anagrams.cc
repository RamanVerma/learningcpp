#include <cctype>
#include <iostream>
#include <string>
#include <memory>

using namespace std;
struct node {
public:
    node (char k, int count)
        : key(k),
        cnt(count),
        lchild(nullptr),
        rchild(nullptr)
    {}
    void
    insert (char k)
    {
        if (k == key) {
            cnt++;
            return;
        }
        if (k < key) {
            if (lchild) {
                lchild->insert(k);
            } else {
                lchild = unique_ptr<struct node> (new struct node (k, 1));
            }
        } else {
            if (rchild) {
                rchild->insert(k);
            } else {
                rchild = unique_ptr<struct node>(new struct node (k, 1));
            }
        }
    }
    bool
    find (char k, int count)
    {
        if ((k == key) && (cnt == count)) {
            return true;
        }
        if (k < key) {
            if (lchild) {
                lchild->find (k, count);
            } else { 
                return false;
            }
        } else {
            if (rchild) {
                rchild->find (k, count);
            }else {
                return false;
            }
        }
    }
    bool
    findAll (const struct node &root)
    {
        if (! find (root.key, root.cnt)) {
            return false;
        }
        if (root.lchild && ! findAll (*(root.lchild))) {
            return false;
        }
        if (root.rchild && ! findAll (*(root.rchild))) {
            return false;
        }
        return true;
    }
    char key;
    int cnt;
    unique_ptr<struct node> lchild;
    unique_ptr<struct node> rchild;
};
typedef struct node node;

bool
anagrams (const string &w1, const string & w2)
{
    if (w1.length() != w2.length()) {
        return false;
    }
    node root = node(w1[0], 1);
    for (size_t i = 1; i < w1.length(); i++)
    {
        root.insert(w1[i]);
    }
    node root2 = node(w2[0], 1);
    for (size_t i = 1; i < w2.length(); i++)
    {
        root2.insert(w2[i]);
    }
    return root.findAll (root2);
}

int
main (int argc, char *argv[])
{
    string w1;
    string w2;
    cout << "Enter the first word/sentence" << endl;
    getline(cin, w1);
    string w11;
    for (auto c: w1)
    {
        if (!isspace(c)) {
            w11 += tolower(c);
        }
    }
    cout << "Enter the second word/sentence" << endl;
    getline(cin, w2);
    string w21;
    for (auto c: w2)
    {
        if (!isspace(c)) {
            w21 += tolower(c);
        }
    }
    string message = w1 + " " +  w2 + " are " + (anagrams(w11, w21) ? "anagrams" : "not anagrams");
    cout << message << endl;
}
