	
struct imagehandler{
	int(*canhandle)(const char *);
	void(*displayimage)(const char *);
	void(*saveimage)(const char *);
};
extern struct imagehandler *handlers[10];
extern void reg_handler(struct imagehandler *);
extern int no_libs;
extern void load_handlers(void);

extern struct imagehandler gifhandler;
extern struct imagehandler tifhandler;
extern struct imagehandler jpghandler;

extern void vdisplayimage(const char *);
extern void vsaveimage(const char *);
