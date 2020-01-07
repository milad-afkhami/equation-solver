#include <iostream>
#include <conio.h>

using namespace std;

string my_uppercase(string a)
{
    int b,j;
    string k;
    k=a;
    for(j=0;(j<a.size());j++)
    {
         b=a[j];
         if (b>96 && b<123)
         {
             k[j]=a[j]-32;
         }
    }
    return k;
}

void my_clean()
{
    system("cls");
}

double my_tavan(double a,int b)
{
    double o=1;
    if(b<0)
    {
        b=-b;
        for(int j=0;j<b;j++)
        {
            o=o*(1/a);
        }
        return o;
    }
    for(int j=0;j<b;j++)
    {
        o=o*a;
    }
    return o;
}

int my_hal_moadele(int min_daraje,int max_daraje,double z[],double ans[])
{
    int m=max_daraje-min_daraje,n,h=0,help;
    if(min_daraje<0)
        help=-min_daraje;
    else
        help=min_daraje;
    double sum=0;
    for(double i=25;(i>-25)&&(h<m);i=i-0.001)
    {
        sum=0;
        for(int j=min_daraje;j<=max_daraje;j++)
        {
         sum=sum+z[j+help]*my_tavan(i,j);
        }
        if(sum<0.001&&sum>-0.001)
        {
            ans[h]=i;
            h++;
        }
    }
    return h;
}

void moadele()
{
    int min_daraje=0,max_daraje,m,k;
    cout<<endl<<"   Min Degree:   ";
    cin>>min_daraje;
    cout<<"   Max Degreee:   ";
    cin>>max_daraje;
    m=max_daraje-min_daraje;
    double zarayeb[m+1];
    double pasokh[m];
    cout<<endl;
    k=max_daraje;
    for(int j=m;j>-1;j--)
    {
        cout<<"   Coefficient of the Term With Degree of "<<k<<" :";
        k--;
        cin>>zarayeb[j];
    }
    cout<<endl;
    int tedad_j;
    tedad_j=my_hal_moadele(min_daraje,max_daraje,zarayeb,pasokh);
    cout<<"   The Equation Has "<<tedad_j<<" Answer";
    for(int j=0;j<tedad_j;j++)
    {
        cout<<endl<<"   "<<pasokh[j];
    }
    cout<<endl<<"   ";
    getch();
}

int main()
{
    string input="0";
    cout<<"   Hello"<<endl<<"   Welcome to The Equation Solving Program."<<endl;
    while(input!="END")
    {
        cout<<endl<<"   Please Enter 'start' or 'end'."<<endl<<"   ";
        cin>>input;
        input=my_uppercase(input);
        if(input=="START")
        {
            my_clean();
            moadele();
        }
        my_clean();
    }
    cout<<"   Bye :)";
    getch;
}
