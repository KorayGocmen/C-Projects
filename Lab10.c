#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


//**********************************************************************
// Linked List Definitions
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//   ADD STATEMENT(S) HERE

typedef struct phoneBook {
    char familyName[55];
    char firstName[55];
    char address[55];
    char phoneNumber[55];
    struct phoneBook *link;
} contact;

contact *listHead = NULL;
contact *listTail = NULL;

//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE

void addContact(contact *newContact);
void deleteContact(contact *newContact);
void searchFamilyName(contact *newContact);
void printContact(contact *newContact);
void searchPhoneNumber(contact *newContact);
void printPhoneBook();
bool aresame(char a[55], char b[55]);

//**********************************************************************
// Support Function Declarations
//

void safegets(char s[], int arraySize); // gets without buffer overflow
void familyNameDuplicate(char familyName[]); // marker/tester friendly
void familyNameFound(char familyName[]); //   functions to print
void familyNameNotFound(char familyName[]); // 	messages to user
void familyNameDeleted(char familyName[]);
void phoneNumberFound(char phoneNumber[]);
void phoneNumberNotFound(char phoneNumber[]);
void printPhoneBookEmpty(void);
void printPhoneBookTitle(void);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';

//**********************************************************************
// Main Program
//

int main(void) {
    const char bannerString[]
    = "Personal Phone Book Maintenance Program.\n\n";
    const char commandList[]
    = "Commands are I (insert), D (delete), S (search by name),\n"
    "  R (reverse search by phone #), P (print), Q (quit).\n";
    
    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.
    
    // announce start of program
    printf("%s", bannerString);
    printf("%s", commandList);
    
    
    
    
    char response;
    char input[MAX_LENGTH + 1];
    do {
    	printf("\nCommand?: ");
    	safegets(input, MAX_LENGTH + 1);
    	// Response is first char entered by user.
    	// Convert to uppercase to simplify later comparisons.
    	response = toupper(input[0]);
        
    	if (response == 'I') {
            
            contact *newContact;
            newContact = (contact*) malloc(sizeof (contact));
            
            // Insert an phone book entry into the linked list.
            // Maintain the list in alphabetical order by family name.
            //   ADD STATEMENT(S) HERE
            char input[MAX_LENGTH + 1];
            printf("  family name: ");
            safegets(input, MAX_LENGTH + 1);
            strcpy(newContact->familyName, input);
            printf("  first name: ");
            safegets(input, MAX_LENGTH + 1);
            strcpy(newContact->firstName, input);
            printf("  address: ");
            safegets(input, MAX_LENGTH + 1);
            strcpy(newContact->address, input);
            printf("  phone number: ");
            safegets(input, MAX_LENGTH + 1);
            strcpy(newContact->phoneNumber, input);
            
            addContact(newContact);
            
            
    	} else if (response == 'D') {
            // Delete an phone book entry from the list.       	 
            //   ADD STATEMENT(S) HERE
            contact *newContact;
            newContact = (contact*) malloc(sizeof (contact));
            
            printf("\nEnter family name for entry to delete: ");
            scanf("%s", newContact->familyName);
            deleteContact(newContact);
            
    	} else if (response == 'S') {
            // Search for an phone book entry by family name
            //   ADD STATEMENT(S) HERE
            contact *newContact;
            newContact = (contact*) malloc(sizeof (contact));
            
            printf("\nEnter family name to search for: ");
            scanf("%s", newContact->familyName);
            
            searchFamilyName(newContact);
            
            
            
    	} else if (response == 'R') {
            // Search for an phone book entry by phone number.
            contact *newContact;
            newContact = (contact*) malloc(sizeof (contact));
            
            printf("\nEnter phone number to search for: ");
            scanf("%s", newContact->phoneNumber);
            
            searchPhoneNumber(newContact);
            
            //   ADD STATEMENT(S) HERE
            
    	} else if (response == 'P') {
            // Print the phone book.
            //   ADD STATEMENT(S) HERE
            if (listHead == NULL)
            	printPhoneBookEmpty();
            else
            	printPhoneBook();
            
            
    	} else if (response == 'Q') {
            ; // do nothing, we'll catch this below
    	} else {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n", commandList);
    	}
    } while (response != 'Q');
    
    // Delete the whole phone book linked list.
    //   ADD STATEMENT(S) HERE
    
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    
    
    return 0;
}


//**********************************************************************
// Add your functions below this line.
//   ADD STATEMENT(S) HERE

