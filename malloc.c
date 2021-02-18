#include <stdio.h>
#include <mm_malloc.h>

struct Student
{
  int age;
  char name[10];
};


int main(void)
{
  int len;
  printf("input\n");
  scanf("%d",&len);
  struct Student *pointer = (struct Student *)malloc(sizeof(struct Student)*len);
  printf("%p",pointer);
}

