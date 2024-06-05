#include <stdio.h>  
#include <omp.h>  
 
int main(int argc, char *argv[]) {  /* omp_numthreads.c  */

   int nthreads, tid;

   printf("Fora = %d\n", omp_in_parallel( ));
   printf("Número de processadores = %d\n", omp_get_num_procs( ));
   #pragma omp parallel private(nthreads, tid) 
   {  
  	    int tid = omp_get_thread_num(); 
  	    printf("Olá da thread %d\n", tid);
        printf("Dentro = %d\n", omp_in_parallel( ));

        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("num de threads = %d\n", nthreads);
        } 
   }
   return(0);
}