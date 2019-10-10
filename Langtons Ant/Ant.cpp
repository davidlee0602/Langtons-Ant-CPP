/*********************************************************************
** Program name: Ant.cpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class member function definitions for the Ant Class (Project 1).
 *              The class contains board creation, board print, ant placement, ant direction and ant move member functions.
 *              Class acts as the brain of the ant with algorithms listed.
*********************************************************************/

#include "Ant.hpp"

Ant::Ant(){ //constructor initializes data member values
    antRowLocation = 0;
    antColumnLocation = 0;
    antDirection = 1;
    antMoveCounter = 0;
    boardRows = 0;
    boardColumns = 0;
    array = nullptr;
    antLocationColor = ' ';
}

Ant::~Ant(){ //console message shown when object is deleted by the program
    cout << "Ant object deleted." << endl;
}
void Ant::antBoard(int boardRowCount, int boardColumnCount, int antRow, int antColumn, int antDirection){ //creates board and sets ant
    setAntRowLocation(antRow);
    setAntColumnLocation(antColumn);
    setAntDirection(antDirection);
    boardRows = boardRowCount;
    boardColumns = boardColumnCount;
    array = new char *[boardRows];
    for (int i = 0; i < boardRows; i++) {
        array[i] = new char[boardColumns];
    }
    //initialize array values to space
    for (int i = 0; i < boardRows; i++) {
        for (int j = 0; j < boardColumns; j++) {
            array[i][j] = ' ';
        }
    }
}

void Ant::deallocate(int boardRowCount){ //de-allocates board created
    for (int i = 0; i < boardRowCount ; i++){
        delete [] array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
}

void Ant::setAntRowLocation(int row){ //set ant row location
    antRowLocation = row;
}

void Ant::setAntColumnLocation(int column){ //set ant column location
    antColumnLocation = column;
}

void Ant::setAntDirection(int direction){ //set ant direction (north = 1, south = 2, east = 3, west = 4)
    antDirection = direction;
}

int Ant::getAntDirection(){ //returns ant's direction
    return antDirection;
}

int Ant::getAntRowLocation(){ //returns ant's row
    return antRowLocation;
}

int Ant::getAntColumnLocation(){ //returns ant's column
    return antColumnLocation;
}
void Ant::resetAntCounter(){ //resets ant move counter
    antMoveCounter = 0;
}
int Ant::getAntCounter(){ //returns ant move counter
    cout << "Ant move #: "<< ++antMoveCounter << endl;
    return antMoveCounter;
}
void Ant::printBoard(){ //prints both the board and ant placed
    for (int i = 0; i < boardRows; i++){
        for (int j = 0; j < boardColumns; j++){
            cout << array[i][j];
        }
        cout << endl;
    }
}

void Ant::changeTileBlack(){ //changes board tile black
    array[getAntRowLocation()][getAntColumnLocation()] = '#';
}
void Ant::changeTileWhite(){ //changes board tile white
    array[getAntRowLocation()][getAntColumnLocation()] = ' ';
}
void Ant::placeAnt(){ //places ant at specified location with '*' symbol
    array[getAntRowLocation()][getAntColumnLocation()] = '*';
}
void Ant::antMove(int direction){ //defines ant movement behavior based on direction (north = 1, south = 2, east = 3, west = 4)
    if(direction == 1){
        setAntRowLocation(getAntRowLocation() - 1);
    }else if(direction == 2){
        setAntRowLocation(getAntRowLocation() + 1);
    }else if(direction == 3){
        setAntColumnLocation(getAntColumnLocation() + 1);
    }else if(direction == 4){
        setAntColumnLocation(getAntColumnLocation() - 1);
    }else{
        cout << "Incorrect direction." << endl;
    }
}
char Ant::currentColor() { //returns ant's current location color
    return array[getAntRowLocation()][getAntColumnLocation()];
}
void Ant::setAntLocationColor(char color){ //sets ant location color
    antLocationColor = color;
}
char Ant::getAntLocationColor(){ //returns ant location color
    return antLocationColor;
}

void Ant::run(int moveCount) { //moves ant based on count in parameter
    int north = 1;
    int south = 2;
    int east = 3;
    int west = 4;

    for (int i = 0; i < moveCount; ++i) {
        if(getAntLocationColor() == ' ') {
            array[getAntRowLocation()][getAntColumnLocation()] = ' ';
        }else {
            array[getAntRowLocation()][getAntColumnLocation()] = '#';
        }


        if(getAntDirection() == north && currentColor() == ' '){


            if(getAntColumnLocation() != (boardColumns-1)){
                setAntDirection(east);
                changeTileBlack();
                antMove(east);
            }else{
                setAntDirection(west);
                changeTileBlack();
                antMove(west);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == north && currentColor() == '#'){

            if(getAntColumnLocation() != 0){
                setAntDirection(west);
                changeTileWhite();
                antMove(west);
            }else{
                setAntDirection(east);
                changeTileWhite();
                antMove(east);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == south && currentColor() == ' '){

            if(getAntColumnLocation() != 0){
                setAntDirection(west);
                changeTileBlack();
                antMove(west);
            }else{
                setAntDirection(east);
                changeTileBlack();
                antMove(east);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == south && currentColor() == '#'){

            if(getAntColumnLocation() != (boardColumns-1)){
                setAntDirection(east);
                changeTileWhite();
                antMove(east);
            }else{
                setAntDirection(west);
                changeTileWhite();
                antMove(west);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == east && currentColor() == ' '){

            if(getAntRowLocation() != (boardRows-1)){
                setAntDirection(south);
                changeTileBlack();
                antMove(south);
            }else{
                setAntDirection(north);
                changeTileBlack();
                antMove(north);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == east && currentColor() == '#'){

            if(getAntRowLocation() != 0){
                setAntDirection(north);
                changeTileWhite();
                antMove(north);
            }else{
                setAntDirection(south);
                changeTileWhite();
                antMove(south);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == west && currentColor() == ' '){

            if(getAntRowLocation() != 0){
                setAntDirection(north);
                changeTileBlack();
                antMove(north);
            }else{
                setAntDirection(south);
                changeTileBlack();
                antMove(south);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else if (getAntDirection() == west && currentColor() == '#'){

            if(getAntRowLocation() != (boardRows-1)){
                setAntDirection(south);
                changeTileWhite();
                antMove(south);
            }else{
                setAntDirection(north);
                changeTileWhite();
                antMove(north);
            }

            setAntLocationColor(currentColor());
            placeAnt();

        }else{
            cout << "Incorrect Ant Placement" << endl;
        }
        getAntCounter();
        printBoard();
        cout << endl;
    }
    resetAntCounter();
}
