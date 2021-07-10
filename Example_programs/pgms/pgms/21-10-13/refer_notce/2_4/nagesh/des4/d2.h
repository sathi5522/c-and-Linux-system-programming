void tif_open(char *);
void tif_convert(char *);
void jpg_open(char *);
void jpg_open(char *);
void gif_convert(char *);
void gif_convert(char *);
  struct image{

        int (* handle)(char *);
        void (* open)(char *);
        void (* convert)(char *);
        };

extern struct image gifhandle;
extern struct image tifhandle;
extern struct image jpghandle;
extern struct image *ih[10];
extern int no_lib;

extern void register_handle(struct image *);

