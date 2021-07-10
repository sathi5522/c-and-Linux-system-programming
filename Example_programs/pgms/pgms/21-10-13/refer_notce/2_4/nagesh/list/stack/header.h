typedef struct msg stack_t;

	struct msg {
		int val;
		stack_t *next;
	};

extern int insert_first(stack_t **,int);
extern void  print(stack_t *);
//extern int delete_first(stack_t **);
extern int delete_last(stack_t **);
