

struct playerStruct{
	char *name;
	char *id;
	int numOfWins;

};

typedef struct playerStruct Player;

struct linkedListNodeStruct{
	Player player;
	struct linkedListNodeStruct *next;
};

typedef struct linkedListNodeStruct  PlayerListNode;

void addToHead( PlayerListNode*);
PlayerListNode* getListHead();
PlayerListNode* createNewNode(char*, char*);

PlayerListNode* searchList(char*);
void deleteList();