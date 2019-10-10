/*********************************************************************
** Program name: Ant.cpp
** Author: David Lee
** Date: 04/13/2019
** Description: Class member function definitions for the Menu Class (Project 1).
 *              Reusable menu to start, end and restart programs.
 *              Also takes in object pointer parameter for input classes created in future projects.
*********************************************************************/

#include "Menu.hpp"

Menu::Menu(Input* inputTemplate){ //constructor that initializes data members needed for menu
    menuIntroMessage = "Welcome to Langton's Ant.\nEnter 1 to START. Enter 2 to END.";
    restartMessage = "Restart?\nEnter 1 to RESTART. Enter 2 to END.";
    invalidInputMessage = "Incorrect input. Please try again.";
    programEndMessage = "Program ended.";
    startInquiry = 0;
    start = 1;
    end = 2;
    restart = 0;
    runStatus = true;
    setInput(inputTemplate);
}

Menu::~Menu(){ //destructor that informs that the menu object is deleted
    cout << "Menu object deleted." << endl;
}

void Menu::setInput(Input* inputTemplate){ ////Input class member functions called to prompt user input
    input = inputTemplate;
}

void Menu::startMenu(){ //runs menu option

    char errorTest;
    bool repeatEntry = true;
    string inputLine;
    while (repeatEntry == true) {
        cout << menuIntroMessage << endl;
        getline(cin, inputLine);
        stringstream lineStream(inputLine);
        if (!(lineStream >> startInquiry)) {
            cout << "Input was not a number." << endl;
            cout << invalidInputMessage << endl;
        } else if ((startInquiry < start) || (startInquiry > end)) {
            cout << "Input out of range." << endl;
            cout << invalidInputMessage << endl;
        } else if (startInquiry - static_cast<int>(startInquiry) != 0) {
            cout << "Input with decimals and not an integer." << endl;
            cout << invalidInputMessage << endl;
        } else if (lineStream >> errorTest) {
            cout << "Input with extra symbols and/or characters." << endl;
            cout << invalidInputMessage << endl;
        } else {
            repeatEntry = false;
            startInquiry = startInquiry;
            cout << "Input accepted." << endl;
        }
    }
    if(startInquiry == 1){
        input->setBoard();
        input->setAnt();
        input->setAntDirection();
        input->setMoveCount();
    }else{
        setRunStatus(false);
        cout << programEndMessage << endl;
    }
}

void Menu::restartOption() { //runs restart option
    if(startInquiry == 1){
        char errorTest;
        bool repeatEntry = true;
        string inputLine;
        while (repeatEntry == true) {
            cout << restartMessage << endl;
            getline(cin, inputLine);
            stringstream lineStream(inputLine);
            if (!(lineStream >> restart)) {
                cout << "Input was not a number." << endl;
                cout << invalidInputMessage << endl;
            } else if ((restart < start) || (restart > end)) {
                cout << "Input out of range." << endl;
                cout << invalidInputMessage << endl;
            } else if (restart - static_cast<int>(restart) != 0) {
                cout << "Input with decimals and not an integer." << endl;
                cout << invalidInputMessage << endl;
            } else if (lineStream >> errorTest) {
                cout << "Input with extra symbols and/or characters." << endl;
                cout << invalidInputMessage << endl;
            } else {
                repeatEntry = false;
                restart = restart;
                cout << "Input accepted." << endl;
            }
        }
        if(restart == 1){
            setRunStatus(true);
        }else{
            setRunStatus(false);
            cout << programEndMessage << endl;
        }
    }
}

void Menu::setRunStatus(bool option){
    runStatus = option;
}

bool Menu::getRunStatus() {
    return runStatus;
}

int Menu::getStartInquiry(){
    return startInquiry;
}