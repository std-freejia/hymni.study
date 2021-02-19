#include <vector>

using namespace std;

const int MAX = 1024;
bool merged[MAX][MAX] = {0};
int diff_dir[3][2] = {{0, 1}, {1, 0}, {1, 1}};

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    int i = 0;  // for loop
    int j = 0;  // for loop
    int k = 0;  // for loop
    int unit = 2;
    int size = arr.size();
    
    // 압축전 0, 1 개수
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            answer[arr[i][j]]++;
            merged[i][j] = true;
        }
    }
    
    // unit * unit 단위로 압촉 (2*2, 4*4, 8*8....)
    while(unit <= size)
    {
        for(i=0; i<size; i+=unit)
        {
            for(j=0; j<size; j+=unit)
            {
                // 왼쪽 위 칸에 압촉된 건지를 표시
                if(merged[i][j])
                {
                    // right, below, bottom right corner 3 방향 체크
                    for(k=0; k<3; k++)
                    {
                        int adj_x = i + (unit / 2) * diff_dir[k][0];
                        int adj_y = j + (unit / 2) * diff_dir[k][1];
                        
                        // sub-unit 압촉 안된 경우나 숫자 다른 경우 압촉 불가
                        if(!merged[adj_x][adj_y] || arr[i][j] != arr[adj_x][adj_y])
                        {
                            merged[i][j] = false;
                            break;
                        }
                    }
                    
                    // 압촉되면 0이나 1 3개 감소
                    answer[arr[i][j]] -= k == 3 ? 3 : 0;
                }
            }
        }
        
        unit = unit << 1;  // unit * 2
    }
    
    return answer;
}
