#include"phoneheader.h"
#include<string.h>

void findcontact(PHONEBOOK *head)
{
	PHONEBOOK *temp=NULL;
	char str[30];
	int cnt=0;

	if(head==NULL)
	{
		printf("Phonebook is empty\n");
		return ;
	}

	temp = head;

	printf("Enter the name that you wanted to find ; ");
	scanf("%s",str);

	while(temp)
	{
		if(strcmp(str,temp->name)==0)
		{
			printf("The entered contact found at index %d\n",cnt);
			return ;
		}
		cnt++;
		temp=temp->link;
	}
	printf("Contact not found\n");
}


