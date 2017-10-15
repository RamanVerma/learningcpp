#include <iostream>

class Integer
{
public:
    Integer(int value = 0)
        : val(value)
    {
        count++;
        std::cout << "Integer constructor" << std::endl;
    }
    Integer(const Integer& x)
    {
        count++;
        val = x.get();
        std::cout << "Copy Constructor called" << std::endl;
    }
    int
    get() const
    {
        return val;
    }
    void
    set(int value)
    {
        val = value;
    }
    int
    compare(Integer x) const
    {
        if (val > x.get()) {
            return 1;
        } else if (val < x.get()) {
            return -1;
        } else {
            return 0;
        }
    }
    Integer *
    add(const Integer* x)
    {
        val += x->get();
        return this;
    }
    Integer *
    multiply(const Integer* x)
    {
        val *= x->get();
        return this;
    }
    static int
    printCount()
    {
        return count;
    }
private:
    int val;
    static inline int count = 0;
};
int
main(int argc, char *argv[])
{
    Integer i1 = Integer(1);
    Integer i2 = Integer(-1);
    i1.get();
    i2.get();
    std::cout << i1.compare(i2) << std::endl;
    auto i4 = Integer(4);
    auto i5 = Integer(5);
    auto i6 = Integer(6);
    auto i7 = Integer(7);
    auto i8 = Integer(8);
    std::cout << "Number of integers: " << Integer::printCount() << std::endl;
}
