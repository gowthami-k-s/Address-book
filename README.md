# Address Book in C

This is a simple **Address Book Management System** written in C.

## Features

* Create a contact
* Search a contact
* Edit a contact
* Delete a contact
* List all contacts
* Save contacts to CSV file
* Load contacts from CSV file
* Validate name, phone number and email
* Avoid duplicate phone numbers and emails
* Search multiple contacts with the same name

## Technologies

* C Programming
* GCC
* File Handling
* CSV File

## Files

main.c
contact.c
contact.h
file.c
file.h
populate.c
populate.h
contacts.csv

## Menu

1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit

## Compile

gcc main.c contact.c file.c populate.c -o addressbook

## Run

./addressbook

## CSV File

Contacts are stored in `contacts.csv`.

Example:
2
Kusuma,9391709685,kusumak@gmail.com
K S Gowthami,6300575631,gowthamiks@gmail.com

## Concepts Used

* Structures
* Pointers
* Functions
* Strings
* Arrays
* File Handling
* Input Validation
* Searching

## Author
**K S Gowthami**
