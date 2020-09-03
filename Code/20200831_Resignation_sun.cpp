#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 15;
int N = 0;
vector<int> T_and_P[2];
int busy[MAX_N] = {0};
int max_income = 0;

int choose(int day, int income);

int main(int argc, char* argv[], char* envs[])
{
    cin>>N;
    
    int time = 0;
    int pay = 0;
    
    for(int i=0; i<N; i++)
    {
        cin>>time>>pay;
        
        T_and_P[0].push_back(time);
        T_and_P[1].push_back(pay);
    }
    
    int day = 0;
    int income = 0;
    
    choose(day, income);
    
    cout<<max_income<<endl;
    
    return 0;
}

int choose(int day, int income)
{
    if(day == N)
    {
        if(income > max_income)
        {
            max_income = income;
        }
        
        return 0;
    }
    
    if(busy[day] == 0 && (day + T_and_P[0][day]) <= N)
    {
        // Option 1 : Accept
        income += T_and_P[1][day];
        
        for(int i=day; i<(day+T_and_P[0][day]); i++)
        {
            busy[i] = 1;
        }
        
        choose(day + 1, income);
        
        // Option 2 : Refuse
        income -= T_and_P[1][day];
        
        for(int i=day; i<(day+T_and_P[0][day]); i++)
        {
            busy[i] = 0;
        }
        
        choose(day + 1, income);
        
    }
    else
    {
        choose(day + 1, income);
    }
    
    return 0;
}
