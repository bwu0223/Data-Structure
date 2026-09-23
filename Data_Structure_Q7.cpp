//資工2A / S14350142 / 吳秉承 
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
	while(cin >> n){
		int cnt = 0;
		vector<int> perfect;
	    for(int i = 2; i <= n; i++){
	        int sum = 0;
	        for(int j = 1; j < i; j++){
	            if(i % j == 0){
	            	sum += j;
				}  
	        }
	        if(sum == i){
	        	perfect.push_back(i);
			}  
	    }
	    cout << perfect.size() << endl;
	    for(auto x : perfect){
	        cout << x << " ";
	    }
	}
    return 0;
}