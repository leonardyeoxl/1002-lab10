#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "PlayerLinkedList.h"

void addNewPlayer();
PlayerListNode* getPlayerIndex(char*);
void getRandom2DigitNumber(char*);
void playerMenu();
void updateNumberOfWins();
void printPlayerList();
void viewAllPlayers();
void viewTopTenPlayers();

PlayerListNode* createNewNode2(char*, char*, int);
void addToHead2(PlayerListNode*);
void printTopPlayerList(PlayerListNode*);
PlayerListNode* sortPlayers(PlayerListNode*, int);
int listLength(PlayerListNode*);