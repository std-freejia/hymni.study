#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int L = 0;
int C = 0;
vector<char> vowel = { 'a','e','i','o','u' };
vector<char> letters;  // given alphabet
vector<char> pw;  // password
vector<int> is_vowel;  // is vowel or not

int find_pw(int index, int vowel_num, int cons_num);

int main()
{
    char letter = '\0';

    cin >> L >> C;

    int i = 0;

    for (i; i < C; i++)
    {
        cin >> letter;

        letters.push_back(letter);
    }

    sort(letters.begin(), letters.end());

    for (i = 0; i < C; i++)
    {
        if (find(vowel.begin(), vowel.end(), letters[i]) == vowel.end())
        {
            is_vowel.push_back(0);
        }
        else
        {
            is_vowel.push_back(1);
        }
    }

    int start = 0;
    int vowel_num = 0;
    int cons_num = 0;

    find_pw(start, vowel_num, cons_num);

    return 0;
}

int find_pw(int index, int vowel_num, int cons_num)
{
    if (pw.size() == L)
    {
        if (vowel_num >= 1 && cons_num >= 2)
        {
            for (int i = 0; i < L; i++)
            {
                cout << pw[i];
            }

            cout << endl;
        }

        return 0;
    }

    if (index >= letters.size())
    {
        return 0;
    }

    pw.push_back(letters[index]);

    if (is_vowel[index] == 1)
    {
        find_pw(index + 1, vowel_num + 1, cons_num);
    }
    else
    {
        find_pw(index + 1, vowel_num, cons_num + 1);
    }

    pw.pop_back();

    find_pw(index + 1, vowel_num, cons_num);

    return 0;
}
