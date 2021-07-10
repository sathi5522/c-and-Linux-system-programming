struct playhandler {
			int (*canhandle) (const char *);
			void (*play) (const char *);
			void (*convert) (const char *);
		     };

extern struct playhandler mp3handler;
extern struct playhandler mp4handler;
extern struct playhandler flvhandler;

extern void vplay(const char *);
extern void convert(const char *);
