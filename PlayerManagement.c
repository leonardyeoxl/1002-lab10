#include "PlayerManagement.h"
#include <time.h>

#define FALSE 0
#define TRUE 1

PlayerListNode *currentPlayerNode;
PlayerListNode *tempPlayerNode;
PlayerListNode *topTenPlayerNode = NULL;
PlayerListNode *temp;
const char *FILE_NAME = "topPlayers.txt";

void playerMenu(){
	char idString[7];
	currentPlayerNode = 0;

	system("cls");
	printf("\n--------PLAYER MENU--------\n");
	printf("Enter playerID or \"New\" to play (0 to exit): ");
	scanf("%s", idString);
	if (strcmp(idString, "0") == 0){
		printPlayerList();
		printf("Press Enter to exit. Bye!\n");
		_getch();
		exit(0);
	}

	if (strcmp(idString, "New") == 0){
		addNewPlayer();
	}
	else{
		currentPlayerNode = getPlayerIndex(idString);
		if (currentPlayerNode == NULL){
			printf("PlayerID not found!!");
			_getch();
			playerMenu();
			return;
		}
		printf("Welcome %s\n", currentPlayerNode->player.name);
		printf("You have won %d games\n", currentPlayerNode->player.numOfWins);
	}
}

void addNewPlayer(){
	char name[20];
	void generateId(char*, char*);
	int checkUniqueness(char*);

	printf("Enter your name: ");
	scanf("%s", name);
	char id[7];
	generateId(name,id);
	while (checkUniqueness(id) == FALSE){
		generateId(name,id);
	}
	printf("Your playerID is: %s\n", id);	
	currentPlayerNode = createNewNode(name,id);
}

void generateId(char *name, char *id){

	strncpy(id, name, 3);
	id[3] = '\0';
	char digit[3];
	getRandom2DigitNumber(digit);
	strcat(id, digit);
	id[5] = '\0';
	int len = strlen(name);
	char last[2];
	last[0] = name[len - 1];
	last[1] = '\0';
	strcat(id, last);
	id[6] = '\0';
}

void getRandom2DigitNumber(char *s){
	int i = 0;
	srand(time(NULL));
	while (i < 10)
		i = (rand() % 99 + 1);
	_itoa(i, s, 10);
}

int checkUniqueness(char * idString){
	PlayerListNode *temp;
	temp = searchList(idString);
	if (temp == NULL)
		return TRUE;
	return FALSE;
}

PlayerListNode* getPlayerIndex(char *idString){
	return searchList(idString);
}

void updateNumberOfWins(){
	currentPlayerNode->player.numOfWins++;
}

void viewAllPlayers(){
	printf("List of all players\n");
	FILE *newFile = fopen(FILE_NAME, "a");
	if (newFile == NULL){
		printf("File could not be opened\n");
		return;
	}
	/*insert your code here (5)*/
	
	
	tempPlayerNode = currentPlayerNode;
	
	while (tempPlayerNode != NULL){
		fprintf(newFile, "%s %s %d\n", 
			tempPlayerNode->player.id,
			tempPlayerNode->player.name,
			tempPlayerNode->player.numOfWins);
		tempPlayerNode = tempPlayerNode->next;
	}
	fclose(newFile);

	FILE *readFile = fopen(FILE_NAME, "r");
	char *pname = malloc(sizeof(char *));
	char *pid = malloc(sizeof(char *));
	int numWins;
	while (!feof(readFile)){

		fscanf(readFile, "%s%s%d", pname, pid, &numWins);
		printf("%s %s %d\n", pname, pid, numWins);

	}
	_getch();
	fclose(readFile);
	
	
}

void viewTopTenPlayers(){
	printf("Top ten players\n");
	/*insert your code here (6)*/
	FILE *readFile = fopen(FILE_NAME, "r");
	char *pname2 = malloc(sizeof(char *));
	char *pid2 = malloc(sizeof(char *));
	int numWins2;
	fscanf(readFile, "%s%s%d", pname2, pid2, &numWins2);
	while (!feof(readFile)){

		
		topTenPlayerNode = createNewNode2(pname2, pid2, numWins2);
		fscanf(readFile, "%s%s%d", pname2, pid2, &numWins2);
	}
	fclose(readFile);
	
	int listLen = 0;
	listLen = listLength(topTenPlayerNode);
	topTenPlayerNode = sortPlayers(topTenPlayerNode, listLen);
	printTopPlayerList(topTenPlayerNode);
	_getch();
}

int listLength(PlayerListNode *topTenPlayerNode){
	int count = 0;
	while (topTenPlayerNode != NULL){
		//printf("%-15s", topTenPlayerNode->player.id);
		//printf("%-25s", topTenPlayerNode->player.name);
		//printf("%-10d\n", topTenPlayerNode->player.numOfWins);
		topTenPlayerNode = topTenPlayerNode->next;
		count++;
	}
	return count;
}

PlayerListNode *sortPlayers(PlayerListNode *start, int length){

	
	//int numNodes = count(start);

	for (int i = 0; i < length; i++){
		PlayerListNode *currentNode = start;
		PlayerListNode *previousNode = NULL;
		PlayerListNode *nextNode = currentNode->next;

		while (nextNode != NULL){
			if (currentNode->player.numOfWins < nextNode->player.numOfWins){
				if (currentNode == start){
					start = nextNode;
				}
				else{
					previousNode->next = nextNode;
				}
				currentNode->next = nextNode->next;
				nextNode->next = currentNode;

				previousNode = nextNode;
				nextNode = currentNode->next;

			}
			else{
				previousNode = currentNode;
				currentNode = currentNode->next;
				nextNode = currentNode->next;
			}
		}
	}
	return start;

}

//void swap(PlayerListNode *first, PlayerListNode *second)
//{
//	
//	temp = first;
//	first = second;
//	second = temp;
//}


void printTopPlayerList(PlayerListNode* topTenPlayerNode){
	printf("%-15s%-25s%-10s\n", "PlayerID", "Player_Name", "Number_of_Wins");
	/*insert your code here (4)*/
	if (topTenPlayerNode == NULL){
		printf("nothing");
	}
	while (topTenPlayerNode != NULL){
		printf("%-15s", topTenPlayerNode->player.id);
		printf("%-25s", topTenPlayerNode->player.name);
		printf("%-10d\n", topTenPlayerNode->player.numOfWins);
		topTenPlayerNode = topTenPlayerNode->next;
	}
}

void addToHead2(PlayerListNode *newNode2){
	/*insert your code here (1)*/
	newNode2->next = topTenPlayerNode;
	topTenPlayerNode = newNode2;
}


PlayerListNode *createNewNode2(char * name, char *id, int wins){

	PlayerListNode *playerNode2;
	/*insert your code here (2)*/
	playerNode2 = malloc(sizeof(PlayerListNode));
	playerNode2->player.id = malloc(sizeof(char) * strlen(id));
	playerNode2->player.name = malloc(sizeof(char) * strlen(name));
	addToHead2(playerNode2);
	strcpy(playerNode2->player.id, id);
	strcpy(playerNode2->player.name, name);
	playerNode2->player.numOfWins = wins;
	return playerNode2;
}

