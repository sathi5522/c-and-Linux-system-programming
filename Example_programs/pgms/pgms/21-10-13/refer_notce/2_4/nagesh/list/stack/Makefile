#target name = printoutput
output :  stackout
		./stackout

stackout : user.c stacklib.so
		gcc  user.c ./stacklib.so -o stackout


	


stacklib.so:   insert_first.o delete_last.o print.o 
		gcc -shared insert_first.o delete_last.o print.o -o stacklib.so	
insert_first.o :
		gcc -c insert_first.c
delete_last.o:
		gcc -c delete_last.c
print.o : 
		gcc -c print.c
      
	     
		

