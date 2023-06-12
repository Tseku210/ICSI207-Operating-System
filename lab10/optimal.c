#include <stdio.h>

int main()
{
  int referenceString[20] = {7, 2, 3, 1, 2, 5, 3, 4, 6, 7, 7, 1, 0, 5, 4, 6, 2, 3, 0, 1};
  int pageFaults = 0, frames = 3, i, j, count, temp[frames], check[3], k, s, max, pos = 0;
  for (i = 0; i < frames; i++)
  {
    temp[i] = -1;
  }
  for (i = 0; i < 20; i++)
  {
    count = 0;
    for (j = 0; j < frames; j++)
    {
      if (referenceString[i] == temp[j])
      {
        count++;
        pageFaults--;
      }
    }
    pageFaults++;
    if (pageFaults <= frames && count == 0)
    {
      temp[i] = referenceString[i];
      printf("\n");
      for (j = 0; j < frames; j++)
      {
        printf("%d\t", temp[j]);
      }
    }
    else if (count == 0)
    {
      for (j = 0; j < frames; j++)
      {
        s = 0;
        for (k = i + 1; k < 20; k++)
        {
          if (temp[j] == referenceString[k])
          {
            check[j] = s;
            break;
          }
          else if (temp[j] != referenceString[k])
          {
            check[j] = s + 1;
          }
          s++;
        }
      }
      max = check[0];
      for (j = 0; j < frames; j++)
      {
        if (max < check[j])
        {
          max = check[j];
          pos = j;
        }
      }
      temp[pos] = referenceString[i];
      printf("\n");
      for (j = 0; j < frames; j++)
      {
        printf("%d\t", temp[j]);
      }
    }
  }
  printf("\nPageFaults: %d\n", pageFaults);
  return 0;
}