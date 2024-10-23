#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    int id;
    char *name;
    char *gender;
    char *email;
    char *phone_number;
} Person;

Person person_add(int id, char *name, char *gender, char *email,
                  char *phone_number) {
    Person person;

    person.id = id;
    person.name = name;
    person.gender = gender;
    person.email = email;
    person.phone_number = phone_number;

    return person;
}

void person_print(Person person) {
    printf("ID: %d\n", person.id);
    printf("Name: %s\n", person.name);
    printf("Gender: %s\n", person.gender);
    printf("Email: %s\n", person.email);
    printf("Phone number: %s\n", person.phone_number);
    printf("------------------------------\n");
}
