#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "timer.c"

#include "dlist.cc"

int main (int argc, char* argv[])
{
    int N = -1;
    int T = 1;
    double total_time = 0.0;

  if (argc == 2) {
    N = atoi (argv[1]);
    assert (N > 0);
  } else {
    fprintf (stderr, "usage: %s <n>\n", argv[0]);
    fprintf (stderr, "where <n> is the length of the list to sort.\n");
    return -1;
  }

    stopwatch_init ();
    struct stopwatch_t* timer = stopwatch_create (); assert (timer);

    struct ListNode* list = NULL;

    for (int i = 1; i <= N; i++)
    {
      add_to_front(&list, i);
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < T; i++)
    {
        stopwatch_start (timer);
        int num = rand() % N + 1;
        remove(&list, search_value(list, num));

        add_to_front(&list, num);

        total_time += stopwatch_stop (timer) / T;
    }

    double average_time = total_time / N;
  
    printf("Time: %.2g \n", average_time);
    printf ("\n");

    free(list);
    stopwatch_destroy (timer);
    return 0;

}
