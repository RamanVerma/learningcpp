#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int
main (int argc, char *argv[])
{
    string lastName = "Verma";
    ostringstream oss { "Name is Raman " + lastName};
//    oss << "Name is Raman " << lastName;
    cout << oss.str() << endl;
}
