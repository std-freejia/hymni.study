#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int S = 0;
vector<int> arr;
int total = 0;

int find(int counter, int index);

int main(int argc, char* argv[], char* envs[])
{
    int num = 0;

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        arr.push_back(num);
    }

    int counter = 0;
    int index = 0;

    find(counter, index);

    cout << total << endl;

    return 0;
}

int find(int counter, int index)
{
    if (index >= N)
    {
        return 0;
    }
    
    if ((counter + arr[index]) == S)
    {
        total++;
    }
    
    // Option 1 : not choose
    find(counter, index + 1);
    
    // Option 2 : choose
    counter += arr[index];

    find(counter, index + 1);

    return 0;
}
