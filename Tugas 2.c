/*
 Array & pointer 
*/
#include <stdio.h>
#include <stdlib.h>
char C[3][3] = {{'x','o','x'},{'o','x','o'},{'x','o','x'}};

int main(int argc, char *argv[]) {
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            printf("%c ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}
