#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool cmp(const int &a, const int &b)
{
    if(abs(a) == abs(b))
    {
        return a > b;
    }
    return abs(a) < abs(b);
}

int main()
{
    int n; // the number of temperatures to analyse
    vector<int> temps;

    cin >> n; cin.ignore();

    for (int i = 0; i < n; i++)
    {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        
        cin >> t; cin.ignore();
        
        temps.push_back(t);
    }

    sort(temps.begin(), temps.end(), cmp);

    cout << (temps.empty() ? 0 : temps[0]) << endl;
}
