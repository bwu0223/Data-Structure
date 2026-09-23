#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int p, q;
    while(cin >> p >> q){
        int all_sum = 0;
        vector<int> prime;
        int a = min(p, q),b = max(p, q);
        for(int i = a; i <= b; i++){
            all_sum += i;

            if(i < 2){
                continue;
            }
            bool flag = true;
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                prime.push_back(i);
            }
        }
        int prime_sum = 0;
        for(auto x : prime){
            prime_sum += x;
        }
        cout << prime.size() << endl << prime_sum << endl;
    }
    return 0;
}