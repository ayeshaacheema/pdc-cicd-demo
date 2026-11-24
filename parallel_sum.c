#include <stdio.h>
#include <omp.h>

int main(void) {
    const long long N = 100000000LL;
    long long sum = 0;
    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long long i = 1; i <= N; i++) {
        sum += i;
    }

    double elapsed = omp_get_wtime() - start;
    long long expected = N * (N + 1) / 2;

    printf("Threads available: %d\n", omp_get_max_threads());
    printf("Parallel sum = %lld\n", sum);
    printf("Expected     = %lld\n", expected);
    printf("Time         = %.4f s\n", elapsed);

    if (sum == expected) {
        printf("RESULT: PASS\n");
        return 0;
    }
    printf("RESULT: FAIL\n");
    return 1;
}
