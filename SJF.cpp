#include<iostream>
#include<iomanip>
using namespace std;
class sjf_alg
{
    int exe[10],id[10];
    int n;
    void sort(int *,int*);
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
void sjf_alg::getdata()
{
    cout<<"How many processes to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter execution time of "<<i+1<<" process : ";
        cin>>exe[i];
        id[i]=i+1;
    }
}
void sjf_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time "<<endl;
    for(int i=0;i<n;i++)
        cout<<setw(5)<<i+1<<setw(15)<<exe[i]<<setw(15)<<"0"<<endl;
}
void sjf_alg::sort(int *f,int *l)
{
    int temp;
    for(int y=0;y<n-1;y++)
    {
        for(int z=0;z<n-1;z++)
            if(f[z]>f[z+1])
            {
                temp=f[z];
                f[z]=f[z+1];
                f[z+1]=temp;
                temp=l[z];
                l[z]=l[z+1];
                l[z+1]=temp;
            }
    }
}
void sjf_alg::cal_wt_tt()
{
 int wt=0,tnt=0;
 float avg=0,avtnt=0;
 sort(exe,id);
 cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
 for(int i=0;i<n;i++)
    {
        tnt+=exe[i];
        avtnt+=tnt;
        avg+=wt;
        cout<<setw(5)<<id[i]<<setw(15)<<wt<<setw(15)<<tnt<<endl;
        wt+=exe[i];
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
 sjf_alg sjf;
 sjf.getdata();
 sjf.display();
 sjf.cal_wt_tt();
    return 0;
}