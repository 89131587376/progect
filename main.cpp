#include <iostream>
#include "GroupmateList.h"
#include "Menu.h"
using namespace std;
int main() {
	GroupmateList list("Denisss", "Kulikov", "Nicolaevich", "denizone66@gmail.com", "89963951628", "SBS-901");
	Menu::execute(list);
}



