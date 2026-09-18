//¸ê¤u2A / S14350142 / §dªÃ©Ó 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int original = n;
    bool first = true;

    cout << original << " = ";

    for (int i = 2; i * i <= n; i++){
        int cnt = 0;
        while (n % i == 0){
            n /= i;
            cnt++;
        }

        if (cnt > 0) {
            if (!first){ 
                cout << "*";
			} 
            cout << i;
            if (cnt > 1){ 
                cout << "^" << cnt;
			} 
            first = false;
        }
    }
    if (n > 1) {
        if (!first){ 
            cout << "*";
        }
        cout << n;
    }
    return 0;
}

