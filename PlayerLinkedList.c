#include "PlayerLinkedList.h"
#include <stdio.h>
#include <string.h>

PlayerListNode *listHead = NULL;
PlayerListNode *tempHead = NULL;

void addToHead(PlayerListNode *newNode){
	/*insert your code here (1)*/
	newNode->next = listHead;
	listHead = newNode;
}


PlayerListNode *createNewNode(char * name, char *id){

	PlayerListNode *playerNode;
	/*insert your code here (2)*/
	playerNode = malloc(sizeof(PlayerListNode));
	playerNode->player.id = malloc(sizeof(char) * strlen(id));
	playerNode->player.name = malloc(sizeof(char) * strlen(name));
	addToHead(playerNode);
	strcpy(playerNode->player.id, id);
	strcpy(playerNode->player.name, name);
	playerNode->player.numOfWins = 0;
	return playerNode;
}

PlayerListNode* searchList(char *idString){
	/*insert your code here (3)*/
	tempHead = listHead;
	while (tempHead != NULL){
		if (strcmp(tempHead->player.id, idString) == 0){
			return tempHead;
		}
		tempHead = tempHead->next;
	}
	return NULL;
}

void printPlayerList(){
	printf("----------------HALL OF FAME---------------\n");
	printf("%-15s%-25s%-10s\n", "PlayerID", "Player_Name", "Number_of_Wins");
	/*insert your code here (4)*/
	if (listHead == NULL){
		printf("nothing");
	}
	while (listHead != NULL){
		printf("%-15s", listHead->player.id);
		printf("%-25s", listHead->player.name);
		printf("%-10d\n", listHead->player.numOfWins);
		listHead = listHead->next;
	}
}

PlayerListNode *getListHead(){
	return listHead;
}

void deleteList(){
	PlayerListNode *tmp = listHead;
	while (tmp != NULL){
		free(*tmp);
		tmp = tmp->next;
	}
	listHead = NULL;
}