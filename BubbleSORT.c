#include<stdio.h>
void BubbleSort(int Arr[],int n);

int main()
{
    int Arr[6]={2,7,4,1,5,3};
    int n,i;
    n=(sizeof(Arr)/sizeof(int));
    printf("Original Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    BubbleSort(Arr,n);
    
    printf("\nSorted Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    
}

void BubbleSort(int Arr[],int n)
{
    int i,k,flag,temp;
    for(k=1;k<n-1;k++)
    {
        flag=0;
        for(i=0;i<(n-k)-1;i++)
        {
            if(Arr[i]>Arr[i+1])
            {
                temp=Arr[i+1];
                Arr[i+1]=Arr[i];
                Arr[i]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}