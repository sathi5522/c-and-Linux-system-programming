#define SUCCESS 0
#define LISTEMPTY -1
#define MALLOC_FAILED -2
struct msg{
		int val;
		struct msg *prev;
		struct msg *next;
		};
typedef struct msg stack_t;

extern int dlist_push(stack_t **, int);

extern void print(stack_t*);

extern int delete_first(stack_t **);

extern void delete_duplicate(stack_t **);
