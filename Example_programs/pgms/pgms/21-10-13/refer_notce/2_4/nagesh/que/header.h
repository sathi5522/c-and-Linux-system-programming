
#define MAX 50
#define FULL -1
#define EMPTY -2
struct msg {
		int curr_num;
		int number[MAX];
	};

typedef struct msg queue_t;

extern int   enqueue(struct msg *,int);
extern int   dequeue(struct msg *);
extern void  error_msg(char *);
//extern int error_no;
