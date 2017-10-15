#include <iostream>
#include <limits>

using namespace std;

int
main()
{
    uint64_t a = std::numeric_limits<uint64_t>::max();
    cout << "Initial Value of a: " << a << endl;
    cout << "Incremented Value of a: " << ++a << endl;

    // divide and add 1 if remainder exists
    uint64_t b = 23;
    auto result = b / 8;
    result += ((b % 8) ? 1 : 0);
    cout << "b=" << b << " (b/8)=" << result << endl;

    b = 24;
    result = b / 8;
    result += ((b % 8) ? 1 : 0);
    cout << "b=" << b << " (b/8)=" << result << endl;

    b = 25;
    result = b / 8;
    result += ((b % 8) ? 1 : 0);
    cout << "b=" << b << " (b/8)=" << result << endl;

    uint8_t arr[10] = {};
    fill_n(arr, 10, 1);
    for (size_t i = 0; i < 10; i++) {
        cout << "arr[" << i << "]=" << (unsigned)arr[i] << "\t";
    }
    cout << endl;

    return 0;
}
