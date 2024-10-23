#include "include/person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOKMARK_LIMIT 150

void help_command() {
    printf("add\tadd new person\n");
    printf("edit\tedit a person\n");
    printf("delete\tdelete a person\n");
    printf("list\tlist all people\n");
    printf("clear\tclear the screen\n");
    printf("help\tshow this help message\n");
    printf("quit\tquit the program\n");
}

int main() {
    Person people[BOOKMARK_LIMIT];
    int person_id = 0;
    int quit = 0;

    help_command(); // Show command list at startup

    while (!quit) {
        char command[10];
        printf(">> ");
        scanf("%s", command);
        scanf("%*c"); // Stops `fgets` from getting skipped

        if (strcmp(command, "add") == 0) {
            char *name = (char *)malloc(sizeof(char) * 100);
            char *gender = (char *)malloc(sizeof(char) * 10);
            char *email = (char *)malloc(sizeof(char) * 100);
            char *phone_number = (char *)malloc(sizeof(char) * 100);

            printf("Name: ");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Gender: ");
            scanf("%s", gender);

            printf("Email: ");
            scanf("%s", email);

            printf("Phone number: ");
            scanf("%s", phone_number);

            people[person_id].id = person_id;
            people[person_id].name = name;
            people[person_id].gender = gender;
            people[person_id].email = email;
            people[person_id].phone_number = phone_number;

            printf("\n");
            person_print(people[person_id]);

            ++person_id;
            fflush(stdin);
        } else if (strcmp(command, "edit") == 0) {
            printf("Enter the ID of the person to edit: ");
            int id;
            scanf("%d", &id);
            scanf("%*c");

            for (int i = 0; i < person_id; i++) {
                if (people[i].id == id) {
                    person_print(people[i]);

                    printf("1. Edit name\n");
                    printf("2. Edit gender\n");
                    printf("3. Edit email\n");
                    printf("4. Edit phone number\n");

                    printf("? ");
                    int choice;
                    scanf("%d", &choice);
                    scanf("%*c");

                    switch (choice) {
                    case 1:
                        printf("Old Name: %s\n", people[i].name);
                        printf("New Name: ");
                        fgets(people[i].name, 100, stdin);
                        people[i].name[strcspn(people[i].name, "\n")] = 0;
                        break;
                    case 2:
                        printf("Old Gender: %s\n", people[i].gender);
                        printf("New Gender: ");
                        scanf("%s", people[i].gender);
                        break;
                    case 3:
                        printf("Old Email: %s\n", people[i].email);
                        printf("New Email: ");
                        scanf("%s", people[i].email);
                        break;
                    case 4:
                        printf("Old Phone number: %s\n",
                               people[i].phone_number);
                        printf("New Phone number: ");
                        scanf("%s", people[i].phone_number);
                        break;
                    }

                    break;
                }
            }
        } else if (strcmp(command, "delete") == 0) {
            int id;
            printf("person ID: ");
            scanf("%d", &id);
            scanf("%*c");

            for (int i = 0; i < person_id; i++) {
                if (people[i].id == id) {
                    if (i < person_id - 1) {
                        for (int j = i; j < person_id - 1; j++)
                            people[j] = people[j + 1];
                    }
                    break;
                }
            }
        } else if (strcmp(command, "list") == 0) {
            if (person_id == 0) {
                printf("Bookmark list is empty.\n");
                continue;
            }

            for (int i = 0; i < person_id; i++) {
                person_print(people[i]);
            }

            printf("\n");
            printf("Total (%i)\n", person_id);
        } else if (strcmp(command, "clear") == 0) {
            system("clear");
        } else if (strcmp(command, "help") == 0) {
            help_command();
        } else if (strcmp(command, "quit") == 0) {
            quit = 1;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}
