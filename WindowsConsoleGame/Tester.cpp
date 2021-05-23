#include <iostream>
#include <windows.h>
#include "Entity.h"
#include "Player.h"
#include "CGameItem.h"
#include "GroundItem.h"
#include "Container.h"
#include "Map.h"


using namespace std;

void drawDefaultDisplay();

void printInvItem(string itemToPrint, int itemNo);

void outputMessage(string messageToOutput);

void gotoXY(int, int);

bool getNumber(int & number);

void printRemovedItem(int itemNo);

void printMap(Map m, const int SCREEN_HEIGHT, const int SCREEN_WIDTH);

int main(){

	const int SCREEN_WIDTH = 56;

	const int SCREEN_HEIGHT = 20;

	const int MAX_ITEMS = 8; //the max amount of inventory items we want to hold

	const char PLAYER_CHAR = '@';

	container<Entity*> ItemsOnMap; //holds all the items that are on the map
	
	container<CGameItem*> invItems; //This is the inventory system

	Map m = Map();
	
	//Spawn Potion at 10,10
	ItemsOnMap.push(new GroundItem(10,10,'P'));

	//Spawn a Spell at 15,4
	ItemsOnMap.push(new GroundItem(15,4,'S'));


	int startx = 3, 
		starty = 3,
		lastx = 1,
		lasty = 1;
	
	Player P1(startx,starty,PLAYER_CHAR, 100);

	ItemsOnMap.push(&P1);

	bool quit = false;

	//Screen output junk to make windows.h work
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    bool running = true;
    
    INPUT_RECORD irInput;
    
    GetNumberOfConsoleInputEvents(hInput, &NumInputs);
	//End of windows.h junk


	/*FIRST WE DRAW THE INTERFACE*/
	drawDefaultDisplay();

	
	/**DRAW ACTUAL MAP HERE**/
	//In this case we only draw map once because it is not yet destructable
	//if it were to be destructable we would either redraw it each time or simply draw over the tile(s) that were destroyed
	//sidenote: when a tile is destroyed remember to replace it in map[][] with ' '
	//If I were we would redraw the map once each time the user entered a new room (or perhaps moves out of screen bounds
	//in which case we would have that check in the movement section)
	printMap(m, SCREEN_HEIGHT, SCREEN_WIDTH);


	//Main Game Loop
	while(!quit){ 

		ReadConsoleInput(hInput, &irInput, 1, &InputsRead);
		
		
		//There is no collision detection for anyhting yet... actually this is really just 
		//practice for drawing stuff to the screen...

		//Buffering variables
		lastx = P1.getX();
		lasty = P1.getY();


		/* MOVEMENT HANDLING */
		//TODO: Add key input for using items 
		if(irInput.Event.KeyEvent.bKeyDown){
		switch(irInput.Event.KeyEvent.wVirtualKeyCode){
		case VK_ESCAPE:
			quit = true;
			break;
		case VK_UP:
			//if map[x][y-1] != some walkable character dont walk there
			if(P1.getY() > 1 && m.isWalkableAt(P1.getX()-1, P1.getY()-2))
				P1.moveY(-1);
			break;
		case VK_DOWN:
			if(P1.getY() < SCREEN_HEIGHT && m.isWalkableAt(P1.getX()-1, P1.getY()))
				P1.moveY(1);
			break;
		case VK_LEFT:
			if(P1.getX() > 1 && m.isWalkableAt(P1.getX()-2, P1.getY()-1))
				P1.moveX(-1);
			break;
		case VK_RIGHT:
			if(P1.getX() < SCREEN_WIDTH && m.isWalkableAt(P1.getX(), P1.getY()-1))
				P1.moveX(1);
			break;
		case 'U':
			int input;
			outputMessage("Enter index of item to use: ");
			if (getNumber(input) == false)
			{
				outputMessage("Invalid input");
				break; // get out of switch statement
			}

			if (input >= 0 && input < invItems.size())
			{
				invItems[input]->use();
			}
			else
			{
				outputMessage("index out of range or no items yet");
			}
			break;
			}
		}


		/*Here we would check if the character went off screen and update the map to refresh accordingly
		That is, if I was using a real map that went beyond the limit of what i had room to draw*/
		//as a side note if we update the map to move over by 5 spaces we must also load the coordinates of
		//everything we draw with a map modifier (so like gotoXY(x-Xmodifier, y-Ymodifier)) so that everything
		//draws in the correct location
		
		/*OVERWRITE WHERE THE PLAYER WAS*/
		gotoXY(lastx, lasty);
		cout << " ";

		/**For now we will load the inventory screen every time the map updates**/
		for(int i=0; i<invItems.size(); i++){
			printInvItem((*invItems[i]).description(),i);
		}

		printRemovedItem(invItems.size());

		/*NEXT WE LOAD ENTITIES THAT ARE ON THE MAP*/
		for(int i=0; i < ItemsOnMap.size(); i++){
			//check collision with player
			if((*ItemsOnMap[i]).getChar() != '@'){
				if(P1.detectCollision(*ItemsOnMap[i])){
					//if we have room to add an item to our inventory
					if(invItems.size() < MAX_ITEMS){
					//Handle Collision
					outputMessage("Item added to inventory");
					switch((*ItemsOnMap[i]).getChar()){
						
					case 'P':
						//Remove Item from map
						ItemsOnMap.remove(i);

						//Add Potion to inventory
						invItems.push(new CPotion());
						break;
					case 'S':
						//Remove item from map
						ItemsOnMap.remove(i);

						//Add Spell to inventory
						invItems.push(new CSpell());
						break;
					default:
						outputMessage("You picked up an invalid item");
						break;
						}
					}
				}
			}
				/*Possible good idea*/
				//handle collision Both objects need to be able to
				//Trigger each other's destroyed state so if one 
				//Object is destroyed we dont have to detect collisions
				//with or draw the other item unless it is a player

			//Draw all entities To screen
			gotoXY(ItemsOnMap[i]->getX(), ItemsOnMap[i]->getY());
			cout << ItemsOnMap[i]->getChar();
		}


	}
	system("Pause");
	return 0;
}


