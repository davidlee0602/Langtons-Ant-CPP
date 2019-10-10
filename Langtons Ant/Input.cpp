/*********************************************************************
** Program name: Ant.cpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class member function definitions for the Input Class (Project 1).
 *              Prompts user for inputs to be used as parameters for the Ant class member functions.
 *              Boardsize, ant start location, randomize ant start location, ant direction, ant movement count.
*********************************************************************/

#include "Input.hpp"

Input::Input() { //constructor initializes all user input storage data members and messages displayed prior to prompt
    boardRowMessage = "How many ROW(S) for the board? Enter integer.";;
    boardColumnMessage = "How many COLUMN(S) for the board? Enter integer.";
    randomAntMessage = "Would you like to place the ant in a random location?\nEnter 1 for YES. Enter 2 for NO.";
    antStartRowMessage = "Which ROW should the ant start? Enter integer.";
    antStartColumnMessage = "Which COLUMN should the ant start? Enter integer.";
    antDirectionMessage = "Which direction should the ant face?\nEnter 1 for NORTH. Enter 2 for SOUTH. Enter 3 for EAST. Enter 4 for WEST.";
    moveCountMessage = "Enter how many times the ant should move? Enter integer.";
    invalidInputMessage = "Invalid input. Please try again.";
    boardRowInput = 1;
    boardColumnInput = 1;
    randomAntInput = 0;
    antStartRowInput = 0;
    antStartColumnInput = 0;
    moveCountInput = 0;
    antDirectionInput = 0;
    randomAntRowSeed = time(0);
    srand(randomAntRowSeed);
    randomAntColumnSeed = time(0);
    srand(randomAntColumnSeed);
    boardRowInputMin = 1;
    boardRowInputMax = 65535;
    boardColumnInputMin = 1;
    boardColumnInputMax = 65535;
    randomAntInputMin = 1;
    randomAntInputMax = 2;
    antStartRowInputMin = 0;
    antStartColumnInputMin = 0;
    antDirectionInputMin = 1;
    antDirectionInputMax = 4;
    moveCountInputMin = 1;
    moveCountInputMax = 65535;
}

Input::~Input(){ //destructor shows input object is deleted
    cout << "Input object deleted." << endl;
}
//input validation referenced from following source "https://stackoverflow.com/questions/13212043/integer-input-validation-how"
void Input::setBoardRow() { //user prompt to set board row size
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << boardRowMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> boardRowInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((boardRowInput < boardRowInputMin) || (boardRowInput > boardRowInputMax)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (boardRowInput - static_cast<int>(boardRowInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            boardRowInput = boardRowInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setBoardColumn() { //user prompt to set board column size
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << boardColumnMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> boardColumnInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((boardColumnInput < boardColumnInputMin) || (boardColumnInput > boardColumnInputMax)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (boardColumnInput - static_cast<int>(boardColumnInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            boardColumnInput = boardColumnInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setRandomAnt() { //user prompt to check if they want random ant starting location
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << randomAntMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> randomAntInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((randomAntInput < randomAntInputMin) || (randomAntInput > randomAntInputMax)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (randomAntInput - static_cast<int>(randomAntInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            randomAntInput = randomAntInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setRandomAntRow(){ //set random ant start row
    antStartRowInput = (rand() % static_cast<int>(boardRowInput));
}

void Input::setRandomAntColumn(){ //set random ant start column
    antStartColumnInput = (rand() % static_cast<int>(boardColumnInput));
}

void Input::setAntStartRow() { //user prompt to set ant start row
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << antStartRowMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> antStartRowInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((antStartRowInput < antStartRowInputMin) || (antStartRowInput > (boardRowInput - 1))) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (antStartRowInput - static_cast<int>(antStartRowInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            antStartRowInput = antStartRowInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setAntStartColumn() { //user prompt to set ant start column
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << antStartColumnMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> antStartColumnInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((antStartColumnInput < antStartColumnInputMin) || (antStartColumnInput > (boardColumnInput - 1))) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (antStartColumnInput - static_cast<int>(antStartColumnInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            antStartColumnInput = antStartColumnInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setAntDirection() { //user prompt to set ant start direction
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << antDirectionMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> antDirectionInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((antDirectionInput < antDirectionInputMin) || (antDirectionInput > antDirectionInputMax)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (antDirectionInput - static_cast<int>(antDirectionInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            antDirectionInput = antDirectionInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setMoveCount() { //user prompt to set ant move count
    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << moveCountMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> moveCountInput)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((moveCountInput < moveCountInputMin) || (moveCountInput > moveCountInputMax)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (moveCountInput - static_cast<int>(moveCountInput) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            moveCountInput = moveCountInput;
            cout << "Input accepted." << endl;
        }
    }
}

void Input::setBoard(){ //condensed board prompt
    setBoardRow();
    setBoardColumn();
}

void Input::setAnt() { //condensed ant start location prompt
    setRandomAnt();
    if (getRandomAnt() == 1) {
        setRandomAntRow();
        setRandomAntColumn();
    }else{
        setAntStartRow();
        setAntStartColumn();
    }
}

int Input::getBoardRow(){
    return boardRowInput;
}

int Input::getBoardColumn(){
    return boardColumnInput;
}

int Input::getRandomAnt(){
    return randomAntInput;
}

int Input::getAntStartRow(){
    return antStartRowInput;
}

int Input::getAntStartColumn(){
    return antStartColumnInput;
}
int Input::getMoveCount(){
    return moveCountInput;
}
int Input::getAntDirection(){
    return antDirectionInput;
}




