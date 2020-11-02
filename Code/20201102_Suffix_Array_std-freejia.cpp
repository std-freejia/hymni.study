#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using namespace std;

string S; 
vector<string> v;

int main() {	
 
 	cin >> S;

 	for(int i=0; i < S.size(); i++){
 		v.push_back(S.substr(i));
	}
 	
 	sort(v.begin(), v.end());
 	
 	for(int i=0; i < v.size(); i++){
 		cout << v[i] << '\n';
	}
 	
	return 0;
} 
