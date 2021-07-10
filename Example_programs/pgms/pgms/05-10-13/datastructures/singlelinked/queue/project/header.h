
typedef struct node {
		int data;
		struct node *next;
} queue_t ;

extern int insert_first(queue_t **, int );
extern int delete_first( queue_t**);
extern int print(queue_t *);


