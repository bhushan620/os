// Bhushan Pisal
// TYCOC194
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void show(int t[],int n)
{
  for(int i=0;i<n;i++ )
  {
    cout<<t[i]<<" ";
  }
  cout<<endl;
}

void remove(queue<int> &q,int val)
{
    queue<int> ref;
    while(q.front()!=val)
    {
        ref.push(q.front());
        q.pop();
    }
    
    q.pop();
    while(!q.empty())
    {
        ref.push(q.front());
        q.pop();
    }
    
    while(!ref.empty())
    {
        q.push(ref.front());
        ref.pop();
    }
}

int main()
{
  int n,query,index;
  cout<<"Enter the number of slots in table ";cin>>n;
  cout<<"Enter the number of pages address to be put ";cin>>query;
  queue<int> q;
  int table[n];
  for(int i=0;i<n;i++)table[i]=-1;
  while(query--)
  {
    int p;
    int hit = false;
    cout<<"Enter the fragment address to be accessed ";cin>>p;
    for(int i=0;i<n;i++)
    {
      if(table[i]==p)
      {
        cout<<"Hit "<<endl;
        remove(q,p);
        q.push(p);
        show(table,n);
        hit  = true;
        break;
      }
    }
    if ( ! hit)
    {
      cout<<"Missed ";
      if(q.size()==n)
      {
        int page = q.front();
        for(int j=0;j<n;j++)
        {
          if(table[j]==page)
          {
            table[j]=p;
            break;
          }
        }
        q.pop();
        q.push(p);
      }
      else
      {
        q.push(p);
        table[index++] = p; 
        
      }
      cout<<"After applying algo table is :";
      show(table,n);
    }


  }
}