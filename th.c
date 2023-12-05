#include <stdio.h>
#include <string.h>

char ft_get_line(char *lst)
{
  int i;
  char *str;

  i = 0;

  while(lst[i] != '\0' && lst[i] != '\n')
  i++;
  str = (char *)malloc(sizeof(char) * (i + 2));

  if(!str)
  {
    return NULL;
  }
  i = 0;
  while(lst[i] != '\0' && lst[i] != '\n')
  {
    str[i] = lst[i];
      i++;
  }
  if(lst[i] == '\n')
  {
    str[i] = lst[i];
    i++;
  }
  str[i] = '\0';
  return str;
}