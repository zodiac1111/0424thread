#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
struct st {
	int a;
	int b;
};
static pthread_mutex_t mtx;
//static long x=0;
static void *mythread(void *arg)
{
	struct st *pp;
	pp=(struct st *)arg;
	while (pp->a) {
		sleep(1);
	//	pthread_mutex_lock(&mtx);
		printf("in thread %d,value= %d\n", pp->a,pp->b);
	//	pthread_mutex_unlock(&mtx);
	}
	sleep(20);
	return NULL;
}

int main(int argc, char *argv[])
{
	int i;
	i = 1;
	struct st *st1;
	struct st a;
	void *status;
	st1=&a;
	st1->a=10;
	st1->b=999;
	pthread_t tid,tid2;
	pthread_create(&tid, NULL, mythread, (void *)st1);
	while(st1->a--){
		printf("main say: a=%d\n",st1->a);
		sleep(1);
	}
//	sleep(2);
//	st1->a=2;
//	st1->b=888;
//	pthread_create(&tid2, NULL, mythread, (void *)st1);
	pthread_join(tid,&status);
	printf("thread exit with id %ld\n",(long)status);
	//sleep(10);
	return 0;
}
