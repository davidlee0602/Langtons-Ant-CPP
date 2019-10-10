/*********************************************************************
** Program name: main.cpp
** Author: David Lee
** Date: 04/13/2019
** Description: Main file for Langton's Ant program that initiates all necessary Ant, Menu, Input classes into objects
 *              and calls class member functions to run. The program will first ask the user to input values used for the board size,
 *              ant starting location, ant direction and ant movement count. After user input, it will use those values to create a board,
 *              then follow the Langton's Ant conditions to move the ant and print the board every move.
*********************************************************************/

#include <iostream>
#include "Ant.hpp"
#include "Menu.hpp"
#include "Input.hpp"

using namespace std;
int main() {
    Input input; //initialize Input object
    Ant ant; //initialize Ant object
    Menu menu(&input); //initialize Menu object via constructor with input object parameter
        while(menu.getRunStatus()){ //loop to run program until user specifies no in restartOption
            menu.startMenu(); //ask user to start program or end program
            if((menu.getStartInquiry() == 1) && (menu.getRunStatus() == 1)){
                ant.antBoard(input.getBoardRow(),input.getBoardColumn(),input.getAntStartRow(),input.getAntStartColumn(),input.getAntDirection()); //calls ant class member function to create board and places ant
                ant.run(input.getMoveCount()); //calls ant class member function to move the ant by referencing move count from user
                ant.deallocate(input.getBoardRow()); //de-allocates board create in ant object
            }
            menu.restartOption(); //ask user to restart program
        }

    return 0;
}
