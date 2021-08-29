#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	int member;
	struct List *next;
}queue;
typedef struct List2{
	int member;
	struct List2 *next;
}stack;
queue *front=NULL;
queue *last=NULL;
stack *st=NULL;
stack *p=NULL;
int Hw();
void Display(int size);
int Push(int number);
void Reset();
int main() {
Hw();
return 0;
}
int Hw(){
	int size;
	FILE * dosya;
    dosya = fopen("data.txt", "r");
    fscanf(dosya,"%d",&size);
while(!feof(dosya)){
	queue *Queue=NULL;
    Queue=(queue*)malloc(sizeof(queue));
	int i=0;
	for(i;i<size;i++){
	if(front!=NULL){
		    Queue=(queue*)malloc(sizeof(queue));
			fscanf(dosya,"%d,",&Queue->member);
			last->next=Queue;
			Queue->next=NULL;                                              //Reading data-line from data.txt - also enqueue part 
			last=Queue;
		}
		else
		{
			fscanf(dosya,"%d,",&Queue->member);
			last=Queue;
			front=Queue;
			Queue->next=NULL;
		}
}
printf("Queue: ");
Display(size);
queue *f;
f=front;
int j=0;
for(j;j<size;j++){
	if(f->member%2==1){
		Push(f->member);
		f=f->next;                                                //Pushing odd numbers from queue into stack .
	}
	else
	{
		f=f->next;
	}
}
queue *t;
t=front;
int o=0;
for(o;o<size;o++){
	if(t->member%2==1){
		t->member=p->member;
		t=t->next;                                              // Chancing location odd numbers and creating new queue .
		p=p->next;
	}
	else
	{
		t=t->next;
	}
}
printf("New Queue: ");
Display(size);
Reset();                                                       //Reset of stack and queue .
printf("\n");
}
return 0;
}
int Push(int number){
	p=(stack*)malloc(sizeof(stack));
	if(p==NULL){
		printf("Not enough memory");
		return -1;
	}
	else
	{
		p->member=number;
		p->next=st;
		st=p;
		return 0;
	}
}
void Display(int size){
	queue *p;
	p=front;
	int i=0;
	for(i;i<size;i++){
		printf("%3d",p->member);
		p=p->next;
	}
	printf("\n");
}
void Reset(){
	queue *p;
	p=front;
	while(p){
		front=front->next;
		free(p);
		p=front;
	}
	last=NULL;
	stack *s;
	while(st!=NULL){
		s=st;
		st=st->next;
		free(s);
	}
}
