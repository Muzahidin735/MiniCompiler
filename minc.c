#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE  1000

void push(char);
int pop(void);
int getline(FILE *);

#define MAXCHAR  1000
double no_of_lines = 0;
char line[MAXCHAR];


int main(void)
{
  char comment[1000];
  int c;
  int i = 0;
  FILE *fp = fopen("sh.c","r");
  while ((c = getc(fp)) != EOF)
  {
    getline(fp);
    printf("%s\n",line);
  }
#if 0
     if (c == '\n')
      {
	no_of_lines++;
      }
    if (c == '#')
      {
	c = getc(fp);
	if ((c != 'd' || c != 'i'))
	  {
	    printf("ERROR in line = %.0f\n", no_of_lines);
	  }
      }
    else if (c == '/')
      {
	if ((c = getc(fp)) == '*')
	  {
	    while (i < 999 && (c = getc(fp)) != '*')
	      {
		if (c == '\n')
		  {
		    no_of_lines++;
		  }
		comment[i++] = c;
	      }
	  }
	else if (c  == '/')
	  {
	    while ((c = getc(fp)) != '\n')
	      {
		comment[i++] = c;
	      }
	    no_of_lines++;
	    comment[i++] = c;
	  }
      }
    else if (c == '(' || c == '{')
      {
	push(c);
      }
    else if (c == ')' || c == '}')
      {
	pop();
      }
    /* else if (c == ';')
      {
	if ((c = getc(fp)) != '\n')
	{
	  printf("ERROR: missing ';' in line %.0f\n", no_of_lines);
	  exit(2);
	}
	no_of_lines++;
      }*/
    
  }
  comment[i] = '\0';
  extern int p;
  if (p > 0)
    {
      printf("ERROR: expected ')' OR '}' in line %.0f\n",no_of_lines);
      exit(1);
    }
  //printf("%s\n",comment);
#endif
  fclose(fp);
  return 0;
}
char stack[STACKSIZE];
int p = 0;
void push(char c)
{
  stack[p++] = c;
}
int pop(void)
{
  if (!p)
    {
      printf( "ERROR:  missing '(' OR '{' in line %.0f\n",no_of_lines);
    }
  else
      return stack[--p];
}
int getline(FILE *fp)
{
  int c, i;
  for ( i = 0 ; i < MAXCHAR - 1 && (c = getc(fp)) != '\n' && c != EOF; i++)
    {
      line[i] = c;
    }
  if (c == '\n')
    {
      line[i++] = c;
    }
  line[i] = '\0';
  return i + 1;
}
