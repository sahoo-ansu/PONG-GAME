
BAT::BAT(){    
    batShape.setFillColor(Color::White);
    batShape.setPosition(1980/2,1020-20);
    batShape.setSize(Vector2f(100,5));
    batSpeed=5;
    batMovePixelPerSec=1980/batSpeed;
}

//move bar left & right
void BAT::moveBatLeft(Time dt){
    float x=batShape.getPosition().x;
    x=x-batMovePixelPerSec*dt.asSeconds();
    if(x<0){
        x=0;
    }
    batShape.setPosition(x,batShape.getPosition().y);    
}
void BAT::moveBatRight(Time dt){
    float x=batShape.getPosition().x;
    x=x+batMovePixelPerSec*dt.asSeconds();
    if(x>1880){
        x=1880;
    }
    batShape.setPosition(x,batShape.getPosition().y);    
}
RectangleShape getShape(){
    return batShape;
}
