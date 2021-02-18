#include <stdio.h>
#include <mm_malloc.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct queue
{
  int value[MAX_SIZE];
  int front;
  int rear;
}QUEUE,* PQUEUE;

_Bool push(PQUEUE,int);
_Bool pop(PQUEUE );
_Bool is_empty(PQUEUE);
_Bool is_full(PQUEUE);
void initQueue(PQUEUE);
void show_queue(PQUEUE);

void initQueue(PQUEUE pQueue)
{
  pQueue->front = 0;
  pQueue->rear = 0;
}

_Bool is_empty(PQUEUE pQueue)
{
  return pQueue->rear == pQueue->front;
}

_Bool is_full(PQUEUE pQueue)
{
  return (pQueue->rear + 1) % MAX_SIZE == pQueue->front;
}

_Bool push(PQUEUE pQueue,int nums)
{
  if (is_full(pQueue))
    return 0;
  pQueue->value[pQueue->rear] = nums;
  pQueue->rear = (pQueue->rear + 1) % MAX_SIZE;
  return 1;
}

_Bool pop(PQUEUE pQueue)
{
  if (is_empty(pQueue))
    return 0;
  printf("弹出的值为%d\n",pQueue->value[pQueue->front]);
  pQueue->front= (pQueue->front + 1) % MAX_SIZE;
  return 1;
}

void show_queue(PQUEUE pQueue)
{
  int pos = pQueue->front;
  if(is_empty(pQueue))
    printf("队列为空\n");
  while (pos != pQueue->rear)
    {
      printf("%d ",pQueue->value[pos]);
      pos = (pos + 1) % MAX_SIZE;
    }
  printf("\n");
}

int main(void)
{
  PQUEUE pQueue = (PQUEUE)malloc(sizeof(QUEUE));
  initQueue(pQueue);
  push(pQueue,1);
  push(pQueue,2);
  push(pQueue,3);
  push(pQueue,4);
  push(pQueue,5);
  pop(pQueue);
  pop(pQueue);
  show_queue(pQueue);
  return 0;
}




