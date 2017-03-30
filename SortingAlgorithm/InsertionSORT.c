#include<stdio.h>
void InsrSort(int Arr[],int n);

int main()
{
    int Arr[6]={2,7,4,1,5,3};
    int n,i;
    n=(sizeof(Arr)/sizeof(int));
    printf("Original Array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    InsrSort(Arr,n);
    
    printf("\nSorted Array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    return 0;
}

void InsrSort(int Arr[],int n)
{
    int i,value,hole;
    for(i=1;i<n;i++)
    {
        value=Arr[i];
        hole=i;
        while(hole>0 && Arr[hole-1]>value)
        {
            Arr[hole]=Arr[hole-1];
            hole=hole-1;
        }
        Arr[hole]=value;
    }
}

