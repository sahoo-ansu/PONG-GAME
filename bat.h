#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class BAT{
    private:
        RectangleShape batShape;
        float batMovePixelPerSec;
        float batSpeed;
    
    public:
        BAT();
    
        //move bar left & right
        void moveBatLeft(Time &dt);
        void moveBatRight(Time &dt);
        RectangleShape getShape();
    };