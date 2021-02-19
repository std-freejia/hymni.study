#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

string elements[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
   "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
   "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
   "Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
   "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
   "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
   "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
   "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
   "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
   "No", "Lr" };
set<string> words(begin(elements), end(elements));
string Answer = "";
string sentence = "";

int check();

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;

    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = "YES";

        cin >> sentence;

        check();

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}

int check()
{
    vector<int> ok(sentence.size(), 0);
    string s = "";

    for (int index = 0; index < sentence.size(); index++)
    {
        s = "";

        // one letter
        s += (sentence[index] - 32);

        ok[index] += (words.count(s) ? 2 : 0);


        // two letters
        if (index < sentence.size() - 1)
        {
            s = sentence.substr(index, 2);
            s[0] -= 32;

            words.count(s) ? ok[index] += 1, ok[index + 1] += 4 : 0;
        }
        
        // 가능한지
        if (ok[index] == 0)
        {
            Answer = "NO";

            break;
        }
        else if(ok[index] == 1)
        {
            index++;
        }
    }

    return 0;
}
