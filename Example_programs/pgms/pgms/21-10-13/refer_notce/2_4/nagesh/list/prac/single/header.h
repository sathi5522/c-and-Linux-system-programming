
#define SUCCESS 0
#define MALLOC_FAILED -1
#define EMPTYLIST -2




struct arr {

		void  *data;
		struct arr *next;
	};

typedef struct arr q_list;
int insert_first(q_list **, void  *);
 int insert_last(q_list **, void *);
 void print(q_list *);
int delete_first(q_list **);
int delete_last(q_list **);
void error_msg(char *);

