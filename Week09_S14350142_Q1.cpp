#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int start, num;
    cout << "請輸入兩個正整數 start 與 num: ";
    if (!(cin >> start >> num) || start <= 0 || num <= 0) {
        cout << "輸入錯誤，請輸入正整數！" << endl;
        return 1;
    }
    int* primes = new int[num];
    int count = 0;
    int current = start;

    while (count < num) {
        if (isPrime(current)) {
            primes[count] = current;
            count++;
        }
        current++;
    }
    cout << "大於等於 " << start << " 的 " << num << " 個質數為 ";
    for (int i = num - 1; i >= 0; i--) {
        cout << primes[i];
        if (i > 0) {
            cout << ", "; 
        }
    }
    cout << endl;
    delete[] primes;

    return 0;
}
