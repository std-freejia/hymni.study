#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 100000;
bool check[4 * MAX + 1];

int main()
{
	int T, test_case;
	int N = 0;
	int num = 0;
	int i = 0;  // for loop
	int j = 0;  // for loop
	int Answer = 0;
	vector<int> nums;
	
	cin >> T;
	
	for(test_case = 0; test_case < T; test_case++)
	{
    memset(check, 0, sizeof(check));
    nums.clear();
		Answer = 0;
		
		cin >> N;
		
		for(i = 0; i < N; i++)
		{
			cin >> num;
			
			nums.push_back(num);
			
			for(j = 0; j < i; j++)
			{
					if(check[nums[i] - nums[j] + 2 * MAX])
					{
						Answer++;
						
						break;
					}
			}
			
			for(j = 0; j <= i; j++)
			{
				check[nums[i] + nums[j] + 2 * MAX] = 1;
			}
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}
	
    return 0;
}
