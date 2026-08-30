#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {

    //To save the given contacts to file
    FILE *fp = fopen("contacts.csv", "w");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    fprintf(fp, "%d\n", addressBook->contactCount);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s, %s, %s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
    //Loading contacts from file
    FILE *fp = fopen("contacts.csv", "r");

    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    fscanf(fp, "%d\n", &addressBook->contactCount);

    int i;
    int count = addressBook->contactCount;

    for(i = 0; i < count; i++){
        fscanf(fp, "\n%[^,], %[^,], %[^\n]",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("Contacts loaded successfully.\n");
}
