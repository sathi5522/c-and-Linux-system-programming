
struct msg {
		int val;
		struct msg *prev;
		struct msg *next;
	};
typedef struct msg dlist_t;

extern int insert(dlist_t**,int);

extern void print(dlist_t *);
		
