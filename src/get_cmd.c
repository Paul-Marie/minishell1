/*
** get_cmd.c for get_cmd.c in /home/Paul-Marie/Tek1/PSU/PSU_2016_minishell1
** 
** Made by BETTINELLI Paul-Marie
** Login   <Paul-Marie@epitech.net>
** 
** Started on  Thu Jan 19 16:01:42 2017 BETTINELLI Paul-Marie

*/

#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (0);
      i = i + 1;
    }
  return (1);
}

char	**get_cmd()
{
  char	**res;
  int	i = 5;
  int	d = 0;
  int	c = 0;

  res = malloc(sizeof(char *) * (84));
  res[c] = malloc(sizeof(char) * (1024));
  for(int j = 0; j != 1024; j++)
	  res[c][j] = '\0';
  while (environ[get_line()][i] != '\0')
    {
      if (environ[get_line()][i] == ':' || environ[get_line()][i] == '\0')
	{
	  res[c][d] = '/';
	  res[c++][d + 1] = '\0';
	  i = i + 1;
	  d = 0;
	  res[c] = malloc(sizeof(char) * (1024));
	  for(int j = 0; j != 1024; j++)
		  res[c][j] = '\0';
	}
      res[c][d++] = environ[get_line()][i++];
    }
  res[c][d] = '/';
  res[c] = NULL;
  return (res);
}
