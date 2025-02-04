/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1401 - Gerando Permutações Ordenadas Rapidamente
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 11

typedef struct TList {
		char permutation[MAX_LEN];
		struct TList* next;
} List;

List* insert(char* str, List* last);
void free_list(List* head);
int next_permutation(char* str, int len);
void sort(char* str, int size);

int main() {
	int n;
	char str[MAX_LEN];

	scanf("%d", &n);
	getchar(); 

	for (int i = 0; i < n; i++) {
		fgets(str, MAX_LEN, stdin);
		str[strcspn(str, "\n")] = '\0'; 

		sort(str, strlen(str)); 
		
		List* head = (List*)malloc(sizeof(List));
		head->next = NULL; 
		List* last = head; 

		do {
			last = insert(str, last);
		} while (next_permutation(str, strlen(str)));

		
		List* temp = head->next; 
		while (temp) {
			printf("%s\n", temp->permutation);
			temp = temp->next;
		}

		free_list(head);

		
		if (i < n - 1) printf("\n");
	}

	return 0;
}

List* insert(char* str, List* last) {
	List* new_cell = (List*)malloc(sizeof(List));
	strcpy(new_cell->permutation, str); 
	new_cell->next = NULL; 
	last->next = new_cell; 
	return new_cell; 
}

void sort(char* str, int size) {
		char temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
}
}


int next_permutation(char* str, int len) {
	int i = len - 2;
	while (i >= 0 && str[i] >= str[i + 1]) i--;
	if (i < 0) return 0; 

	int j = len - 1;
	while (str[j] <= str[i]) j--;
	
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	int left = i + 1, right = len - 1;
	while (left < right) {
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}

	return 1; 
}

void free_list(List* head) {
	List* temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}