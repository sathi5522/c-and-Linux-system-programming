#define MAX 100

typedef struct manager{
	int data[MAX];
	int curr;
}stack_t ;

extern int push(stack_t *, int );
extern int pop(stack_t *);
extern int print(stack_t *);
extern int peek(stack_t *);
extern int stack_init(stack_t *);



