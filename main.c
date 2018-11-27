#include<stdio.h>
#define STUDENT 7
#define CLASS 6

int score[STUDENT][CLASS];
double *avg_class(int nums_c[STUDENT][CLASS],double Avg_C[CLASS]);
double *avg_student(int nums_s[STUDENT][CLASS],double Avg_S[STUDENT]);
int max(int nums[STUDENT][CLASS],int MAX[2]);
int main()
{
    int i,t,Max,MAX[2];
    double *s,*c;
    double Avg_C[CLASS],Avg_S[STUDENT];
    
    printf("输入%d个学生%d门课程的成绩\n",STUDENT,CLASS);
    
    for(i=0;i<STUDENT;i++)
    {
        for(t=0;t<CLASS;t++)
        {
            scanf("%d",&score[i][t]);
        }
    }
    
    c=avg_class(score,Avg_C);
    s=avg_student(score,Avg_S);
    Max=max(score,MAX);
    
    for(i=0;i<STUDENT;i++)
    {
        printf("\n第%d个学生的每门课程的平均分：  ",i+1);
        printf("%.1lf",*s);
        s++;
    }
    
    for(t=0;t<CLASS;t++)
    {
        printf("\n第%d门课程的平均分：  ",t+1);
        printf("%.1lf",*c);
        c++;
    }
    printf("\n最高分是第%d个学生的第%d门成绩：%d\n",MAX[0]+1,MAX[1]+1,Max);
    return 0;
}

int max(int nums[STUDENT][CLASS],int MAX[2])
{
    int i,t,Max=0;
    
    for(i=0;i<STUDENT;i++)
    {
        for(t=0;t<CLASS;t++)
        {
            if(nums[i][t]>=Max)
            {
                Max=nums[i][t];
                MAX[0]=i;
                MAX[1]=t;
            }
        }
    }
    
    return Max;
}

double *avg_class(int nums_c[STUDENT][CLASS],double Avg_C[CLASS])
{
    double *pc;
    int i,t,sum=0;
    for(t=0;t<CLASS;t++)
    {
        for(i=0;i<STUDENT;i++)
        {
            sum=sum+nums_c[i][t];
        }
        Avg_C[t]=sum/STUDENT;
        sum=0;
    }
    pc=Avg_C;
    return pc;
}

double *avg_student(int nums_s[STUDENT][CLASS],double Avg_S[STUDENT])
{
    double *ps;
    int i,t,sum=0;
    for(i=0;i<STUDENT;i++)
    {
        for(t=0;t<CLASS;t++)
        {
            sum=sum+nums_s[i][t];
        }
        Avg_S[i]=sum/CLASS;
        sum=0;
    }
    ps=Avg_S;
    return ps;
}
