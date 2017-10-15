#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <time.h>

using namespace std;
class CurveBall
{
public:
    CurveBall(std::string message = "CurveBall")
        : message(message)
        {}

    std::string
    what() const
    {
        return message;
    }
private:
    std::string message;
};

class NegativeNumber : public std::domain_error
{
public:
    NegativeNumber (std::string faultyInput)
        : std::domain_error ("User entered a Negative Number: " + faultyInput)
    {}
};

class NotANumber : public std::domain_error
{
public:
    NotANumber (std::string faultyInput)
        : std::domain_error("User entered Non Numeric Value: " + faultyInput)
    {}
};

class OddNumber : public std::domain_error
{
public:
    OddNumber (std::string faultyInput)
        : std::domain_error("User entered an Odd Number: " + faultyInput)
    {}
};

int
readEvenNumber ()
{
    int randomNum = (rand() % 100);
    if (randomNum < 25) {
        throw CurveBall();
    }
    int num;
    std::cin >> num;
    if (! std::cin.fail()) {
        if (num < 0) {
            throw NegativeNumber {std::to_string(num)};
        } else if ((num % 2) != 0) {
            throw OddNumber {std::to_string(num)};
        }
        return num;
    }
    std::cin.clear();
    std::string line;
    std::getline(std::cin, line);
    throw NotANumber {line};
}

void
askEvenNumber ()
{
    cout << "Please enter an even number" << endl;
    try {
        auto num = readEvenNumber();
        cout << "Thanks for entering " << num << endl;
    } catch (const NotANumber &ex) {
        cout << ex.what() << endl;
    } catch (const OddNumber &ex) {
        cout << ex.what() << endl;
        askEvenNumber();
    } catch (const NegativeNumber &ex) {
        cout << ex.what() << endl;
        askEvenNumber();
    } catch (const std::exception &ex) {
        cout << "std::exception caught " << ex.what() << endl;
        throw;
    }
}

int
main (int argc, char *argv[])
{
    srand(time(NULL));
    try {
        askEvenNumber();
    } catch (const CurveBall &ex) {
        cout << ex.what() << " Throw it out of the park!" << endl;
    }
    return 0;
}
