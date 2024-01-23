#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"
#include "helper.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
//things that could go wrong that is not checked: numbers are strings
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    char** map = nullptr;
    int actualRows = -2;
    int actualCols = 0;
    bool isExit = false;
    string temporary = "";
    ifstream input(fileName);
    if(!input.is_open()){
        return map;
    }
    input >> maxRow;
    if(input.fail()){
        return map;
    }
    input >> maxCol;
    if(input.fail()){
        return map;
    }
    input >> player.row;
    if(input.fail()){
        return map;
    }
    input >> player.col;
    if(input.fail()){
        return map;
    }
    if(maxRow <= 0 || maxCol <= 0){
        return nullptr;
    }
    ifstream inputCopy(fileName);
    ifstream inputCopy2(fileName);
    //getting the actual number of rows in the map
    while(getline(inputCopy,temporary)){
        actualRows++;
    }
    getline(inputCopy2,temporary);
    getline(inputCopy2,temporary);
    getline(inputCopy2,temporary);
    //finding the number of cols based on the first row
    for(size_t i = 0; i < temporary.length(); i++){
        if(temporary.at(i) == TILE_MONSTER || temporary.at(i) == TILE_AMULET || temporary.at(i) 
                == TILE_DOOR || temporary.at(i) == TILE_EXIT || temporary.at(i) == TILE_OPEN || temporary.at(i) 
                == TILE_PILLAR || temporary.at(i) == TILE_TREASURE){
            actualCols++;
        }
    }
    /*
    for(int i = 1; i < actualRows; i++){
        getline(inputCopy2,temporary);

    }*/
    char temp = 'n';
    if(actualCols == maxCol && actualRows == maxRow){
        map = createMap(maxRow,maxCol);
        for(int row = 0; row < maxRow; row++){
            for(int col = 0; col < maxCol; col++){
                input >> temp;
                if(input.fail()){
                    deleteMap(map,maxRow);
                    return map;
                }
                //checking for invalid symbols in file
                if(temp != TILE_MONSTER && temp != TILE_AMULET && temp 
                != TILE_DOOR && temp!= TILE_EXIT && temp != TILE_OPEN && temp 
                != TILE_PILLAR && temp != TILE_TREASURE){
                    deleteMap(map,maxRow);
                    return map;
                }
                else{
                    map[row][col] = temp;
                }
            }
        }
        //checking for valid place within the dungeon level
        if((player.row < maxRow && player.col < maxCol) && (player.row >= 0 && player.col >= 0)){
            map[player.row][player.col] = TILE_PLAYER;
        }
        else{
            deleteMap(map,maxRow);
            return map;
        }
        //checking to see if the map has a door or exit
        for(int row = 0; row < maxRow; row++){
            for(int col = 0; col < maxCol; col++){
                if(map[row][col] == TILE_EXIT || map[row][col] == TILE_DOOR){
                    isExit = true;
                }
            }
        }
        if(!isExit){
            deleteMap(map,maxRow);
            return map;
        }
        return map;
    }
    else{
        return map;
    }
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
//might need support for upcase inputs
void getDirection(char input, int& nextRow, int& nextCol) {
    if(input == MOVE_UP || input == MOVE_DOWN|| input == MOVE_LEFT|| input == MOVE_RIGHT){
        if(input == MOVE_UP){
            nextRow--;
        }
        if(input == MOVE_DOWN){
            nextRow++;
        }
        if(input == MOVE_LEFT){
            nextCol--;
        }
        if(input == MOVE_RIGHT){
            nextCol++;
        }
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char** map = new char* [maxRow];
    for(int row = 0; row < maxRow; row++){
        map[row] = new char[maxCol];
    }
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            map[row][col] = TILE_OPEN;
        }
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if(map != nullptr){
        for(int i = 0; i < maxRow; i++){
            delete [] map[i];
        }
        delete [] map;
        map = nullptr;
    }
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    int playerRow = 0;
    int playerCol = 0;
    if((maxRow <= 0 || maxCol <= 0) && map != nullptr){
        for(int i = 0; i < maxRow; i++){
            delete[] map[i];
        }
        delete[] map;
        map = nullptr;
        return map;
    }
    if(map == nullptr){
        return map;
    }
    //creating and allocating the new map
    char** newMap = new char* [maxRow*2];
    for(int i = 0; i < maxRow*2; i++){
        newMap[i] = new char [maxCol*2];
    }
    //deleting the player tile from the original map for ease of copying
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            if(map[row][col] == TILE_PLAYER){
                playerRow = row;
                playerCol = col;
                map[row][col] = TILE_OPEN;
            }
        }
    }
    //copying the old map exactly into subarray A
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            newMap[row][col] = map[row][col];
        }
    }
    //copying the old map exactly into subarray B
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            newMap[row][col + maxCol] = newMap[row][col];
        }
    }
    //copying the old map exactly into subarray C
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            newMap[row + maxRow][col] = newMap[row][col];
        }
    }
    //copying the old map exactly into subarray D
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            newMap[row + maxRow][col + maxCol] = newMap[row][col];
        }
    }
    //replacing player tile after array has been resized and copied
    newMap[playerRow][playerCol] = TILE_PLAYER;
    //deallocating the old map
    for(int i = 0; i < maxRow; i++){
        delete[] map[i];
    }
    delete[] map;
    maxRow = 2*maxRow;
    maxCol = 2*maxCol;
    map = new char* [maxRow];
    for(int i = 0; i < maxRow; i++){
        map[i] = new char [maxCol];
    }
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            map[row][col] = TILE_OPEN;
        }
    }
    for(int row = 0; row < maxRow; row++){
        for(int col = 0; col < maxCol; col++){
            map[row][col] = newMap[row][col];
        }
    }
    for(int i = 0; i < maxRow; i++){
        delete[] newMap[i];
    }
    delete[] newMap;
    return map;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status = STATUS_STAY;
    if(nextRow >= maxRow || nextRow < 0 || nextCol >= maxCol || nextCol < 0){
        status = STATUS_STAY;
        return status;
    }
    if(map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == TILE_MONSTER){
        status = STATUS_STAY;
        return status;
    }
    if(map[nextRow][nextCol] == TILE_OPEN && ((player.row+1 == nextRow && player.col == nextCol)
    ||(player.row == nextRow && player.col+1 == nextCol)||(player.row-1 == nextRow && player.col ==
    nextCol)||(player.row == nextRow && player.col-1 == nextCol))){
        status = STATUS_MOVE;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
    }
    else{
        status = STATUS_STAY;
    }
    if(map[nextRow][nextCol] == TILE_TREASURE){
        status = STATUS_TREASURE;
        player.treasure++;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
    }
    if(map[nextRow][nextCol] == TILE_AMULET){
        status = STATUS_AMULET;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
    }
    if(map[nextRow][nextCol] == TILE_DOOR){
        status = STATUS_LEAVE;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
    }
    if(map[nextRow][nextCol] == TILE_EXIT && player.treasure >= 1){
        status = STATUS_ESCAPE;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
    }
    else if(map[nextRow][nextCol] == TILE_EXIT && player.treasure == 0){
        status = STATUS_STAY;
    }
    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    bool monsterStatus = false;
    //checking for upward LOS
    for(int row = player.row-1; row > -1; row--){
        if(map[row][player.col] == TILE_PILLAR){
            break;
        }
        else if (map[row][player.col] == TILE_MONSTER){
            map[row+1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
        }
    }
    //checking for downward LOS
    for(int row = player.row+1; row < maxRow; row++){
        if(map[row][player.col] == TILE_PILLAR){
            break;
        }
        else if(map[row][player.col] == TILE_MONSTER){
            map[row-1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
        }
    }
    //checking for left LOS
    for(int col = player.col-1; col > -1; col--){
        if(map[player.row][col] == TILE_PILLAR){
            break;
        }
        else if(map[player.row][col] == TILE_MONSTER){
            map[player.row][col+1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
        }
    }
    //checking for right LOS
    for(int col = player.col+1; col < maxCol; col++){
        if(map[player.row][col] == TILE_PILLAR){
            break;
        }
        else if(map[player.row][col] == TILE_MONSTER){
            map[player.row][col-1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
        }
    }
    if(map[player.row][player.col] == TILE_MONSTER){
        monsterStatus = true;
    }
    return monsterStatus;
}
