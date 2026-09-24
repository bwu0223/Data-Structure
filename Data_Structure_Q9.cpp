//資工2A / S14350142 / 吳秉承 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while(cin >> n){
        vector<int> prime_factor;
        int temp = n,cnt = 0;
        bool first = true;
        cout << temp << " = ";
        for (int i = 2; i <= n; i++){
            if(n % i == 0){
                cnt++;
            }
            while (n % i == 0){
                n /= i;
                prime_factor.push_back(i);
            }
        }
        cout << prime_factor[0];
        for(int i = 1 ; i < prime_factor.size() ; i++){
            cout << "*" << prime_factor[i];
        }
        cout << endl << temp << " has " << cnt << " prime factors." << endl;
    }
    return 0;
}

