#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
	char name[100];
} element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; // ��� �������� ���� ���� //(3)
	head = p; // ��� ������ ���� //(4)
	return head;
}
//void insert_fruit(ListNode *head, element value)
//{
//	ListNode * p = (ListNode*)malloc(sizeof(ListNode));
//	p->data = value;
//	p->link = NULL;
//
//	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
//	temp = head;
//	while (temp->link != NULL)
//	{
//		if (strcmp(temp->data.name, value.name) == 0)
//		{
//			printf("%s allready exists\n", value.name);
//			return;
//		}
//		temp = temp->link;
//	}
//	temp->link = p;
//	printf("%s has been addedd\n",value.name);
//}

void insert_fruit(ListNode** head, element value) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = value;
	new_node->link = NULL;

	if (*head == NULL) {
		*head = new_node;
		printf("%s has been added.\n", value.name);
		return;
	}

	ListNode* temp = *head;
	while (temp->link != NULL) {
		if (strcmp(temp->data.name, value.name) == 0) {
			printf("%s already exists.\n", value.name);
			free(new_node);
			return;
		}
		temp = temp->link;
	}

	if (strcmp(temp->data.name, value.name) == 0) {
		printf("%s already exists.\n", value.name);
		free(new_node);
		return;
	}

	temp->link = new_node;
	printf("%s has been added.\n", value.name);
}

void delete_fruit(ListNode** head, ListNode** deleteList, element value) {
	if (*head == NULL) {
		printf("List is empty.\n");
		return;
	}

	ListNode* current = *head;
	ListNode* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->data.name, value.name) == 0) {
			if (previous == NULL) {
				// ù ��° ��� ����
				*head = current->link;
			}
			else {
				// �߰� �Ǵ� ������ ��� ����
				previous->link = current->link;
			}

			printf("%s has been deleted.\n", value.name);

			// ������ �����͸� deleteList�� �߰�
			current->link = *deleteList;
			*deleteList = current;

			return;
		}

		previous = current;
		current = current->link;
	}

	printf("%s not found in the list.\n", value.name);
}



void print_list(ListNode* head)
{
	if (head == NULL)
	{
		printf("List is NULL\n");
		return;
	}
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

int main(void)
{
	ListNode* head = NULL;
	element data;
	strcpy(data.name, "Peach");
	head = insert_first(head, data);
	strcpy(data.name, "Banana");
	head = insert_first(head, data);
	strcpy(data.name, "Raspberry");
	head = insert_first(head, data);
	strcpy(data.name, "Guava");
	head = insert_first(head, data);
	strcpy(data.name, "Plum");
	head = insert_first(head, data);
	strcpy(data.name, "Cherry");
	head = insert_first(head, data);
	strcpy(data.name, "Grape");
	head = insert_first(head, data);
	strcpy(data.name, "Apple");
	head = insert_first(head, data);
	strcpy(data.name, "Orange");
	head = insert_first(head, data);
	strcpy(data.name, "Mango");
	head = insert_first(head, data);
	int selected;
	ListNode* deleteList = NULL;
	while (1)
	{
		printf("1. Insert new fruit\n");
		printf("2. Delete the fruit\n");
		printf("3. Print the delete list\n");
		printf("4. Exit\n");
		printf("Enter the menu :");
		scanf("%d", &selected);
		element fruitname;
		if (selected == 1) {
			element data;
			printf("Enter the fruit name: ");
			scanf("%s", data.name);
			insert_fruit(&head, data);
		}
		else if (selected == 2)
		{
			element data;
			printf("Enter the fruit name: ");
			scanf("%s", data.name);
			delete_fruit(&head, &deleteList, data);
		}
		else if (selected == 3)
		{
			print_list(deleteList);
		}
		else if (selected == 4)
		{
			printf("Exit the program");
			break;
		}
		

	}

	return 0;
}