# Address Book Management System in C

This project is a simple **Address Book Management System** developed using the C programming language.

The program allows the user to create, search, edit, delete, and display contacts. The contacts are stored in a CSV file so that the data can be saved and loaded between program executions.

## Features

* Create a new contact
* Search contacts
* Search by:

  * Name
  * Phone number
  * Email
* Edit existing contact details
* Delete a contact
* Display all contacts
* Save contacts to a CSV file
* Load contacts from a CSV file
* Validate contact details
* Prevent duplicate phone numbers
* Prevent duplicate email addresses
* Handle multiple contacts with the same name

## Technologies Used

* **C Programming**
* **GCC Compiler**
* **Structures**
* **Arrays**
* **Pointers**
* **Functions**
* **Strings**
* **File Handling**
* **CSV File Handling**

## Project Structure

```text
AddressBook/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
```

### Description of Files

**main.c**

Contains the main function and the menu-driven program. It takes the user's choice and calls the required function.

**contact.c**

Contains the main Address Book operations such as:

* Create contact
* Search contact
* Edit contact
* Delete contact
* List contacts
* Input validation

**contact.h**

Contains the structure definitions and function declarations required for the Address Book.

**file.c**

Contains functions related to file handling. It is responsible for saving contacts to the CSV file and loading contacts from the CSV file.

**file.h**

Contains the declarations of the file-handling functions.

**contacts.csv**

Stores the contact information permanently.

## How the Program Works

When the program starts, the contacts are loaded from the `contacts.csv` file.

The user is then shown a menu:

```text
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit
```

The user selects an option and performs the required operation.

The contact information is maintained in memory using an array of structures.

When the user selects **Save and Exit**, the current contacts are written back to the CSV file.

## Contact Information

Each contact contains three fields:

```text
Name
Phone Number
Email
```

Example:

```text
K S Gowthami
6300575631
gowthamiks@gmail.com
```

## CSV File Format

The contacts are stored in the following format:

```text
2
Kusuma,9391709685,kusumak@gmail.com
K S Gowthami,6300575631,gowthamiks@gmail.com
```

The first line represents the number of contacts.

Each following line contains:

```text
Name, Phone, Email
```

## Input Validation

The program validates the information entered by the user.

### Name Validation

The name accepts:

* Uppercase letters
* Lowercase letters
* Spaces
* Dot (`.`)

### Phone Validation

The phone number:

* Must contain only digits
* Must contain exactly 10 digits
* Must not already exist in the Address Book

### Email Validation

The email is checked for basic email requirements such as:

* `@`
* `.`
* Valid characters
* Duplicate email prevention

## Searching Contacts

The program provides different ways to search for a contact:

```text
1. Search by name
2. Search by phone
3. Search by email
```

Name searching is case-insensitive.

If more than one contact has the same name, the matching contacts are displayed and the user can select the required contact.

## Editing a Contact

The user can search for a contact and modify:

```text
1. Name
2. Phone number
3. Email
```

The new information is validated before updating the contact.

## Deleting a Contact

The user can search for a contact and delete it from the Address Book.

After deletion, the remaining contacts are shifted so that there are no empty positions between contacts.

## File Handling

The project uses C file-handling functions such as:

```c
fopen()
fscanf()
fprintf()
fgetc()
fclose()
```

The file is opened when contacts need to be loaded or saved and is closed after the operation is completed.

## Compilation

Compile all the `.c` files together:

```bash
gcc main.c contact.c file.c -o addressbook
```

## Run

```bash
./addressbook
```

## Example

```text
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save and Exit

Enter your choice: 1

Enter the name: K S Gowthami
Enter the phone: 6300575631
Enter the email: gowthamiks@gmail.com
```

After saving, the information will be stored in `contacts.csv`.

## Concepts Learned

This project helps in understanding and practicing:

* Structures
* Structure arrays
* Pointers
* Functions
* Header files
* Multiple source files
* Modular programming
* String handling
* Searching
* Input validation
* File handling
* CSV data storage
* Menu-driven programming

## Purpose of the Project

The main purpose of this project is to understand how a real-world application can be divided into multiple C files and how data can be stored permanently using file handling.

It also provides practical experience with **structures, functions, pointers, strings, modular programming, and file handling** in C.

## Author

**K S Gowthami**
