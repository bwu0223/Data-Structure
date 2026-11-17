#include <iostream>

using namespace std;

// 選項一：遞迴輾轉相除法求最大公因數
long long GCD(long long x, long long y) {
    if (y == 0) {
        return x;
    }
    return GCD(y, x % y);
}

// 選項二：遞迴計算 1 到 n 連續整數累加和
long long Sum(int n) {
    if (n <= 1) {
        return n;
    }
    return n + Sum(n - 1);
}

// 選項三：遞迴計算費氏數列第 n 項 (Fib(0)=0, Fib(1)=1)
long long Fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fib(n - 1) + Fib(n - 2);
}

int main() {
    int choice;

    while (true) {
        cout << "\n========== 多個遞迴程式實作選單 ==========" << endl;
        cout << "1. GCD(x, y)：求兩數的最大公因數與最小公倍數" << endl;
        cout << "2. Sum(n)：計算 1 + 2 + 3 + ... + n 連續整數和" << endl;
        cout << "3. Fib(n)：求費氏數列第 n 項數值" << endl;
        cout << "0. 結束程式" << endl;
        cout << "請輸入選項 (0-3): ";

        if (!(cin >> choice)) {
            cout << "輸入格式錯誤，程式結束。" << endl;
            break;
        }

        if (choice == 0) {
            cout << "程式結束。" << endl;
            break;
        }

        switch (choice) {
            case 1: {
                long long x, y;
                cout << "請輸入兩個正整數 x 與 y: ";
                cin >> x >> y;
                if (x <= 0 || y <= 0) {
                    cout << "請輸入正整數！" << endl;
                } else {
                    long long gcd = GCD(x, y);
                    long long lcm = (x / gcd) * y;
                    cout << x << " 與 " << y << " 的最大公因數 = " << gcd 
                         << ", 最小公倍數 = " << lcm << endl;
                }
                break;
            }
            case 2: {
                int n;
                cout << "請輸入正整數 n: ";
                cin >> n;
                if (n <= 0) {
                    cout << "請輸入正整數！" << endl;
                } else {
                    cout << "1 到 " << n << " 的連續整數和為 " << Sum(n) << endl;
                }
                break;
            }
            case 3: {
                int n;
                cout << "請輸入非負整數 n: ";
                cin >> n;
                if (n < 0) {
                    cout << "請輸入大於等於 0 的整數！" << endl;
                } else {
                    cout << "費氏數列的第 " << n << " 項數值為 " << Fib(n) << endl;
                }
                break;
            }
            default:
                cout << "無效的選項，請重新輸入 0 到 3 之間的數字！" << endl;
                break;
        }
    }

    return 0;
}
