#include <malloc/_malloc.h>
#include <stdio.h>
#include <stdlib.h>
struct DynamicArray{
  int *array;
  int capacity;
  int size;
};

void initArray(struct DynamicArray *pArray);
_Bool isEmpty(struct DynamicArray *pArray);
void append(struct DynamicArray *pArray,int value);
void insert(struct DynamicArray *pArrary,int index,int value);
int pop(struct DynamicArray *pArrary);
void push(struct DynamicArray *pArray,int value);
void DynamicAllcate(struct DynamicArray *pArray);
void showArray(struct DynamicArray *pArray);

int main(void)
{
  struct DynamicArray *pArray = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
  initArray(pArray);
  isEmpty(pArray);
  push(pArray,1);
  showArray(pArray);
  push(pArray,2);
  showArray(pArray);
  push(pArray,4);
  showArray(pArray);
  insert(pArray,1,6);
  showArray(pArray);
  append(pArray,12);
  showArray(pArray);
  pop(pArray);
  showArray(pArray);
  return 0;
}

void initArray(struct DynamicArray *pArray)
{
  pArray->array = (int *)malloc(sizeof(int));
  if (pArray->array == NULL)
    {
      printf("Memory error");
	return;
    }
  pArray->size = 0;
  pArray->capacity = 1;
  return;
}

_Bool isEmpty(struct DynamicArray *pArray)
{
  return pArray->size == 0;
}

void append(struct DynamicArray *pArray,int value)
{
  DynamicAllcate(pArray);
  pArray->array[pArray->size] = value;
  pArray->size++;
}

void insert(struct DynamicArray *pArray,int index,int value)
{
  int i = 0;
  DynamicAllcate(pArray);
  for(i = pArray->size ;i > index ;i--)
    {
      pArray->array[i] = pArray->array[i-1];
    }
  pArray->array[index] = value;
  pArray->size++;
  return;
}

int pop(struct DynamicArray *pArray)
{
  int i = 0;
  int ret_value = pArray->array[0];
  for (i = 0 ;i < pArray->size-1 ;i++)
    {
      pArray->array[i] = pArray->array[i+1];
    }
  pArray->size--;
  printf("%d\n",ret_value);
  return ret_value;
}
  
void push(struct DynamicArray *pArray,int value)
{
  int i = 0;
  DynamicAllcate(pArray);
  for(i = pArray->size ;i > 0; i--)
    {
      pArray->array[i] = pArray->array[i-1];
    }
  pArray->array[0] = value;
  pArray->size++;
  return;
}

void DynamicAllcate(struct DynamicArray *pArray)
{
  int i = 0;
  if(pArray->size == pArray->capacity)
    {
      int *New_Array = (int *)malloc(sizeof(int)*2*pArray->capacity);

      for (i = 0; i < pArray->size; i++)
	{
	  New_Array[i] = pArray->array[i];
	}
      free(pArray->array);
      pArray->array = New_Array;
      pArray->capacity = pArray->capacity*2;
      return;
    }
  else return; 
      
}

void showArray(struct DynamicArray *pArray)
{
  int i = 0;
  printf("The size is %d\n", pArray->size);
  printf("The capacity is %d\n", pArray->capacity);
  for (i = 0 ;i<pArray->size ;i++)
    {
      printf ("%d ",pArray->array[i]);
    }
}
