#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAX_LENGTH 100000
#define MAX_BUF 10000
#define col 27

void save();
void sort();
int main() {
	// Variable Declaration
	FILE * fp;
	char data[MAX_LENGTH];
	char * tmp_ptr = data;
	char *ptr;
	char input[5];
	char *alp[50][col] = { 0, };
	int num[50][col] = { 0, };

	// Read text data & Put into 'data' array
	// If you want to read extended_data, replace "data.txt" to "extended_data.txt"
	if ((fp = fopen("extended_data.txt", "r")) == NULL) {
		printf("File Open Error!\n");
		return -1;
	}
	while (fgets(tmp_ptr, MAX_BUF, fp)) {
		tmp_ptr += strlen(tmp_ptr);
	}
	fclose(fp);

	// ���ĺ� ��ȯ
	for (int i = 0; data[i] != 0; i++){
		if (data[i] >= 65 && data[i] <= 90)
			data[i] += 32;
	}

	// token ���� #1
	ptr = strtok(data, "	 ,.!?-();:\n\"");
	save(ptr, alp, num);
	// #2~
	while (ptr = strtok(NULL, "	 ,.!?-();:\n\"")){
		save(ptr, alp, num);
	}

	sort(alp, num);

	// print start
	while (1){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("\n�ܾ��� ���� ���ڸ� �Է����ּ��� (a ~ z, else, end) : ");
		scanf("%s", &input);

		// non-alphabet
		if (strcmp(input, "else") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("non-alphabet �� �����ϴ� �ܾ��� ����Ʈ�Դϴ�.\n");
			for (int i = 0; i <50; i++){	// no-word
				if (num[0][input[0] - 'a'] == 0){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("�ܾ �������� �ʽ��ϴ�.\n");
					break;
				}
				else{
					if (alp[i][26] == NULL)	// ��
						break;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("[%d] %s : %d ��\n", i + 1, alp[i][26], num[i][26]);	// ���
				}
			}
		}// end �Է�
		else if (strcmp(input, "end") == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			printf("�����մϴ�.\n\n");
			break;
		}// a~z �� ����Ʈ
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			printf("%c �� �����ϴ� �ܾ��� ����Ʈ�Դϴ�.\n", input[0]);
			for (int i = 0; i<50; i++){
				if (num[0][input[0] - 'a'] == 0){	// no-word
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					printf("�ܾ �������� �ʽ��ϴ�.\n");
					break;
				}
				else{
					if (alp[i][input[0] - 'a'] == NULL) // ��
						break;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("[%d] %s : %d ��\n", i + 1, alp[i][input[0] - 'a'], num[i][input[0] - 'a']); //���
				}
			}
		}
	}

	system("pause");
	return 0;
}
// ���ĺ������� �迭�� ����
void save(char *ptr, char *alp[][col], int num[][col]){
	//a~z
	if (ptr[0] >= 'a'&&ptr[0] <= 'z'){
		for (int i = 0; i < 50; i++){
			if (alp[i][ptr[0] - 'a'] == 0){
				alp[i][ptr[0] - 'a'] = ptr;
				num[i][ptr[0] - 'a']++;
				break;
			}
			else if (strcmp(alp[i][ptr[0] - 'a'], ptr, strlen(ptr)) == 0){
				num[i][ptr[0] - 'a']++;
				break;
			}
		}
	}// non-alphabet
	else{
		for (int i = 0; i < 50; i++){
			if (alp[i][26] == 0){
				alp[i][26] = ptr;
				num[i][26]++;
				break;
			}
			else{
				if (strcmp(alp[i][26], ptr, strlen(ptr)) == 0){
					num[i][26]++;
					break;
				}
			}
		}
	}
}
// �󵵼� ����
void sort(char *alp[][col], int num[][col]){
	int hold_num = 0;
	char hold_alp[20] = { 0, };

	for (int k = 0; k < col; k++){
		for (int loop = 1; loop < 50; loop++){
			for (int i = 0; i < col - 1; i++){
				if (num[i][k] < num[i + 1][k]){
					// num ����
					hold_num = num[i][k];
					num[i][k] = num[i + 1][k];
					num[i + 1][k] = hold_num;
					// alp ����
					strcpy(hold_alp, alp[i][k]);
					strcpy(alp[i][k], alp[i + 1][k]);
					strcpy(alp[i + 1][k], hold_alp);
				}
			}
		}
	}
}