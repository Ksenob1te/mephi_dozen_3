#include "colors.h"
#include "iostream"
#include "menu.h"

using namespace std;
int main() {
    std::string x = "Hello";
    auto text = new Label();
    text->set_label(x);
    x = "Hello2";
    text->render(true);
    int wait;
    cin >> wait;
    return 0;
}
