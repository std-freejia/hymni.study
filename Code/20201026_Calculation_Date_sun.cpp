#include <iostream>

using namespace std;

const int MAX_E = 15;
const int MAX_S = 28;
const int MAX_M = 19;

int main(int argc, char* argv[], char* envs[])
{
    int e = 0;
    int s = 0;
    int m = 0;
    int year = 1;
    
    cin>>e>>s>>m;
    
    while(1)
    {
        if((year - e) % MAX_E == 0 &&
           (year - s) % MAX_S == 0 &&
           (year - m) % MAX_M == 0)
        {
            cout<<year;
            
            return 0;
        }
        
        year++;
    }
}
