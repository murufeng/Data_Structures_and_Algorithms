#include<stdio.h>  
#include<stdlib.h>  
#include<iostream>  
#include<queue>  
#include<climits>  
#include<cstring>  
using namespace std;   
void package0_1(int m[][6],int w[],int v[],int n,int c)//n代表物品的个数   
{  
    //采用从底到顶的顺序来设置m[i][j]的值  
    //首先放w[n]  
    for(int j = 0; j <= c; j++)  
       if(j < w[n]) m[n][j] = 0;     //j小于w[n],所对应的值设为0，否则就为可以放置   
       else         m[n][j] = v[n];  
         
    //对剩下的n-1个物品进行放置。  
    int i;  
    for(i = n-1; i >= 1; i--)  
        for(int j = 0; j <= c; j++)  
           if(j < w[i])   
                        m[i][j] = m[i+1][j];//如果j < w[i]则，当前位置就不能放置，它等于上一个位置的值。  
                                            //否则，就比较到底是放置之后的值大，还是不放置的值大，选择其中较大者。              
           else         m[i][j] = m[i+1][j] > m[i+1][j-w[i]] + v[i]?   
                                  m[i+1][j] : m[i+1][j-w[i]] + v[i];    
}  
void answer(int m[][6],int n,int x[],int w[],int c)  
{  
    int j = c;  
    int i;  
    for(i = 1; i <= n-1; i++)  
        if(m[i][j] == m[i+1][j]) x[i] = 0;  
        else                    {   
                                 x[i] = 1;  
                                 j = j - w[i];  
                                 }      
    x[n] = m[i][j] ? 1 : 0;   
}  
int main()  
{
    int m[5][6]={0};
 	int i,n,c;
	int w[10],v[10],x[10];
	cout<<"给定背包的物品数n为:";
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
	for(i=1;i<=n;i++)
	{
		cout<<"第"<<i<<"件物品的重量为:"<<w[i];
		cout<<"    价值为:"<<v[i]<<endl;
	}
 package0_1(m,w,v,n,c);  
 for(i = 0; i <=4; i++)  
 {  
     for(int j = 0; j <=5; j++)  
     printf("%2d ",m[i][j]);  
     cout << endl;   
 }   
 answer(m,n,x,w,c);  
 cout << "The best answer is:\n";  
 for( i=1; i <=4; i++)  
 cout << x[i] << " ";  
 system("pause");  
 return 0;  
} 
