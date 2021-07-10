
struct node{
	
	int val;
	struct node *next;

	};
typedef struct node list_t;

extern int  insert(list_t **, int val);
extern void print(list_t *);
extern int delere_arg(list_t **,int val); 
extern void rev_print(list_t *);
extern list_t * middle(list_t **);
extern int delet(list_t  **);
extern int del_ref(list_t*);
