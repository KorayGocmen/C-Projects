#include <stdio.h>
#include <stdlib.h>

void printer(int, char);

int main(void) {
   
    //taking the input from the user
    int inputRows, n, row, t, col;
    do {
        printf("Enter the number of rows in the triangle: ");
        scanf("%d", &inputRows);
        n = inputRows;
    } while (n <= 0);
    
    while(n>0){
                
        //Printing the first line
        printer(n - 1, ' ');
        printf("*\n");
        
        //Printing the following lines
        for (row = 2; row <= n - 1; row++) {
            printer(n - row, ' ');
            printf("*");
            printer(2 * row - 3, ' ');
            printf("*\n");
        }
        //Printing the last line
        if (n > 1)
            printer(2 * n - 1, '*');
        
        //ask again
        do {
            printf("\nEnter the number of rows in the triangle: ");
            scanf("%d", &inputRows);
            n = inputRows;
        } while (n <= 0);
    }
    return (0);
}

void printer(int m, char c) {
    for (int i = 1; i <= m; i++)
        printf("%c", c);
}
