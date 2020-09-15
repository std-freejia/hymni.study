#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    string word = " ";
    char alphabet[26] = {0};
    int i = 0;  // for loop
    
    cin>>word;
    
    for(i=0; i<word.size(); i++)
    {
        if(alphabet[word[i] - 'a'] == 0)
        {
            alphabet[word[i] - 'a'] = i + 1;
        }
    }
    
    for(i=0; i<26; i++)
    {
        cout<<alphabet[i] - 1<<" ";
    }
    
    return 0;
}
