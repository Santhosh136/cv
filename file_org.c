#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insert();
void delete();
void display();
void ins();
void del();
void dis();

char st[10];

struct node
{
 char name[10];
 int flag;
 //struct node * file;
 char ns[10][10];
 struct node * nxt;
 struct node * prv;
};

struct node *first=NULL,*last=NULL,*temp=NULL,*new=NULL,*store=NULL,*head=NULL,*tail=NULL;
int i=0,j,k;

typedef struct node n;

n* createnode(char a[10])
{
 new=(n*)malloc(sizeof(n));
 strcpy(new->name,a);
 new->nxt=new->prv=NULL;
 return new;
}

void insert()
{

 if(first==NULL)
 {
  printf("\nEnter root dir name:");
  scanf("%s",st);
  new=createnode(st);
  first=last=new;
  first->nxt=last->nxt=NULL;
  first->prv=last->prv=NULL;
 }
 else
 {
  printf("\nEnter file name:");
  scanf("%s",st);
  new=createnode(st);
  last->nxt=new;
  new->prv=last;
  last=new;
  last->nxt=NULL;
 }
}

void ins()
{
 int c;
 char n[10];
 if(first==NULL)
 {
  printf("\nEnter root dir name:");
  scanf("%s",st);
  new=createnode(st);
  first=last=new;
  first->nxt=last->nxt=NULL;
  first->prv=last->prv=NULL;
 }
 else
 {
 printf("\nEnter 1 for dir 2 for file 3 for create file in dir:");
 scanf("%d",&c);
 if(c==3)
 {
  printf("\nEnter the dir name:");
  scanf("%s",n);
  temp=first;
  while(temp!=NULL)
  {
   if(strcmp(n,temp->name)==0)
   {
    store=temp;
   }
   temp=temp->nxt;
  }
  if(store==NULL)
  {
   printf("\nDir is not found");
  }
  else
  {
   store->flag=1;
   printf("\nEnter the file name:");scanf("%s",st);
   strcpy(store->ns[i],st);
   i++;
  }
 }
 else 
 {
 if(c==1)
 {
  printf("\nEnter dir name:");scanf("%s",n);
 }
 else if(c==2)
 {
  printf("\nEnter file name:");scanf("%s",n);
 }
 new=createnode(n);
 last->nxt=new;
 new->prv=last;
 last=new;
 last->nxt=NULL;
 }
 } 
}

void display()
{
 if(first==NULL)
 {
  printf("\nList is empty");
 }
 else
 {
  temp=first->nxt;
  while(temp!=NULL)
  {
   printf("\n%s=>%s",first->name,temp->name);
   temp=temp->nxt;
  }
 }
}

void dis()
{
 if(first==NULL)
 {
  printf("\nNo files");
 }
 else
 {
  temp=first->nxt;
  while(temp!=NULL)
  {
   if(temp->flag==1)
   {
    printf("\n%s => %s",first->name,temp->name);
    for(j=0;j<i;j++)
    {
     printf("\n=> %s",temp->ns[j]);
    }
   }
   else
   {
    printf("\n%s => %s",first->name,temp->name);
   }
   temp=temp->nxt;
  }
 }
}

void single()
{
 int c;
 do
 {
  printf("\nEnter 1.insert 2.delete 3.display 4.exit :");
  scanf("%d",&c);
  switch(c)
  {
   case 1:insert();
   break;
   //case 2:delete();
   break;
   case 3:display();
   break;
   case 4:break;
  }
 }while(c!=4);
}

void two()
{
 int c;
 do
 {
  printf("\nEnter 1 insert 2.delete 3.display 4.exit :");
  scanf("%d",&c);
  switch(c)
  {
  case 1:ins();break;
  //case 2:del();break;
  case 3:dis();break;
  case 4:break;
  }
 }while(c!=4);
}

void main()
{
 int choice;
 printf("\nEnter 1)Single level 2)Double level 3)Multi level:");scanf("%d",&choice);
 switch(choice)
 {
 case 1:single();break;
 case 2:two();break;
 case 3:break;
 }
}					
