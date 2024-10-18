#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define N 10000000000
#define THREADS 16

void* add_thread(void* arg)
{
    long long offset = (long long)(intptr_t)arg;
    long long total = 0;

    for (long long i = offset; i < N; i += THREADS) {
        total += i;
    }

    return (void*)(intptr_t)total;
}

int main()
{
    long long i;
    pthread_t tids[THREADS];
    long long total = 0;

    // 繧ｹ繝ｬ繝�ラ繧堤ｫ九■荳翫￡繧�
    for (i = 0; i < THREADS; i++) {
        pthread_create(&tids[i], NULL, add_thread, (void*)(intptr_t)i);
    }
    // 繧ｹ繝ｬ繝�ラ縺ｮ邨ゆｺ�ｒ蠕�■蜷医ｏ縺帙※縲√◎繧後◇繧後�蜷郁ｨ亥､繧貞粋邂励☆繧�
    for (i = 0; i < THREADS; i++) {
        void* ret;
        pthread_join(tids[i], &ret);
        total += (long long)(intptr_t)ret;
    }
    
    printf("total = %lld\n", total);
    return 0;
}