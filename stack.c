#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>
#include <sys/_types/_sigaltstack.h>
#include <sys/signal.h>

typedef struct node
{
  int data;
  struct node * pNext;
}NODE,* PNODE;

typedef struct stack
{
  struct node * top;
  struct node * bottom;
}STACK,* PSTACK;

void initStack(PSTACK);
void push(PSTACK,int);
_Bool pop(PSTACK);
void showStack(PSTACK);
_Bool is_empty(PSTACK);

_Bool is_empty(PSTACK pStack)
{
  return (pStack->top == pStack->bottom);
}

void initStack(PSTACK pStack)
{
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  if (pNew == NULL)
    printf("Memory error");
  pNew->pNext = NULL;
  pStack->top = pNew;
  pStack->bottom = pStack->top;
  return;
}

void push(PSTACK pStack,int value)
{
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  pNew->data = value;
  pNew->pNext = pStack->top;
  pStack->top = pNew;
}

_Bool pop(PSTACK pStack)
{
  int value;
  if (is_empty(pStack))
    return 0;
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  pNew = pStack->top;
  value = pStack->top->data;
  printf("弹出的数为%d\n",value);
  pStack->top = pStack->top->pNext;
  free(pNew);
  return 1;
}

void showStack(PSTACK pStack)
{
  if (is_empty(pStack))
    {
      printf("No values\n");
      return;
    }
  PNODE pNew = pStack->top;
  while (pNew != pStack->bottom)
    {
      printf("%d ",pNew->data);
      pNew = pNew->pNext;
    }
  printf("\n");
  return;
}

int main(void)
{
  PSTACK pStack = (PSTACK)malloc(sizeof(STACK));
  initStack(pStack);
  pop(pStack);
  push(pStack,1);
  push(pStack,2);
  push(pStack,3);
  pop(pStack);
  push(pStack,4);
  push(pStack,5);
  push(pStack,6);
  showStack(pStack);
  return 0;
}
