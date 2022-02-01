//LOOK disk scheduling program in C++.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    vector <int> a(n),l;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        if(a[i]>m)
        {
            cout<<"Error, Unknown position\n";
            return 0;
        }
    }
    cout<<"Enter the head position\n";
    cin>>h;
    a.push_back(h);
    sort(a.begin(),a.end());
    for(i=0; i<a.size(); i++)
    {
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2)
    {
        for(i=k; i<a.size(); i++)
        {
            l.push_back(a[i]);
        }
        for(i=k-1; i>=0; i--)
        {
          l.push_back(a[i]);
        }
    }
    else
    {
        for(i=k; i>=0; i--)
        {
           l.push_back(a[i]);
        }
        for(i=k+1; i<a.size(); i++)
        {
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1; i<l.size(); i++)
    {
       cout<<" -> "<<l[i]<<" ";
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<<sum<<'\n';
    return 0;
}

/*
Enter the size of disk
199
Enter number of requests
8
Enter the requests
98
183
37
122
14
124
65
58
Enter the head position
53
53 -> 58  -> 65  -> 98  -> 122  -> 124  -> 183  -> 37  -> 14
Total head movements = 481
*/
