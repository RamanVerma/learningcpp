#include <iostream>
#include <stdlib.h>
#include <time.h>

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

class TooManyExceptions
{
public:
    TooManyExceptions(std::string message = "Too Many Exceptions")
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
    
void
genException()
{
    auto num = rand() % 1000;
    if (num < 250) {
        throw CurveBall{"Here's a CurveBall"};
    }
}
    
int
main ()
{
    srand(time(NULL));
    int count = 0;
    try {
        for (int i {}; i < 1000; i++)
        {

                try {
                    genException();
                } catch (const CurveBall& ex) {
                    count++;
                    std::cout << ex.what() << std::endl;
                    if (count > 10) {
                        throw TooManyExceptions();
                    }
                }

        }
    } catch (const TooManyExceptions &ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "CurveBall thrown " << count << " times" << std::endl;
}
