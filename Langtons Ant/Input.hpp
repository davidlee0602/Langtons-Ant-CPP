/*********************************************************************
** Program name: Input.hpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class declarations, both public and private for the Input class
*********************************************************************/

#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include <string>
#include <sstream> //header file for stringstream
#include <cstdlib> //header file for srand and rand
#include <ctime> // header file for time
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

class Input {
private:
    string boardRowMessage; //messages for input prompt
    string boardColumnMessage;
    string randomAntMessage;
    string antStartRowMessage;
    string antStartColumnMessage;
    string antDirectionMessage;
    string moveCountMessage;
    string invalidInputMessage;
    double boardRowInput; //store input values (double used to check for decimals in input validation)
    double boardColumnInput;
    double randomAntInput;
    double antStartRowInput;
    double antStartColumnInput;
    double moveCountInput;
    double antDirectionInput;
    int randomAntRowSeed; //seed set for rand()
    int randomAntColumnSeed; //seed set for rand()
    int boardRowInputMin; //set fixed ranges for input values
    int boardRowInputMax;
    int boardColumnInputMin;
    int boardColumnInputMax;
    int randomAntInputMin;
    int randomAntInputMax;
    int antStartRowInputMin;
    int antStartColumnInputMin;
    int antDirectionInputMin;
    int antDirectionInputMax;
    int moveCountInputMin;
    int moveCountInputMax;



public:
    Input(); //constructor
    ~Input(); //destructor
    void setBoardRow(); //prompts board size input
    void setBoardColumn();
    void setRandomAnt(); //prompts if user wants random ant location
    void setRandomAntRow(); //sets random ant location to ant start location
    void setRandomAntColumn();
    void setAntStartRow(); //prompts user to input ant start location
    void setAntStartColumn();
    void setAntDirection(); //prompts user to input ant start direction (north = 1, south = 2, east = 3, west = 4)
    void setMoveCount(); //prompts user to input how many times the ant should move
    void setBoard(); //calls setBoardRow() & setBoardColumn() class member functions
    void setAnt(); //calls setRandomAnt(), setRandomAntRow(), setRandomAntColumn(), setAntStartRow(), setAntStartColumn() class member functions
    int getBoardRow(); //returns board size stored in input
    int getBoardColumn();
    int getRandomAnt(); //returns user option stored in random ant location yes/no input
    int getAntStartRow(); //returns ant's location stored in input
    int getAntStartColumn();
    int getMoveCount(); //returns move count stored in input
    int getAntDirection(); //returns starting direction set by user

};


#endif
