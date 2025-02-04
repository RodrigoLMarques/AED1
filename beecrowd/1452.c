/* 
  Nome: Rodrigo Lopes Marques
  Matrícula: 180385
  Exercício: 1452 - Gloud Computing
  Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 21

typedef struct AppNode {
  char app[MAX_NAME];
  struct AppNode *next;
} AppNode;

typedef struct {
  AppNode *apps;
} Server;

typedef struct {
  AppNode *apps;
} Client;

typedef struct ListNode {
  void *data;
  struct ListNode *next;
} ListNode;

AppNode* insert_app(AppNode *last, char *app);
void read_apps(ListNode **head, int size);
int count_connections(ListNode *servers, ListNode *clients);
int is_app_in_server(AppNode *server_apps, char *app);

int main() {
  int n, m;

  while (1) {
    scanf("%d %d", &n, &m);
    if (n == 0 && m == 0) break;

    ListNode *servers = NULL;
    ListNode *clients = NULL;

    read_apps(&servers, n);
    read_apps(&clients, m);

    int connections = count_connections(servers, clients);
    printf("%d\n", connections);

    while (servers != NULL) {
      ListNode *temp = servers;
      servers = servers->next;
      AppNode *app_node = (AppNode*) temp->data;
      while (app_node != NULL) {
        AppNode *temp_app = app_node;
        app_node = app_node->next;
        free(temp_app);
      }
      free(temp);
    }

    while (clients != NULL) {
      ListNode *temp = clients;
      clients = clients->next;
      AppNode *app_node = (AppNode*) temp->data;
      while (app_node != NULL) {
        AppNode *temp_app = app_node;
        app_node = app_node->next;
        free(temp_app);
      }
      free(temp);
    }
  }

  return 0;
}

AppNode* insert_app(AppNode *last, char *app) {
  AppNode *new_node = (AppNode*) malloc(sizeof(AppNode));
  strcpy(new_node->app, app);
  new_node->next = NULL;
  if (last != NULL) {
    last->next = new_node;
  }
  return new_node;
}

void read_apps(ListNode **head, int size) {
  ListNode *last = NULL;

  for (int i = 0; i < size; i++) {
    int count;
    scanf("%d", &count);

    AppNode *app_list = NULL;
    AppNode *app_last = NULL;

    for (int j = 0; j < count; j++) {
      char app[MAX_NAME];
      scanf("%s", app);
      app_last = insert_app(app_last, app);
      if (app_list == NULL) {
        app_list = app_last;
      }
    }

    ListNode *new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->data = app_list;
    new_node->next = NULL;

    if (*head == NULL) {
      *head = new_node;
    } else {
      last->next = new_node;
    }
    last = new_node;
  }
}

int count_connections(ListNode *servers, ListNode *clients) {
  int connections = 0;

  while (clients != NULL) {
    AppNode *client_apps = (AppNode*) clients->data;
    ListNode *server_node = servers;

    while (server_node != NULL) {
      AppNode *server_apps = (AppNode*) server_node->data;

      AppNode *client_app_node = client_apps;
      while (client_app_node != NULL) {
        if (is_app_in_server(server_apps, client_app_node->app)) {
          connections++;
          break;
        }
        client_app_node = client_app_node->next;
      }

      server_node = server_node->next;
    }

    clients = clients->next;
  }

  return connections;
}

int is_app_in_server(AppNode *server_apps, char *app) {
  while (server_apps != NULL) {
    if (strcmp(server_apps->app, app) == 0) {
      return 1;
    }
    server_apps = server_apps->next;
  }
  return 0;
}