#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  int n=50; //start position
  int loc[] = {82,170,43,140,24,16,190};
  int t=0;
  int m= sizeof(loc)/sizeof(loc[0]);
  

  for (int i = 0; i < m; i++)
  {
    t = t + abs(loc[i]-n);
    cout<<"|"<<n<<"-"<<loc[i]<<"|"<<endl;
    n=loc[i];
  }

  cout<<"Total overhead is : "<<t<<endl;

}