//資工2A / S14350142 / 吳秉承 
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	for(int i = 1 ; i <= 9 ; i++){
		cout << setw(7) << i;
	}
	cout << endl << string(66,'-') << endl;
	for(int i = 1 ; i < 10 ; i++){
		cout << i << " | ";
		for(int j = 1 ; j < 10 ; j++){
			cout << j << "*" << i << "=" << setw(2) << i * j << " ";
			if(j == i){
				cout << endl;
				break;
			}
		}
	}
	cout << string(66,'-') << endl;
    return 0;
}
