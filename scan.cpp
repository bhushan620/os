#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
  int n=50;//start position
  int loc[] = {82,170,43,140,24,16,190};
  int size = sizeof(loc)/sizeof(int);
  int flag[size]={0};
  int t=0;
  for(int i=0;i<size-1;i++)
  {
    for(int j=i;j<size;j++)
    {
      if(loc[i]>loc[j])
      {
        swap(loc[i],loc[j]);
      }
    }
  }

  for(int i:loc)cout<<i<<" ";
  
  if(n<loc[0])
  {
    t = loc[size-1]-n;
  }
  else if(n<loc[size-1])
  {
    int q;
    cout<<"\nPress 1 if You want to move to larger values first"<<endl;
    cout<<"Press 2 if you want to move to lower value first : "<<endl;
    cin>>q;
    if(q==1)
    {
      t = (loc[size-1]-n) + (loc[size-1]-loc[0]);
    }
    else if (q==2)
    {
      t = (n-loc[0]) + (loc[size-1]-loc[0]);
    }
    
  }
  else
  {
    t = loc[0] - n;
  }
  
  cout<<"Total overhead is : "<<t<<endl;

}