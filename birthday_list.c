#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LIST_SIZE 100

struct Birthday {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
};

struct Birthday birthdayList[MAX_LIST_SIZE];
int numBirthdays = 0;

void addBirthday() {
    if (numBirthdays >= MAX_LIST_SIZE) {
        printf("Birthday List is full!\n");
        return;
    }
    
    struct Birthday newBirthday;
    
    printf("Enter name: ");
    fgets(newBirthday.name, MAX_NAME_LENGTH, stdin);
    newBirthday.name[strcspn(newBirthday.name, "\n")] = '\0'; // Remove newline character
    
    printf("Enter day (1-31): ");
    scanf("%d", &newBirthday.day);
    
    printf("Enter month (1-12): ");
    scanf("%d", &newBirthday.month);
    
    printf("Enter year: ");
    scanf("%d", &newBirthday.year);
    
    birthdayList[numBirthdays] = newBirthday;
    numBirthdays++;
    
    printf("Birthday added successfully!\n");
}

void sortBirthdays() {
    struct Birthday temp;
    int i, j;
    
    for (i = 0; i < numBirthdays - 1; i++) {
        for (j = 0; j < numBirthdays - i - 1; j++) {
            if (birthdayList[j].month > birthdayList[j + 1].month ||
               (birthdayList[j].month == birthdayList[j + 1].month && birthdayList[j].day > birthdayList[j + 1].day)) {
                temp = birthdayList[j];
                birthdayList[j] = birthdayList[j + 1];
                birthdayList[j + 1] = temp;
            }
        }
    }
    
    printf("Birthday List sorted!\n");
}

void printBirthdays() {
    if (numBirthdays == 0) {
        printf("No birthdays found.\n");
        return;
    }
    
    printf("Birthday List:\n");
    
    for (int i = 0; i < numBirthdays; i++) {
        printf("%d. Name: %s\n", i + 1, birthdayList[i].name);
        printf("   Date: %d/%d/%d\n", birthdayList[i].day, birthdayList[i].month, birthdayList[i].year);
    }
}

void searchBirthday() {
    char searchName[MAX_NAME_LENGTH];
    int searchDay, searchMonth, searchYear;
    int found = 0;
    
    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline character
    
    for (int i = 0; i < numBirthdays; i++) {
        if (strcmp(birthdayList[i].name, searchName) == 0) {
            printf("Name: %s\n", birthdayList[i].name);
            printf("Date: %d/%d/%d\n", birthdayList[i].day, birthdayList[i].month, birthdayList[i].year);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No birthdays found for the given name.\n");
    }
}

void deleteBirthday() {
    char deleteName[MAX_NAME_LENGTH];
    int found = 0;
    
    printf("Enter name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0'; // Remove newline character

for (int i = 0; i < numBirthdays; i++) {
    if (strcmp(birthdayList[i].name, deleteName) == 0) {
        found = 1;
        for (int j = i; j < numBirthdays - 1; j++) {
            birthdayList[j] = birthdayList[j + 1];
        }
        numBirthdays--;
        printf("Birthday for %s deleted successfully!\n", deleteName);
        break;
    }
}

if (!found) {
    printf("No birthdays found for the given name.\n");
}
}

int main() {
int choice;
do {
    printf("========== Birthday List ==========\n");
    printf("1. Add Birthday\n");
    printf("2. Sort Birthdays\n");
    printf("3. Print Birthdays\n");
    printf("4. Search Birthday\n");
    printf("5. Delete Birthday\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    getchar(); // Clear input buffer

    switch (choice) {
        case 1:
            addBirthday();
            break;
        case 2:
            sortBirthdays();
            break;
        case 3:
            printBirthdays();
            break;
        case 4:
            searchBirthday();
            break;
        case 5:
            deleteBirthday();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    printf("\n");

} while (choice != 6);

return 0;
}

