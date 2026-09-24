#include <iostream>
using namespace std;
 
void primefactor(int n, int arr[], int &len) {
    len = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            arr[len++] = i;
            n /= i;
        }
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int arrA[30] = {0}, arrB[30] = {0};
        int lenA = 0,lenB = 0;

        primefactor(a, arrA, lenA);
        primefactor(b, arrB, lenB);

        int posA = 0, posB = 0,gcd = 1,lcm = 1;
        while (posA < lenA && posB < lenB) {
            if (arrA[posA] == arrB[posB]) {
                gcd *= arrA[posA];
                lcm *= arrA[posA];
                posA++;
                posB++;
            } else if (arrA[posA] < arrB[posB]) {
                lcm *= arrA[posA];
                posA++;
            } else {
                lcm *= arrB[posB];
                posB++;
            }
        }
        
        while (posA < lenA) {
            lcm *= arrA[posA];
            posA++;
        }
        while (posB < lenB) {
            lcm *= arrB[posB];
            posB++;
        }
        
        cout << "The greatest common divisor of " << a << " and "<< b << " = " << gcd << endl;
        cout << "The least common multiple of " << a << " and "<< b << " = " << lcm << endl;
    }
    return 0;
}