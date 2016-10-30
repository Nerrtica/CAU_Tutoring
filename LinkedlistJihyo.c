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
		printf("**메뉴 선택\n1. 노드 추가\t2. 노드 삭제\t3. 노드 검색\t4. 전체 노드 출력\t5. 종료\n선택 : ");
		scanf("%d", &menu);

		if (menu == 1) {
			printf("1. index로 추가\t2. 끝에 추가\t3. 돌아가기\n선택 : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("노드가 추가될 index를 입력해주세요 : ");
				scanf("%d", &index);
				printf("추가할 노드의 data를 입력해주세요 : ");
				scanf("%d", &data);

				addNodeByIndex(head, index, data);
				continue;
			}
			else if (innerMenu == 2) {
				printf("추가할 노드의 data를 입력해주세요 : ");
				scanf("%d", &data);

				addNodeAtEnd(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 2) {
			printf("1. index로 삭제\t2. data로 삭제\t3. 돌아가기\n선택 : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("삭제할 노드의 index를 입력해주세요 : ");
				scanf("%d", &index);

				delNodeByIndex(head, index);
				continue;
			}
			else if (innerMenu == 2) {
				printf("삭제할 노드의 data를 입력해주세요 : ");
				scanf("%d", &data);

				delNodeByData(head, data);
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 3) {
			printf("1. index로 검색\t2. data로 검색\t3. 돌아가기\n선택 : ");
			scanf("%d", &innerMenu);

			if (innerMenu == 1) {
				printf("검색할 노드의 index를 입력해주세요 : ");
				scanf("%d", &index);

				nptr = searchNodeByIndex(head, index);
				if (nptr == NULL) {
					printf("해당 index에 노드가 존재하지 않습니다.\n");
				}
				else {
					printf("해당 index의 노드의 data 값은 %d 입니다.\n", nptr->data);
				}
				continue;
			}
			else if (innerMenu == 2) {
				printf("검색할 노드의 data를 입력해주세요 : ");
				scanf("%d", &data);

				nptr = searchNodeByData(head, data, &index);
				if (nptr == NULL) {
					printf("해당 data를 가진 노드가 존재하지 않습니다.\n");
				}
				else {
					printf("해당 data를 가진 노드의 index 값은 %d 입니다.\n", index);
				}
				continue;
			}
			else {
				continue;
			}
		}
		else if (menu == 4) {
			printf("전체 노드의 data : ");
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
/***************************************************************
이부분 next지정하는 데에서 일치하는data 다다음걸로 지정됨ㅠㅠ 왜죠
****************************************************************/
void delNodeByData(Node * head, int data) {
	Node *nptr = head;
	while (nptr->data!=data) {
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
