#define MAXRESOURCES 5
int available_resources = MAXRESOURCES;
/* decrease available
resources by count resources */
/* return 0 if sufficient resources available, */
/* otherwise return -1 */
int decrease_count(int count)
{
  if (available_resources <
      count)
    return -1;
  else
  {
    available_resources -= count;
    return 0;
  }
}
/* increase available
resources by count */
int increase_count(int count)
{
  available_resources += count;
  return 0;
}