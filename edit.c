#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include"phoneheader.h"

void editaddress(PHONEBOOK *);
void editgmail(PHONEBOOK *);

// Function to handle the editing process
PHONEBOOK *edit(PHONEBOOK *head)
{
    char choice;

    // Clear the input buffer before reading the choice
    while (getchar() != '\n');  // Clear any leftover characters in the buffer

    // Ask for what to edit (Address or Gmail)
    printf("Enter what you want to edit:\n");
    printf("A/a: Address\n");
    printf("G/g: Gmail\n");
    printf("Choice: ");

    scanf(" %c", &choice);  // Now it's safe to take the choice input without leftover newlines

    switch(choice)
    {
        case 'A': case 'a': 
            editaddress(head);
            break;
        case 'G': case 'g':
            editgmail(head);
            break;
        default:
            printf("Invalid Entry\n");
    }
    return head;  // Return head to maintain the linked list
}

// Function to edit address of a contact
void editaddress(PHONEBOOK *head)
{
    char name[20];
    PHONEBOOK *temp = head;

    // Ask for the contact name to edit the address
    printf("Enter the name of the contact whose address you want to edit: ");
    // Clear any leftover newline character in the buffer
    while (getchar() != '\n');
    
    // Read the name using fgets
    fgets(name, sizeof(name), stdin);

    // Remove newline at the end of the name input
    name[strlen(name) - 1] = '\0';

    // Search for the contact by name
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Current Address: %s\n", temp->address);
            printf("Enter new address: ");

            // Read the new address using fgets
            fgets(temp->address, sizeof(temp->address), stdin);

            // Ensure the address is properly null-terminated (fgets includes the newline)
            temp->address[strlen(temp->address) - 1] = '\0';

            printf("Address updated successfully!\n");
            return;
        }
        temp = temp->link;
    }

    printf("Contact not found!\n");
}

// Function to edit Gmail of a contact
void editgmail(PHONEBOOK *head)
{
    char name[20];
    PHONEBOOK *temp = head;

    // Ask for the contact name to edit the Gmail
    printf("Enter the name of the contact whose Gmail you want to edit: ");
    // Clear any leftover newline character in the buffer
    while (getchar() != '\n');
    
    // Read the name using fgets
    fgets(name, sizeof(name), stdin);

    // Remove newline at the end of the name input
    name[strlen(name) - 1] = '\0';

    // Search for the contact by name
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Current Gmail: %s\n", temp->gmail);
            printf("Enter new Gmail: ");

            // Read the new Gmail using fgets
            fgets(temp->gmail, sizeof(temp->gmail), stdin);

            // Ensure the Gmail is properly null-terminated (fgets includes the newline)
            temp->gmail[strlen(temp->gmail) - 1] = '\0';

            printf("Gmail updated successfully!\n");
            return;
        }
        temp = temp->link;
    }

    printf("Contact not found!\n");
}

