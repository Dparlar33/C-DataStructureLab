#include <stdio.h>
#include <stdlib.h>
//Doubly Linked List
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void insert_after();
void insert_before();
void delete_key();
void sort();

void main() {
	int option;
	do
	{
		printf("\n\n 1: Display the list");
		printf("\n 2: Insert at the beginning");
		printf("\n 3: Insert at the end");
		printf("\n 4: Delete from the beginning");
		printf("\n 5: Delete from the end");
		printf("\n 6: Insert after");
		printf("\n 7: Insert before");
		printf("\n 8: Delete key");
		printf("\n 9: Sort List");

		printf("\n 0: EXIT");
		printf("\n\n Enter your option : ");
		scanf_s("%d", &option);
		switch (option)
		{
			case 1: display();	  break;
			case 2: insert_beg(); break;
			case 3: insert_end(); break;
			case 4: delete_beg(); break;
			case 5: delete_end(); break;
			case 6: insert_after(); break;
			case 7: insert_before(); break;
			case 8: delete_key(); break;
			case 9: sort(); break;
		}
	} while (option != 0);
	return;
}

void display(){
	struct node *ptr = tail;
	if (ptr == NULL)
	{
		printf("\nList is empty!");
	}
	else{
		while(ptr != NULL)
		{
			printf("\t%d", ptr->data);
			ptr = ptr->prev;
		}
	}
	printf("\n");
}

void insert_beg(){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else{
		printf("\nEnter the node data value: ");
		scanf_s("%d",&ptr->data);

		if (head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else{
			ptr->prev = NULL;
			ptr->next = head;
			head->prev = ptr;

			head = ptr;
		}
	}
}

void insert_end(){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else{
		printf("\nEnter the node data value: ");
		scanf_s("%d",&ptr->data);

		if (head == NULL)
		{
			ptr->prev = NULL;
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else{
			struct node *temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			ptr->next = NULL;
			tail = ptr;
		}
	}
}

void delete_beg(){
	struct node *ptr=head;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");
	}
	else{
		head = head->next;
		ptr->next = NULL;
		head->prev = NULL;
		free(ptr);
		printf("\nFirst node is deleted!");
	}
}

void delete_end(){
	struct node *ptr, *temp;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");
	}
	else if(head->next == NULL){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head;
		ptr = temp->next;

		while(ptr->next !=NULL){
			temp = temp->next;
			ptr = ptr->next;
		}
		temp->next = NULL;
		ptr->prev = NULL;
		free(ptr);
		tail = temp;
	}
}

void insert_after(){
	//read two value from the user. Find the first value and insert the second value after first value's location.
   struct node *ptr = (struct node *)malloc(sizeof(struct node));  
   struct node *temp;   
   int i, number, secondnumber;
   printf("Enter a number from the linked list: ");
   scanf("%d",&number);
   while(ptr){
   	if(number==ptr->data){
   		break;
	   }
	   ptr=ptr->next;
   }
   if(ptr==NULL)  
   {  
    printf("\n Number is not in linked list!");  
	   return;
   } 
   else  
   {  
       printf("\nEnter the second number you want to insert which next to the number entered: ");  
       scanf("%d",&secondnumber);  
       temp=head; 
       ptr->prev = temp->prev;
       temp->prev = ptr;
       ptr->next = temp;

	if (ptr->prev != NULL){
	ptr->prev->next = ptr;  
       }
	   printf("Second number is Inserted!");
	   return;
   } 
	return;
}
void insert_before(){
	//read two value from the user. Find the first value and insert the second value before first value's location.
   struct node *ptr = (struct node *)malloc(sizeof(struct node));  
   struct node *temp;   
   int i, number, secondnumber;
   printf("Enter a number from the linked list: ");
   scanf("%d",&number);
   while(ptr){
   	if(number==ptr->data){
   		break;
	   }
	   ptr=ptr->next;
   }
   if(ptr==NULL)  
   {  
    printf("\n Number is not in linked list!");
	   return;
   } 
   else  
   {  
    printf("\nEnter the second number you want to insert which next to the number entered: ");  
    scanf("%d",&secondnumber);  
    temp=head; 
    ptr->next = temp->next;
    temp->next = ptr;
    ptr->prev = temp;
    if (ptr->next != NULL){
          ptr->next->prev = ptr;
    }
    printf("Second number is Inserted!");
	   return;
   }
	return;
}
void delete_key(){
	//read a key from the user and delete that key from the list if it is in the list.
	struct node *ptr;
	ptr=head;
	int key;
	printf("Enter the key want to delete: ");
	scanf("%d",&key);
	while(ptr){
		if(key==ptr->data){
			break;
     	}
		ptr=ptr->next;
}
if(ptr==NULL){
printf("Key is not in linked list!");
	return;
}
if(ptr==head){
    if(head==tail){
    		head=NULL;
    		tail=NULL;
	}
	else{
		 head=ptr->next;
		 head->prev=NULL;
	}
}
else{
		
		if(ptr==tail){
			tail=ptr->prev;
			tail->next=NULL;
	      }
	    else{
			ptr->prev->next=ptr->next;
			ptr->next->prev=ptr->prev;
		}	
	}
	return;
}
void sort(){
	//any kind of sort is acceptable BUBBLE QUICK MERGE etc.
	struct node *ptr;
	int temp=0;
	ptr=head;
	if(ptr==NULL){
		printf("Linked list is empty !");
		return;
	}
  while (ptr->next != NULL)
		{
			if (ptr->data < ptr->next->data)
			{
				temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
			}
		}	
}
