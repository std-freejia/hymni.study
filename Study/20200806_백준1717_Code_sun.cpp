#include <iostream>
#include <stdio.h>

using namespace std;

const int Max_N = 1000000;
const int Max_M = 100000;
int parents[Max_N] = {0};
int ranks[Max_N] = {0};
int options[Max_M][3] = {0};

//struct DisjointSet
//{
//    int parent;
//    int rank;
//};

int init_set(int N);
int find(int element);
int merge(int element1, int element2);
int is_same_set(int element1, int element2);

int main(int argc, char* argv[], char* envs[])
{
    int N = 0;
    int M = 0;
    int i = 0;
   
    //cin>>N>>M;
    scanf("%d %d", &N, &M);
    
    init_set(N);
    
    for(i=0; i<M; i++)
    {
        //cin>>options[i][0]>>options[i][1]>>options[i][2];
        scanf("%d %d %d", &options[i][0], &options[i][1], &options[i][2]);
    }
    
    for(i=0; i<M; i++)
    {
        if(options[i][0] == 0)
        {
            merge(options[i][1], options[i][2]);
        }
        else
        {
            is_same_set(options[i][1], options[i][2]);
        }
    }
    
    return 0;
}

int init_set(int N)
{
    for(int i=0; i<=N; i++)
    {
        parents[i] = i;
        ranks[i] = 0;
    }
    
    return 0;
}

int find(int element)
{
   if(element == parents[element])
   {
       return parents[element];
   }
    else
    {
        return parents[element] = find(parents[element]);  // Path compression
    }
}

int merge(int element1, int element2)
{
    int set1 = find(element1);
    int set2 = find(element2);
    
    if(set1 == set2)
    {
        return 0;
    }
    
    if(ranks[set1] >= ranks[set2])
    {
        parents[set2] = set1;
        
        if(ranks[set1] == ranks[set2])
        {
            ranks[set1]++;
        }
    }
    else
    {
        parents[set1] = set2;
    }
    
    return 0;
}

int is_same_set(int element1, int element2)
{
    if(find(element1) == find(element2))
    {
        //cout<<"YES"<<endl;
        printf("YES\n");
    }
    else
    {
        //cout<<"NO"<<endl;
        printf("NO\n");
    }
    
    return 0;
}
