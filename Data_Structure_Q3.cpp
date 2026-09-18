//資工2A / S14350142 / 吳秉承 
#include <iostream>
using namespace std;

int main() {
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (i < 2){ 
            continue;
        } 
        bool prime = true;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cnt++;
        }
    }
    cout << "There are " << cnt << " prime numbers between " << a << " and " << b << "."<< endl;
    return 0;
}

