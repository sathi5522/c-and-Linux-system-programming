
struct msg {

		int val;
		struct msg *prev;
		struct msg *next;
		};
typedef struct msg que_t;

extern int enque_last(que_t **,int);
extern void print(que_t *);
extern int delete_first(que_t **);
extern void error_msg(char *s);
