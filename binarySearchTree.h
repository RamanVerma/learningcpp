#include <iostream>

using namespace std;

template<class T>
struct Node {
public:
    Node() : data_(nullptr), rChild_(nullptr), lChild_(nullptr) {}
    Node(struct Node *other)
    {
        if (other == nullptr) {
            return;
        }
        Node *root = new Node();
        root->data_ = other->data;
        root->right = Node(other->right);
        root->left = Node(other->left);
        return root;
    }

    /* pre-order algorithm using a lambda to do the required processing*/
    static void
    preOrderProcessor(struct Node* root, std::function<void(struct Node *n)>f)
    {
        if (root == nullptr) {
            return;
        }
        f(root);
        preOrderProcessor(root->right, f);
        preOrderProcessor(root->left, f);
    }

    /* Breadth first traversal using a lambda to do the required processing */
    static void
    breadthFirstProcessor(struct Node* root, std::function<void(struct Node *n)>f)
    {
        if (root == nullptr) {
            return;
        }
        queue<struct Node *> q;
        q.push(root);

        while(!q.empty()) {
            auto n = q.pop();
            f(n);
            if (n->rChild) {
                q.push(n->rChild);
            }
            if (n->lChild) {
                q.push(n->lChild);
            }
        }
    }

    /* TODO Write a depth first algorithm using a lambda */

    /* TODO Write a post-order algorithm using a lambda */
    /* TODO Write a in-order algorithm using a lambda */

    friend ostream& operator<<(ostream &out, struct Node *node)
    {
       /* TODO print the tree rooted at node using breadth first algorithm and a lambda */ 
        out << "Not implemented yet!";
        return out;
    }
    /* TODO Write destructors as I am using raw pointers all over */
    /* TODO Write a method to generate a random BST */
    /* TODO Does it make sense to use smart pointers here */
    T* data_;
    struct Node *lChild_;
    struct Node *rChild_;
};
