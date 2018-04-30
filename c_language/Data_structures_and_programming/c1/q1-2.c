/* code: q1-5.c (v1.18.00) */
#include <stdio.h>

int main()
{
    int i, j, k;
    int a[2][3][4] = {
        {
            {1, 2, 3, 4},
            {3, 4, 5, 6},
            {5, 6, 7, 8}
        },
        {
            {7, 8, 9, 10},
            {9, 10, 11, 12},
            {11, 12, 13, 14}
        }
    };
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 4; k++){
            printf("array[%d][%d][%d]=%4d\n", i, j, k, a[i][j][k]);
            }
        }
    }
    
    return 0;
}