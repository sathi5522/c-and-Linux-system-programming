#include<stdio.h>
#include<pthread.h>

pthread_mutex_t lock;/* = PTHREAD_MUTEX_INITIALIZER;*/

int i=0;
void *even_function(void *args)
{
	
	do {
		if(i%2 == 0) {
			pthread_mutex_lock(&lock);
			printf("%d \n",i);
			i++;
			pthread_mutex_unlock(&lock);
		}
	}while(i < 10);
}
void *odd_function(void *args)
{
	do {
		if(i%2 != 0) {
			pthread_mutex_lock(&lock);
			printf("%d \n",i);
			i++;
			pthread_mutex_unlock(&lock);
		}
	}while(i < 10);
}


int main()
{
	pthread_t even_t, odd_t;
	void *retval;

	pthread_mutex_init(&lock, NULL);

	pthread_create(&even_t, NULL, even_function, NULL);
	pthread_create(&odd_t, NULL, odd_function, NULL);
	pthread_join(even_t, &retval);
	pthread_join(odd_t, &retval);

	return 0;
}
