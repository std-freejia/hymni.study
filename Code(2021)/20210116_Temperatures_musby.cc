#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int main()
{
    // the number of temperatures to analyse
    int n, min = 0;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        
        int t;
        scanf("%d", &t);
        
        // MUSBY CODE!!!
        (0 == i) ? min = INT_MAX : false;

        if(abs(t) < abs(min)){
            min = t;
        }else if(abs(t) == abs(min)){
            min = abs(t);
        }
    }

    printf("%d\n", min);

    return 0;
}
