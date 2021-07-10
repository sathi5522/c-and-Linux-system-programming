#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{

	float ret = 0;
	
	while(argc--){
		
		ret = ret + atof(argv[argc]);
		
		}

	printf("%lf",ret);
	return 0;
}
