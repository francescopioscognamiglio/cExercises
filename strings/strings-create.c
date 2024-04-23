#include <stdio.h>
#include <stdlib.h>

void main() {
  // read-only strings
  char s1[] = "Hello World!";
  char *s2 = "Hello World, again!";
  printf("The first string is: %s\n", s1);
  printf("The second string is: %s\n", s2);


  // modifiable strings
  char *modS1 = malloc(sizeof(char)*20);
  modS1 = "Hello modifiable world!";
  printf("The modifiable string is: %s\n", modS1);
  modS1 = "Hello again with an updated string";
  printf("The modifiable string is: %s\n", modS1);
}
