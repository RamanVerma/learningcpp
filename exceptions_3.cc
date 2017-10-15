#include <iostream>
//#include <string>
#include <vector>

using namespace std;
const uint16_t NUM = 5;

template <class T>
class Database
{
public:
    Database ()
    {}
    T&
    operator[] (int index)
    {
        if (index >= data.size()) {
            throw std::out_of_range("Index out-of-bounds: " + index);
        }
        return data[index];
    }
    void
    push_back (T t)
    {
        data.push_back(t);
    }
private:
    std::vector<T> data;
};

int
main ()
{
    Database<int> db = Database<int>();
    for (int i {}; i < NUM; i++)
    {
        db.push_back(i);
    }
    try {
        for (int i {}; i <= NUM; i++)
        {
            cout << db[i] << endl;
        }
    } catch (const std::out_of_range& ex) {
        cout << ex.what() << endl;
    }
    cout << "Graceful end of the program" << endl;
}
