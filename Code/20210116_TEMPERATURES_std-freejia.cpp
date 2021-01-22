#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;


int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    
    int min = 10000;  // 최소값 초기화 
    vector<int> v; 

    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        v.push_back(t);
    }

    sort(v.begin(), v.end(), greater<>());  // 내림차순 정렬 

    int idx = 0;

    for(int i = 0; i < n; i++){

        if(min > abs(v[i])){ // 절대값 
            min = abs(v[i]);
            idx = i; // 인덱스 기억 
        }
    }

    if(n == 0){
        cout << 0;
    }else{
        cout << v[idx] << endl;
    }
    
}