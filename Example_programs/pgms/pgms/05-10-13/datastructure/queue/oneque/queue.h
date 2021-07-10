#define MAX 100

struct manager {
	int data[MAX];
	int curr_ele;
};

extern struct manager obj;

extern int enqueue(int);
extern int dequeue();
extern void print();

