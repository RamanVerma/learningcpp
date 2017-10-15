#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

int
main (int argc, char *argv[])
{
    int arr[50];
    *arr = 1;
    for (int i = 1; i < 50; i++)
    {
        *(arr + i) = *(arr + i - 1) + 2;
    }
    cout << "Q1" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << *(arr + i) << " " << *(arr + 49 - i) << ", ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    int *parr = arr;
    cout << "Q2" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << *parr << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
        parr++;
    }
    for (int i = 0; i < 50; i++)
    {
        parr--;
        cout << *(parr) << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << "Q3" << endl;
    int numElems = (argc > 1) ? atoi(argv[1]) : 10;
    float *arr_2 {new float[numElems]};

    for (int i = 0; i < numElems; i++)
    {
        *(arr_2 + i) = 1 / pow((i + 1), 2);
//        cout << *(arr_2 + i) << " ";
    }
    cout << endl;
    float sum = 0.0;
    for (int i = 0; i < numElems; i++)
    {
        sum += arr_2[i];
    }
    cout << "Answer: " << sqrt(sum * 6) << endl;
    cout << "Q4" << endl;
    sum = 0.0;
    auto pvec { new std::vector<float>() };
    for (int i {}; i < numElems; i++)
    {
        pvec->push_back(1 / pow((i + 1), 2));
        sum += pvec->back();
    }
    cout << "Answer: " << sqrt(sum * 6) << endl;
    cout << "Q5" << endl;
    sum = 0.0;
    std::unique_ptr<std::vector<float>> pvec2 { new std::vector<float>() };
    for (int i {}; i < numElems; i++)
    {
        pvec2->push_back(1 / pow((i + 1), 2));
        sum += pvec2->back();
    }
    cout << "Answer: " << sqrt(sum * 6) << endl;
    cout << "Q6" << endl;
    sum = 0.0;
    auto pvec3 = std::unique_ptr<std::vector<float>>( new std::vector<float>() );
    for (int i {}; i < numElems; i++)
    {
        pvec3->push_back(1 / pow((i + 1), 2));
        sum += pvec3->back();
    }
    cout << "Answer: " << sqrt(sum * 6) << endl;

    return 0;
}
