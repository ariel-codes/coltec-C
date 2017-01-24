#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
short um(){

	return 0;
}

short dois(){
	return 0;
}


typedef struct Connection{
	short status;
	void* node[2];
} connection;

typedef struct Node{
	char id[16];
	connection* ports;
} node;

node* machine(int connections, char name[16]){
	node* comp= (node*) malloc(sizeof(node));
	comp->nodes=(node*) malloc(connections*sizeof(node));
	if(name==NULL || name[0]==0){
		printf("Insert machine % name:")
		fgets(comp->id, 16, stdin);
	}else strcpy(comp->id, name);
	return comp;
}

short tres(){
	node* Server[10];
	char* serv_name=(char*) malloc(16);
	short i;
	for(i=0; i<10; i++)
		Server[i]=machine(17, itoa(i+1, serv_name, 10));
	return 0;
}

int main(){
	short opt;
	printf("Choose your fate:\n");
	scanf("%hi", &opt);
	switch(opt){
	case 1:
		um();
		break;
	case 2:
		dois();
		break;
	case 3:
		tres();
		break;
	default:
		printf("Invalid");
	}
}
