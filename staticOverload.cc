#include <iostream>
class A
{
public:
    static void setUp() { dataA = 10; }
    static int dataA;
};
int A::dataA = 0;

class B: public A
{
public:
    static void setUp() { dataA = 20; }
};

int
main()
{
    A::setUp();
    std::cout << "dataA: " << A::dataA << std::endl;
    B::setUp();
    std::cout << "dataA: " << A::dataA << std::endl;
}
