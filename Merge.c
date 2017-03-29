#include<stdio.h>
void MergeSort(int Arr[]);
void Merge(int L[],int R[],int Arr[]);

int main()
{
    int Arr[8]={2,4,1,6,8,5,3,7};
    int i;
    printf("Original Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    MergeSort(Arr);
    
    printf("\nSorted Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    
    return 0;
}

void Merge(int L[],int R[],int Arr[])
{
    int nL,nR,i=0,j=0,k=0;
    nL=(sizeof(L)/sizeof(int));
    nR=(sizeof(R)/sizeof(int));
    while(i<nL && j<nR)
    {
        if(L[i]<=R[j])
        {
            Arr[k]=L[i];
            i++;
        }
        else
        {
            Arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nL)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(i<nR)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}


void MergeSort(inr Arr[])
{
    int n,mid,i;
    n=(sizeof(Arr)/sizeof(int));
    if(n<2)
        return;
    mid=n/2;
    int L[mid];
    int R[n-mid];
    for(i=0;i<=mid-1;i++)
    {
        L[i]=Arr[i];
    }
    for(i=mid;i<=n-1;i++)
    {
        R[i-mid]=Arr[i];
    }
    MergeSort(L);
    MergeSort(R);
    Merge(L,R,Arr);
}