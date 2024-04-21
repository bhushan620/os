#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
  int n=50;//start position
  int loc[] = {82,170,43,140,24,16,199};
  int size = sizeof(loc)/sizeof(int);
  int flag[sizeof(loc)/sizeof(int)]={0};
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
  int ind;
  for(int i=0;i<size;i++)
  {
    cout<<i<<" ";
    if(loc[i]<n)
    {
      ind = i;
    }
  }
  cout<<endl;
  if(n<loc[0])
  {
    t = loc[size-1]-n;
  }
  else if(n<loc[size-1])
  {
    int q;
    cout<<"Press 1 if You want to move larger values first\n Press 2 if you want to move to lower value first : ";
    cin>>q;
    if(q==1)
    {
        t = (loc[size-1]-n) + (loc[ind]-0) +loc[size-1];
    }
    else if (q==2)
    {
      t = (n-0) + (loc[size-1]-loc[ind+1]) + loc[size-1];
    }
    
  }
  else
  {
    t =  n;
  }
  
  cout<<"Total overhead is : "<<t<<endl;

}
