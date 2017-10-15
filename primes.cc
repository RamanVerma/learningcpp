/* Find 'n' primes */
#include <iostream>
#include <cmath>

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
    if (num == 0) {
        return 0;
    }
    auto primes {new uint64_t[num] {}};
    primes[0] = 2;
    uint64_t count {1};
    uint64_t trial {3};
    bool isPrime {true};
    uint64_t limit = 1;

    while (count <= num) {
        isPrime = true;

        limit = std::sqrt(trial);
        for (uint64_t i {}; (primes[i] <= limit) && isPrime; i++)
        {
            isPrime = ((trial % primes[i]) > 0);
        }

        if (isPrime) {
            primes[count++] = trial;
        }
        trial += 2;
    }
    printPrimes(primes, num);
}
