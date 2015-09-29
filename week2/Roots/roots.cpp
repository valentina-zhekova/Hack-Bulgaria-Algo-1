#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// result should be to rounded to 5th digit after the decimal point
// e.g. square_root(4) should print 2.00000
double square_root(int number) {
    double left = 0;
    double right = number;
    double sq_root, result;
    do {
        sq_root = (left + right) / 2;
        result = number - sq_root * sq_root;
        if (result < 0) {
            right = sq_root;
            result = -result;
        } else if (result > 0) {
            left = sq_root;
        } else {
            break;
        }
    } while (result >= 0.000001);
    return sq_root;
}

int main() {
	string line;
	cout << "integer: ";
    getline(cin, line);
    cout << setprecision(5) << fixed << square_root(stoi(line)) << endl;

    cin.get();
    return 0;
}
