// a) Data involved in race condition is available_resources
// b) Location where race condition takes place is decrease_count & increase_count
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_RESOURCES 5

pthread_t tid[MAX_RESOURCES];
int counter;
pthread_mutex_t lock;
int available_resources = MAX_RESOURCES;

int decrease_count(int count)
{
  if (available_resources < count)
  {
    return -1;
  }
  else
  {
    available_resources -= count;
    return 0;
  }
}

int increase_count(int count)
{
  available_resources += count;
  return 0;
}

void *thread_func(void *arg)
{
  pthread_mutex_lock(&lock);
  unsigned long i = 0;
  counter += 1;
  printf("\n Thread %d has started\n", counter);
  // increase_count()
  for (i = 0; i < (0xFFFFFFFF); i++)
    ;
  printf("\n Thread %d has finished\n", counter);

  pthread_mutex_unlock(&lock);

  return NULL;
}

int main(void)
{
  int i = 0;
  int error;

  pthread_mutex_init(&lock, NULL);
  while (i < MAX_RESOURCES)
  {
    error = pthread_create(&(tid[i]), NULL, &thread_func, NULL);
    if (error != 0)
      printf("\nThread can't be created : [%s]", strerror(error));
    i++;
  }

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  return 0;
}