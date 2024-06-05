#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    int i, myid, n = 10000;
    float a[n][4];

    #pragma omp parallel num_threads(4) private(i, myid) shared(a, n)
    {
        myid = omp_get_thread_num();

        for (i = 0; i < n; i++){
            a[i][myid] = i + 1.0;
            printf("%f - %d\n", a[i][myid], myid);
        }
    }

    /* end parallel*/

}