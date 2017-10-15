#include <iostream>

using namespace std;

void
printPrimes(uint64_t *primes, uint64_t num)
{
    for (uint64_t i {}; i < num; i++)
    {
        cout << primes[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}
int
main (int argc, char *argv[])
{
    uint64_t num {};
    cout << "How many primes do you want?" << endl;
    cin >> num;
    auto primes {new uint64_t[num] {}};
    uint64_t count {0};
    primes[count++] = 2;
    uint64_t trial {3};
    bool isPrime {true};

    while (count <= num)
    {
        isPrime = true;
        for (size_t i {}; (i < count) && isPrime; i++)
        {
            isPrime = ((trial % primes[i]) > 0);
        }
        if (isPrime) {
            primes[count++] = trial;
        }
    }
    printPrimes(primes, num);

}
