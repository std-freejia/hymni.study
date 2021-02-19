#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

    int gotoX = 0, gotoY = 0;

    // game loop
    while (1) {
        
		// MUSBY CODE!!!
        gotoX = light_x - initial_tx;
        gotoY = light_y - initial_ty;
        
        if(0 != gotoY){
            (0 > gotoY) ? printf("N"), initial_ty-- : printf("S"), initial_ty++;
        }

        if(0 != gotoX){
            (0 > gotoX) ? printf("W"), initial_tx-- : printf("E"), initial_tx++;
        }
        
        printf("\n");
    }

    return 0;
}
