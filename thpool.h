#ifndef _THPOOL_

#define _THPOOL_

#include <pthread.h>
#include <semaphore.h>


/* Individual job */
typedef struct thpool_job_t{
	void*  (*function)(void* arg);                     /**< function pointer         */
	void*                     arg;                     /**< function's argument      */
	struct thpool_job_t*     next;                     /**< pointer to next job      */
	struct thpool_job_t*     prev;                     /**< pointer to previous job  */
}thpool_job_t;


/* Job queue as doubly linked list */
typedef struct thpool_jobqueue{
	thpool_job_t *head;                                /**< pointer to head of queue */
	thpool_job_t *tail;                                /**< pointer to tail of queue */
	int           jobsN;                               /**< amount of jobs in queue  */
	sem_t        *queueSem;                            /**< semaphore(this is probably just holding the same as jobsN) */
}thpool_jobqueue;


/* The threadpool */
typedef struct thpool_t{
	pthread_t*       threads;                          /**< pointer to threads' ID   */
	int              threadsN;                         /**< amount of threads        */
	thpool_jobqueue* jobqueue;                         /**< pointer to the job queue */
}thpool_t;



thpool_t* thpool_init(int threadsN);

void thpool_thread_do(thpool_t* tp_p);

int thpool_add_work(thpool_t* tp_p, void*(*function_p)(void *), void* arg_p);

void thpool_destroy(thpool_t* tp_p);




int thpool_jobqueue_init(thpool_t* tp_p);

void thpool_jobqueue_add(thpool_t* tp_p,thpool_job_t* newjob_p);

int thpool_jobqueue_removelast(thpool_t* tp_p);

thpool_job_t* thpool_jobqueue_peek(thpool_t* tp_p);

void thpool_jobqueue_empty(thpool_t* tp_p);




#endif
