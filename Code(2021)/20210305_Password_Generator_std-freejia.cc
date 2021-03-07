#include "bits/stdc++.h"
#define endl '\n'
using namespace std;


// 암호 만들기 

int L, C; // 암호 길이, 알파벳 개수 
vector<char> v;
string mo_str = "aeiou";
char ch;


// 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음

bool Jamo_check(string pw)
{
	int mo, ja;
	mo = ja = 0;

	for (int i = 0; i < pw.length(); i++) { 
		if (mo_str.find(pw[i]) == -1) {
			ja++;
		}else{
			mo++;
		}
	}

	return (mo >= 1 && ja >= 2) ? true : false;
}

void recursive(string pw, int n) 
{
	if (pw.length() == L)
	{
		if (Jamo_check(pw))
		{
			cout << pw << endl;
		}
		return;
	}

	if (n >= C) return;

	recursive(pw + v[n], n + 1); // 포함 
	recursive(pw, n+1); // 미포함 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for(int i = 0; i < C; i++){
		cin >> ch;
		v.push_back(ch);
	}

	sort(v.begin(), v.end());

	string str = "";

	// 0부터 C-1 까지 문자를 '선택/선택하지 않음'으로 길이 L의 pw를 만든다 
	recursive(str, 0); 

	return 0;
}