#include <stdio.h>
#include <stdlib.h>
void inivector(int ** vector);

int main()
{
    int * vector;
    inivector(&vector);
    printf("%p\n",vector);
    int i=0;
    for(i=0;i<5;i++)
        printf("%i\n",vector[i]);
    return 0;
}

void inivector(int ** vector) 
{
   *vector = malloc (sizeof(int)*5);
    int i=0;
    for(i=0;i<5;i++)
        (*vector)[i]=1;
    printf("%p\n",*vector);
}