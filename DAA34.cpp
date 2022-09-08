//Name: OM MAIND
//Roll no: TI34

//KNAPSACK Problem using Greedy n Dynamic approach in one Program


#include <iostream>
#include <math.h>
using namespace std;

void Greedy(int n, float weight[], float profit[], int capacity)
{
    int i,j;
    
    
    
     float ratio[20];

    cout<<"Enter no of elements:"<<endl;
        cin>>n;

        cout<<"Enter Weights of the elemnts:"<<endl;
        for(i=0; i<n; i++)
        {
            cin>>weight[i];          
        }

        cout<<"Enter profits of the elemnts:"<<endl;
        for(i=0; i<n; i++)
        {
            cin>>profit[i];
        }

        cout<<"Enter total capacity of sack:"<<endl;
        cin>>capacity;

         for(i=0; i<n; i++)
        {
            ratio[i]=profit[i]/weight[i];
        }

        for(i=0; i<n-1 ;i++)
        {
            for(j=0; j<n-i-1; j++)
            {                                              //Used Switch case for better understanding of code.
                if(ratio[j]<ratio[j+1])
                {
                   swap(ratio[j],ratio[j+1]);
                   swap(weight[j],weight[j+1]);
                   swap(profit[j],profit[j+1]);
                    
                }
            }
        }
        cout<<"The Sorted Ratio"<<endl;

        for(i=0; i<n ;i++)
        {
            cout<<ratio[i]<<endl;
        } 
        cout<<"The Sorted Profit"<<endl;
        for(i=0; i<n ;i++)
        {
            cout<<profit[i]<<endl;
        } 
        cout<<"The Sorted Weight:"<<endl;

        for(i=0; i<n ;i++)
        {
            cout<<weight[i]<<endl;
        } 
        


        float xi[10];
        int u;
        u=capacity;
        float tp=0;

    for(int i=0;i<n;i++)
    {
        xi[i]=0.0;
    }


    cout<<"I is: "<<endl<<i;
    
    for(i=0;i<n;i++)
    {
        if(weight[i]>u)
        {
            break;
        }
        else
        {
            xi[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
      
    if(i<n)
    {
        xi[i]=u/weight[i];
    }

    cout<<endl<<xi[i]*profit[i];

    tp=tp+(xi[i] * profit[i]);

    cout<<"\nThe vector is:"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<xi[i]<<endl;
    }

    cout<<"The Total profit :"<<endl;
    cout<<tp;
   
}

void Dynamic(int n, float weight[], float profit[], int capacity)
{

    int v[20][20];
    int i,j;

    cout<<"Enter no of elements:"<<endl;
        cin>>n;

        cout<<"Enter Weights of the elemnts:"<<endl;
        for(i=1; i<=n; i++)
        {
            cin>>weight[i];          
        }

        cout<<"Enter profits of the elemnts:"<<endl;
        for(i=1; i<=n; i++)
        {
            cin>>profit[i];
        }

        cout<<"Enter total capacity of sack:"<<endl;
        cin>>capacity;


       

        for(i=0; i<=n; i++)
        {
            for(j=0; j<=capacity; j++)
            {
                if(i==0 || j==0)
                {
                    v[i][j]=0;
                }
               /* else if(weight[i]<=capacity)
                {    
                    v[i][j]=max((v[i-1][j]), (v[i-1][j - weight[i]]) + profit[i]);
                }
                */

                else if(j<weight[i])
                {
                    v[i][j]=v[i-1][j];
                }
                else
                {
                   if(v[i-1][j]>v[i-1][j-int(weight[i])] + int(profit[i]))              //Type Casted !
                    {
                        v[i][j]=v[i-1][j];
                    } 
                    else
                    {
                        v[i][j]=v[i-1][j-int(weight[i])] + int(profit[i]);
                    }

                }
            }
        }

        for(i=0; i<=n; i++)
        {
            for(j=0; j<=capacity;j++)
            {
               cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"The Maximum profit is :"<<v[n][capacity]<<endl; 

        i=n;j=capacity;
        while(i>=0 && j>=0)
        {
            if(v[i][j]==v[i-1][j])
            {
                cout<<i<<"is 0"<<endl;
                i--;
            }
            else
            {
                cout<<i<<"is 1"<<endl;
                i--;
                j=j-profit[i];
            }
        }

}
 

int main()
{
        float weight[20],profit[20];
        int i,j,temp,n,capacity;
       
    int ch;
    cout<<"Enter the approach you want to proceed with \n 1)Greedy approach \n 2) Dynamic: \n";
    cin>>ch;

    switch (ch)
    {
    case 1:

            Greedy(n,weight,profit,capacity);
        break;

    case 2:

        Dynamic(n,weight,profit,capacity);

        break;

    default:

        cout<<"Enter valid Choice!!";
        break;
    }

        return 0;
       
}

//Conclusion : We got more optimal solution by using Greedy approach rather than Dynamic. 