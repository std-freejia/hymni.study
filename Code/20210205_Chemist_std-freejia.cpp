#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 화학자의 문장 -- 88.435점 

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
	
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = "YES";
		string st;
		cin >> st;

		int idx = 0;

		while (idx < st.size()) {

			if (idx < st.size()) {
				string temp = st.substr(idx, 1);
				bool ok = any_of(symbols.begin(), symbols.end(), [temp](string x) { return x == temp; });

				if (ok) {
					idx = idx + 1;
					continue;
				}
			}

			if (idx < st.size()-1) {

				string temp = st.substr(idx, 2);
				bool ok = any_of(symbols.begin(), symbols.end(), [temp](string x) { return x == temp; });

				if (ok) {
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