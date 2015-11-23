#include <stdio.h>
#include <stdlib.h>

void printFactorial(int n, int r) {
    int multi1 = 1;
    for (int i = 1; i <= n; i++)
    	multi1 *= i;
    
    int multi2 = 1;
    for (int i = 1; i <= r; i++)
    	multi2 *= i;
    
    int multi3 = 1;
    for (int i = 1; i <= n - r; i++)
    	multi3 *= i;
    
    int comb = multi1 / (multi2 * multi3);
    printf("%d", comb);
}

void printNumberOfTimes(int n, char k) {
    for (int i = 1; i <= n; i++)
    	printf("%c", k);
}

int returnFactorial(int n, int r) {
    int multi1 = 1;
    for (int i = 1; i <= n; i++)
    	multi1 *= i;
    
    int multi2 = 1;
    for (int i = 1; i <= r; i++)
    	multi2 *= i;
    
    int multi3 = 1;
    for (int i = 1; i <= n - r; i++)
    	multi3 *= i;
    
    int comb = multi1 / (multi2 * multi3);
    return comb;
}

int main(void) {
    
    int n, k, j;
    printf("What is the number of rows in Pascal's triangle? ");
    scanf("%d", &n);
    
    while (n>=0){
        
        if (n!=0){
            printNumberOfTimes(3* n - 3, ' ');
            printFactorial(0, 0);
            printf("\n");
            
            for (k = 1; k <= n - 1; k++) {
                
                if (3 * n - 3 * k-3 > 0)
                    printNumberOfTimes(3 * n - 3 * k -3, ' ');
                
                printf("1");
                printNumberOfTimes(5, ' ');
                
                j=k-1;
        	for (j; j> 0; j--) {
                    
                    if (returnFactorial(k, j) / 10 == 0) {
                	printFactorial(k, j);
                	printNumberOfTimes(5, ' ');
                    } else if (returnFactorial(k, j) / 10 >= 1 && returnFactorial(k, j) / 10 <10) {
                	printFactorial(k, j);
                	printNumberOfTimes(4, ' ');
                    } else if (returnFactorial(k, j) / 100 >= 1 && returnFactorial(k, j) / 100 <10) {
                	printFactorial(k, j);
                	printNumberOfTimes(3, ' ');
                    }
        	}
                printf("1\n");
            }
        }
        printf("What is the number of rows in Pascal's triangle? ");
	scanf("%d", &n);
    } 
    return 0;
}
