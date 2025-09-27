#include"phoneheader.h"
#include<stdio_ext.h>
#include<string.h>

PHONEBOOK *addContact( PHONEBOOK *head)
{
	PHONEBOOK *newnode=NULL,*temp=NULL;

	newnode=calloc(1,sizeof(PHONEBOOK));
	if(newnode==NULL)
	{
		printf("Node not created\n");
		exit(0);
	}
	else
	{	
		printf("Enter the name: ");
		__fpurge(stdin);
		fgets(newnode->name, sizeof(newnode->name), stdin);
		if (newnode->name[strlen(newnode->name) - 1] == '\n')
		    newnode->name[strlen(newnode->name) - 1] = '\0';


		newnode->numbers=NULL;
		newnode->numcount=0;

		char choice ='Y';

		while(choice =='Y' || choice =='y')
		{
			newnode->numbers=realloc(newnode->numbers,(newnode->numcount+1)*sizeof(char *));
			newnode->numbers[newnode->numcount]=malloc(15*sizeof(char));

			printf("Enter the phone number : ");
			fgets(newnode->numbers[newnode->numcount],15,stdin);

			if (newnode->numbers[newnode->numcount][strlen(newnode->numbers[newnode->numcount]) - 1] == '\n')
            			newnode->numbers[newnode->numcount][strlen(newnode->numbers[newnode->numcount]) - 1] = '\0';

			newnode->numcount++;

			printf("Do you want to add another number to same contact:? (Y/N): ");
			scanf(" %c",&choice);
			while(getchar() !='\n');
		}


		printf("Enter the Gmail: ");
		fgets(newnode->gmail, sizeof(newnode->gmail), stdin);
		if (newnode->gmail[strlen(newnode->gmail) - 1] == '\n')
		    newnode->gmail[strlen(newnode->gmail) - 1] = '\0';

		printf("Enter the address: ");
		fgets(newnode->address, sizeof(newnode->address), stdin);
		if (newnode->address[strlen(newnode->address) - 1] == '\n')
		    newnode->address[strlen(newnode->address) - 1] = '\0';

		newnode->link = NULL;


		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			temp=head;
			while(temp->link)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}
	}
	return head;
}


