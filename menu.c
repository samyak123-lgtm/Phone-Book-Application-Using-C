#include<stdio_ext.h>
#include "phoneheader.h"

int main()
{
	PHONEBOOK *head=NULL;
	char choice;
	head=Syncfromfile(head);
	while(1)
	{
		printf("\nc/C:Create a new contact\np/P:Print all contacts\nd/D:Delete contact\nf/F:Find contact\ne/E:Edit contact\ns/S:To save the contacts in the file\nq/Q:Quit from the app\n");
		printf("\nEnter the choice :  ");
		__fpurge(stdin);
		scanf("%c",&choice);
		printf("\n");

		switch(choice)
		{
			case 'C': case 'c': head=addContact(head);
					 break;
			case 'P': case 'p': displayContacts(head);
					 break;
			case 'D': case 'd': head=deletecontact(head);
					 break;
			case 'F': case 'f': findcontact(head);
					 break;
			case 'S': case 's':save(head);
					 break;
			case 'E': case 'e':head=edit(head);
					 break;
			case 'Q': case 'q': return 0;
					 break;
			default :printf("Invalid choice\n");
		}
	}
}


