#include<stdio.h>
#include<stdlib.h>

typedef struct phonebook
{
	char name[20];
	char **numbers;
	int numcount;
	char gmail[40];
	char address[50];
	struct phonebook *link;
}PHONEBOOK;

PHONEBOOK *addContact( PHONEBOOK *);
void displayContacts(PHONEBOOK *);
PHONEBOOK *deletecontact(PHONEBOOK *);
void findcontact(PHONEBOOK *);
void save(PHONEBOOK *);
PHONEBOOK *Syncfromfile(PHONEBOOK *);
PHONEBOOK *edit(PHONEBOOK *);

