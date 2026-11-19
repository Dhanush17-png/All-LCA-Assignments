#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice;
    char str1[100], str2[100], ch, sub[50];
    char *ptr;

    while (1) {
        printf("\n--- String Ops Menu ---\n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy String (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find Character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize strings (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter Source String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                strcpy(str2, str1);
                printf("Copied String: %s\n", str2);
                break;

            case 3:
                printf("Enter First String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Second String: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter First String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Second String: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';
                if (strcmp(str1, str2) == 0) {
                    printf("Strings are equal\n");
                } else {
                    printf("Strings are unequal\n");
                }
                break;

            case 5:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Character: ");
                scanf("%c", &ch);
                getchar(); // Consume newline
                ptr = strchr(str1, ch);
                if (ptr != NULL) {
                    printf("Character found at position: %ld\n", ptr - str1 + 1);
                } else {
                    printf("Not Found\n");
                }
                break;

            case 6:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter Substring: ");
                fgets(sub, 50, stdin);
                sub[strcspn(sub, "\n")] = '\0';
                ptr = strstr(str1, sub);
                if (ptr != NULL) {
                    printf("Substring found at position: %ld\n", ptr - str1 + 1);
                } else {
                    printf("Not Found\n");
                }
                break;

            case 7:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Tokens (split by space):\n");
                ptr = strtok(str1, " ");
                while (ptr != NULL) {
                    printf("%s\n", ptr);
                    ptr = strtok(NULL, " ");
                }
                break;

            case 8:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = toupper(str1[i]);
                }
                printf("Uppercase String: %s\n", str1);
                break;

            case 9:
                printf("Enter String: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = tolower(str1[i]);
                }
                printf("Lowercase String: %s\n", str1);
                break;

            case 10:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
