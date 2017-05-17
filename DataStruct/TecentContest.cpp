#include<stdio.h>
#include<stdlib.h>/*乾卦 2012.5.24  */
/*存储每月的天数*/
int daymon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int totaldays=365;//一年的总天数 ，初始置为平年的总天数
struct Date
{
       int y;//year;
       int m;//month;
       int d;//day;
};
struct retday
{
       int aftda;//输入的日期距离date.y.1.1有多少天
       int agoda;//输入的日期距离date.y.12.31的天数 
};
/*判断是否为闰年*/
int leap(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
    return 1;//闰年返回1 
    else
    return 0;//非闰年返回0 
}
/*返回y.1.1-y.m.d的天数和y.m.d-y.12.31的天数,用结构体struct  retday存放*/
struct  retday rd(int y,int m,int d)
{
       struct retday return_day;
       int i;
       int sumday=0; //存储输入的日期这天是这一年的第几天
//      int daymon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//      int totaldays=365;//一年的总天数 ，初始置为平年的总天数
       if(leap(y)) //如果是闰年 
       {
             daymon[1]=29;  //闰年2月换为29天 
             totaldays=366;  
       }
       /*注意此处是从0开始，所以是<m-1为终止条件*/
       for(i=0;i<m-1;i++)
            sumday += daymon[i];
       sumday=sumday+d; 
       return_day.agoda=sumday;
       return_day.aftda=totaldays-sumday;
       return return_day;
}
/*容错处理*/
void error(int y,int m,int d)
{
if(d>31||m>12||m<1)
     {
           printf("输入错误！\n");
     exit(0);
     }
if(m!=1&&m!=3&&m!=5&&m!=7&&m!=8&&m!=10&&m!=12)
   {
   if(m==2)
   {
      if(leap(y))  //如果是闰年
      {
         if(d>29)  //2月最多29天 
         {
            printf("输入错误！\n");
            exit(0);
         } 
      } 
      else              //如果是平年
      {
          if(d>28) //2月最多28天 
          {
            printf("输入错误！\n");
            exit(0);
          } 
      } 
   } 
   else               //除二月和一三五七八十腊之外的月 
   {
       if(d>30)  //最多30天 
       {
            printf("输入错误！\n");
            exit(0);
       }
   }
} }int main()
{
struct Date date;
struct retday rday;
int days;
int j=11;
int remaindays;//剩余天数
printf("请输入日期：");
scanf("%d %d %d",&date.y,&date.m,&date.d);
//date.y=2000;date.m=1;date.d=4;  //调试使用
error(date.y,date.m,date.d);
printf("请输入天数：");
scanf("%d",&days);
//days=56;  //调试使用
rday=rd(date.y,date.m,date.d);
//调试使用
printf("%d.1.1到%d.%d.%d一共有%d天\n",date.y,date.y,date.m,date.d,rday.agoda);
printf("%d.%d.%d到%d.12.31一共有%d天\n",date.y,date.m,date.d,date.y,rday.aftda);
/*如果输入的天数加上输入日期之后的日期还在本年中*/
if(rday.aftda>=days)
{
  remaindays=rday.aftda-days;
  while(remaindays>=daymon[j])
  {
   remaindays=remaindays-daymon[j];//从12月开始减去天数
   j--;
  }
  printf("%d.%d.%d\n",date.y,j+1,daymon[j]-remaindays); }
/*加起来后超出本年*/
else
{
  printf("没时间写了...这部分比上面那一部分麻烦LZ自己完成吧，有更好的可行的思路，欢迎大家提出......");
  scanf("%*d");
}
scanf("%*d");
return 0;
}