void addContact(contact *newContact) {
    contact *current;
    current = listHead;
    
    if (listHead == NULL) {
    	listHead = newContact;
    	newContact->link = NULL;
    } else if (current->link == NULL) {
    	if (aresame(newContact->familyName, current->familyName)) {
            printf("\nAn entry for <%s> is already in the phone book!\n", newContact->familyName);
            printf("New entry not entered.\n");
    	} else {
            printf("else de girdi\n");
            if (newContact->familyName > current->familyName) {
            	newContact->link = NULL;
            	current->link = newContact;
                
            } else {
            	newContact->link = current;
            	listHead = newContact;
            }
    	}
    } else {
    	while (current->link != NULL) {
            if (newContact->familyName == current->familyName) {
            	printf("\nAn entry for <%s> is already in the phone book!\n", newContact->familyName);
            	printf("New entry not entered.\n");
            	break;
            } else if (newContact->familyName > current->familyName) {
            	newContact->link = current->link;
            	current->link = newContact;
            } else if (newContact->familyName < current->familyName) {
            	newContact->link = current;
            	if (listHead == current)
                    listHead = newContact;
            }
    	}
    }
}

void deleteContact(contact *newContact) {
    contact *current;
    bool found = false;
    current = listHead;
    
    while (current != NULL && !found) {
    	if (newContact->familyName == current->familyName) {
            found = true;
            
            if (listHead == current)
            	listHead = current->link;
            free(current);
    	}
    }
    if (!found)
    	printf("The family name <%s> is not in the phone book.\n", newContact->familyName);
    
}

void searchFamilyName(contact *newContact) {
    contact *current;
    current = listHead;
    bool found = false;
    contact *holder;
    while (current != NULL && !found) {
    	if (aresame(newContact->familyName, current->familyName)) {
            found = true;
            holder = current;
    	}
    	current = current->link;
    }
    
    if (found) {
    	printf("\nThe family name <%s> was found in the phone book.\n\n", holder->familyName);
    	printContact(holder);
    } else {
    	printf("\nThe family name <%s> is not in the phone book.\n", newContact->familyName);
    }
}

void printContact(contact *newContact) {
    printf("%s\n", newContact->familyName);
    printf("%s\n", newContact->firstName);
    printf("%s\n", newContact->address);
    printf("%s\n", newContact->phoneNumber);
}

void searchPhoneNumber(contact *newContact) {
    contact *current;
    current = listHead;
    bool found = false;
    contact *holder;
    while (current != NULL && !found) {
    	if (aresame(newContact->familyName, current->familyName)) {
            found = true;
            holder = current;
    	}
    	current = current->link;
    }
    if (found) {
    	printf("\nThe phone number <%s> was found in the phone book.\n\n", holder->phoneNumber);
    	printContact(holder);
    } else {
    	printf("\nThe phone number <%s> is not in the phone book.\n", newContact->phoneNumber);
    }
}

void printPhoneBook() {
    contact *current;
    current = listHead;
    
    printPhoneBookTitle();
    
    while (current != NULL) {
    	printContact(current);
    	current = current->link;
    }
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.

void safegets(char s[], int arraySize) {
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE) {
    	s[i] = c;
    	i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name
// that is already in the book.

void familyNameDuplicate(char familyName[]) {
    printf("\nAn entry for <%s> is already in the phone book!\n"
            "New entry not entered.\n", familyName);
}

// Function to call when a family name was found in the phone book.

void familyNameFound(char familyName[]) {
    printf("\nThe family name <%s> was found in the phone book.\n",
            familyName);
}

// Function to call when a family name was not found in the phone book.

void familyNameNotFound(char familyName[]) {
    printf("\nThe family name <%s> is not in the phone book.\n",
            familyName);
}

// Function to call when a family name that is to be deleted
// was found in the phone book.

void familyNameDeleted(char familyName[]) {
    printf("\nDeleting entry for family name <%s> from the phone book.\n",
            familyName);
}

// Function to call when a phone number was found in the phone book.

void phoneNumberFound(char phoneNumber[]) {
    printf("\nThe phone number <%s> was found in the phone book.\n",
            phoneNumber);
}

// Function to call when a phone number was not found in the phone book.

void phoneNumberNotFound(char phoneNumber[]) {
    printf("\nThe phone number <%s> is not in the phone book.\n",
            phoneNumber);
}

// Function to call when printing an empty phone book.

void printPhoneBookEmpty(void) {
    printf("\nThe phone book is empty.\n");
}

// Function to call to print title when whole phone book being printed.

void printPhoneBookTitle(void) {
    printf("\n  My Personal Phone Book: \n\n");
}

bool aresame(char a[55], char b[55]) {
    
    bool go=true;
    int i;
    for(i=0; i<55 && go; i++){
        
    	if(a[i]==b[i])  go=true;
    	else        	go=false;
        
    }
    return go;
}