/*This is my version of gotoXY that uses windows libraries instead of the dos conio.h*/
void gotoXY(int x,int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void outputMessage(string messageToOutput){
	//Clear line
	gotoXY(1,22);
	cout << "                                                                          \n";
	cout << "                                                                          \n";
	cout << "                                                                          ";
	//Write line
	gotoXY(1,22);
	cout << messageToOutput;
}

void drawDefaultDisplay(){
	gotoXY(0,0);
	cout << "***********************************************************      **************\n";
	for(int i=0;i<20;i++)
	cout << "*                                                         *      *            *\n";
	cout << "***********************************************************      **************";
}

void printInvItem(string itemToPrint, int itemNo){
	//Clear Line
	gotoXY(67,1+itemNo);
	cout << endl;
	//write line
	gotoXY(66,1+itemNo);
	cout << itemNo << " " << itemToPrint;
}

//In the event we remove an item from the inventory we need to be able to stop printing it on the inv screen
void printRemovedItem(int itemNo){
	gotoXY(66,1+itemNo);
	cout << endl;
}

bool getNumber(int & number)
{
	// no code to add here 

	string input;

	getline(cin, input);

	// check that input is numeric
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
		{
			return false;
		}
	}

	number = atoi(input.c_str());

	return true;
}

void printMap(Map m, const int SCREEN_HEIGHT, const int SCREEN_WIDTH){
	for(int y = 0; y < SCREEN_HEIGHT; y++){
		for(int x = 0; x < SCREEN_WIDTH; x++){
			gotoXY(x+1, y+1);
			cout << m.getTileAt(x,y);
		}
	}

}