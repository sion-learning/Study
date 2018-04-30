/* code: q1-4.c (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>
#define TABLE 9

int main()
{
    int i, j;
    int a[TABLE][TABLE];
    
    for(i = 0; i < TABLE; i++){
        for(j = 0; j < TABLE; j++){
            a[i][j] = (i + 1) * (j + 1);
            printf("%02d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}