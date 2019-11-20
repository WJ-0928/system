#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int i,bknum;
FILE *fp;
typedef struct
{
	char isbn[10];//书号
	char bkname[20];//书名
	char author[10];//作者
	float price;//单价 
	int num; //数量 
}BOOK;
BOOK bk[100];
//读取文件 
void rdata()
{
	FILE *fp;
	if((fp=fopen("bookdata.txt","r"))==NULL)
	{
		printf("Can not open the file!\n");
		return;
	}

   while(!feof(fp))
   {
  	fscanf(fp,"%s%s%s%f%d\n",&bk[bknum].isbn,&bk[bknum].bkname,&bk[bknum].author,&bk[bknum].price,&bk[bknum].num);
 	bknum++;
   }
	fclose(fp);
} 
// 写入文件 
 void wdata()
 {
    FILE *fp;
    if((fp=fopen("bookdata.txt","w"))==NULL)
	{
 		printf("Can not open the file!\n");
 		return;
    }
    for(int i=0;i<bknum;i++)
    {
	fprintf(fp,"%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);
	fputc('\n',fp);
 	} 
    fclose(fp);
}
// 打印指定位置的信息 
void pb(int i,int j)
{
	if(j!=0)
	{
		printf("\n");
		printf("%-14s%-22s%-14s%-9s%-5s\n","书号","书名","作者","单价","数量");
		printf("----------------------------------------------------------\n"); 
	}
	if(i!=-1)
	{
		printf("%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);
	}
}
// 图书列表函数 
void bklist()
 {
 	int i;
 	system("cls");
 	    printf("%-14s%-22s%-14s%-9s%-5s\n","书号","书名","作者","单价","数量");
 	printf("---------------------------------------------------\n");
 	for(i=0;i<bknum;i++)
 	{
 		printf("%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);	
    }
	getch();
}
//图书录入函数 
void bkin()
{
	int i,n1;
	char b[10];
	system("cls");
	printf("\n\n\n");
	printf("----------------------图书进库------------------\n");
	printf("------------------------------------------------\n");
	printf("\n\n\n");
	printf("请输入书号：");
	scanf("%s",b);
    if(strcmp(b,"000"))
	{
		int count=0;
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				printf("该书已存入，请输入书的数量\n");
				scanf("%d",&n1);
				bk[i].num+=n1;
				count++;
			}
		}
		if(count==0)
		{
			strcpy(bk[i].isbn,b);
			printf("请输入书名：");
			scanf("%s",bk[i].bkname);
			printf("请输入作者：");
     	    scanf("%s",bk[i].author);
			printf("请输入价格：");
			scanf("%f",&bk[i].price);
			printf("请输入数量：");
			scanf("%d",&bk[i].num);
			bknum++;
		}
	}
	wdata();
}
//图书销售函数 
void bksell()
{
	int i,count=0,a;
	char b[10];
	BOOK s[100];
	float sum=0,in,out;
		system("cls");
	printf("----------------图书销售----------------\n\n\n");
	printf("\n\n"); 
	printf("请输入书号或输入000停止结算：>");
   	scanf("%s",b);
	int cou=0;
	while(strcmp(b,"000"))
	{
		
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				cou++;
			    if(bk[i].num>0)
			    {
				s[count++]=bk[i];
				bk[i].num--;
				sum+=bk[i].price;
			    }
			    else
			    {
				printf("抱歉，该书库存不足\n");
				printf("按任意键返回\n");
				getch();
				break;
			   }
			}
		}
		
	    if(cou==0)
		{
			printf("该书未入库\n");
			printf("请先入库后再进行销售\n");
			getch();
		}
		printf("请输入书号：>");
   	    scanf("%s",b);
		wdata();
	}
	system("cls");
		printf("---------------------------------------------------------\n");
		printf("---------------零售清单\t输入000即可进行结算-------------\n");
		printf("---------------------------------------------------------\n");
		scanf("%d",&a);
		system("cls");
		if(a==000)
		{
		    printf("%-10s%-20s%-10s%-6s\n","书号","书名","作者","单价"); 
		    printf("---------------------------------------------------------\n");
	        for(i=0;i<count;i++)
		    {
			printf("%-10s%-20s%-10s%-6.2f\n",s[i].isbn,s[i].bkname,s[i].author,s[i].price);
		    }
		}
	
	printf("---------------------------------------------------------\n");
	printf("总价：> %.2f\n",sum);
	printf("您购买的书本数量为：> %d",count);
	printf("\n请输入收入金额：>");
	scanf("%f",&in);
	out=in-sum;
	printf("找零：> %6.2f",out);
	getch();
}
//图书查询函数 
void bkfind()
{
	int select=-1,t=0;
	char in[20],b;
	while(select)
	{
		system("CLS");
		printf("\n\n 请按需求进行查询：""\n\n\t\t\t\t1. 搜书名\n\n\t\t\t\t2. 搜作者\n\n\t\t\t\t0. 退出\n  -->");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
				select=0;
				break;
			case 1:
				select=1;
				break;
			case 2:
				select=2;
				break;
			default :
				printf("输入错误，请重新输入");
		}
		
		if(select==1)
		{
			printf("\n 请输入书名：>");
			scanf("%s",in);
			if(strlen(in)==0)
			{
				continue;
			}
			
			for(int i=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].bkname)==0)
				{
					pb(i,1);
					t=1;
				}
			}
			if(t!=1)
			{
				printf("\n 找不到对应的书！\n");
			}
				
		}
		if(select==2)
		{
			printf("\n 请输入作者：>");
			scanf("%s",in);
			for(int i=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].author)==0)
				{
					pb(i,1);
					t=1;
				}
			}
			if(t!=1)
			{
				printf("\n 找不到对应的书！\n");
			}
				
	   }
		
			getch();
	} 	
}
//图书删除函数 
void bookdelete()
{
	char text[10];
	int i,j,k,tip=0,t20=0;
	system("CLS");
	printf("\n 输入【del 书号】并回车可执行删除操作如：del 001\n");
	printf("\n 输入f可刷新列表哦！\n ");
	printf("\n 输入000返回\n");
	printf("\n----------------------------------------\n");
	pb(-1,1);
	for(i=0;i<bknum;i++,t20++)
	{
	   pb(i,0);
		if(t20==20)
		{
			printf("\n\n");
			system("PAUSE");
		}
	}
	printf("\n");
	while(1) 
	{
			 if(bknum==0)
		 {
		 	printf("列表为空！\n\n");
		 }
		 printf("-->");
		scanf("%s",text);
		if(strcmp(text,"del")==0)
		{
		 	tip=0;
		 	scanf("%s",text);
		 	for(j=0;j<bknum;j++)
			{
				if(strcmp(text,bk[j].isbn)==0)
		 		{
		 			for(k=j;k<bknum;k++)
		 			{
		 				bk[k]=bk[k+1];
	     			}
				     bknum--;		
						 printf("\n删除成功!\n\n");
						 tip=1;
				}
					 if(tip==0)
					 {
					 	printf("\n未找到删除项！\n\n");
					 } 
			 }			 
		}
		 if(strcmp(text,"000")==0)
		 {
		 	return;
		 }
		 if(strcmp(text,"f")==0)
		 {
		 	bklist();
		 	getch();
		 	return ;
		 }
		 fflush(stdin);
		  wdata();
	} 
  	
}
//菜单列表 
int showsell()
{
	int sell;
	system("cls");
	
	printf("  \n\n\n");
	printf("                书店管理系统\n");
	printf("------------------------------------------\n");
	printf("                0：退出\n\n");
	printf("                1：图书列表\n");
	printf("                2：图书录入\n");
	printf("                3：图书销售\n");
	printf("                4：图书查询\n");
	printf("                5：图书删除\n");
	printf("------------------------------------------\n");
	printf("             请输入您想查询的：>          \n");
	
	scanf("%d",&sell);
	return sell;
	
}
//主函数 
 int main()
 {
 	int sell=-1;
 	int k;
 	rdata();
 	while(sell!=0)
 	{
 		switch(sell)
 		{
 			case 0:break;
 			case 1:bklist();break;
 			case 2:bkin();break;
 			case 3:bksell();break;
 			case 4:bkfind();break;
 			case 5:bookdelete();break;
		 }
		 sell=showsell();
	 }
 }
 

