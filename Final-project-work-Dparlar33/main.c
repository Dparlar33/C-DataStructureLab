#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define TableSize 2671
#define DataSize 1000

typedef struct HashData {
	char psw[20];
}data_r;

typedef struct SortLinkData{
	char password[20];
	struct SortLinkData *next;
}sort_list;

typedef struct ScoreLinkData2{
	char pass[20];
	int score;
	struct ScoreLinkData2 * next;
}score_list;

sort_list *first =NULL;

sort_list *last =NULL;

score_list *head=NULL;

score_list *tail =NULL;

data_r data[DataSize];

data_r HashTable[TableSize];

int Searching();

int Hashing();

int Hashvalue(char* name);

int HashSearch();

int Linkedlist_assign();

void ascending();

void descending();

int DataRead();

int scoree(char *pswrd);

void Powerfullpw();

void Weaknesspw();

void Swap(int* a, int* b);

int main() 
{

int choice;
printf("To searching in 100.000 passwords list enter 1\n"
       "To see how many collision are there  and which key has how many collision in my hashtable enter 2\n"
	   "To see the top 10 ascending and descending passwords in 1.000 passwords list enter 3 \n"
	   "To see the top 10 strongest and weakness password in 1.000 passwords list enter 4\n"
	   "To exit enter 5: ");
	   
scanf("%d",&choice);

while(choice!=5){
	
if(choice==1){
printf("\n****************************SEARCHING*********************\n");

Searching();

printf("\n");
}
else if(choice==2){
printf("\n***************************TOTAL COLLISION************************\n");
Hashing();

printf("\n**************************COLLISION OF WORDS**************\n");

HashSearch();

printf("\n");
}
else if(choice==3){
printf("\n**************** ASCENGIND AND DESCENDING ORDER************\n");

Linkedlist_assign();

printf("\n");
}
else if(choice==4){
printf("\n****************TOP 10 STRONGEST AND WEAKEST PASSWORD****************\n");

DataRead();

printf("\n");
}
else if (choice==5){
	break;
}

printf("To searching in 100.000 passwords list enter 1\n"
       "To see how many collision are there  and which key has how many collision in my hashtable enter 2\n"
	   "To see the top 10 ascending and descending passwords in 1.000 passwords list enter 3 \n"
	   "To see the top 10 strongest and weakness password in 1.000 passwords list enter 4\n"
	   "To exit enter 5: ");
scanf("%d",&choice);
}
}

int DataRead(){
	score_list *p;
	p=head;
	char x[20];
	FILE * y;
	y = fopen("10-million-password-list-top/1000.txt", "r");
	while(!feof(y)){
		if(p==NULL){
			fscanf(y,"%s",x);
			p=(score_list*)malloc(sizeof(score_list));
			strcpy(p->pass,x);
			p->score=scoree(p->pass);
		head=p;
		tail=p;
		p->next=NULL;
		}
		else
		{
			fscanf(y,"%s",x);
			p=(score_list*)malloc(sizeof(score_list));
			strcpy(p->pass,x);
			p->score=scoree(p->pass);
			tail->next=p;
			p->next=NULL;
			tail=p;
		}
	}
printf("Top 10 strongest password in 1.000 password list ! \n");
Powerfullpw();
printf("\n--------------------------\n");
printf("Top 10 weakness password in 1.000 password list ! \n");
Weaknesspw();
}

int scoree(char *pswrd){
	int score=0;
	int len=strlen(pswrd);
	char pw[len];
	strcpy(pw,pswrd);
	int i=0;
	for(i;i<len;i++){
		if(pw[i]>=97 && pw[i]<=122){
			score++;
			if(pw[i]!=pw[i+1]){
				score++;
			}
		}
		else if(pw[i]>=65 && pw[i]<=90){
			score+=3;
			if(pw[i]!=pw[i+1]){
				score++;
			}
		}
		else{
			score++;
			if(pw[i]!=pw[i+1]){
				score++;
			}
		}
	}
	return score*len;
} 

