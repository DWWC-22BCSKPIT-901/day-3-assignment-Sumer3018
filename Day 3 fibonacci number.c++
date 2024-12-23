#include<bits/stdc++.h>
int fibo(int x)
{
    if(x<=1)
    {
        return x;
    }
    return fibo(x-1)+fibo(x-2);
}
int main()
{
    int x=10;
    std::cout<<fibo(x);
}