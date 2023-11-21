
#include <stdio.h>
int main()
{
int sortedArr[]={1,2,2,4,7,7};
int size= sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<size;i++)
{
if(sortedArr[i]==sortedArr [i+1])
for (int j=0;j<size;j++)
{sortedArr [j+1]=sortedArr [j+2];
}
}
return 0;
}
