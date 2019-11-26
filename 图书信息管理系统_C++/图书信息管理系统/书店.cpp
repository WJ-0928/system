#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define ISBN 3
#include<windows.h>
int i,bknum;
FILE *fp;
int Mark=0;
typedef struct
{
	char isbn[10];//书号
	char bkname[20];//书名
	char author[10];//作者
	float price;//单价 
	int num; //数量 
}BOOK;
BOOK bk[1000];
void rdata()
{
	FILE *fp;
	if((fp=fopen("bookdata.txt","rb"))==NULL)
	{
		printf("Can not open the file!\n");
		return;
	}
	fread(&bknum,sizeof(int),1,fp);
	fread(bk,sizeof(BOOK),bknum,fp);
	fclose(fp);
 } 
 void wdata()
 {
    FILE *fp;
    if((fp=fopen("bookdata.txt","wb"))==NULL)
	{
 		printf("Can not open the file!\n");
 		return;
    }
    fwrite(&bknum,sizeof(int),1,fp);
    fwrite(bk,sizeof(BOOK),bknum,fp);
    fclose(fp);
 }
void pb(int i,int j)
{
	if(j!=0)
	{
		printf("%-14s%-22s%-14s%-9s%-5s\n","书号","书名","作者","单价","数量");
		printf("----------------------------------------------------------\n"); 
	}
	if(i!=-1)
	{
		printf("%-14s%-22s%-14s%-9.2f%-5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);
	}
}
void booklist()
{
	char text[10];
	int i,j,k,t20=1,tip=0;
	system("CLS");
	printf("\n 输入【del 书号】并回车可执行删除操作如：del 001\n");
	printf("\n 输入f可刷新列表哦！\t 输入000返回\n");
	printf("\n----------------------------------------\n");
	pb(-1,1);
	if(bknum)
	{
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
		 if(!bknum)
		 {
		 	printf("列表为空！\n\n");
		 }
		 while(1)
		 {
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
		 }
		 if(strcmp(text,"000")==0)
		 {
		 	return;
		 }
		 if(strcmp(text,"f")==0)
		 {
		 	booklist();
		 	return;
		 }
		 fflush(stdin);
		 Mark=0;
	} 
 } 
bklist()
 {
 	int i;
 	system("cls");
 	    printf("%-10s%-20s%-10s%-6s%-5s\n","书号","书名","作者","单价","数量");
 	printf("---------------------------------------------------\n");
 	for(i=0;i<bknum;i++)
 	{
 		printf("%-10s%-20s%-10s%-6.2f%5d\n",bk[i].isbn,bk[i].bkname,bk[i].author,bk[i].price,bk[i].num);	
	}
	getch();
 }
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
	while(strcmp(b,"000"))
	{
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				break;
			}
			if(i<bknum)
			{
				printf("该书已存入，请输入书的数量\n");
				scanf("%d",&n1);
				bk[i].num+=n1;
			}
			else
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
			printf("请输入书号：");
			scanf("%s",b);
		}
	}
	wdata();
}
void bksell()
{
	int i,count=0;
	char b[10];
	BOOK s[10];
	float sum=0,in,out;
		system("cls");
	printf("----------------图书销售----------------\n\n\n");
	printf("请输入书号：>");
	scanf("%s",b);
	
	while(strcmp(b,"000"))
	{
		for(i=0;i<bknum;i++)
		{
			if(strcmp(bk[i].isbn,b)==0)
			{
				break;
			}
		}
		
		if(i<bknum)
		{
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
			}
		}
		else
		{
			printf("该书未入库\n");
			printf("请先入库后再进行销售\n");
			getch();
		}
			system("cls");
		printf("---------------------------------------------------------\n");
		printf("---------------零售清单\t输入000即可进行结算-------------\n");
		printf("---------------------------------------------------------\n");
		printf("%-10s%-20s%-10s%-6s%5s\n","书号","书名","作者","单价","数量"); 
		printf("---------------------------------------------------------\n");
		
		for(i=0;i<count;i++)
		{
			printf("%-10s%-20s%-10s%-6.2s%5s\n",s[i].isbn,s[i].bkname,s[i].author,s[i].price,s[i].num);
		}
		
		wdata();
		printf("请输入书号：>");
		scanf("%s",b);
	}
	
	printf("---------------------------------------------------------\n");
	printf("总价：> %.2f\n",sum);
	printf("您购买的书本数量为：> %d",count);
	printf("\n请输入收入金额：>");
	printf("\n%f",&in);
	
	out=in-sum;
	printf("找零：> %6.2f",out);
	getch();
}

void bkfind()
{
	int select=-1,tip=0,k,i,l,t=0,j=0;		//j  是 判断字符 
	char d,in[20],bj[20];
	
	while(1)
	{
		fflush(stdin);
		tip=0;
			system("CLS");
		printf("\n\n 请按需求进行查询：>""\n\n\t\t\t\t1. 搜书名\n\n\t\t\t\t2. 搜作者\n\n\t\t\t\t0. 退出\n");
		
		switch(getch())
		{
			case'0':
				return;
				break;
			case'1':
				select=1;
				break;
			case'2':
				select=2;
				break;
		}
		
		if(select==1)
		{
			printf("\n 请输入书名：>");
		}
		
		tip=0;
		gets(in);
		fflush(stdin);
		
		if(strlen(in)==0)
		{
			continue;
		}
		
		for(i=0,t=0;i<bknum;i++)
		{
			if(strcmp(in,bk[i].bkname)==0)
			{
				pb(i,1);
				t=1;
				tip=1;
			}
		}
		
		if(t!=1)
		{
			for(i=0,j=0;i<bknum;i++)
			{
				if(strcmp(in,bk[i].bkname)==0)
				{
					pb(i,1);
					t=1;
					tip=1;
				}
				else if(t!=1)
				{
					for(k=0;k<strlen(in);k++)
					{
						for(l=0;l<strlen(bk[i].bkname);l++)
						{
							if(in[k]==bk[i].bkname[l]||in[k]==bk[i].bkname[l]+32)
							{
								j++;
							}
						}
					}
					
					if(j>=strlen(in))
					{
						printf("\n");
						pb(i,1);
						tip=1;
					}
					
					j++;
					
				}
			}
			
			if(bknum==0||tip==0)
			{
				printf("\n 找不到对应的书！\n");
			}
			
		}
		
		getch();
		
	 } 
}

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
 			case 5:booklist();break;
		 }
		 sell=showsell();
	 }
 }
 

