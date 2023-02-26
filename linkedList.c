// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0

typedef struct linkedList{
    int data;
    struct linkedList* next;
}node;


void addElement(int);
node* insertNewNode(int);
void enterElementAtPosition(int,int);
void removeElementAtPosition(int);
int findElement();
void reverseList();
void printList(node*);
bool isListEmpty();
int totalElement();

node* head;

int main() {
    head = NULL;
	bool flag = true;
	int ele, ch, pos, count;
	while(flag != false){
		printf("0-->Print list\n1-->insert element\n2-->Enter element at position\n3-->Remove element at position\n4-->Reverse linked list\n5-->Find Element in list\n9-->Exit\n");
	    scanf("%d",&ch);
		switch(ch){
			case 0:
			printList(head);
			break;
			
			case 1:
			printf("Enter element to insert\n");
			scanf("%d",&ele);
			addElement(ele);
			break;
			
			case 2:
			printf("Enter position to insert element\n");
			scanf("%d",&pos);
		    printf("Enter element to insert\n");
		    scanf("%d",&ele);
		    enterElementAtPosition(pos,ele);
			break;
			
			case 3:
			printf("Enter position to remove element\n");
			scanf("%d",&pos);
			count = totalElement();
			if(pos <= count && count != 0){
			    removeElementAtPosition(pos);
			}
			else{
			    printf("Invalid position entered, %d Elements available\n",count);
			}
			break;
			
			case 4:
			reverseList();
			break;
			
			case 5:
			int res;
			printf("Enter element to search in list\n");
			scanf("%d",&ele);
			res = findElement(ele);
			if(res>0){
			    printf("%d is availabe in list at %d position\n",ele,res);
			}
			else{
			    printf("%d is not available in list\n");
			}
			break;
			
			case 9:
			free(head);
			flag = false;
			break;
			
			default:
			printf("INVALID CHOICE!! TRY AGAIN\n");
		}		
	}
    return 0;
}

void addElement(int data){
    node* temp = head;
	if(temp == NULL){
		head = insertNewNode(data);
	}
	else{
	    while(temp->next !=NULL){
	        temp=temp->next;
	    }
		temp->next = insertNewNode(data);		
	}
}

node* insertNewNode(int data){
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

enterElementAtPosition(int pos,int data){
	node* temp = head;
	node* prev = temp;
	while(--pos != 0){
	    prev = temp;
		temp=temp->next;
	}
	if(isListEmpty()){
		addElement(data);
	}
	else{
		if(temp == prev){
			node* newNode = insertNewNode(data);
			newNode->next = prev;
			head = newNode;
		}
		else{
			prev->next = insertNewNode(data);
			prev=prev->next;
			prev->next = temp;
		}
	}
}

removeElementAtPosition(int pos,int data){
	node* temp = head;
	node* prev = temp;
 	while(--pos != 0){
    prev = temp;
	temp=temp->next;
	}
	if(isListEmpty()){
	    printf("List is already empty\n");
	}
	else{
		if(temp == prev){
			printf("removed:|%d|\n",prev->data);
			head = head->next;
		}
		else{
			printf("removed:|%d|\n",temp->data);
			temp=temp->next;
			free(prev->next);
			prev->next = temp;
		}
		
	}
}

void reverseList(){
	node* prev = NULL;
    node* current = head;
    node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

bool isListEmpty()
{
	if(head == NULL)
		return true;
	else
		return false;
}

int findElement(int data){
	node* temp = head;
	int count = 1;
	while(temp != NULL)
	{
		if(temp->data == data){
			++count;
			return count;
		}
		temp = temp->next;
	}
	return false;
}

int totalElement(){
    node* temp = head;
	int count = 0;
	if(isListEmpty()){
	    return 0;
	}
	else{
		while(temp != NULL)
		{
			++count;
			temp=temp->next;
		}
	}
	return count;
}

void printList(node* temp){
	if(isListEmpty()){
	    printf("List is already empty\n");
	}
	else{
		while(temp != NULL)
		{
			printf("|%d|\n",temp->data);
			temp=temp->next;
		}
	}
}