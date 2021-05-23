#pragma once
#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <string>
using namespace std;

class Map{
private:
	
	static const int WIDTH = 54;
	static const int HEIGHT = 18;

	char _a[WIDTH][HEIGHT];
public:
	Map(){
		for(int y = 0; y < HEIGHT; y++){
			for(int x = 0; x < WIDTH; x++){
				if(x % 5 == 1)
					_a[x][y] = 'X';
				else
					_a[x][y] = ' ';
			}
		}
	}

	Map(string FileToLoadFrom){
		//Open the file to read from
		
		//Read lines from the file into the map rows

		//every time a line ends move to the next row until we dont have any more room in the array or the file is empty

		//if the file was empty before we fully filled the map, fill the rest with ' ' empty chars
	}

	bool isWalkableAt(int x, int y) {
		return _a[y][x] == ' ';
	}

	char getTileAt(int x, int y){
		return _a[y][x];
	}

};

#endif