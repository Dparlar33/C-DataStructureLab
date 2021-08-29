#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<math.h>
#define TableSize 277
#define StudentSize 273

typedef struct StudentRecord {
	int no;
	char name[30];
	int grade;
}Student;

Student student[StudentSize];
Student HashTable[TableSize];

int main() {
	setlocale(LC_ALL,"Turkish");
	int* size;
    int i = 0;
    FILE * dosya;
    dosya = fopen("data.txt", "r");
    while (!feof(dosya)) {
        if(i==0){
            fscanf(dosya,"%d\n",&size);
        }
        fscanf(dosya, "%d,%[^,],%d\n", &student[i].no, student[i].name, &student[i].grade);
        i++;
    }
    fclose(dosya);
    FirstHashing();
    SecondHashing();
    ThirdHashing();                      // I realized that i could use Switch case for insertion in one function but i wrote'em one by one sorry for this.
    FourthHashing();
    FifthHashing();
    printf("\nAcoording to collision of hashings the best hashing is Basic hashing \n ");
}
void FirstHashing(){
	hash_reset();
	int number;
	int i=0;
	int collision=0;
	for(i;i<TableSize;i++){
	number=HashvalueBasic(student[i].no);
	if(HashTable[number].no==0){
		HashTable[number].no=student[i].no;
		strcpy(HashTable[number].name,student[i].name);
		HashTable[number].grade=student[i].grade;
	}
	else{
		collision++;
		int t=1;
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(HashTable[number].no==0){
			HashTable[number].no=student[i].no;
			strcpy(HashTable[number].name,student[i].name);
			HashTable[number].grade=student[i].grade;
			break;
		}
		t++;
			}
	}
	}
	printf("\nBasic hashing has %d collision\n",collision);
	hash_reset();
        }
void SecondHashing(){
	hash_reset();
	int number;
	int i=0;
	int collision=0;
	for(i;i<TableSize;i++){
	number=HashvalueTruncation(student[i].no);
	if(HashTable[number].no==0){
		HashTable[number].no=student[i].no;
		strcpy(HashTable[number].name,student[i].name);
		HashTable[number].grade=student[i].grade;
	}
	else{
		collision++;
		int t=1;
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(HashTable[number].no==0){
			HashTable[number].no=student[i].no;
			strcpy(HashTable[number].name,student[i].name);
			HashTable[number].grade=student[i].grade;
			break;
		}
		t++;
			}
	}
	}
	printf("\nTruncation hashing has %d collision\n",collision);
	hash_reset();
}
void ThirdHashing(){
	hash_reset();
	int number;
	int i=0;
	int collision=0;
	for(i;i<TableSize;i++){
	number=HashvaluePrivate(student[i].grade);
	if(HashTable[number].grade==0){
		HashTable[number].no=student[i].no;
		strcpy(HashTable[number].name,student[i].name);
		HashTable[number].grade=student[i].grade;
	}
	else{
		collision++;
		int t=1;
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(HashTable[number].grade==0){
			HashTable[number].no=student[i].no;
			strcpy(HashTable[number].name,student[i].name);
			HashTable[number].grade=student[i].grade;
			break;
		}
		t++;
			}
	}
	}
	printf("\nMy first private hashing has %d collision\n",collision);
	hash_reset();
}
void FourthHashing(){
	hash_reset();
	int number;
	int i=0;
	int collision=0;
	for(i;i<TableSize;i++){
	number=HashvaluePrivate2(student[i].name);
	if(strcmp(HashTable[number].name,"")==0){
		HashTable[number].no=student[i].no;
		strcpy(HashTable[number].name,student[i].name);
		HashTable[number].grade=student[i].grade;
	}
	else{
		collision++;
		int t=1;
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(strcmp(HashTable[number].name,"")==0){
			HashTable[number].no=student[i].no;
			strcpy(HashTable[number].name,student[i].name);
			HashTable[number].grade=student[i].grade;
			break;
		}
		t++;
			}
	}
	}
	printf("\nMy second private hashing has %d collision\n",collision);
	hash_reset();
}
void FifthHashing(){
	hash_reset();
	int number;
	int i=0;
	int collision=0;
	for(i;i<TableSize;i++){
	number=HashvaluePrivate3(student[i].name);
	if(strcmp(HashTable[number].name,"")==0){
		HashTable[number].no=student[i].no;
		strcpy(HashTable[number].name,student[i].name);
		HashTable[number].grade=student[i].grade;
	}
	else{
		collision++;
		int t=1;
		while(t<TableSize){
		number=number+t*t;
		number = number%TableSize;
		if(strcmp(HashTable[number].name,"")==0){
			HashTable[number].no=student[i].no;
			strcpy(HashTable[number].name,student[i].name);
			HashTable[number].grade=student[i].grade;
			break;
		}
		t++;
			}
	}
	}
	printf("\nMy third private hashing has %d collision\n",collision);
	hash_reset();
}
int HashvalueBasic(int number){
	return number%TableSize;
}
int HashvalueTruncation(int number){
	int x,y,z;
	int total;
	x=number%10;
	y=(number%100)/10;
	z=(number%10000)/1000;
	total=x+y*10+z*100;
	return total%TableSize;
}
int HashvaluePrivate(int number){
	int x,y,z,total,total2;
	x=number/100;
	y=number/10;
	z=number/1;
	total=x+y+z;
	total2 =pow(total,2);
	return total2%TableSize;
}
int HashvaluePrivate2(char* name){
	int x , y,total;
	x=name[10]-48;
	y=name[15]-48;
	if(x>y){
		total=x*y;
	}
	else 
     total=(y%x)*(x%y);
     return total%TableSize;
}
int HashvaluePrivate3(char* name){
	int x,y,z,total;
	x=name[3]-48;
	y=name[5]-48;
	z=name[15]-48;
	total=pow(abs(x+y-z),3);
	
	return total%TableSize;
}
void hash_reset(){
	int i;
	for(i=0;i<TableSize;i++){
		HashTable[i].no=0;
		strcpy(HashTable[i].name,"");
		HashTable[i].grade=0;	
	}
} 

