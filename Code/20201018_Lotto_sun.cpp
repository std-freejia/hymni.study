/*
1. Backtracking 알고리즘 사용
2. vector k_and_S에 모든 testcase를 저장
3. vector lotto에 선정한 숫자를 저장
4. S중 선정된 숫자 뒤에 있는 숫자만 다음 lotto 숫자로 선정할 수 있음 
*/

#include <iostream>
#include <vector>

using namespace std;

const int total_num = 6;
vector<vector<int>> k_and_S;  // 모든 testcase의 k + S
vector<int> lotto;  // 선정한 숫자 저장

int find_combination(int tc_id, int num_id);

int main(int argc, char* argv[], char* envs[])
{
    int k = 0;
    int num = 0;
    vector<int> testcase;

    // 입력 시작
    while (1)
    {
        testcase.clear();

        cin >> k;

        if (k == 0)
        {
            break;
        }

        testcase.push_back(k);

        while (k--)
        {
            cin >> num;

            testcase.push_back(num);
        }

        k_and_S.push_back(testcase);  // testcase를 입력 순서대로 저장
    }
    // 입력 끝
    
    // testcase 순서대로 수행
    for (int i = 0; i < k_and_S.size(); i++)
    {
        lotto.clear();  // 비어줌

        // 첫자리 숫자 선정
        for (int j = 1; j <= (k_and_S[i][0] - total_num + 1); j++)
        {
            lotto.push_back(k_and_S[i][j]);
            find_combination(i, j);
            lotto.pop_back();
        }

        cout << "\n";
    }

    return 0;
}

int find_combination(int tc_id, int num_id)
{
    // 숫자 6개 선정되면 lotto 출력
    if (lotto.size() == total_num)
    {
        for (int i = 0; i < total_num; i++)
        {
            cout << lotto[i] << " ";
        }

        cout << "\n";

        return 0;
    }

    // 다음 자리 숫자 선정
    for (int j = num_id + 1; j <= k_and_S[tc_id][0]; j++)
    {
        lotto.push_back(k_and_S[tc_id][j]);
        find_combination(tc_id, j);
        lotto.pop_back();
    }

    return 0;
}
