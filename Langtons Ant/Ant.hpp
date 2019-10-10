/*********************************************************************
** Program name: Ant.hpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class declarations, both public and private for the Ant class
*********************************************************************/

#ifndef PROJECT1_ANT_HPP
#define PROJECT1_ANT_HPP
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Ant{
    private:
        int antRowLocation; //defines the location of the ant.
        int antColumnLocation;
        int antDirection; //stores the direction value which the ant is facing via integers.
        int antMoveCounter; //counter that keeps track of ant movement frequency
        int boardRows; //defines board size
        int boardColumns;
        char **array; //used to initialize dynamic array
        char antLocationColor;// ant location color

    public:
        Ant(); //constructor
        ~Ant(); //destructor
        void antBoard(int boardRowCount, int boardColumnCount, int antRow, int antColumn, int antDirection); //parameters used to create board, set ant start location and set ant start direction
        void deallocate(int boardRowCount); //de-allocates ant board after program runs
        void setAntRowLocation(int row); //set ant row
        int getAntRowLocation(); //returns ant row
        void setAntColumnLocation(int column); //set ant column
        int getAntColumnLocation(); //returns ant column
        void resetAntCounter(); //reset ant move counter
        int getAntCounter(); //returns ant counter
        void setAntDirection(int direction); //set ant direction
        int getAntDirection(); //returns ant direction
        void printBoard(); //prints dynamic array board
        void run(int moveCount); //moves the ant by count specified in the parameter

        void changeTileBlack(); //change tile in board black
        void changeTileWhite(); //change tile in board white
        void placeAnt(); //place ant on board
        void antMove(int direction); //move respective to direction parameter set
        char currentColor(); //returns color of tile stored
        void setAntLocationColor(char color); //set color at ant's location
        char getAntLocationColor(); //get color at ant's location

};


#endif