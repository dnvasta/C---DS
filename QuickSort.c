#include <stdio.h>
void Quicksort(int Arr[],int start,int end);
int Partition(int Arr[],int start,int end);

int main()
{
    int Arr[8]={5,9,8,4,2,1,6,3};
    int i,n,start,end;
    printf("Original Array is: \n");
    for(i=0;i<8;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    n=(sizeof(Arr)/sizeof(int));
    start=0;
    end=n-1;
  
    Quicksort(Arr,start,end);
    
    printf("\nSorted Array is: \n");
    for(i=0;i<8;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    return 0;
}

void Quicksort(int Arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int pIndex;
    pIndex=Partition(Arr,start,end);
    Quicksort(Arr,start,pIndex-1);
    Quicksort(Arr,pIndex+1,end);
}

int Partition(int Arr[],int start,int end)
{
    int pivot,pIndex,i,temp;
    pivot=Arr[end];             //Pivot is assumed to be the last one
    pIndex=start;               //pIndex is throwed start from Quicksort function
    for(i=start;i<end;i++)
    {
        if(Arr[i]<=pivot)
        {
            //Swap Arr[i] <--> pIndex   
            temp=Arr[i];
            Arr[i]=Arr[pIndex];
            Arr[pIndex]=temp;
            pIndex=pIndex+1;
        }
    }
    //Swap Arr[pIndex] <--> Arr[end]*****
    temp=Arr[pIndex];
    Arr[pIndex]=Arr[end];
    Arr[end]=temp;
    
    return pIndex;          //pIndex value is updated
}

