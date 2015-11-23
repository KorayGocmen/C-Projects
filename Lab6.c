#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int length, sequence;
    int DNA[] = {1, 2, 4, 2, 2, 2, 1, 4, 4, 2, 3, 4, 4, 4, 2, 1, 4, 1,
    3, 3, 2, 1, 3, 2, 1, 1, 2, 2, 2, 3, 4, 1, 3, 1, 2, 1,
    4, 4, 4, 1, 1, 3, 1, 4, 2, 4, 4, 1, 4, 4, 1, 4, 4, 4,
    4, 1, 1, 2, 3, 3, 3, 3, 4, 4, 3, 2, 3, 2, 3, 4, 3, 3,
    4, 4, 1, 3, 3, 2, 1, 2, 3, 1, 2, 1, 3, 3, 2, 1, 4, 1,
    4, 3, 4, 4, 4, 1, 2, 1, 3, 2, 0};
    
    int digits[100];
    int i = 0;
    printf("Enter length of DNA sequence to match: ");
    scanf("%d", &length);
    if (length > 0) {
    	printf("Enter %d characters (one of 12345) as a search sequence: ", length);
    	for (i = 0; i < length; i++) {
            scanf("%1d", &digits[i]);
    	}
    }
    int isThereSix = 1;
    for (int i = 0; i < length; i++) {
    	if (digits[i] == 6) {
            isThereSix = 0;
            printf("Erroneous character input '6' exiting\n");
    	}
    }
    while (isThereSix && length > 0) {
    	for (int i = 0; i <= 100 - length; i++) {
            int found = 1;
            for (int j = 0; j < length && found > 0; j++) {
            	if (digits[j] == DNA[i + j] || digits [j] == 5) {
                    found = 1;
            	} else {
                    found = 0;
            	}
                
            }
            if (found == 1)
            	printf("Match of search sequence found at element %d\n", i);
            
    	}
    	printf("Enter length of DNA sequence to match: ");
    	scanf("%d", &length);
    	if (length > 0) {
            printf("Enter %d characters (one of 12345) as a search sequence: ", length);
            for (i = 0; i < length; i++) {
            	scanf("%1d", &digits[i]);
            }
    	}
    	for (int i = 0; i < length; i++) {
            if (digits[i] == 6) {
            	isThereSix = 0;
            	printf("Erroneous character input '6' exiting\n");
            }
    	}
    }
    printf("Goodbye");
    
    return (EXIT_SUCCESS);
}
