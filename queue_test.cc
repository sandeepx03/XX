#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "timer.c"

#include "queue.cc"

int main (int argc, char* argv[])
{
    int N = -1;
    int T = -1;
    double total_time = 0.0, average_time = 0.0;

  if (argc == 3) {
    N = atoi (argv[1]);
    T = atoi (argv[2]);
    assert (N > 0);
    assert (T > 0);
  } else {
    fprintf (stderr, "usage: %s <n>\n", argv[0]);
    fprintf (stderr, "where <n> is the length of the list to sort.\n");
    return -1;
  }

    stopwatch_init ();
    struct stopwatch_t* timer = stopwatch_create (); assert (timer);

    struct Queue *q = createQueue();
    float num;
    for (int i = 0; i < N; i++)
    {
      num = lrand48();
      enqueue(q, num);
    }

    for (int i = 0; i < T; i++)
    {
        stopwatch_start (timer);
        num = dequeue(q);
        enqueue(q, num);
        total_time += stopwatch_stop (timer) / N;
    }

    average_time = total_time;

    printf("Average time: %.2g \n", average_time);
    printf ("\n");

    free(q);
    stopwatch_destroy (timer);
    return 0;

}

