#include<iostream>
#include<math.h>
using namespace std;
int divide(int, int);
void display(int [],int);
void product(int [],int);
int main()
{
  int i,j;
  cout<<"Enter the size of array: "<<endl;
  cin>>i;
  int num[i];
  cout<<"Enter "<<i<<" elements of array: "<<endl;
  for(j=0; j<i; j++)
    cin>>num[j];
  cout<<"Input: "<<endl;
  display(num,i);
  cout<<"Output: "<<endl;
  product(num,i);
  return 0;
}

void display(int n[],int size)
{
  for(int i=0; i<size; i++)
    cout<<n[i]<<" ";
  cout<<"\n";
}

void product(int n[],int size)
{
  int multi=1,ans[size],nZero=0,j;
  if(size==1)
    cout<<n[0];
  else
  {
   for(j=0; j<size; j++)
   {
     if(n[j]==0)
       nZero++;
     else
       multi=multi*n[j];
   }
   for(j=0; j<size; j++)
   {
    if(nZero>1)
      ans[j]=0;
    else if(nZero==1)
    {
      if(n[j]!=0)
        ans[j]=0;
      else
        ans[j]=multi;
    }
    else
    {
      ans[j]=divide(multi,n[j]);
    }
    cout<<ans[j]<<" ";
   }
  }
  cout<<endl;
}

int divide(int d1, int d2)
{
  int sign=((d1<0)^(d2<0));
  if(d1<0||d2<0)
  {
    d1=abs(d1);
    d2=abs(d2);
  }
  int ans=exp(log(d1)-log(d2))+0.0001;
  return (sign?(-ans):(ans));
}

