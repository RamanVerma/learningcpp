#include <vector>
#include <memory>
#include <iostream>

struct alpha
{
    alpha(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    int a;
    int b;
};
typedef std::unique_ptr<alpha> alphaPtr;
typedef std::vector<alphaPtr> alphaPtrVec;

void
foo(alphaPtrVec *v)
{
    int i = 0;
    for (;i < 10; i++)
    {
        v->push_back(std::move(std::make_unique<alpha>(i, i)));
    }
}
    
int
main()
{
    // Test the lifetime of unique_ptr
    alphaPtrVec alpha_vec;
    foo(&alpha_vec);
    for(auto& alpha_ref: alpha_vec)
    {
        std::cout << "alpha->a " << alpha_ref->a << " alpha->b " << alpha_ref->b << "\n";
    }
}
