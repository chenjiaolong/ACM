#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define MAX_ARRAY_DIM 8

#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define UNDERFLOW -1

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType *base;
    int dim;
    int *bounds;
    int *constants;
} Array;
Status InitArray(Array &A,int dim,...)
{
    if(dim<1||dim>MAX_ARRAY_DIM)
        return ERROR;
    A.dim=dim;
    A.bounds=(int *)malloc(dim*sizeof(int));
    if(!A.bounds)
        exit(OVERFLOW);
    int elemtotal=1;
    va_list ap;
    va_start(ap,dim);
    int i;
    for(i=0; i<dim; ++i)
    {
        A.bounds[i]=va_arg(ap,int);
        if(A.bounds[i]<0)
            return UNDERFLOW;
        elemtotal *=A.bounds[i];
    }
    va_end(ap);
    A.base=(ElemType *)malloc(elemtotal *sizeof(ElemType));
    if(!A.base)
        exit(OVERFLOW);
    A.constants=(int *)malloc(dim *sizeof(int));
    if(!A.constants)
        exit(OVERFLOW);
    A.constants[dim-1]=1;
    for(i=dim-2; i>=0; --i)
        A.constants[i]=A.bounds[i+1]*A.constants[i+1];
    return OK;
}
Status DestroyArray(Array &A)
{
    if(!A.base)
        return ERROR;
    free(A.base);
    A.base=NULL;
    if(!A.bounds)
        return ERROR;
    free(A.bounds);
    A.bounds=NULL;
    if(!A.constants)
        return ERROR;
    free(A.constants);
    A.constants=NULL;
    return OK;
}
Status Locate(Array A,va_list ap,int &off)
{
    off=0;
    int i,ind;
    for(i=0; i<A.dim; ++i)
    {
        ind=va_arg(ap,int);
        if(ind<0||ind>=A.bounds[i])return OVERFLOW;
        off+=A.constants[i]*ind;
    }
    return OK;
}
Status Value(Array A,ElemType &e,...)
{
    va_list ap;
    va_start(ap,e);
    int result,off;
    if((result=Locate(A,ap,off))<=0)
        return result;
    e=*(A.base+off);
    return OK;
}
Status Assign(Array &A,ElemType e,...)
{
    va_list ap;
    va_start(ap,e);
    int result,off;
    if((result=Locate(A,ap,off))<=0) return result;
    *(A.base+off)=e;
    return OK;
}
int main()
{
    Array array;
    int i,j,e;
    InitArray(array,2,3,4);
    for(i=0; i<3; i++)
        for(j=0; j<4; j++)
            Assign(array,(i+1)*10+j,i,j);
    for(i=0; i<3; i++)
    {
        printf("\n");
        for(j=0; j<4; j++)
        {
            Value(array,e,i,j);
            printf("%4d",e);
        }
    }
    DestroyArray(array);
    return 0;

}
