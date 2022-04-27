#include <SDL.h>
#include "Label.h"
#include "Session.h"
#include "Button.h"
#include "Player.h"
#include "Food.h"
#include <string>

namespace game {
std::string imagePath = "../../resources/images/";
std::string fontPath = "../../resources/fonts/";
std::string soundPath = "../../resources/sounds/";
}

using namespace std;
using namespace game;

int main(int argc, char** argv) {
    Label* lbl = Label::getInstance(1,1,100,70, "Scoure:");
    ses.add(lbl);
    Label* lbl1 = Label::getInstance(100,1,70,70, "0");
    ses.add(lbl1);
    Player* player1 = Player::getInstance(400,415,100,100);
    ses.add(player1);
    Button* r = Button::getInstance(1,500,90,90,"Restart",lbl1);
    ses.add(r);
    Food* f1 = Food::getInstance(300,1,40,40,lbl1,player1,"apple.bmp",10);
    ses.add(f1);
    Food* f2 = Food::getInstance(400,-50,40,40,lbl1,player1,"apple.bmp",10);
    ses.add(f2);
    Food* f3 = Food::getInstance(600,-150,60,60,lbl1,player1,"rott-apple.bmp",-10);
    ses.add(f3);
    Food* f4 = Food::getInstance(100,-400,60,60,lbl1,player1,"rott-apple.bmp",-10);
    ses.add(f4);
    Food* f5 = Food::getInstance(700,-400,40,40,lbl1,player1,"apple.bmp",10);
    ses.add(f5);
    ses.run();


    return 0;
}