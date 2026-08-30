#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    if(addressBook->contactCount == 0)//checking if address book is empty
    {
        printf("The address book is empty\n");
        return;
    }
    int i, j;
    Contact temp;
    
    for(i = 0; i < (addressBook->contactCount)-1; i++)
    {
        for(j = 0 ; j < (addressBook->contactCount)-i-1; j++)
        {
            if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }

    printf("====================================================================================\n");
    printf("|  %-3s  |  %-20s  |  %-12s  |  %-25s  |\n", "Sl.No.", "NAME", "PHONE No.","EMail ID.");
    printf("------------------------------------------------------------------------------------\n");
    for(i = 0; i < (addressBook->contactCount); i++)
    {
        printf("|  %-6d  |  %-20s  |  %-12s  |  %-25s  |\n", i+1, addressBook->contacts[i].name, 
            addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("====================================================================================\n");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization 
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	//To create contact

    if(addressBook->contactCount >= MAX_CONTACTS)//checking if address book is Full
    {
        printf("The address book is full\n");
        return;
    }
    
    char str[50], str1[20], str2[50];;
    int res;

    do
    {
        printf("Enter the name : ");
        scanf(" %[^\n]", str);

        res = validate_name(str);
    }while(res == 0);

    do
    {
        printf("Enter the phone : ");
        scanf(" %s", str1);

        res = validate_phone(addressBook, str1);
    }while(res == 0);

    do
    {
        printf("Enter the email : ");
        scanf(" %s", str2);

        res = validate_mail(addressBook, str2);
    }while(res == 0);

    //copy given contact details into address book
    strcpy(addressBook->contacts[addressBook->contactCount].name, str);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, str1);
    strcpy(addressBook->contacts[addressBook->contactCount].email, str2);

    addressBook->contactCount++;
    
}

void searchContact(AddressBook *addressBook) 
{
    //To search contact
    if(addressBook->contactCount == 0)//checking if address book is empty
    {
        printf("The address book is empty\n");
        return;
    }
    int op, ind;
    printf("\n1. Search by name\n2. Search by phone\n3. Search by Email\nEnter your choice : ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            ind = search_by_name(addressBook);
            break;
        case 2:
            ind = search_by_phone(addressBook);
            break;
        case 3:
            ind = search_by_mail(addressBook);
            break;
        default:
            printf("Invalid inpiut\n");
    }

    if(ind >= 0)//Print conatct if found
    {
        printf("%s, %s, %s\n",addressBook->contacts[ind].name, 
            addressBook->contacts[ind].phone, addressBook->contacts[ind].email);
        }    
    else
    {
        printf("Contact not found\n");
    }
}

void editContact(AddressBook *addressBook)
{
	//To edit contact
    if(addressBook->contactCount == 0)//checking if address book is empty
    {
        printf("The address book is empty\n");
        return;
    }
    int op, ind, res;
    printf("1. Search by name\n2. Search by phone\n3. Search by Email\nEnter your choice : ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            ind = search_by_name(addressBook);
            break;
        case 2:
            ind = search_by_phone(addressBook);
            break;
        case 3:
            ind = search_by_mail(addressBook);
            break;
        default:
            printf("Invalid inpiut\n");
    }

    //Editing contact after we get index value
    if(ind >= 0)
    {
        char str[50];
        printf("1. Edit name\n2. Edit phone number\n3. Edit email\nEnter your choice : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            do
            {
                printf("Enter the name : ");
                scanf(" %[^\n]",str);
                res = validate_name(str);
            }while(res == 0);

            strcpy(addressBook->contacts[ind].name, str);
            break;

            case 2:
            do
            {
            printf("Enter the phone : ");
            scanf(" %[^\n]",str);
            res = validate_phone(addressBook, str);
            }while(res == 0);

            strcpy(addressBook->contacts[ind].phone, str);
            break;

            case 3:
            do
            {
            printf("Enter the email : ");
            scanf(" %[^\n]",str);
            res = validate_mail(addressBook, str);
            }while(res == 0);

            strcpy(addressBook->contacts[ind].email, str);
            break;

            default:
            printf("Invalid inpiut\n");
        }
    }
    else
    {
        printf("Contact not found\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
	//To delete contact
    if(addressBook->contactCount == 0)
    {
        printf("The address book is empty\n");
        return;
    }
    int i, op, ind;
    printf("1. Search by name\n2. Search by phone\n3. Search by Email\nEnter your choice : ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
        ind = search_by_name(addressBook);
        break;
        case 2:
        ind = search_by_phone(addressBook);
        break;
        case 3:
        ind = search_by_mail(addressBook);
        break;
        default:
        printf("Invalid inpiut\n");
    }
    if(ind >= 0)//Deleting contact with the help of index value
    {
        for(i = ind; i < (addressBook->contactCount) - 1; i++)
        {
            addressBook->contacts[i] =
                addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;
    }
    else
    {
        printf("Contact not found\n");
    }
   
}

int validate_name(char *s)
{
    //checking if name is valid or not
    int i;
    
    //Name should only Alphabets, space and dots
    for(i = 0; s[i]; i++)
    {
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') 
            || (s[i] == ' ') ||(s[i] == '.')))
        {
            printf("Invalid input\n");
            return 0;
        }
    }
    return 1;
}

int validate_phone(AddressBook *addressBook, char *s)
{
    //checking if phone number is valid or not
    int i;
    
    //checking if phone no. already exists or not
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, s) == 0)
        {
            printf("Phone number already exists\n");
            return 0;
        }
    }

    //phone number should contain only [0 - 9] numbers and should contain 10 digits
    for(i = 0; s[i]; i++)
    {
        if(!(s[i] >= '0' && s[i] <= '9'))
        {
            printf("Invalid input\n");
            return 0;
        }
    }

    if(i == 10)
    {
        return 1;
    }
    else
    {
        printf("Phone number should contain 10 digits\n");
        return 0;
    }
}

