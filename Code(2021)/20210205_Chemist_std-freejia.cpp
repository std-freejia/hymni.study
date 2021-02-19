#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 화학자의 문장 -- 93.481

string Answer;
vector<string> symbols{
	"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr"
};

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	
	// 문자열 통째로 소문자 문자열로 변환 
	for (int i = 0; i < symbols.size(); i++) { 
		transform(symbols[i].begin(), symbols[i].end(), symbols[i].begin(), ::tolower);
	}
		
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = "YES";
		string st;
		cin >> st;

		int idx = 0; // 문자열에서 이동할 인덱스 

		while (idx < st.size()) {

			if (idx < st.size()) { // 길이1 문자열 검사 
				string temp = st.substr(idx, 1); // 길이1 문자열 추출하여 벡터에 존재하는지 확인 
				bool ok = any_of(symbols.begin(), symbols.end(), [temp](string x) { return x == temp; });

				if (ok) { // 있음
					idx = idx + 1;
					continue;
				}
			}

			if (idx < st.size()-1) { // 길이2 문자열 검사 

				string temp = st.substr(idx, 2); // 길이2 문자열 추출하여 벡터에 존재하는지 확인 
				bool ok = any_of(symbols.begin(), symbols.end(), [temp](string x) { return x == temp; });

				if (ok) { // 있음 
					idx = idx + 2;
					continue;
				}
				else {
					Answer = "NO";
					break;
				}
			}
			else {
				Answer = "NO";
				break;
			}
		}			

		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer <<  '\n';
	}

	return 0;
}
