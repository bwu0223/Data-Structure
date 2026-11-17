#include <iostream>
#include <algorithm>
using namespace std;

int factorize(int n, int arr[]) {
    int count = 0;
    for (int d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            if (count < 30) {
                arr[count++] = d;
            }
            n /= d;
        }
    }
    if (n > 1 && count < 30) {
        arr[count++] = n;
    }
    return count;
}

void printFactors(int orig, const int arr[], int len) {
    cout << orig << " = ";
    if (len == 0) {
        cout << orig << endl; 
        return;
    }
    for (int i = 0; i < len; i++) {
        cout << arr[i];
        if (i < len - 1) {
            cout << " * ";
        }
    }
    cout << endl;
}

int main() {
    int a, b, c;

    // 提供輸入提示
    cout << "請輸入三個正整數 a, b, c: ";
    if (!(cin >> a >> b >> c) || a <= 0 || b <= 0 || c <= 0) {
        cout << "輸入錯誤，請輸入正整數！" << endl;
        return 1;
    }
    int arrA[30], arrB[30], arrC[30];
    int lenA = factorize(a, arrA);
    int lenB = factorize(b, arrB);
    int lenC = factorize(c, arrC);
    printFactors(a, arrA, lenA);
    printFactors(b, arrB, lenB);
    printFactors(c, arrC, lenC);
    int i = 0, j = 0, k = 0;
    long long gcd = 1;
    long long lcm = 1;

    while (i < lenA || j < lenB || k < lenC) {
        int minP = 2147483647; // INT_MAX
        if (i < lenA) minP = min(minP, arrA[i]);
        if (j < lenB) minP = min(minP, arrB[j]);
        if (k < lenC) minP = min(minP, arrC[k]);

        int cntA = 0, cntB = 0, cntC = 0;
        while (i < lenA && arrA[i] == minP) { cntA++; i++; }
        while (j < lenB && arrB[j] == minP) { cntB++; j++; }
        while (k < lenC && arrC[k] == minP) { cntC++; k++; }

        int minCnt = min({cntA, cntB, cntC});
        int maxCnt = max({cntA, cntB, cntC});

        for (int m = 0; m < minCnt; m++) gcd *= minP;
        for (int m = 0; m < maxCnt; m++) lcm *= minP;
    }

    cout << "GCD = " << gcd << endl;
    cout << "LCM = " << lcm << endl;

    return 0;
}
