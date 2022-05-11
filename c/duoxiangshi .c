#include <stdio.h>
#include <stdlib.h>
Polyn Createpoly()
{
	Polynomail *head ,*rear,*s;
	int c,e;
	head=(Polynomail * )malloc (sizeof(Polynomail));
	rear = head;
	scanf("%d,%d",&%c,&e);
	while(c!=0)
	{
		s=(Polynomail * )malloc(sizeof(Polynomail));
		s->coeff = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		scanf("%d,%d",&c,&e);
	}
	rear->next =NULL;
	return (head);
 } 
 
 void PrintPolyn(Polyn p)
 {
 	Polyn q = p->next;
 	int flag = 1;
 	if(!q)
 	{
 		putchar('0');
 		printf("\n");
 		return;
	 }
	 while(q)
	 {
	 	if(q->coef>0&&flag!=1)
	 	putchar("+");
	 	if(q->coef!=1&&q->coef!=1)
	 	{
	 		printf("%g",q->coef);
	 		if(q->expn ==1)
			 putchar('X');
			 else if(q->expn)
			 printf("X^%d",q->expn);
		 }
		 else
		 {
		 	if(q->coef ==1)
		 	{
		 		if(!q->expn)
		 		putchar('1');
		 		else if(q->expn==1)
		 		putchar('X');
		 		else printf ("X^%d",q->expn); 
			 }
			 if(q->coeff==-1)
			 {
			 	if(!q->expn)
			 	printf("-1");
			 	else if(q->expn==1)
			 	printf("-X");
			 	else printf("-X^%d",q->expn);
			 }
		 	
		 }
		 q=q->next;
		 flag++; 
	 }
	 printf("\n");
 }
 
 Polyn Addpolyn(Polyn pa,Polyn pb)
 {
 	Polyn qa=pa->next;
 	Polyn qb=pb->nxet;
	Polyn headc,pc,qc; 
	pc=(polyn)malloc(sizeof(struct Polynmail));
	pc->next =NULL;
	headc =pc;
	while (qa!=NULL&&qb!=NULL)
	{
		qc=(Poyln)malloc(sizeof(struct Polynmail));
		if(qa->expn<qb->expn)
		{
			qc->coef=qa->coef;
			qc->expn=qa->expn;
			qa=pa->next;
		}
		else if(qa->expn==qb->expn)
		{
			qc->expn=qa->expn+qb->expn;
			qc->expn=qa->expn;
			qa=qa->next;
			qb=qb->next;
		}
		else
		{
			qc->coef=qb->coef;
			qc->expn=qb->expn;
			qb=qb->expn;
		}
		if(qc->coef!=0)
		{
			qc->next=pc->next;
			pc->next=qc;
			pc=qc;
		}
		else free(pc);		
	}
	while(qa!=NULL)
	{
		qc=(Polyn)malloc(sizeof(Polynmial));
		qc->coef=qa->coef;
		qc->expn=qa->expn 
		qa=qa->next;
		qc->next=pc->next;
		pc->next=qc;
		pc=qc; 
		 
	}
	while(qb!=NULL)
	{
		qc=(POlyn)malloc(sizeof(struct)Polynmail);
		qc->coef=qb->coef;
		qc->expn=qb->expn;
		qb=qb->next;
		qc->next=pc->next;
		pc->next=qc;
	}
	return headc;
 }
 
 PolynSubtraactPolyn(Polyn pa,Polyn pb)
 {
 	Polyn h=pb;
 	Polyn p=pb->next;
 	Polyn pd;
 	while(p)
 	{
 		p->coef*=1;
 		p=p->next;
	 }
	 pd=AddPolyn (pa,h);
	 for(p=h->next;p;p=p->next)
	 p->coef * =-1;
	 return pb;
 }
