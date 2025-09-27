a.out:addcontact.o deletecontact.o menu.o findcontact.o displaycontact.o save.o sync.o edit.o
	cc addcontact.o deletecontact.o menu.o findcontact.o displaycontact.o save.o sync.o edit.c

addcontact.o:addcontact.c
	cc -c addcontact.c
deletecontact.o:deletecontact.c
	cc -c deletecontact.c
menu.o:menu.c
	cc -c menu.c
displaycontact.o:displaycontact.c
	cc -c displaycontact.c
findcontact.o:findcontact.c
	cc -c findcontact.c
save.o:save.c
	cc -c save.c
sync.o:sync.c
	cc -c sync.c
edit.o:edit.c
	cc -c edit.c	

