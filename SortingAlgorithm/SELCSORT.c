#include <stdio.h>
void SelecSort(int Arr[],int n);

int main()
{
    int Arr[6]={2,7,4,1,5,3};
    int n,i;
    n=(sizeof(Arr)/sizeof(int));
    
    printf("Original Array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
  
   
    SelecSort(Arr,n);
    
    printf("\n");
    printf("Sorted Array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",Arr[i]);
    }
    

    return 0;
}

void SelecSort(int Arr[], int n)
{
    int i,j,iMin,temp;
    for(i=0;i<n-1;i++)
    {
        iMin=i;
        for(j=i+1;j<n;j++)
        {
            if(Arr[j]<Arr[iMin])
                iMin=j;
        }
        temp=Arr[iMin];
        Arr[iMin]=Arr[i];
        Arr[i]=temp;
    }
}