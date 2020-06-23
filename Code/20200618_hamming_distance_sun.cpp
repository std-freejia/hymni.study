#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[], char* env[])
{
    int num = 0;
    int n=0;
    char string_1[100] = {0,};
    char string_2[100] = {0,};
    
    cin>>num;  // the number of test cases
    
    int hamming_dist[num] = {0,};
    
    for(n=0; n<num; n++)
    {
        cin>>string_1;
        cin>>string_2;
        
        int len = strlen(string_1);
        
        for(int i=0; i<len; i++)
        {
            if((string_1[i] ^ string_2[i]) != 0)
            {
                hamming_dist[n]++;
            }
        }
    }
    
    for(n=0; n<num; n++)
    {
        cout<<"Hamming distance is "<<hamming_dist[n]<<"."<<endl;
    }
    
    return 0;
}
