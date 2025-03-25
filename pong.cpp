#include<SFML/Graphics.hpp>
#include<sstream>
#include "bat.cpp"

using namespace sf;
using namespace std;




int main(){
    VideoMode vm(800,600);
    RenderWindow window(vm,"PongGame !!!");

    View vw(FloatRect(0,0,1980,1020));
    window.setView(vw);//view window

    //add bar
    BAT bat;

    //add score,lifeline
    Text textScore;
    Font fnt;
    fnt.loadFromFile("KOMIKAP_.ttf");
    textScore.setFont(fnt);
    textScore.setCharacterSize(75);
    textScore.setFillColor(Color::White);
    textScore.setString("Score = 0");
    textScore.setPosition(20,20);

    Text textLive;//life line
    textLive.setFont(fnt);
    textLive.setCharacterSize(75);
    textLive.setFillColor(Color::White);
    textLive.setString("Live : 3");
    textLive.setPosition(1600,20);

    int lives=3;
    int score=0;
    bool acceptInput=true;
    bool gameOver=false;
    Clock ct;
    Time dt;

    while (window.isOpen()) //open window
    {
        Event ev;
        dt=ct.restart();
        while (window.pollEvent(ev))
        {
            //window close
            if(ev.type==Event::Closed){
                window.close();
            }
            if(ev.type==Event::KeyReleased){
                acceptInput=true;
            }
        }

        //update score
        stringstream ss,ss1;
        ss<<"SCORE = "<<score;
        textScore.setString(ss.str());
        if(lives!=0){
            ss1<<"LIVE = "<<lives;
        }
        else{
            ss1<<"GameOver!!";
            gameOver=true;
        }
        textLive.setString(ss1.str());

        if(acceptInput){
            if(Keyboard::isKeyPressed(Keyboard::Left) && gameOver==false){
                bat.moveBatRight(dt);
                score++;
                acceptInput=false;
            }
            if(Keyboard::isKeyPressed(Keyboard::Right) && gameOver==false){
                bat.moveBatRight(dt);
                score++;
                acceptInput=false;
            }
            if(Keyboard::isKeyPressed(Keyboard::Enter) && gameOver){ //restart the game
                lives=3;
                score=0;
                gameOver=false;
            }
    }

        window.clear();//clear everything before drawing

        //drawing object
        window.draw(bat.getShape());
        window.draw(textScore);
        window.draw(textLive);
        
        window.display();
    }
    
}