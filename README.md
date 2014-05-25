# Linux下C语言实现线程池


> * pthread线程
> * 构造双向链表维持任务队列
> * 使用线程信号量sem_t控制线程池
> * 使用线程互斥锁pthread_mutex_t保护任务队列


## 编译说明
The library is not precompiled so you have to compile it with your project. The thread pool
uses POSIX threads so if you compile with gcc you have to use the flag -pthread like this:

  <code>gcc main.c thpool.c -pthread -o test</code>


Then run the executable like this:

  <code>./test</code>



## 使用说明

1. Make a thread pool: <code>thpool_t* thpool;</code>
2. Initialise the thread pool with number
   of threads(workers) you want:             <code>thpool=thpool_init(N);</code>
3. Add work to the pool:                     <code>thpool_add_work(thpool, (void*)doSth, (void*)arg);</code>
4. Destroy pool:                             <code>thpool_destroy(thpool);</code>




## 内部实现

### 任务队列的结点结构
双向链表保存所需完成的任务。每个任务是要执行的函数和函数的参数。

    typedef struct thpool_job_t{

        void*  (*function)(void* arg);    
    
        void*                     arg;    
    
	    struct thpool_job_t*     next;   
	
	    struct thpool_job_t*     prev;  
	
    }thpool_job_t;
    
### 任务队列结构体
包括队列头结点，尾结点，任务个数，任务信号量。

    typedef struct thpool_jobqueue{

	    thpool_job_t *head;          
	
	    thpool_job_t *tail;         
	
	    int           jobsN;        
	
	    sem_t        *queueSem;                            
	
    }thpool_jobqueue;

### 线程池结构体
包含指向各个线程的指针数组，线程个数，任务队列。
    typedef struct thpool_t{

    	pthread_t*       threads;   
	
	    int              threadsN;   
	
	    thpool_jobqueue* jobqueue;   
	
    }thpool_t;




====== 
**Forked from Johan Hanssen Seferidis**

May. 2014
