#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct shoppingitem
{
    char name[15];//���� 
    int quantity;//���� 
    struct shoppingitem *next;
};
//���� 
struct shoppingitem *insert(struct shoppingitem *h)
{
    struct shoppingitem *p=h,*q=NULL,*t=NULL;
    
    t=(struct shoppingitem *)malloc(sizeof(struct shoppingitem));
    scanf("%s%d",t->name,&t->quantity);
    t->next=NULL;
        while(p)
        {
            if(p->quantity>t->quantity)
            {
                if(p==h)
                    h=t;
                else
                    q->next=t;
                t->next=p;
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        if(p==NULL&&h!=NULL)
            q->next=t;
    else if(h==NULL)h=t;
}
//�Ƴ���Ʒ
void removeitem(char itemname[],struct shoppingitem *shoppinglist)
{
struct shoppingitem *current=shoppinglist;
struct shoppingitem *previous=NULL;
while(current!=NULL)
{
	if(strcmp(current->name,itemname)==0)
	{
		if(previous!=NULL)
		{
			previous->next=current->next;
		}
		else
		{
			shoppinglist=current->next;
			
		}
		free(current);
		break;
	}
	previous=current;
	current=current->next;
}
} 
//�鿴�����嵥
void displaylist(struct shoppingitem *shoppinglist)
{
	struct shoppingitem *current=shoppinglist;
	printf("�����嵥\n");
	while(current!=NULL)
	{
		printf("%s-����:%d\n",current->name,current->quantity);
		current=current->next; 
	}
 } 
 //�޸�����
 void updatequantity(char itemname[],int newitemquantity,struct shoppingitem *shoppinglist)
 {
 	struct shoppingitem *current=shoppinglist;
 	while(current!=NULL)
 	{
 		if(strcmp(current->name,itemname)==0)
 		{
 			current->quantity=newitemquantity;
 			break;
		 }
		 current=current->next;
	 }
  } 
  //��չ����嵥
  void clearlist(struct shoppingitem *shoppinglist)
  {
  	struct shoppingitem *temp;
  	while(shoppinglist!=NULL)
  	{
  		temp=shoppinglist;
  		shoppinglist=temp->next;
  		free(temp);
	  }
   } 
   //���㹺����Ʒ�嵥�е�������
   int totalquantity(struct shoppingitem *shoppingitem)
   {
   	struct shoppingitem *current=shoppingitem;
   	int total=0;
   	while(current!=NULL)
   	{
   		total++;
   		current=current->next;
	   }
	} 
	//���ҹ����嵥�ҵ���Ʒ
	void finditem(char itemname[],struct shoppingitem *shoppinglist)
	{
		struct shoppingitem *current=shoppinglist;
		printf("������Ʒ%s:\n",itemname);
		while(current!=NULL)
		{
			if(strcmp(current->name,itemname)==0)
			{
				printf("%s-����:%d\n",current->name,current->quantity);
				return;
			}
			current=current->next;
		}
		printf("δ�ҵ���Ʒ%s:\n",itemname);
	 } 
	 //�������嵥
	 void sortlist(struct shoppingitem *shoppinglist)
	 {
	 	struct shoppingitem *current=shoppinglist;
	 	struct shoppingitem *nextitem=NULL;
	 	char tempname[50];
	 	int tempquantity;
	 	while(current!=NULL)
	 	{
	 		
	 		nextitem=current->next;
	 		while(nextitem!=NULL)
	 		{
	 			if(strcmp(current->name,nextitem->name)>0)
	 			{
	 				strcpy(tempname,current->name);
	 				strcpy(current->name,nextitem->name);
	 				strcpy(nextitem->name,tempname);
	 				tempquantity=current->quantity;
	 				current->quantity=nextitem->quantity;
	 				nextitem->quantity=tempquantity;
				 }
				 nextitem=nextitem->next;
			 }
			 current=current->next;
		 }
	  } 
//ɾ�������嵥�е���Ʒ
void deleteitem(char itemname[],int deleteall,struct shoppingitem *shoppinglist)
{
	struct shoppingitem *current=shoppinglist;
	struct shoppingitem *prev = NULL;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemname)==0)
		{
			if(prev==NULL)
			{
				struct shoppingitem *temp=shoppinglist;
				shoppinglist=shoppinglist->next;
				free(temp);
				if(!deleteall)break;
			}
			else
			{
				prev=current;
				free(current);
				current=prev->next;
				if(!deleteall)break;
			}
		}
		else
		{
			prev=current;
			current=current->next;
		}
	}
 } 
int main(void)
{
  struct shoppingitem *h=NULL,*p,*q;
    char n[15];
    int quan;
    int sum;
	scanf("%d",&sum); 
    scanf("%s%d",n,&quan);
    for(int i=0;i<sum;i++)
    {
        p=(struct shoppingitem *)malloc(sizeof(struct shoppingitem));
        strcpy(p->name,n);
        p->quantity=quan;
        p->next=NULL;
        
        if(h==NULL)
            h=p;
        else
            q->next=p;
        q=p;
        
        scanf("%s%d",n,&quan);
    }
    return 0;   

}
