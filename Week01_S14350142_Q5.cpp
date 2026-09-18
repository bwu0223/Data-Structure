//戈2A / S14350142 / ┯ 
#include <iostream>
using namespace std;

int Gcd(int a,int b){
	while((a %= b) && (b %= a));
	return a + b;
}
9
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
	
	cout << a << " 籔 " << b << " 程そ计 = " << mygcd << endl;
	cout << a << " 籔 " << b << " 程そ计 = " << mylcm << endl;
	return 0;
} 
