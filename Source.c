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
		printf("**�޴� ����\n1. ��� �߰�\t2. ��� ����\t3. ��� �˻�\t4. ��ü ��� ���\t5. ����\n���� : ");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("1. index�� �߰�\t2. ���� �߰�\t3. ���ư���\n���� : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("��尡 �߰��� index�� �Է����ּ��� : ");
				scanf("%d", &index);
				printf("�߰��� ����� data�� �Է����ּ��� : ");
				scanf("%d", &data);

				addNodeByIndex(head, index, data);
				continue;
			}
			else if (innerMenu == 2) {
				printf("�߰��� ����� data�� �Է����ּ��� : ");
				scanf("%d", &data);

				addNodeAtEnd(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 2) {
			printf("1. index�� ����\t2. data�� ����\t3. ���ư���\n���� : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("������ ����� index�� �Է����ּ��� : ");
				scanf("%d", &index);

				delNodeByIndex(head, index);
				continue;
			}
			else if (innerMenu == 2) {
				printf("������ ����� data�� �Է����ּ��� : ");
				scanf("%d", &data);

				delNodeByData(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 3) {
			printf("1. index�� �˻�\t2. data�� �˻�\t3. ���ư���\n���� : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("�˻��� ����� index�� �Է����ּ��� : ");
				scanf("%d", &index);

				nptr = searchNodeByIndex(head, index);
				if (nptr == NULL) {
					printf("�ش� index�� ��尡 �������� �ʽ��ϴ�.\n");
				}
				else {
					printf("�ش� index�� ����� data ���� %d �Դϴ�.\n", nptr->data);
				}
				continue;
			}
			else if (innerMenu == 2) {
				printf("�˻��� ����� data�� �Է����ּ��� : ");
				scanf("%d", &data);

				nptr = searchNodeByData(head, data, &index);
				if (nptr == NULL) {
					printf("�ش� data�� ���� ��尡 �������� �ʽ��ϴ�.\n");
				}
				else {
					printf("�ش� data�� ���� ����� index ���� %d �Դϴ�.\n", index);
				}
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 4) {
			printf("��ü ����� data : ");
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
	Node *newNode=makeNode(data);

	Node *nptr = head;

	while (nptr->next != NULL)
		nptr = nptr->next;
	nptr->next = newNode;
}

void addNodeByIndex(Node * head, int index, int data) {
	Node *newNode = makeNode(data);
	Node *nptr = head;
	for (int i = 0; i < index - 1; i++) {
		nptr = nptr->next;
	}
	if (nptr != NULL) {
		newNode->next = nptr->next;
		nptr->next = newNode;
	}
}

void delNodeByData(Node * head, int data) {
	Node *nptr = head;
	while (nptr->next!=data) {
		nptr = nptr->next;
	}
	if(nptr!=NULL)
	nptr->next = nptr->next->next;
}

void delNodeByIndex(Node * head, int index) {
	Node *nptr = head;

	for (int i = 0; i < index-1; i++) {
		nptr = nptr->next;
	}
	nptr->next=nptr->next->next;
}

void printAllNodeData(Node * head) {
	Node *nptr = head;
	if (nptr == NULL) printf("NO DATA !\n");
	while (nptr->next != NULL) {
		printf("[ %2d ] ", nptr->data);
		nptr = nptr->next;
	}
	printf("[ %2d ] ", nptr->data);
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