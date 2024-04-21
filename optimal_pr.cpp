
// Bhushan Pisal
// TYCOC194
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sh(queue<int> q)
{
  int l=q.size();
  while(l--)
  {
    cout<<q.front();
    q.pop();
  }
  cout<<endl;
}
bool remove(int t, queue<int>& q)
{
 
    // Helper queue to store the elements
    // temporarily.
    queue<int> ref;
    int s = q.size();
    int cnt = 0;
 
    // Finding the value to be removed
    while (q.front() != t and !q.empty()) {
        ref.push(q.front());
        q.pop();
        cnt++;
    }
 
    // If element is not found
    if (q.empty()) {
        // cout << "element not found!!" << endl;
        while (!ref.empty()) {
 
            // Pushing all the elements back into q
            q.push(ref.front());
            ref.pop();
        }
        return false;
    }
 
    // If element is found
    else {
        q.pop();
        while (!ref.empty()) {
 
            // Pushing all the elements back into q
            q.push(ref.front());
            ref.pop();
        }
        int k = s - cnt - 1;
        while (k--) {
 
            // Pushing elements from front of q to its back
            int p = q.front();
            q.pop();
            q.push(p);
        }
        return true;
    }
}
void show(int t[],int n)
{
  for(int i=0;i<n;i++ )
  {
    cout<<t[i]<<" ";
  }
  cout<<endl;
}

int which(queue<int> q , int num , int p[],int query)
{
  for(int i=num+1;i<query;i++)
  {
    bool a = remove(p[i],q);
    // cout<<a<<" ";
    if (a)
    q.push(p[i]);
    // sh(q);
  }
  return q.front();
}

int main()
{
  int n,query,index;
  cout<<"Enter the number of slots in table ";cin>>n;
  cout<<"Enter the number of pages address to be put ";cin>>query;
  int p[query];
  int que = query;
  queue<int> q;
  int table[n];
  for(int i=0;i<n;i++)table[i]=-1;
  cout<<"Enter all the pages to be accessed ";
  for(int i=0;i<query;i++)cin>>p[i];

  int num=0;
  
  while(query--)
  {
    // int p;
    int hit = false;
    // cout<<"Enter the fragment address to be accessed ";cin>>p;
    for(int i=0;i<n;i++)
    {
      if(table[i]==p[num])
      {
        cout<<"Hit "<<endl;
        // remove(p,q);
        // q.push(p);
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
        int page = which(q,num,p,que);
        for(int j=0;j<n;j++)
        {
          if(table[j]==page)
          {
            table[j]=p[num];
            break;
          }
        }
        remove(page,q);
        q.push(p[num]);
      }
      else
      {
          q.push(p[num]);
        table[index++] = p[num]; 
        
      }
      cout<<"After applying algo table is :";
      show(table,n);
    }

  num++;
  }
}