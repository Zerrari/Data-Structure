#include <stdio.h>
#include <string.h>

struct Student
{
  int age;
  char name[20];
};

int main(void)
{
  struct Student st = {20,"1234"};
  strcpy(st.name,"1234");    

  struct Student *point;

  point = &st;
  
  point->age = 20;
  
  printf("%d,%s",st.age,st.name);
}
