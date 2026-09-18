//資工2A / S14350142 / 吳秉承 
#include <iostream>
using namespace std;

int Gcd(int a,int b){
	while((a %= b) && (b %= a));
	return a + b;
}

int Lcm(int a, int b) {
    int step = b;

    while (true) {
        if (step % a == 0 && step % b == 0) {
            return step;
        }
        step += b;
    }
}

int main(){
	int a,b;
	cin >> a >> b;
	int mygcd = Gcd(a,b);
	int mylcm = Lcm(a,b);
	
	cout << "The greatest common divisor of " << a << " and "<< b << " = " << mygcd << endl;
	cout << "The least common multiple of " << a << " and "<< b << " = " << mylcm << endl;
	return 0;
} 