void Powerfullpw(){
score_list *ptr;
ptr=head;
score_list *temp=NULL;
while(ptr){
	temp=ptr->next;
	while(temp){
		if(ptr->score < temp->score){
			Swap(&ptr->score,&temp->score);
			char *tmp[20];
			strcpy(tmp,ptr->pass);
			strcpy(ptr->pass,temp->pass);
			strcpy(temp->pass , tmp);
		}
	temp=temp->next;
}
	ptr=ptr->next;
}
    int i=0;
	score_list *f;
	f=head;
	while(i<10){
		printf(" %s \n",f->pass);
		f=f->next;
		i++;
	}
}
void Weaknesspw(){
score_list *ptk;
ptk=head;
score_list *temp=NULL;
while(ptk){
	temp=ptk->next;
	while(temp){
		if(ptk->score > temp->score){
			Swap(&temp->score,&ptk->score);
			char *tmp[20];
			strcpy(tmp,ptk->pass);
			strcpy(ptk->pass,temp->pass);
			strcpy(temp->pass , tmp);
		}
	temp=temp->next;
}
	ptk=ptk->next;
}

int i=0;
	score_list *ftr;
	ftr=head;
	while(i<10){
		printf(" %s \n",ftr->pass);
		ftr=ftr->next;
		i++;
	}
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Linkedlist_assign(){
	sort_list *p;
	p=first;
	char x[20];
	FILE * y;
	y = fopen("10-million-password-list-top/10000.txt", "r");
	while(!feof(y)){
		if(p==NULL){
			fscanf(y,"%s",x);
			p=(sort_list*)malloc(sizeof(sort_list));
			strcpy(p->password,x);
		first=p;
		last=p;
		p->next=NULL;
		}
		else
		{
			fscanf(y,"%s",x);
			p=(sort_list*)malloc(sizeof(sort_list));
			strcpy(p->password,x);
			last->next=p;
			p->next=NULL;
			last=p;
		}
	}
	descending();
	printf("\n-----------------------------------------\n");
	ascending();
}
	
void ascending(){
	sort_list *t;
	t=first;
	sort_list *index=NULL;
	while(t)
	{
		index=t->next;
		while (index) {
			if (strcmp(t->password,index->password) > 0) {
				char *tmp[20];
				strcpy(tmp,t->password);
				strcpy(t->password,index->password);
				strcpy(index->password , tmp);
			}
			index=index->next;
		}
		t=t->next;
	}
	printf("The top 10 descending password of the 10.000 list ! \n");
	sort_list *se;
	se=first;
	int i=0;
	while(i<10){
		printf("%s \n",se->password);
		se=se->next; 
		i++;
	}
}

void descending(){
	sort_list *t;
	t=first;
	sort_list *index=NULL;
	while(t)
	{
		index=t->next;
		while (index) {
			if (strcmp(t->password,index->password) < 0) {
				char *tmp[20];
				strcpy(tmp,t->password);
				strcpy(t->password,index->password);
				strcpy(index->password , tmp);
			}
			index=index->next;
		}
		t=t->next;
	}
	printf("The top 10 ascending password of the 10.000 list ! \n");
	sort_list *se;
	se=first;
	int i=0;
	while(i<10){
		printf("%s \n",se->password);
		se=se->next; 
		i++;
	}
}

int Searching() {
	char pw[20];
	printf("Enter a password max 20 character: ");
	scanf("%s",pw);
	printf("\n");
	//Firstly open dosya and read data.
	FILE * dosya;
	dosya = fopen("10-million-password-list-top/100000.txt", "r"); 
	int control = 0;
	char temp[20];
	//Secondly i used fgets in order to assigning data into temp array.
	while(!feof(dosya)) {
		fscanf(dosya, "%s", temp);
		//Thirdly i used strstr function to compare strings ,if two strings are equal then it will return indice of data.
		if(strcmp(temp, pw) == 0) {
			printf("Key is found ! \n");
			control++;
			break;
		}
	}
	if(control == 0) {
		printf("couldn't find key.\n");
	}
   	return 0;
}

int Hashing(){
	FILE * dosya;
	int q=0;
    dosya = fopen("10-million-password-list-top/1000.txt", "r");
    while (!feof(dosya)) {
        fscanf(dosya, "%s",data[q].psw );
        q++;
    }
    int k;
    int t=1;
	for(k=0;k<TableSize;k++){
		strcpy(HashTable[k].psw,"");
	}
	int number;
	int i=0;
	for(i;i<TableSize;i++){
	number=Hashvalue(data[i].psw);
	if(strcmp(HashTable[number].psw,"")==0){
		strcpy(HashTable[number].psw,data[i].psw);
	}
	else{
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(strcmp(HashTable[number].psw,"")==0){
			strcpy(HashTable[number].psw,data[i].psw);
	        break;
		}
		t++;
			}
	}
	}
	printf("\nMy hashing has %d collision\n",t--);
	return 0;
}

int HashSearch(){
	int collision = 0;
	int control=0;
	char pw[20];
	printf("Enter a password max 20 character: ");
	scanf("%s",pw);
	printf("\n");
    int a;
    int j=0;
    for(j;j<TableSize;j++){
    	 a=Hashvalue(pw);
    	if(strcmp(HashTable[a].psw,pw)==0){
    		printf("Key is in list ! and it has 0 collision \n");
    		control++;
    	     break;
		}
		else
		{   collision++;
			int t=1;
	     	while(t<TableSize){
		    a=a+t*t;
		    a = a%TableSize;
	    	if(strcmp(HashTable[a].psw,pw)==0){
			printf("Key is in list ! and it has %d collision \n",collision);
			control++;
			break;
		    }
		    t++;
			}
		}
		break;
	}
    if(control==0){
		printf("Key is not in list ! \n");
}
return 0;
}

int Hashvalue(char* str){
    int hash = 0;
    int c;

    while (c = *str++){
        hash += c;
}
    return hash%TableSize;
}

