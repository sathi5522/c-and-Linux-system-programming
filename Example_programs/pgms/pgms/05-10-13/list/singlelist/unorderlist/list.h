struct node {
        int data;
        struct node *next;
};

extern struct node *start;
extern int insert_first(struct node **,int);
extern int insert_last(struct node **,int);
extern int delete_first(struct node **);
extern int delete_last(struct node **);
extern int print(struct node **);
extern int dup_del(struct node **);


