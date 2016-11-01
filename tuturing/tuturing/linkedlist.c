#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _Node {
	int data;
	struct _Node *next;
} Node;

Node * makeNode(int data);
Node * searchNodeByData(Node * head, int data, int * index);
Node * searchNodeByIndex(Node * head, int index);
void addNodeAtEnd(Node * head, int data);
void addNodeByIndex(Node * head, int index, int data);
void delNodeByData(Node * head, int data);
void delNodeByIndex(Node * head, int index);
void printAllNodeData(Node * head);
void freeAllNode(Node * head);

int main() {
	Node * head;
	Node * nptr;
	int menu, innerMenu, index, data;
	
	head = makeNode(0);

	while (1) {
		printf("\n\n");
		printf("**Select Menu\n1. Add Node\t2. Delete Node\t3. Search Node\t4. Print All Node\t5. END\nSelect : ");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("1. Add by index\t2. Add at End\t3. Return\nSelect : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("Enter index which add node : ");
				scanf("%d", &index);
				printf("Enter data which add node : ");
				scanf("%d", &data);

				addNodeByIndex(head, index, data);
				continue;
			}
			else if (innerMenu == 2) {
				printf("Enter data which add node : ");
				scanf("%d", &data);

				addNodeAtEnd(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 2) {
			printf("1. Delete by index\t2. Delete by data\t3. Return\nSelect : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("Enter index which delete node : ");
				scanf("%d", &index);

				delNodeByIndex(head, index);
				continue;
			}
			else if (innerMenu == 2) {
				printf("Enter data whick delete node : ");
				scanf("%d", &data);

				delNodeByData(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 3) {
			printf("1. Search by index\t2. Search by data\t3. Return\nSelect : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("Enter index which search node : ");
				scanf("%d", &index);

				nptr = searchNodeByIndex(head, index);
				if (nptr == NULL) {
					printf("It doesn't have that Node.\n");
				}
				else {
					printf("Data which has that index is %d.\n", nptr->data);
				}
				continue;
			}
			else if (innerMenu == 2) {
				printf("Enter data which search node : ");
				scanf("%d", &data);

				nptr = searchNodeByData(head, data, &index);
				if (nptr == NULL) {
					printf("It doesn't have that Node.\n");
				}
				else {
					printf("Index which has that data is %d.\n", index);
				}
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 4) {
			printf("data of All Node: ");
			printAllNodeData(head);
			continue;
		}
		else if (menu == 5) {
			break;
		}
	}

	freeAllNode(head);

	return 0;
}

Node * makeNode(int data) {
	Node * tmpNode;

	tmpNode = (Node *)malloc(sizeof(Node));
	tmpNode->data = data;
	tmpNode->next = NULL;

	return tmpNode;
}

Node * searchNodeByData(Node * head, int data, int * index) {
	Node * nptr = head;

	*index = 0;
	while (nptr != NULL && nptr->data != data) {
		nptr = nptr->next;
		(*index)++;
	}

	return nptr;
}

Node * searchNodeByIndex(Node * head, int index) {
	Node * nptr = head;
	int i;

	for (i = 0; nptr != NULL && i < index; i++) {
		nptr = nptr->next;
	}

	return nptr;
}

void addNodeAtEnd(Node * head, int data) {
	Node * nptr = head;
	Node * new = makeNode(data);
	for (int i = 0; nptr->next != NULL; i++) {
		nptr = nptr->next;
	}
	nptr->next = new;

}

void addNodeByIndex(Node * head, int index, int data) {
	Node * nptr1, *nptr2;
	Node * newn = makeNode(data);
	Node *checker=head;
	int check;
	for (check = 0; checker->next != NULL; check++)
	{
		checker = checker->next;
	}
	if (check >= index)
	{
		nptr1 = searchNodeByIndex(head, index - 1);
		nptr2 = searchNodeByIndex(head, index);
		nptr1->next = newn;
		newn->next = nptr2;
	}
	else
		printf("\nIt doesn't have that Node!\n");
}

void delNodeByData(Node * head, int data) {
	Node * nptr1;
	int index;
	nptr1 = searchNodeByData(head, data, &index);
	delNodeByIndex(head, index);
}

void delNodeByIndex(Node * head, int index) {

	Node * nptr1=head, *nptr2=head, *nptr3=head, *temp; 
	Node *checker = head;
	int check;
	for (check = 0; checker->next != NULL; check++)
	{
		checker = checker->next;
	}
	if (index != 0&&index<=check)
	{
		nptr1 = searchNodeByIndex(head, index - 1);
		nptr2 = searchNodeByIndex(head, index + 1);
		nptr3 = searchNodeByIndex(head, index);
		nptr1->next = nptr2;
		free(nptr3);
	}
	else if (index == 0)
	{
		printf("\nYOU CAN'T DELETE HEADNODE!\n");
		/*	for (int c = 0; nptr1->next != NULL; c++)
		{
			temp = nptr2;
			nptr2 = nptr1->next;
		}
		*/
	}
	else
		printf("\nIt doesn't have that Node!\n");

}

void printAllNodeData(Node * head) {
	Node * nptr = head;
	int i;

	for (i = 0; nptr != NULL; i++)
	{
		if (i == 0)
			printf("\nHeadnode has %d data\n", nptr->data);
		else
			printf("Number %d node has %d data\n", i, nptr->data);
		nptr = nptr->next;
	}
}

void freeAllNode(Node * head) {
	Node * nptr1 = head;
	Node * nptr2 = nptr1;

	while (nptr1 != NULL) {
		nptr2 = nptr1->next;
		free(nptr1);
		nptr1 = nptr2;
	}
}