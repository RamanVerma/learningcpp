#include <iostream>
#include <memory>

using namespace std;
void
raii_method(std::unique_ptr<int> pi)
{
    cout << *pi << endl;
}
void
raii_method_2(std::shared_ptr<int> pi)
{
    cout << *pi << endl;
}

int
main (int argc, char *argv[])
{
    int num = 10;
//    auto pu = std::make_unique<int>(num);
    auto ps = std::make_shared<int>(num);
//    raii_method(pi);
    raii_method_2(ps);
    return 0;
}
