#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) { /* omp_schedule.c  */
int n = 2000000;

double inicio1 = omp_get_wtime();

    printf("Cláusula static SEM o parâmetro tamanho \n");
#pragma omp parallel for schedule (static) num_threads(4)
    for (int i = 0; i < n; ++i) {
	    // printf("tid =%d iteracao = %d \n", omp_get_thread_num(),i);
    }

double final1 = omp_get_wtime();
printf("tempo decorrido: %f\n", final1 - inicio1);

double inicio2 = omp_get_wtime();

    printf("Cláusula static COM o parâmetro tamanho \n");
#pragma omp parallel for schedule (static,3) num_threads(4)
    for (int i = 0; i < n; ++i) {
	    // printf("tid =%d iteracao = %d \n", omp_get_thread_num(),i);
    }

double final2 = omp_get_wtime();
printf("tempo decorrido: %f\n", final2 - inicio2);

    return 0;
}