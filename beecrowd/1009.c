/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1009 - Soma Simples
  Observações: Experimentando o uso de uma struct mais personalizada
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TList {
  double value;
  struct TList* next;
} List;

typedef struct {
  List* head;
  List* tail;
} HeadList;

HeadList* create_head_list();
void insert(HeadList* headList, double value);
void free_list(List* head);
double calculate_total_salary(double fixed_salary, double total_sales);


int main() {
  char seller_name[50];
  double fixed_salary, total_sales;
  HeadList* salesList = create_head_list();

  scanf("%s", seller_name);
  scanf("%lf", &fixed_salary);
  scanf("%lf", &total_sales);

  insert(salesList, fixed_salary);
  insert(salesList, total_sales);

  double total_salary = calculate_total_salary(fixed_salary, total_sales);

  printf("TOTAL = R$ %.2lf\n", total_salary);

  free_list(salesList->head);
  free(salesList);

  return 0;
}

HeadList* create_head_list() {
  HeadList* newHeadList = (HeadList*)malloc(sizeof(HeadList));
  newHeadList->head = NULL;
  newHeadList->tail = NULL;
  return newHeadList;
}

void insert(HeadList* headList, double value) {
  List* newList = (List*)malloc(sizeof(List));
  newList->value = value;
  newList->next = NULL;

  if (headList->head == NULL) {
    headList->head = newList;
    headList->tail = newList;
  } else {
    headList->tail->next = newList;
    headList->tail = newList;
  }
}

void free_list(List* head) {
  List* temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

double calculate_total_salary(double fixed_salary, double total_sales) {
  double commission = total_sales * 0.15;
  return fixed_salary + commission;
}
