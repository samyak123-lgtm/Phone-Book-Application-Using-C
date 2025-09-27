#include "phoneheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PHONEBOOK *Syncfromfile(PHONEBOOK *head) {
    PHONEBOOK *newnode = NULL, *temp = NULL;
    PHONEBOOK var;
    int i;
    int size= sizeof(PHONEBOOK) - sizeof(PHONEBOOK *);

    FILE *fp = fopen("phonebook.txt", "r");
    if (fp == NULL) {
        //printf("No phonebook file found\n");
        return head;
    }

    while (fread(&var,size,1, fp) == 1) {
        newnode = calloc(1, sizeof(PHONEBOOK));
        if (newnode ==NULL)
       	{
            printf("Node not created\n");
            //fclose(fp);
            return head;
        }

        // **Copy contact details**
        strcpy(newnode->name, var.name);
        strcpy(newnode->gmail, var.gmail);
        strcpy(newnode->address, var.address);
        newnode->numcount = var.numcount;

        // **Allocate memory for phone numbers**
        newnode->numbers = malloc(newnode->numcount * sizeof(char *));
        if (!newnode->numbers) 
	{
            printf("Memory allocation for phone numbers failed!\n");
            free(newnode);
            fclose(fp);
            return head;
        }

        // **Read phone numbers dynamically**
        for (i = 0; i < newnode->numcount; i++) 
	{
            newnode->numbers[i] = malloc(15 * sizeof(char));  // 15 characters per number
            fread(newnode->numbers[i], 15, 1, fp);
        }

        // **Insert at the end of the linked list**
        newnode->link = NULL;
        if (head == NULL) 
	{
            head = newnode;
        }
       	else 
	{
            temp = head;
            while (temp->link) 
	    {
                temp = temp->link;
            }
            temp->link = newnode;
        }
    }

    fclose(fp);
    return head;
}

