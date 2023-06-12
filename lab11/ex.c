#include <stdio.h>
#include <stdlib.h>

#define CYLINDERS 5000
#define REQUESTS 1000

int start = 0;

int ran_array[REQUESTS];

int *sort_array()
{

  int temp = 0, i = 0, j = 0;

  for (i = 0; i < REQUESTS; ++i)
  {

    for (j = i + 1; j < REQUESTS; ++j)
    {

      if (ran_array[i] > ran_array[j])
      {

        temp = ran_array[i];
        ran_array[i] = ran_array[j];
        ran_array[j] = temp;
      }
    }
  }

  return ran_array;
}

int fcfs(int *ran, int start)
{

  int i = 0, head_movement = 0;

  for (i = 0; i < REQUESTS; i++)
  {
    head_movement += abs(ran_array[i] - start);
    start = ran[i];
  }

  return head_movement;
}

int scan(int *a, int headposition)
{
  int queue[2000], i, j, k, sum = 0,
                            temp, queue1[1000], queue2[1000], temp1 = 0, temp2 = 0;
  for (i = 1; i <= REQUESTS; i++)
  {
    if (a[i] > headposition)
    {
      queue1[temp1] = a[i];
      temp1++;
    }
    else
    {
      queue2[temp2] = a[i];
      temp2++;
    }
  }
  for (i = 0; i < temp1 - 1; i++)
  {
    for (j = i + 1; j < temp1; j++)
    {
      if (queue1[i] > queue1[j])
      {
        temp = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp;
      }
    }
  }
  for (i = 0; i < temp2 - 1; i++)
  {
    for (j = i + 1; j < temp2; j++)
    {
      if (queue2[i] < queue2[j])
      {
        temp = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp;
      }
    }
  }

  for (i = 1, j = 0; j < temp1; i++, j++)
  {
    queue[i] = queue1[j];
  }

  queue[i] = CYLINDERS;

  for (i = temp1 + 2, j = 0; j < temp2; i++, j++)
  {
    queue[i] = queue2[j];
  }
  queue[i] = 0;
  queue[0] = headposition;

  for (j = 0; j <= REQUESTS; j++)
  {
    sum += abs(queue[j + 1] - queue[j]);
  }

  return sum;
}

int cscan(int *a, int headposition)
{
  int queue[2000], i, j, k, sum = 0,
                            temp, queue1[1000], queue2[1000], temp1 = 0, temp2 = 0;
  for (i = 1; i <= REQUESTS; i++)
  {
    if (a[i] > headposition)
    {
      queue1[temp1] = a[i];
      temp1++;
    }
    else
    {
      queue2[temp2] = a[i];
      temp2++;
    }
  }
  for (i = 0; i < temp1 - 1; i++)
  {
    for (j = i + 1; j < temp1; j++)
    {
      if (queue1[i] > queue1[j])
      {
        temp = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp;
      }
    }
  }
  for (i = 0; i < temp2 - 1; i++)
  {
    for (j = i + 1; j < temp2; j++)
    {
      if (queue2[i] > queue2[j])
      {
        temp = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp;
      }
    }
  }
  for (i = 1, j = 0; j < temp1; i++, j++)
  {
    queue[i] = queue1[j];
  }
  queue[i] = CYLINDERS;
  queue[i + 1] = 0;
  for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
  {
    queue[i] = queue2[j];
  }
  queue[0] = headposition;
  for (j = 0; j <= REQUESTS + 1; j++)
  {
    sum += abs(queue[j + 1] - queue[j]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  int i;
  for (i = 0; i < REQUESTS; i++)
  {

    ran_array[i] = rand() % 5000 + 1;
  }

  while (1)
  {
    printf("\nТолгойн эхний байрлал: ");
    scanf("%d", &start);
    printf("\nЭхлэл индэкс: %d\n\n", start);

    printf("FCFS: %d\n", fcfs(ran_array, start));
    printf("SCAN: %d\n", scan(ran_array, start));
    printf("CSCAN: %d\n", cscan(ran_array, start));
  }

  return 0;
}