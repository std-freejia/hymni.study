#include <iostream>
#include <stdlib.h>

using namespace std;

const int Max = 50;
int map[Max][Max] = {0};

int do_clean(int N, int M, int r, int c, int d, int map[][Max]);

int main(int argc, char* argv[], char* env[])
{
    int N, M, r, c, d;
    
    cin>>N>>M;
    cin>>r>>c>>d;
    
    //int map[N][M] = {0};
    //int** map = (int**)malloc(sizeof(int*)*N);
    //for(int i=0; i<N; i++)
    //{
    //    map[i] = (int*)malloc(sizeof(int)*M);
    //}
    
    for(int row=0; row<N; row++)
    {
        for(int col=0; col<M; col++)
        {
            cin>>map[row][col];
        }
    }
    
    cout<<do_clean(N, M, r, c, d, map);
    
    //free(map);
    return 0;
}

int do_clean(int N, int M, int r, int c, int d, int map[][Max])
{
    int counter = 0;
    int stop = 0;
    
    while(!stop)
    {
        if(map[r][c] == 0)
        {
            counter++;
            map[r][c] = -1;  // clean in situ
        }
        
        //d = (d + 3) % 4;  // change direction
        bool surrounded = (map[r-1][c] != 0 && map[r+1][c] != 0 && map[r][c-1] != 0 && map[r][c+1] != 0);
        
        switch(d)
        {
            case 0:
                {
                    if(surrounded)
                    {
                        if(map[r+1][c] == 1)
                        {
                            stop = 1;
                        }
                        else
                        {
                            r++;
                        }
                    }
                    else
                    {
                        if(map[r][c-1] == 0)
                        {
                            c--;
                        }
                        
                        d = 3;
                    }
                    
                    break;
                }
            case 1:
                {
                    if(surrounded)
                    {
                        if(map[r][c-1] == 1)
                        {
                            stop = 1;
                        }
                        else
                        {
                            c--;
                        }
                    }
                    else
                    {
                        if(map[r-1][c] == 0)
                        {
                            r--;
                        }
                        
                        d = 0;
                    }
                    
                    break;
                }
            case 2:
                {
                    if(surrounded)
                    {
                        if(map[r-1][c] == 1)
                        {
                            stop = 1;
                        }
                        else
                        {
                            r--;
                        }
                    }
                    else
                    {
                        if(map[r][c+1] == 0)
                        {
                            c++;
                        }
                        
                        d = 1;
                    }
                    
                    break;
                }
            case 3:
                {
                    if(surrounded)
                    {
                        if(map[r][c+1] == 1)
                        {
                            stop = 1;
                        }
                        else
                        {
                            c++;
                        }
                    }
                    else
                    {
                        if(map[r+1][c] == 0)
                        {
                            r++;
                        }
                        
                        d = 3;
                    }
                    
                    break;
                }
        }
    }
    
    return counter;
}
