
typedef struct msg que_t;

struct msg {

		int val;
		que_t *next;
	};

extern int insert_last(que_t **,int);
//extern int delete_first(que_t **);
extern int delere_arg(que_t **,int);
extern void print(que_t *);

