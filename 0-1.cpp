#include<iostream>
using namespace std;
int m[100][100];
int KnapSack(int n,int w[],int v[],int x[],int C);
int max(int a,int b);
int main()
{
	int i,n,c;
	int w[100],v[100],x[100];
	cout<<"输入要放入背包的物品数n为:";
	cin>>n;
	cout<<"输入背包的容量c为:";
	cin>>c;
	cout<<"每个物品的重量:";
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	cout<<endl;
	cout<<"每个物品对应的价值:";
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	cout<<endl;
	for(i=1;i<n;i++)
	{
		cout<<"第"<<i<<"件物品的重量为:"<<w[i];
		cout<<"    价值为:"<<v[i]<<endl;
	}
	cout<<"最大物品价值为:"<<KnapSack(n,w,v,x,c)<<endl;
	return 0;
}
int max(int a,int b)
 {
     if(a>=b)
         return a;
     else 
		 return b;
}
int KnapSack(int n,int w[],int v[],int x[],int C)
 {
     int i,j;
     for(i=0;i<=n;i++)
         m[i][0]=0;
     for(j=0;j<=C;j++)
         m[0][j]=0;
     for(i=0;i<=n-1;i++)
         for(j=0;j<=C;j++)
             if(j<w[i])
                m[i][j]=m[i-1][j];
             else
                 m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
             j=C;
             for(i=n-1;i>=0;i--)
             {
                 if(m[i][j]>m[i-1][j])
                 {
                   x[i]=1;
                   j=j-w[i];
                 }
                 else
                     x[i]=0;
             }
             cout<<"选中的物品是:";
             for(i=1;i<=n;i++)
			 {
                  cout<<x[i];
			 }
			 cout<<endl;
             return m[n-1][C];
}
