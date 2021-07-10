
#define SUCCESS        0
#define LIST_EMPTY    -1
#define NOTFOUND      -2
#define MALLOC_FAILED -3


struct msg {

		int val;
		struct msg *prev;
		struct msg *next;
		};

typedef struct msg dlist_t;

extern int insert(dlist_t **,int);
extern void print(dlist_t *);
extern int delete_arg(dlist_t **,int);
extern void error_msg(char *);
