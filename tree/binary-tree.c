#include <stdlib.h>
#include <stdio.h>

typedef struct TTree {
  int value;
  struct TTree* root;
  struct TTree* right;
  struct TTree* left;
} Tree;

Tree* insertTree(Tree* root, int value);
Tree* insertLeft(Tree* node, int value);
Tree* insertRight(Tree* node, int value);
void printTreeRED(Tree* node);
int treeHeight(Tree* node);
Tree* searchTree(Tree* node, int target);

int main() {
  Tree* root = (Tree*) malloc(sizeof(Tree));
  root->value = 19;
  
  insertTree(root, 18);
  insertTree(root, 10);
  insertTree(root, 8);
  insertTree(root, 14);
  insertTree(root, 12);
  insertTree(root, 5);
  insertTree(root, 11);

  printTreeRED(root);

  Tree* node = searchTree(root, 11);
  printf("Node search: %d\n", node->value);

  return 0;
}

Tree* insertTree(Tree* root, int value) {
  Tree* newNode = (Tree*) malloc(sizeof(Tree));
  newNode->value = value;

  if (root == NULL) return newNode;

  Tree *aux, *last;
  aux = root;

  while(aux != NULL) {
    last = aux;
    if (aux->value > newNode->value) aux = aux->left;
    else aux = aux->right;
  }

  if (last->value > newNode->value) last->left = newNode;
  else last->right = newNode;

  return root;
}

void printTreeRED(Tree* node) {
  if (node != NULL) {
     printf("%d\n", node->value);
    printTreeRED(node->left);
    printTreeRED(node->right);
  }
}

int treeHeight(Tree* node) {
  if (node == NULL) return -1;

  int leftHeight = treeHeight(node->left);
  int rightHeight = treeHeight(node->right);

  if (leftHeight > rightHeight) return leftHeight + 1;
  return rightHeight + 1;
}

Tree* searchTree(Tree* node, int target) {
  if (node == NULL || node->value == target) return node;
  if (node->value > target) return searchTree(node->left, target);
  return searchTree(node->right, target);
}

Tree* removeRoot(Tree* root) {
  
}
