#include <iostream>

using namespace std;

const int n_max = 11;

int main(int argc, char* argv[], char* envs[])
{
    /* Calculate and store in dictionary */
    int answer[n_max+1] = {0};
    int i = 0;
    int j = 0;
    
    for(i=1; i<=n_max; i++)
    {
        if(i < 4)
        {
            answer[i]++;
        }
        
        for(j=1; j<=3; j++)
        {
            if((i - j) > 0)
            {
                answer[i] += answer[i-j];
            }
            else
            {
                break;
            }
        }
    }
    
    /* Input and search the dictionary */
    int testcase_num = 0;
    
    cin>>testcase_num;
    
    int n[testcase_num] = {0};
    
    for(i=0; i<testcase_num; i++)
    {
        cin>>n[i];
    }
   
    for(i=0; i<testcase_num; i++)
    {
        cout<<answer[n[i]]<<endl;
    }
    
    return 0;
}
