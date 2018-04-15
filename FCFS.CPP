#include <iostream>
class process
{
    public:
    int arrtime;
    int cbt;
};
int main()
{
    process p[20];
    int np,atime[20];
    cout<<"enter no of process \n";
    cin>>np;
    cout<<"enter arr time \n";
    for(int i=0;i<np;i++)
    {
        cin>>p[i].arrtime;
    }
    /*sort arrival time*/
    for(i=0;i<np;i++)
    {
        atime[i]=p[i].arrtime;
    }
    for(i=0;i<np;i++)
    {
        for(j=i+1;j<np;j++)
        {
            if(atime[i]>atime[j])
            {
                int s=atime[i];
                atime[i]=atime[j];
                atime[j]=s;
            }
        }
    }
    cout<<"enter CBT of processes \n";
    for(i=0;i<np;i++)
    {
        cin>>p[i].cbt;
    }
    /*print gantt chat*/
    int wtime[20];
    wtime[0]=0;
    cout<<" ";
    for(i=0;i<np;i++)
    {
        for(int j=0;j<p[i].cbt;j++)
        {
            if(j>=atime[i])
            {cout<<"p"<<i<<" ";}
            else
            {
            cout<<"i";
            if(j<atime[0])
            {wtime[0]++;}
            }
        }
        wtime[i+1]=wtime[i]+p[i].cbt;
    }
    for(i=0;i<;i++)
    {
        cout<<i;
    }


return 0;
}