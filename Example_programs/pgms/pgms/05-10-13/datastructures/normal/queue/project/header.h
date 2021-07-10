#define MAX 100
typedef struct manager{

		int data[MAX];
		int cur;
} queue_t ;


extern int enqueue (queue_t *, int);
extern int dequeue (queue_t *);
extern int print (queue_t *);
extern errorno(int );

#define QFULL -1
#define QEMTY -2
#define SUCCESS 0

