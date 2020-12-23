
int x, y, direction; // 좌표, 숫자 채울 방향 

int arr[1001][1001]; // 달팽이 배열 

vector<int> solution(int n) {
    vector<int> answer;
    int num = 1; //채울 숫자 
    for (int i = 0; i < n; i++) // 회전 횟수 n 번. 
    {
        switch (direction)
        {
        case 0: // 아래 
            for (int j = i; j < n; j++)
                arr[x++][y] = num++; // x만 증가 
			
            x--;
            y++;
            direction = 1; // 방향 변경 
            break;
        case 1: // 오른쪽 
            for (int j = i; j < n; j++)
                arr[x][y++] = num++;  // y만 증가 
			
            x--;
            y -= 2;
            direction = 2; // 방향 변경 
            break;
        case 2: // 위 
            for (int j = i; j < n; j++)
                arr[x--][y--] = num++; // x,y둘다 감소 
			
            x += 2;
            y++;
            direction = 0; // 방향 변경 
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            answer.push_back(arr[i][j]);
    }
    return answer;
}
