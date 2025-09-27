#include "phoneheader.h"
#include<string.h>

PHONEBOOK *deletecontact(PHONEBOOK *head)
{
	PHONEBOOK *temp=NULL,*prev=NULL;
	char str[30];

	if(head==NULL)
	{
		printf("Phonebook is empty\n");
		return head ;
	}

	printf("Enter the contact name that you want to delete : ");
	scanf("%s",str);
	
	temp =head;

	if(strcmp(str,head->name)==0)
	{
		head=head->link;
		free(temp);
		printf("Contact deleted successfully\n");
		return head;
	}


	while(temp && (strcmp(str,temp->name))!=0)
	{
		prev=temp;
		temp=temp->link;
	}

	if(temp==NULL)
	{
		printf("Contact not found\n");
		return head;
	}

	prev->link=temp->link;
	free(temp);
	printf("Contact deleted successfully\n");

	return head;

}

