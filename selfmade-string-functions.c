// Write a program in C to implement string functions copy(), compare(), and concatenate() by clearly defining it on your own.

#include <stdio.h>
#include <string.h>

void sanCopy(char a[], char b[]) {
    int i;
    for(i = 0; b[i] != '\0'; i++) {
        a[i] = b[i];
    }
    a[i] = '\0';
    printf("\nCopied string: %s\n", a);
}

void sanCompare(char a[], char b[]) {
    int i = 0;
    
    // compare the strings character by character
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] < b[i]) {
            printf("\nString 1 is smaller than String 2.\n");
            return;
        } else if (a[i] > b[i]) {
            printf("\nString 1 is greater than String 2.\n");
            return;
        }
        i++;
    }
    
    if (a[i] == '\0' && b[i] != '\0') {
        printf("\nString 1 is smaller than String 2.\n");
    } 
    else if (b[i] == '\0' && a[i] != '\0') {
        printf("\nString 1 is greater than String 2.\n");
    } 
    else {
        printf("\nBoth strings are equal.\n");
    }
}

void sanConcatenate(char a[], char b[]) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    
    int totalLen = aLen + bLen;
    char concat[totalLen + 1];  // +1 for null terminator
    
    int count = 0;
    for(int i = 0; i < aLen; i++, count++) {
        concat[count] = a[i];
    }
    for(int j = 0; j < bLen; j++, count++) {
        concat[count] = b[j];
    }
    concat[count] = '\0';
    
    printf("\n%s\n", concat);
}

int main() {
    int ch = 1;
    char s1[20], s2[20];
    
    printf("Enter 1st string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;  // Remove trailing newline
    
    printf("Enter 2nd string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;  // Remove trailing newline
    
    while (ch != 0) {
        printf("\nEnter 1 to COPY string."
               "\nEnter 2 to COMPARE string."
               "\nEnter 3 to CONCATENATE string."
               "\nEnter 0 to EXIT."
               "\nEnter your choice: ");
        
        if (scanf("%d", &ch) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            continue;
        }
        
        switch(ch) {
            case 1:
                sanCopy(s1, s2);
                break;
                
            case 2:
                sanCompare(s1, s2);
                break;
                
            case 3:
                sanConcatenate(s1, s2);
                break;
                
            case 0:
                printf("\nProgram exited successfully!\n");
                break;
                
            default:
                printf("Enter correct choice.\n");
        }
    }
    return 0;
}
