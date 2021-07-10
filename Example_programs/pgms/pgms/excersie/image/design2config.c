#define TRUE 1
#define FALSE 0

typedef struct handler {
	int (*canhandle) (char *);
	int (*drawimage) (char *);
	int (*saveimage) (char *);
}imagehandler;
extern imagehandler *imagehandlers[];
extern imagehandler gifhandler;
extern imagehandler tifhandler;
extern imagehandler jpghandler;

