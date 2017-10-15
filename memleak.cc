#include <vector>
#include <memory>
#include <iostream>

struct alpha
{
    alpha(int64_t x, int64_t y)
    {
        a = x;
        b = y;
    }
    int64_t a;
    int64_t b;
};

// creates vector of int* and does not delete the int objects
void
test_1()
{
    std::vector<int64_t *> bad_vector;
    int64_t i = 0;
    for (;i < 10; i++)
    {
        bad_vector.push_back(new int64_t(i));
    }
}

// creates vector of unique_ptr<int> and does not delete the int objects
void
test_2()
{
    std::vector<std::unique_ptr<int64_t>> good_vector;
    int64_t i = 0;
    for (;i < 10; i++)
    {
        good_vector.push_back(std::make_unique<int64_t>(i));
    }
}
    
void
test_3(std::vector<int64_t> *v)
{
    int i = 0;
    for(;i < 10;i++)
    {
        v->push_back(*(new int64_t(i)));
    }
}

// allocate a struct on stack and one on heap
void
test_4()
{
    std::cout << "Size of alpha is " << sizeof(struct alpha) << "\n";
    std::cout << "Size of int64_t is " << sizeof(int64_t) << "\n";
    int64_t *x;
    std::cout << "Size of *int64_t is " << sizeof(x) << "\n";
    struct alpha a1 = alpha(1, 2);          // stack allocation
    struct alpha* p1 = new alpha(1, 2);     // heap/dynamic allocation
}

int
main()
{
  //  test_1();
    test_2();
    std::vector<int64_t> my_vec;
#if 0
    test_3(&my_vec);
    for (auto i: my_vec)
    {
        std::cout << i << "\t";
    }
    std::cout << "\n";
#endif
    test_4();
}
