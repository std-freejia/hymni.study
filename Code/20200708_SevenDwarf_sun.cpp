#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int dwarf_num = 9;  // the number of dwarfs
const int age_sum = 100;  // sum of seven dwarfs 
int overall_sum = 0;  // sum of all dwarfs

int find_seven_dwarfs(vector<int> heights);

int main(int argc, char* argv[], char* envs[])
{
    vector<int> heights(dwarf_num, 0);
    
    for(int n=0; n<dwarf_num; n++)
    {
        cin>>heights[n];
        
        overall_sum += heights[n];
        
        if(heights[n] < 0 || heights[n] > 100)
        {
            cout<<"Bad input!"<<endl;
            exit(-1);
        }
    }

    find_seven_dwarfs(heights);
    
    return 0;
}

int find_seven_dwarfs(vector<int> heights)
{
    int fake_1 = 0;
    int fake_2 = 0;
    
    for(fake_1; fake_1<dwarf_num-1; fake_1++)
    {
        for(fake_2=fake_1+1; fake_2<dwarf_num; fake_2++)
        {
            if((overall_sum - heights[fake_1] - heights[fake_2]) == age_sum)
            {
                heights.erase(heights.begin() + fake_1);
                heights.erase(heights.begin() + fake_2 - 1);
                
                sort(heights.begin(), heights.end());
                
                for(int i=0; i<7; i++)
                {
                    cout<<heights[i]<<endl;
                }
                
                return 0;
            }
        }
    }
}
