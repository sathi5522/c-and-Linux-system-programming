#define MAX 100

struct manager {
	int data[MAX];
	int curr_ele;
};

typedef struct manager queue_t;

extern int push(queue_t *,int);
extern int pop(queue_t *);
extern void print(queue_t *);


