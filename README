# Linux下C语言实现线程池
------
> * pthread线程
> * 使用线程信号量


## 编译
The library is not precompiled so you have to compile it with your project. The thread pool
uses POSIX threads so if you compile with gcc you have to use the flag -pthread like this:

  gcc main.c thpool.c -pthread -o test


Then run the executable like this:

  ./test



## 使用

1. Make a thread pool:                       thpool_t* thpool;
2. Initialise the thread pool with number
   of threads(workers) you want:             thpool=thpool_init(4);
3. Add work to the pool:                     thpool_add_work(thpool, (void*)doSth, (void*)arg);
4. Destroy pool:                             thpool_destroy(thpool);


## Threadpool Interface


NAME
     thpool_t* thpool_init(int num_of_threads);

SYNOPSIS
  
     #include <thpool.h>

     thpool_t* thpool_init(int num_of_threads);

DESCRIPTION

     Initialises the threadpool. On success a threadpool structure is returned. Otherwise if memory could not be allocated NULL is returned. The argument which is the number of threads in the threadpool should be a thoughfull choice. A common suggestion is to use as many threads as the ones supported by your cpu.

     Example:
     thpool_t* myThreadpool;                 //First we declare a threadpool
     myThreadpool=thpool_init(4);            //then we initialise it to 4 threads




====== 
**Forked from Johan Hanssen Seferidis**
May. 2014
