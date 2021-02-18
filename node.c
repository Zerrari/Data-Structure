#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

typedef struct node
{
  int data;
  struct node *pNext;
}NODE,* PNODE;

PNODE create_LinkList();
_Bool is_empty(PNODE);
void insert(PNODE,int,int);
int delete(PNODE,int);
void show_LinkList(PNODE);
int len_LinkList(PNODE);

PNODE create_LinkList()
{
  int length;
  int value;
  PNODE pNode = (PNODE)malloc(sizeof(NODE));
  PNODE pTail = pNode;
  pNode->pNext = NULL;
  printf("input length\n");
  scanf("%d",&length);
  for (int i = 0; i < length; i++)
    {
      scanf("%d",&value);
      pTail->pNext = (PNODE)malloc(sizeof(NODE));
      pTail = pTail->pNext;
      pTail->data = value;
    }
  return pNode;
}

_Bool is_empty(PNODE pNode)
{
  return pNode->pNext == NULL;
}

void show_LinkList(PNODE pNode)
{
  while (pNode->pNext != NULL)
    {
      pNode = pNode->pNext;
      printf("%d ",pNode->data);
    }
  printf("\n");
}

int delete(PNODE pNode,int index)
{
  int value = 0;
  PNODE pFlag = pNode;
  for (int i = 0;i < index-1;i++)
    {
      pFlag = pFlag->pNext;
    }
  value = pFlag->pNext->data;
  PNODE pTemp = pFlag->pNext;
  pFlag->pNext = pFlag->pNext->pNext;
  free(pTemp);
  return value;
}

void insert(PNODE pNode,int index,int value)
{
  PNODE pFlag = pNode;
  for (int i = 0;i < index - 1;i++)
    {
      pFlag = pFlag->pNext;
    }
  PNODE pNew = (PNODE)malloc(sizeof(NODE));
  pNew->data = value;
  pNew->pNext = pFlag->pNext;
  pFlag->pNext = pNew;
  return;
}

int len_LinkList(PNODE pNode)
{
  int len = 0;
  PNODE pFlag = pNode;
  while(pFlag->pNext != NULL)
    {
      len++;
      pFlag = pFlag->pNext;
    }
  return len;
}

int main(void)
{
  PNODE pNode = NULL;
  pNode = create_LinkList();
  printf("%d\n",len_LinkList(pNode));
  show_LinkList(pNode);
  insert(pNode,1,10);
  printf("%d\n",len_LinkList(pNode));
  show_LinkList(pNode);
  printf("%d\n",delete(pNode,1));
  show_LinkList(pNode);
  return 0;
}

