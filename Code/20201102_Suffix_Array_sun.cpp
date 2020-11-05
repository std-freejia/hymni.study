/*
1. substring 절취하는 함수 : s.substr(pos, n)  // pos~n
                           s.substr(pos)  // pos~end
2. 공짜 sort() 사용
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char* argv[], char* envs[])
{
    string S = " ";
    vector<string> arr;
    
    cin>>S;
    
    // 모든 substring 절취
    for(int i=0; i<S.size(); i++)
    {
        arr.push_back(S.substr(i));
    }
    
    // 사전순으로 정렬
    sort(arr.begin(), arr.end());
    
    // 출력
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<"\n";
    }
    
    return 0;
}
