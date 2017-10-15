#include<boost/numeric/ublas/matrix_sparse.hpp>

using namespace std;
namespace ublas = boost::numeric::ublas;
typedef ublas::compressed_matrix<bool> Matrix;

const uint64_t rows = 5;
const uint64_t cols = 5;

int main() {

    Matrix db = Matrix(rows, cols);
    db(0,0) = db(0,3) = db(0,4) = db(2,0) = db(2,2) = db(3,1) = db(4,4) = true;

    cout << "Row first" << endl;
    for (auto it1 = db.begin1(); it1 != db.end1(); ++it1) {
        for (auto it2 = it1.begin(); it2 != it1.end(); ++it2) {
            cout << "(Row:" << it2.index1() << ",Col:" << it2.index2() << ") ";
        }
        cout << endl;
    }

    cout << endl << "Column first" << endl;
    for (auto it2 = db.begin2(); it2 != db.end2(); ++it2) {
        for (auto it1 = it2.begin(); it1 != it2.end(); ++it1) {
            cout << "(Col: " << it1.index2() << ", Row:" << it1.index1() << ") ";
        }
        cout << endl;
    }

    cout << endl << "Element Access Using operator ()";
    for (auto row = 0; row < db.size1(); row++) {
        for (auto col = 0; col < db.size2(); col++) {
            cout << "(Row: " << row << ", Col: " << col << " :: " << db(row, col) << " ) ";
        }
        cout << endl;
    }

    cout << endl << "Getting to the last row without knowing the num rows" << endl;
    auto it = db.end1();
    it--;
    cout << "Last row index: " << it.index1();

    cout << endl << "Resize matrix" << endl;
    cout << "Before:: Num rows: " << db.size1() << " Num cols: " << db.size2() << endl;
    db.resize(db.size1() + 10, db.size2(), /* preserve */ true);
    cout << "After:: Num rows: " << db.size1() << " Num cols: " << db.size2() << endl;
    for (auto it1 = db.begin1(); it1 != db.end1(); ++it1) {
        for (auto it2 = it1.begin(); it2 != it1.end(); ++it2) {
            cout << "(Row:" << it2.index1() << ",Col:" << it2.index2() << ") ";
        }
        cout << endl;
    }

#if 0
    cout << "Access rows" << endl;
    auto it1 = db.begin1() + 2;
    for (auto it2 = it1.begin(); it2 != it1.end(); ++it2) {
        cout << "(Row:" << it2.index1() << ",Col:" << it2.index2() << ") ";
    }
    cout << endl;

    cout << "Access rows" << endl;
    cout << db[2][2] << endl;
#endif
}
