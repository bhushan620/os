#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

int main()
{
  int n=50;//start position
  int loc[] = {82,170,43,140,24,16,190};
  int size = sizeof(loc)/sizeof(loc[0]);
  int flag[size]={0};
  int t=0;
 
  for(int i=0;i<size;i++)
  {
    int min = INT32_MAX;
    int index;
      for(int j=0;j<size;j++)
      {
        if(flag[j]==0 && abs(loc[j]-n)<min)
        {
          index = j;
          min = abs(loc[j]-n);
        }
      }
    cout<<loc[index]<<" is targeted "<<endl;
    t+=abs(loc[index]-n);
    n=loc[index];
    flag[index]=1;
  }
  
  cout<<"Total overhead is : "<<t<<endl;
return 0;
}