/*********************************************************************
** Program name: Menu.hpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class declarations, both public and private for the Menu class
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include <sstream> //header file for stringstream
#include "Input.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

class Menu{
private:
    string menuIntroMessage; //intro message in menu
    string restartMessage; //message asking user if they want to restart
    string invalidInputMessage; //message after failing input validation in menu
    string programEndMessage; //program ended message
    double startInquiry; //user input value in menu prompt
    double restart; //user input value in restart prompt
    int start; //min value range for user input
    int end; //max value range for user input
    bool runStatus = true; //run flag
    Input* input; //Input class object pointer used for parameter

public:
    Menu(Input* inputTemplate); //constructor
    ~Menu(); //destructor
    void startMenu(); //calls menu to start or end program
    void setInput(Input* inputTemplate); //Input class member functions called to prompt user input
    void restartOption(); //prompts user to input for restart option
    void setRunStatus(bool option); //flag to change runStatus value
    bool getRunStatus(); //returns runStatus
    int getStartInquiry(); //returns user input for menu option
};


#endif