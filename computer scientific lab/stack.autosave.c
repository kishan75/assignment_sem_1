#include<stdio.h>
#include<stdlib.h>

int size = 0;
int total_size;

int* init (int capacity)
{
	total_size = capacity;
	int *s = (int*)calloc(capacity, sizeof(int));
	return s;
}
int get_size(int *s)
{
	return size;
}
int pop(int *s)
{
	if (size == 0)
		return -1;
	return s[--size];
}
void push(int* s, int e)
{
	if (size + 1 <= total_size)
		s[size++] = e;
}
void deallocate(int *s)
{
	free(s);
}
int main()
{
	int cap;
	printf("enter capacity of stack\n");
	scanf("%d", &cap);
	int *s = NULL;
	s = init(cap);
	push(s, 4);
	push(s, 5);
	printf("size of stack : %d\n", get_size(s));
	printf("top element : %d\n", pop(s));
	deallocate(s);
	return 0;
}