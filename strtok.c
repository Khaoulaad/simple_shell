#include "shell.h"
char* _strtok(char* str, const char* d)
{
  static char* lastToken = NULL;
  char* token;
  int i, j;
  bool isDelimiter;

  if (str == NULL)
    str = lastToken;
  else
    lastToken = str;

  while (*str != '\0')
  {
    isDelimiter = false;
    for (i = 0; d[i] != '\0'; i++)
    {
      if (*str == d[i])
      {
        isDelimiter = true;
        break;
      }
    }

    if (!isDelimiter)
      break;

    str++;
  }

  if (*str == '\0')
    return NULL;

  token = str;
  while (*str != '\0')
  {
    isDelimiter = false;
    for (i = 0; d[i] != '\0'; i++)
    {
      if (*str == d[i])
      {
        isDelimiter = true;
        break;
      }
    }

    if (isDelimiter)
    {
      int tokenLength = str - token;
      char* newToken = (char*)malloc((tokenLength + 1) * sizeof(char));
      if (newToken == NULL)
      {
        return NULL;
      }
      for (j = 0; j < tokenLength; j++)
        newToken[j] = token[j];
      newToken[j] = '\0';

      lastToken = str + 1;
      return newToken;
    }

    str++;
  }

  return token;
}