int validate_mail(AddressBook *addressBook, char *s)
{
    //checking if email is valid or not
    int i;
    int dot = 0, at = 0;
    int dot_pos = 0, at_pos = 0;

    //checking if email already exists or not
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email, s) == 0)
        {
            printf("Email already exists\n");
            return 0;
        }
    }

    //email should not satart with numbers 
    if(s[0] >= '0' && s[0] <= '9')
    {
        printf("Email should not start with numbers\n");
        return 0;
    }

    //email should have lower case alphabets, '@' and  '.'
    for(i = 0; s[i]; i++)
    {
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '@') || (s[i] == '.')))
        {
            printf("Invalid input\n");
            return 0;
        }
        if(s[i] == '@')
        {
            at++;
            at_pos = i;
        }
        if(s[i] == '.')
        {
            dot++;
            dot_pos = i;
        }
    }

    if(at == 1 && dot == 1
        && at_pos > 0 && dot_pos > at_pos+1 
        && s[dot_pos + 1] != '\0')
    {
        return 1;
    }
    else
    {
        printf("Invalid input\n");
        return 0;
    }
}

int search_by_name(AddressBook *addressBook)
{
    //searching the contact by name 
    int i, n, arr[100];
    int count = 0;
    char str[20];
    printf("Enter the name to search : ");
    scanf(" %[^\n]",str);
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcasecmp(addressBook->contacts[i].name, str) == 0)
        {
            arr[count] = i;
            count++;
        }
    }
    if(count == 0)
    {
        printf("The contact not found\n");
        return -1;
    }
    if(count == 1)
    {
        return arr[0];
    }

    //if there are more than one contact with same name
    for(i = 0; i < count; i++)
    {
        printf("%d\t%s\t%s\t%s\n",i+1, addressBook->contacts[arr[i]].name, 
                addressBook->contacts[arr[i]].phone, addressBook->contacts[arr[i]].email);
    }
    
    printf("Pick your choice in serial number : ");
    scanf("%d",&n);

    if(n >= 1 && n <= count)
    {
    return arr[n-1];
    }
    
    printf("Invalid choice \n");
    return -1;
}

int search_by_phone(AddressBook *addressBook)
{
    //searching the contact by phone number
    int i;
    char str[20];
    printf("Enter the phone number to search : ");
    scanf(" %[^\n]",str);
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, str) == 0)
        {
            return i;
        }
    }
    return -1;
}

int search_by_mail(AddressBook *addressBook)
{
    //searching the contact by email
    int i;
    char str[20];
    printf("Enter the Email to search : ");
    scanf(" %[^\n]",str);
    for(i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].email, str) == 0)
        {
            return i;
        }
    }
    return -1;
}