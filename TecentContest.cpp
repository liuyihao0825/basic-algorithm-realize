#include<stdio.h>
#include<stdlib.h>/*Ǭ�� 2012.5.24  */
/*�洢ÿ�µ�����*/
int daymon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int totaldays=365;//һ��������� ����ʼ��Ϊƽ���������
struct Date
{
       int y;//year;
       int m;//month;
       int d;//day;
};
struct retday
{
       int aftda;//��������ھ���date.y.1.1�ж�����
       int agoda;//��������ھ���date.y.12.31������ 
};
/*�ж��Ƿ�Ϊ����*/
int leap(int year)
{
    if((year%4==0&&year%100!=0)||(year%400==0))
    return 1;//���귵��1 
    else
    return 0;//�����귵��0 
}
/*����y.1.1-y.m.d��������y.m.d-y.12.31������,�ýṹ��struct  retday���*/
struct  retday rd(int y,int m,int d)
{
       struct retday return_day;
       int i;
       int sumday=0; //�洢�����������������һ��ĵڼ���
//      int daymon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//      int totaldays=365;//һ��������� ����ʼ��Ϊƽ���������
       if(leap(y)) //��������� 
       {
             daymon[1]=29;  //����2�»�Ϊ29�� 
             totaldays=366;  
       }
       /*ע��˴��Ǵ�0��ʼ��������<m-1Ϊ��ֹ����*/
       for(i=0;i<m-1;i++)
            sumday += daymon[i];
       sumday=sumday+d; 
       return_day.agoda=sumday;
       return_day.aftda=totaldays-sumday;
       return return_day;
}
/*�ݴ���*/
void error(int y,int m,int d)
{
if(d>31||m>12||m<1)
     {
           printf("�������\n");
     exit(0);
     }
if(m!=1&&m!=3&&m!=5&&m!=7&&m!=8&&m!=10&&m!=12)
   {
   if(m==2)
   {
      if(leap(y))  //���������
      {
         if(d>29)  //2�����29�� 
         {
            printf("�������\n");
            exit(0);
         } 
      } 
      else              //�����ƽ��
      {
          if(d>28) //2�����28�� 
          {
            printf("�������\n");
            exit(0);
          } 
      } 
   } 
   else               //�����º�һ�����߰�ʮ��֮����� 
   {
       if(d>30)  //���30�� 
       {
            printf("�������\n");
            exit(0);
       }
   }
} }int main()
{
struct Date date;
struct retday rday;
int days;
int j=11;
int remaindays;//ʣ������
printf("���������ڣ�");
scanf("%d %d %d",&date.y,&date.m,&date.d);
//date.y=2000;date.m=1;date.d=4;  //����ʹ��
error(date.y,date.m,date.d);
printf("������������");
scanf("%d",&days);
//days=56;  //����ʹ��
rday=rd(date.y,date.m,date.d);
//����ʹ��
printf("%d.1.1��%d.%d.%dһ����%d��\n",date.y,date.y,date.m,date.d,rday.agoda);
printf("%d.%d.%d��%d.12.31һ����%d��\n",date.y,date.m,date.d,date.y,rday.aftda);
/*������������������������֮������ڻ��ڱ�����*/
if(rday.aftda>=days)
{
  remaindays=rday.aftda-days;
  while(remaindays>=daymon[j])
  {
   remaindays=remaindays-daymon[j];//��12�¿�ʼ��ȥ����
   j--;
  }
  printf("%d.%d.%d\n",date.y,j+1,daymon[j]-remaindays); }
/*�������󳬳�����*/
else
{
  printf("ûʱ��д��...�ⲿ�ֱ�������һ�����鷳LZ�Լ���ɰɣ��и��õĿ��е�˼·����ӭ������......");
  scanf("%*d");
}
scanf("%*d");
return 0;
}
