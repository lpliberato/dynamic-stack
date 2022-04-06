#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int id;
	struct no *next;
} TNode;

TNode *push(TNode *top, int id) {
	
	TNode *node = malloc(sizeof(TNode));
	
	if (node) {
		node->id = id;
		node->next = top;
		return node;
	} else {
		printf("Erro: Nao foi possivel alocar memoria");
	}
	
	return NULL;
}

TNode *pop(TNode **top) {
	
	if (*top != NULL) {
		TNode *nodeRemoved = *top;
		*top = nodeRemoved->next;
		return nodeRemoved;
	} else {
		printf("\n\nPilha vazia!\n\n");
	}

	return NULL;
	
}

void printStack(TNode *node) {
	printf("\n------------ PILHA ------------\n");
	while(node) {
		printf("%d\n", node->id);
		node = node->next;
	}
	printf("----------- FIM PILHA ----------\n\n");
}

int main()
{   
	TNode *top = NULL;
	int count, option = 0;

	do {
		printf("0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
		scanf("%d", &option);
		getchar();
		
		switch(option) {
			case 0:
				break;
			case 1:
				count++;
				top = push(top, count);
				break;
			case 2:
				pop(&top);
				break;
			case 3:
				printStack(top);
				break;
			default:
				printf("\nOpcao invalida\n\n");
				break;
		}
	} while(option != 0);
	
	return 0;
}