#include<bits/stdc++.h>
using namespace std;
int arr[100];
int si=0;
void heapup(int ind)
{
    if(ind==1)return ;
    if(arr[ind]>arr[ind/2])
    {
        swap(arr[ind],arr[ind/2]);
        heapup(ind/2);
    }
}
void ins(int num)
{
    si++;
    arr[si]=num;
    heapup(si);
}
void heapdo(int ind)
{
    int tind=ind;
    if(ind*2<=si)
    {
        if(arr[tind]<arr[ind*2])tind=ind*2;
    }
    if(ind*2+1<=si)
    {
        if(arr[tind]<arr[ind*2+1])tind=ind*2+1;
    }
    if(ind!=tind)
    {
        swap(arr[ind],arr[tind]);
        heapdo(tind);
    }
}
void pop()
{
    swap(arr[1],arr[si]);
    si--;
    heapdo(1);
}
int top()
{
    return arr[1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(1)
    {
        int op;
        cin>>op;
        if(op==0)
        {
            break;;
        }else if(op==1)
        {
            int k;
            cin>>k;
            ins(k);
        }else if(op==2)
        {
            cout<<top()<<"\n";
            pop();
        }
        //for(int i=1;i<=si;i++)cout<<arr[i]<<" ";cout<<"\n";
    }
}
