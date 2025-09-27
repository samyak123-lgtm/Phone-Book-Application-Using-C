#include "phoneheader.h"

void displayContacts(PHONEBOOK *head)
{
	if(head==NULL)
	{
		printf("No contacts found\n");
		return ;
	}
	PHONEBOOK *temp =head;

	while(temp)
	{
		printf("Name : %s\n",temp->name);
		for(int i=0;i<temp->numcount;i++)
		{
			printf("Phone no[%d]: %s\n",i+1,temp->numbers[i]);
		}

		printf("Gmail : %s\n",temp->gmail);
		printf("Address :%s\n",temp->address);
		printf("\n");


		temp=temp->link;
	}
}

