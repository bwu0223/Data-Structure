#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

void menu(){
    cout << "=====================================" << endl;
	cout << "a)輸入所有係數輸出非零項次" << endl;
	cout << "b)輸入非零項次輸出所有係數" << endl;
	cout << "c)輸入所有係數相加後輸出所有係數" << endl;
	cout << "d)輸入非零項次相加後輸出非零項次" << endl;
    cout << "e)退出" << endl;
	cout << "=====================================" << endl;
}

void option_a(){
	int maxexp;
	vector<int> coff;
	cout << "輸入最高次方"; 
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
    cout << "輸入有幾對";
    cin >> pairno;
    vector<pair<int,int>> coff_pair(pairno);
    int maxexp = 0;
    for(int i = 0; i < pairno; i++){
        cin >> coff_pair[i].first >> coff_pair[i].second;
        if(coff_pair[i].second > maxexp){
            maxexp = coff_pair[i].second;
        }
    }
    vector<int> checklist(maxexp + 1, 0);
    for(int i = 0; i < pairno; i++){
        checklist[coff_pair[i].second] = coff_pair[i].first;
    }
    for(int i = 0; i <= maxexp; i++){
        cout << checklist[i] << " ";
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
	for(int i = 0 ; i <= poly_1 ; i++){
		cin >> coff_1[i];
	}
	for(int i = 0 ; i <= poly_2 ; i++){
		cin >> coff_2[i];
	}
	for(int i = 0 ; i <= larger ; i++){
		cout << coff_1[i] + coff_2[i] << " ";
	}
	cout << endl;
}

void option_d(){
    int pairno_1, pairno_2;
    cout << "輸入第一個多項式有幾對 : ";
    cin >> pairno_1;
    cout << "輸入第二個多項式有幾對 : ";
    cin >> pairno_2;
    vector<pair<int,int>> coff_pair_1(pairno_1);
    vector<pair<int,int>> coff_pair_2(pairno_2);
    int maxexp = 0;
    for(int i = 0; i < pairno_1; i++){
        cin >> coff_pair_1[i].first >> coff_pair_1[i].second;
        maxexp = max(maxexp, coff_pair_1[i].second);
    }
    for(int i = 0; i < pairno_2; i++){
        cin >> coff_pair_2[i].first >> coff_pair_2[i].second;
        maxexp = max(maxexp, coff_pair_2[i].second);
    }
    vector<int> result(maxexp + 1, 0);
    for(int i = 0; i < pairno_1; i++){
        result[coff_pair_1[i].second] += coff_pair_1[i].first;
    }
    for(int i = 0; i < pairno_2; i++){
        result[coff_pair_2[i].second] += coff_pair_2[i].first;
    }
    for(int i = 0; i <= maxexp; i++){
        cout << result[i] << " ";
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