#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

void menu(){
    cout << "=====================================" << endl;
	cout << "a)輸出非零項次" << endl;
	cout << "b)輸出所有係數陣列" << endl;
	cout << "c)相加後輸出非零項次" << endl;
	cout << "d)相加後輸出所有係數陣列" << endl;
    cout << "e)退出" << endl;
	cout << "=====================================" << endl;
}

void option_a(){
	int maxexp;
	vector<int> coff;
	cout << "輸入最高次方" << endl; 
	cin >> maxexp;
	for(int i = 0 ; i <= maxexp ; i++){
		int read;
		cin >> read;
		coff.push_back(read);
	}
	for(int i = 0 ; i <= maxexp ; i++){
		if(coff[i] == 0){
			continue;
		}
		cout << i << "次方項係數 = " << coff[i] << endl; 
	}
}

void option_b(){
	int pairno;
    cout << "輸入有幾對" << endl;
	cin >> pairno;
	vector<pair<int,int>> coff_pair(pairno + 1);
	for(int i = 0 ; i < pairno ; i++){
		cin >> coff_pair[i].first >> coff_pair[i].second;
	}
	for(int i = 0 ; i < pairno ; i++){
		cout << coff_pair[i].first << " ";
	}
	cout << endl;
}

void option_c(){
	int poly_1,poly_2;
	cout << "輸入第一個多項式最高次方 : ";
	cin >> poly_1;
	cout << "輸入第二個多項式最高次方 : ";
	cin >> poly_2;
	int larger = max(poly_1,poly_2);
	vector<int> coff_1(larger + 1,0);
	vector<int> coff_2(larger + 1,0);
	for(int i = 0 ; i < poly_1 ; i++){
		cin >> coff_1[i];
	}
	for(int i = 0 ; i < poly_2 ; i++){
		cin >> coff_2[i];
	}
	for(int i = 0 ; i < larger ; i++){
		cout << i << "次方項係數 = " << coff_1[i] + coff_2[i] << endl;
	}
}

void option_d(){
	int poly_1,poly_2;
	cout << "輸入第一個多項式最高次方 : ";
	cin >> poly_1;
	cout << "輸入第二個多項式最高次方 : ";
	cin >> poly_2;
	int larger = max(poly_1,poly_2);
	vector<int> coff_1(larger,0);
	vector<int> coff_2(larger,0);
	for(int i = 0 ; i < poly_1 ; i++){
		cin >> coff_1[i];
	}
	for(int i = 0 ; i < poly_2 ; i++){
		cin >> coff_2[i];
	}
	for(int i = 0 ; i < larger ; i++){
		cout << coff_1[i] + coff_2[i] << " ";
	}
    cout << endl;
}

int main(){
    
    while(true){
        menu();
        char op;
        int flag = 1;
        cin >> op;
        switch(op){	
            case 'a':
                option_a();
                break;
            case 'b':
                option_b();
                break;
            case 'c':
                option_c();
                break;
            case 'd':
                option_d();
                break;
            case 'e':
                flag = 0;
                break;
            default:
                cout << "沒這個選項" << endl;
        }
        if(!flag){
            break;
        }
    }
} 