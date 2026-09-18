//資工2A / S14350142 / 吳秉承 
#include <iostream>
using namespace std;

int main(){
	cout << "for loop : " << endl;
	int cnt = 0;
	for(int i = 1 ; i <= 100;i++){
		cnt += i;
	}
	cout << "1+2+3+…+100 = " << cnt << endl;
	
	cout << "\nwhile loop : " << endl;
	int i = 1,while_cnt = 0;
	while(i <= 100){
		while_cnt += i;
		i++;
	}
	cout << "1+2+3+…+100 = " << while_cnt << endl;
	
	cout << "\ndo … while loop : " << endl;
	int j = 1,do_while_cnt = 0;
	do{
		do_while_cnt += j;
		j++;
	}while(j <= 100);
	cout << "1+2+3+…+100 = " << do_while_cnt << endl;
	return 0;
}
