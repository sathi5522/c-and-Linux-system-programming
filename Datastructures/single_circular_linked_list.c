struct list {
	char buff[256];
	struct list *next;
};

struct list *start=NULL, *var;
int insert(char *data) {
	struct list *new, *tmp;

	new = malloc(sizeof(struct list));
	if(new == NULL){
		printf("malloc failed\n");
		return;
	}
	if(data != NULL) {
		strcpy(new->buff, data);			log
	} else {
		printf("data is NUUL");
		free(new);
		return;
	}
	if(start == NULL){
		start= new;
		start->next = start;
		return;
	}
	tmp = start;
	while(tmp){
		if(tmp->next == start) {
			tmp->next = new;
			new->next = start;
			break;
		}
		tmp = tmp->next;
	}
	var = new;
	
}

int remove() {
	struct list *tmp, *tm;
	tmp = start;
	while(tmp){
		if(tmp->next == start)
			break;
		tmp = tmp->next;
	}
	if(start != NULL) {
		if(start->next == start) {
			free(start);
			start = NULL;
		} else {
			tm = start;
			start = start->next;
			tmp->next =start; // var->next = start;
			free(tm);
		}
	}
	
}
