
struct node{
	
	int val;
	struct node *next;

	};
typedef struct node list_t;

extern int  insert(list_t **, int val);
extern void print(list_t *);
extern int delere_arg(list_t **,int val); 

