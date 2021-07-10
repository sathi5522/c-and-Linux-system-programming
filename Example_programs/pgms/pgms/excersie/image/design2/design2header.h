struct imagehandler {
	int (*canhandle) (const char *);
	void (*drawimage) (const char *);
	void (*saveimage) (const char *);
};

extern struct imagehandler gifhandle;
extern struct imagehandler tifhandle;
extern struct imagehandler jpghandle;

extern void vdrawimage(const char *);
extern void vsaveimage(const char *);
