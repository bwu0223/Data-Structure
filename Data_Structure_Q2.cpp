//資工2A / S14350142 / 吳秉承 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << setw(2) << i << " * "
                 << setw(2) << j << " = "
                 << setw(2) << i * j << "    ";
        }
        cout << endl;
    }

    return 0;
}

