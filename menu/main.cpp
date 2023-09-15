//#include "colors.h"
//#include "iostream"
//#include "menu.h"

//using namespace std;
//int main() {
//    std::string x = "Hello";
//    auto text = new Label();
//    text->set_label(x);
//    x = "Hello2";
//    text->render(true);
//    int wait;
//    cin >> wait;
//    return 0;
//}

#include <iostream>
#include <termios.h>

using namespace std;
int main()
{
// Black magic to prevent Linux from buffering keystrokes.
    struct termios t;
    tcgetattr(0, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &t);

// Once the buffering is turned off, the rest is simple.
    cout << "Enter a character: ";
    char c = cin.get();
    cout << "Your character was " << c << endl;

    return 0;
}
