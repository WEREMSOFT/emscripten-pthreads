#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* my_turn(void* param) {
    int *i = (int *)param;

    for(*i = 0; *i < 1000000000; (*i)++){
    }
    return NULL;
}

int main() {
    pthread_t my_t, your_t, a_t, b_t;

    int y, m, a, b;

    y = m = b = a = 0;
    #ifdef __EMSCRIPTEN_PTHREADS__
    printf("Threads ARE supported!!!\n");

    pthread_create(&my_t, NULL, my_turn, &m);
    pthread_create(&your_t, NULL, my_turn, &y);
    pthread_create(&a_t, NULL, my_turn, &a);
    pthread_create(&b_t, NULL, my_turn, &b);

    pthread_join(my_t, NULL);
    pthread_join(your_t, NULL);
    pthread_join(a_t, NULL);
    pthread_join(b_t, NULL);
    #else
    printf("Threads NOT supported!!!\n");
    #endif
//    my_turn(&m);
//    my_turn(&y);
//    my_turn(&a);
//    my_turn(&b);


    printf("mine value %d\n", m);
    printf("yours value %d\n", y);
    printf("mine value %d\n", a);
    printf("yours value %d\n", b);


    return 0;
}
