#ifndef PERSON_H
#define PERSON_H
#include <stddef.h>

typedef struct Person {
    int id;
    char *name;
    char *gender;
    char *email;
    char *phone_number;
} Person;

Person person_add(int id, char *name, char *gender, char *email,
                  char *phone_number);

void person_print(Person person);

#endif
