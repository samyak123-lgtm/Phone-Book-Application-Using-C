#include "phoneheader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void save(PHONEBOOK *head) 
{
    FILE *fp;
    int i;
    int size = sizeof(PHONEBOOK) - sizeof(PHONEBOOK *);

    if (head == NULL) 
    {
        printf("Phonebook is empty\n");
        return;
    }

    fp = fopen("phonebook.txt", "wb");  // ✅ Use binary mode
    if (fp==NULL) 
    {
        printf("file not found\n");
        return;
    }

    while(head) 
    {
        // **Save main contact details**
        fwrite(head, size, 1, fp);  

        // **Save phone numbers one by one**
        for (i = 0; i < head->numcount; i++) 
	{
            fwrite(head->numbers[i], 15, 1, fp);
        }

        head = head->link;
    }

    fclose(fp);
    printf("Phonebook saved successfully!\n");
}

