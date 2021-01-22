#include <stdlib.h>
#include <stdio.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);

    int temp = 0;

    if(n != 0)
    {
        temp = 5526;
    }

    for (int i = 0; i < n; i++) {
        // a temperature expressed as an integer ranging from -273 to 5526
        int t;
        scanf("%d", &t);

        if(abs(t) <= abs(temp))
        {
            if(abs(t) == abs(temp))
            {
                if(temp > t){
                    temp = abs(t);
                }else{
                    temp = t;
                }
            }else{
                temp = t;
            }
        }
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");  

    printf("%d\n", temp);

    return 0;
}