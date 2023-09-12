#include <iostream>
#include <conio.h>//For _getch().

//https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer

int main() {
    int selected = 0;    //Keeps track of which option is selected.
    int numChoices = 2; //The number of choices we have.
    bool selecting = true;//True if we are still waiting for the user to press enter.
    bool updated = false;//True if the selected value has just been updated.

    //Output options
    std::cout << "A. Option 1\n";
    std::cout << "B. Option 2\n";

    char c; //Store c outside of loop for efficiency.
    while (selecting) { //As long as we are selecting...
        switch ((c = (char) _getch())) { //Check value of the last inputed character.
            case KEY_UP:
                if (selected > 0) { //Dont decrement if we are at the first option.
                    --selected;
                    updated = true;
                }
                break;
            case KEY_DOWN:
                if (selected < numChoices - 1) { //Dont increment if we are at the last option.
                    ++selected;
                    updated = true;
                }
                break;
            case KEY_ENTER:
                //We are done selecting the option.
                selecting = false;
                break;
            default: break;
        }
        if (updated) { //Lets us know what the currently selected value is.
            std::cout << "Option " << (selected + 1) << " is selected.\n";
            updated = false;
        }
    }
    //Lets us know what we ended up selecting.
    std::cout << "Selected " << (selected + 1) << '\n';
    return 0;

}