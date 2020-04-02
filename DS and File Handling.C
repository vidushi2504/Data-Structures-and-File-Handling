/*Submitted by: VIDUSHI GUPTA
Roll No:1812917
Class Roll No:116
BTech CS II year
Sction B*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct node
{
	int len;
	struct node *next;
	char st[256];
};
typedef struct node NODE;
struct dllnode
{
	char st[256];
	int len;
	struct dllnode *next, *prev;
};
typedef struct dllnode DLLNODE;
DLLNODE* dllinsertf(DLLNODE *ss, char st[]);
DLLNODE* dllcreatenode(DLLNODE *temp, char st[]);
DLLNODE* dllinsertl(DLLNODE *ss, char st[]);
DLLNODE* dlldeletef(DLLNODE *ss);
DLLNODE* dlldeletel(DLLNODE *ss);
void dlldisplayf(DLLNODE *ss);
void dlldisplayr(DLLNODE *ss);
DLLNODE* dllinserts(DLLNODE *ss, char st[], int pos);
int dllsize(DLLNODE *ss);
DLLNODE* dlldeletes(DLLNODE *ss,int pos);
NODE* createnode(NODE *temp, char s[]);
NODE* insertf(NODE *s, char st[]);
NODE* insertl(NODE *s, char st[]);
NODE* deletef(NODE *s);
NODE* deletel(NODE *s);
void display(NODE *s);
void displayfile();
void dlldisplayfile();
NODE* insertsp(NODE *s, char st[], int pos);
NODE* deletesp(NODE *s, int pos);
void main()
{
	int d, ch, pos;
	char st[256];
	NODE *s=NULL;
	DLLNODE *ss=NULL;
	clrscr();
	gotoxy(30,1);
	printf("Options\n1.Singly Linked List\n2.Doubly Linked List\n3.Exit\nEnter choice\n");
	scanf("%d",&d);
	switch(d)
	{
		case 1: do{     clrscr();
				gotoxy(30,1);
				printf("MENU\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Display\n6.Display File\n7.Insert specified\n8.Delete Specified\n9.Exit\n\n");
				printf("Enter choice");
				fflush(stdin);
				scanf("%d",&ch);
				switch(ch)
				{
					case 1: printf("Enter string");
						fflush(stdin);
						gets(st);
						s=insertf(s,st);
						break;
					case 2: printf("Enter string");
						fflush(stdin);
						gets(st);
						s=insertl(s,st);
						break;
					case 3: s=deletef(s);
						sleep(3);
						break;
					case 4: s=deletel(s);
						sleep(3);
						break;
					case 5: display(s);
						sleep(5);
						break;
					case 6: displayfile();
						sleep(5);
						break;
					case 7: printf("Enter string");
						fflush(stdin);
						gets(st);
						printf("Enter position");
						scanf("%d",&pos);
						s=insertsp(s,st,pos);
						break;
					case 8: printf("Enter position");
						scanf("%d",&pos);
						s=deletesp(s,pos);
						sleep(3);
						break;
				}
			}while(ch!=9);
			break;
		case 2: do{     clrscr();
				gotoxy(30,1);
				printf("MENU\n1.Insert First\n2.Insert Last\n3.Delete First\n4.Delete Last\n5.Display Forward\n6.Display File\n7.Insert specified\n8.Delete Specified\n9.Display Backwards\n10.Exit\n\n");
				printf("Enter choice");
				fflush(stdin);
				scanf("%d",&ch);
				switch(ch)
				{
					case 1: printf("Enter string");
						fflush(stdin);
						gets(st);
						ss=dllinsertf(ss,st);
						break;
					case 2: printf("Enter string");
						fflush(stdin);
						gets(st);
						ss=dllinsertl(ss,st);
						break;
					case 3: ss=dlldeletef(ss);
						sleep(3);
						break;
					case 4: ss=dlldeletel(ss);
						sleep(3);
						break;
					case 5: dlldisplayf(ss);
						sleep(5);
						break;
					case 6: dlldisplayfile();
						sleep(5);
						break;
					case 7: printf("Enter string");
						fflush(stdin);
						gets(st);
						printf("Enter position");
						scanf("%d",&pos);
						ss=dllinserts(ss,st,pos);
						break;
					case 8: printf("Enter position");
						scanf("%d",&pos);
						ss=dlldeletes(ss,pos);
						sleep(3);
						break;
					case 9: dlldisplayr(ss);
						sleep(5);
						break;
				}
			}while(ch!=10);
			break;

	}
}

NODE* createnode(NODE *temp, char s[])
{
	int i;
	temp=(NODE*)malloc(sizeof(struct node));
	strcpy(temp->st,s);
	temp->len=strlen(s);
	temp->next=NULL;
	return temp;
}
NODE* insertf(NODE *s, char st[])
{
	NODE *temp;
	FILE *fp1,*fp2;
	char ch;
	char t[256];
	temp=createnode(temp,st);
	fp1=fopen("abcd.txt","w");
	fp2=fopen("abc.txt","r");
	if(s==NULL)
	{
		s=temp;
	}
	else
	{
		temp->next=s;
		s=temp;
	}
	fwrite(temp->st,(temp->len)*(sizeof(char)),1,fp1);
	fprintf(fp1,"\n");
	while((ch=fgetc(fp2))!=EOF)
	{
		fputc(ch,fp1);
	}
	fclose(fp1);
	fclose(fp2);
	remove("abc.txt");
	rename("abcd.txt","abc.txt");
	return s;
}
NODE* insertl(NODE *s, char st[])
{
	NODE *temp, *t;
	FILE *fp1;
	temp=createnode(temp, st);
	fp1=fopen("abc.txt","a");
	if(s==NULL)
	{
		s=temp;
	}
	else
	{
		for(t=s;t->next!=NULL;t=t->next);
		t->next=temp;
	}
	fwrite(temp->st,(temp->len)*(sizeof(char)),1,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
	return s;
}
NODE* deletef(NODE *s)
{
	NODE *t;
	FILE *fp1, *fp2;
	char ch;
	if(s==NULL)
	{
		printf("Underflow\n");
		return s;
	}
	else
	{
		t=s;
		s=t->next;
		puts(t->st);
		free(t);
	}
	fp1=fopen("abc.txt","r");
	fp2=fopen("abcd.txt","w");
	while((ch=fgetc(fp1))!='\n');
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("abc.txt");
	rename("abcd.txt","abc.txt");
	return s;
}
NODE* deletel(NODE *s)
{
	NODE *t, *p;
	int n=0;
	FILE *fp1, *fp2;
	char ch, ti[256];
	if(s==NULL)
	{
		printf("Underflow\n");
		return s;
	}
	else
	{
		for(t=s;t->next!=NULL;p=t,t=t->next);
		p->next=NULL;
		puts(t->st);
		free(t);
	}
	fp1=fopen("abc.txt","r");
	fp2=fopen("abcd.txt","w");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch=='\n')
		n++;
	}
	n=n-1;
	fseek(fp1,0,SEEK_SET);
	while(n--)
	{
		fgets(ti,265,fp1);
		fputs(ti,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("abc.txt");
	rename("abcd.txt","abc.txt");
	return s;
}
void display(NODE *s)
{
	NODE *t;
	if(s==NULL)
	{
		printf("Underflow\n");
	}
	else
	{
		for(t=s;t!=NULL;t=t->next)
		{
			puts(t->st);
		}
	}
}
int size(NODE* s)
{
	NODE *t;
	int i;
	for(i=1,t=s;t!=NULL;i++,t=t->next);
	return i;
}
NODE* insertsp(NODE *s, char st[], int pos)
{
	NODE *t, *temp;
	int n=1, i, flg=0;
	char ch;
	FILE *fp1, *fp2;
	if(pos<1 || pos>size(s))
	{
		printf("Invalid position\n");
		return s;
	}
	else if(pos==1)
	{
		s=insertf(s,st);
		return s;
	}
	else if(pos==size(s)+1)
	{
		s=insertl(s,st);
		return s;
	}
	else
	{
		temp=createnode(temp, st);
		for(i=1, t=s;i<(pos-1);i++,t=t->next);
		temp->next=t->next;
		t->next=temp;
	}
	fp1=fopen("abc.txt","r");
	fp2=fopen("abcd.txt","w");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch=='\n')
		n++;
		fputc(ch,fp2);
		if(n==pos)
		{
			fputs(st,fp2);
			fprintf(fp2,"\n");
			n++;
			flg=1;
		}
	}
	if(flg==0)
	{
		fprintf(fp2,"\n");
		fputs(st,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("abc.txt");
	rename("abcd.txt","abc.txt");
	return s;
}
NODE* deletesp(NODE *s, int pos)
{
	NODE *t, *p;
	int i, n=1;
	char ch;
	FILE *fp1, *fp2;
	if(pos<1 || pos>size(s))
	{
		printf("Invalid Position\n");
		return s;
	}
	else if(pos==1)
	{
		s=deletef(s);
	}
	else if(pos==size(s))
	{
		s=deletel(s);
	}
	else
	{
		for(i=0,t=s;i<(pos-1);i++,p=t,t=t->next);
		p->next=t->next;
		puts(t->st);
		free(t);
	}
	fp1=fopen("abc.txt","r");
	fp2=fopen("abcd.txt","w");
	while((ch=getc(fp1))!=EOF)
	{
		if(ch=='\n')
		{
			n++;
			if(n==pos)
			while((ch=getc(fp1))!='\n');
			fputc(ch, fp2);
		}
		else
		{
			fputc(ch,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("abc.txt");
	rename("abcd.txt","abc.txt");
	return s;
}
//Displaying contents of file
void displayfile()
{
	FILE *fp1;
	char st[256];
	char ch;
	fp1=fopen("abc.txt","r");
	while((ch=fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp1);
}
void dlldisplayfile()
{
	FILE *fp1;
	char st[256];
	char ch;
	fp1=fopen("def.txt","r");
	while((ch=fgetc(fp1))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp1);
}
//Doubly Linked List
DLLNODE* dllcreatenode(DLLNODE *temp, char st[])
{
	temp=(DLLNODE*)malloc(sizeof(struct dllnode));
	strcpy(temp->st,st);
	temp->len=strlen(st);
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
DLLNODE* dllinsertf(DLLNODE *ss, char st[])
{
	DLLNODE *temp;
	FILE *fp1, *fp2;
	char ch;
	fp1=fopen("defg.txt","w");
	fp2=fopen("def.txt","r");
	temp=dllcreatenode(temp,st);
	if(ss==NULL)
	ss=temp;
	else
	{
		temp->next=ss;
		ss->prev=temp;
		ss=temp;
	}
	fwrite(temp->st,(temp->len)*(sizeof(char)),1,fp1);
	fprintf(fp1,"\n");
	while((ch=fgetc(fp2))!=EOF)
	{
		fputc(ch,fp1);
	}
	fclose(fp1);
	fclose(fp2);
	remove("def.txt");
	rename("defg.txt","def.txt");
	return ss;
}
DLLNODE* dllinsertl(DLLNODE *ss, char st[])
{
	DLLNODE *temp, *t;
	FILE *fp1;
	fp1=fopen("def.txt","a");
	temp=dllcreatenode(temp,st);
	if(ss==NULL)
	ss=temp;
	else
	{
		for(t=ss;t->next!=NULL;t=t->next);
		t->next=temp;
		temp->prev=t;
	}
	fwrite(temp->st,(temp->len)*(sizeof(char)),1,fp1);
	fprintf(fp1,"\n");
	fclose(fp1);
	return ss;
}
DLLNODE* dlldeletef(DLLNODE *ss)
{
	DLLNODE *t;
	FILE *fp1, *fp2;
	char ch;
	if(ss==NULL)
	printf("Underflow");
	else
	{
		t=ss;
		ss=t->next;
		ss->prev=NULL;
		puts(t->st);
		free(t);
	}
	fp1=fopen("def.txt","r");
	fp2=fopen("defg.txt","w");
	while((ch=fgetc(fp1))!='\n');
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("def.txt");
	rename("defg.txt","def.txt");
	return ss;
}
DLLNODE* dlldeletel(DLLNODE *ss)
{
	DLLNODE *t, *p;
	FILE *fp1, *fp2;
	char ch, ti[256];
	int n=0;
	if(ss==NULL)
	printf("Underflow");
	else
	{
		for(t=ss;t->next!=NULL;p=t,t=t->next);
		if(t==ss)
		ss=NULL;
		else
		p->next=NULL;
		puts(t->st);
		free(t);
	}
	fp1=fopen("def.txt","r");
	fp2=fopen("defg.txt","w");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch=='\n')
		n++;
	}
	n=n-1;
	fseek(fp1,0,SEEK_SET);
	while(n--)
	{
		fgets(ti,265,fp1);
		fputs(ti,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("def.txt");
	rename("defg.txt","def.txt");
	return ss;
}
void dlldisplayf(DLLNODE *ss)
{
	DLLNODE *t;
	if(ss==NULL)
		printf("Underflow");
	else
	{
		for(t=ss;t!=NULL;t=t->next)
		{
			puts(t->st);
		}
	}
}
void dlldisplayr(DLLNODE *ss)
{
	DLLNODE *t, *p;
	if(ss==NULL)
	printf("Underflow");
	else
	{
		for(t=ss;t->next!=NULL;t=t->next);
		for(p=t;p!=NULL;p=p->prev)
		{
			puts(p->st);
		}
	}
}
int dllsize(DLLNODE *ss)
{
	DLLNODE *t;
	int i;
	for(t=ss, i=0;t!=NULL;t=t->next, i++);
	return i;
}
DLLNODE* dllinserts(DLLNODE *ss, char st[], int pos)
{
	DLLNODE *temp, *t, *p=ss;
	FILE *fp1, *fp2;
	int l, i, n=1, flg=0;
	char ch;
	l=dllsize(ss);
	if(pos<0 || pos>(l+1))
	{
		printf("Not Possible");
		return ss;
	}
	else if(pos==1)
	{
		ss=dllinsertf(ss,st);
		return ss;
	}
	else if(pos==(l+1))
	{
		ss=dllinsertl(ss,st);
		return ss;
	}
	else if(pos>1 && pos<=l)
	{
		temp=dllcreatenode(temp,st);
		for(t=ss, i=1;i<pos;p=t,t=t->next,i++);
		temp->next=t;
		p->next=temp;
		t->prev=temp;
		temp->prev=p;
	}
	fp1=fopen("def.txt","r");
	fp2=fopen("defg.txt","w");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(ch=='\n')
		n++;
		fputc(ch,fp2);
		if(n==pos)
		{
			fputs(st,fp2);
			fprintf(fp2,"\n");
			n++;
			flg=1;
		}
	}
	if(flg==0)
	{
		fprintf(fp2,"\n");
		fputs(st,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("def.txt");
	rename("defg.txt","def.txt");
	return ss;
}
DLLNODE* dlldeletes(DLLNODE *ss,int pos)
{
	DLLNODE *t, *p;
	FILE *fp1, *fp2;
	int l, i, n=0;
	char ch;
	l=dllsize(ss);
	if(pos<0 || pos>l)
	{
		printf("Not Possible");
		return ss;
	}
	else if(pos==1)
	{
		ss=dlldeletef(ss);
		return ss;
	}
	else if(pos==l)
	{
		ss=dlldeletel(ss);
		return ss;
	}
	else
	{
		for(t=ss,i=0;i<(pos-1);p=t,t=t->next,i++);
		p->next=t->next;
		(t->next)->prev=p;
		puts(t->st);
		free(t);
	}
	fp1=fopen("def.txt","r");
	fp2=fopen("defg.txt","w");
	while((ch=getc(fp1))!=EOF)
	{
		if(ch=='\n')
		{
			n++;
			if(n==pos)
			while((ch=getc(fp1))!='\n');
			fputc(ch, fp2);
		}
		else
		{
			fputc(ch,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("def.txt");
	rename("defg.txt","def.txt");
	return ss;
}