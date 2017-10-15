#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct node {
public:
    node (string k, int cnt)
        : key(k),
          count(cnt),
          lchild(nullptr),
          rchild(nullptr)
    {}
    void
    insert (string k)
    {
        if (key.compare(k) == 0) {
            count++;
        } else if (key.compare(k) > 0) {
            if (lchild) {
                lchild->insert(k);
            } else {
                lchild = unique_ptr<struct node> (new struct node (k, 1));
            }
        } else {
            if (rchild) {
                rchild->insert (k);
            } else {
                rchild = unique_ptr<struct node> (new struct node (k, 1));
            }
        }
    }
    void
    inorderTraversal ()
    {
        if (lchild) {
            lchild->inorderTraversal();
        }
        cout << *this;
        if (rchild) {
            rchild->inorderTraversal();
        }
    }
    friend std::ostream&
    operator << (std::ostream &os, const struct node& n)
    {
        os << n.key << "::" << n.count << " ";
        return os;
    }
    string key;
    int count;
    unique_ptr<struct node> lchild;
    unique_ptr<struct node> rchild;
};
typedef struct node node;

int
main (int argc, char *argv[])
{
    unique_ptr<node> root {nullptr};
    string word;
    string EOFILE = "EOF";
    cout << "Enter the text. End it by writing \"EOF\"" << endl;
    while (true) {
        cin >> word;
        if (word.compare(EOFILE) == 0) {
            break;
        }
        if (root) {
            root->insert(word);
        } else {
            root = unique_ptr<node> (new node (word, 1));
        }
    }
    root->inorderTraversal ();
    cout << endl;
}
