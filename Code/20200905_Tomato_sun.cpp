#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct box_cell
{
    int row;
    int col;
};

const int MAX_SIZE = 1000;
int M = 0;
int N = 0;
int raw_num = 0;
int status[MAX_SIZE][MAX_SIZE] = { 0 };
queue<box_cell> tomato_queue;

int BFS();

int main(int argc, char* argv[], char* envs[])
{
    box_cell tomato = { 0, 0 };

    cin >> M >> N;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            tomato.row = row;
            tomato.col = col;
            cin >> status[row][col];

            if (status[row][col] == 1)
            {
                tomato_queue.push(tomato);
            }

            if (status[row][col] == 0)
            {
                raw_num++;
            }
        }
    }

    BFS();

    return 0;
}

int BFS()
{
    box_cell temp = { 0, 0 };
    int timer = -1;
    int counter = 0;

    while (!tomato_queue.empty())
    {
        int len = tomato_queue.size();
        
        for (int i = 0; i < len; i++)
        {
            temp = tomato_queue.front();

            tomato_queue.pop();

            // front
            if (temp.row - 1 >= 0 && status[temp.row - 1][temp.col] == 0)
            {
                status[temp.row - 1][temp.col] = 1;
                tomato_queue.push({ temp.row - 1, temp.col });
                counter++;
            }

            // back
            if (temp.row + 1 < N && status[temp.row + 1][temp.col] == 0)
            {
                status[temp.row + 1][temp.col] = 1;
                tomato_queue.push({ temp.row + 1, temp.col });
                counter++;
            }

            // left
            if (temp.col - 1 >= 0 && status[temp.row][temp.col - 1] == 0)
            {
                status[temp.row][temp.col - 1] = 1;
                tomato_queue.push({ temp.row, temp.col - 1 });
                counter++;
            }

            // right
            if (temp.col + 1 < M && status[temp.row][temp.col + 1] == 0)
            {
                status[temp.row][temp.col + 1] = 1;
                tomato_queue.push({ temp.row, temp.col + 1 });
                counter++;
            }
        }

        timer++;
    }

    if (counter < raw_num)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << timer << endl;
    }

    return 0;
}
