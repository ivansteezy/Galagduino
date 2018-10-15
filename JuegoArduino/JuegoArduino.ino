#include <TVout.h>
#include <fontALL.h>
#include <Keypad.h>
#include "Nave.h"
#include "Clear.h"
const int pasosPorRevolucion = 200;
int JoystickX = 0, JoystickY = 0;
TVout Tv;

int Vidas = 4;
class Asteroide{
  int AstX = 20, AstY = 50;
  
  public:
    Asteroide(int x, int y);
    void GenerarAsteroides();
    void MoverAsteroides();
    void Colisiones();
    //void Vida();
};
Asteroide asteroide(60, 20), asteroide2(80, 8), asteroide3(5, 20), asteroide4(100, 30);
int x = 50, y = 75;

Asteroide::Asteroide(int x, int y){
  AstX = x;
  AstY = y;
}

void MoverNave(){
  JoystickX = analogRead(A0);
  JoystickY = analogRead(A1);
  if(JoystickX == 1023){
    Tv.bitmap(x, y, Clear);
    y = y - 5;
  }
  if(JoystickX == 0){
    Tv.bitmap(x, y, Clear);
    y = y + 5;
  }
  if(JoystickY == 1023){
    Tv.bitmap(x, y, Clear);
    x = x + 5;
  }
  if(JoystickY == 0){
    Tv.bitmap(x, y, Clear);
    x = x - 5;
  }
}

void DibujarNave(){
  Tv.bitmap(x, y, Nave);
}

void Asteroide::GenerarAsteroides(){
   Tv.println(AstX, AstY, "0");
}

void Asteroide::MoverAsteroides(){
  Tv.println((AstX - 2), (AstY - 2), " ");
  AstY++;
  if((AstY + 5) > 90){
    Tv.println(AstX, AstY, " "); 
    AstX = random(5, 110);
    AstY = 5;
  }
  //Tv.delay(10);
}

void Asteroide::Colisiones(){
  if((AstX > x &&  AstX < (x + 16) || AstX > x &&  AstX < (x - 16)) && AstY > y && AstY < (y + 16)){
      Vidas--;
      AstX = random(5, 110);
      AstY = 5;
      MoverAsteroides();
  }
}

void Vida(){
   if(Vidas == 2){
      Tv.bitmap(5, 3, Corazon);
      Tv.bitmap(15, 3, miniClear);
      Tv.bitmap(25, 3, miniClear);
   }
    if(Vidas == 3){
      Tv.bitmap(5, 3, Corazon);
      Tv.bitmap(15, 3, Corazon);
      Tv.bitmap(25, 3, miniClear);
    }
    if( Vidas == 4){
      Tv.bitmap(5, 3, Corazon);
      Tv.bitmap(15, 3, Corazon);
      Tv.bitmap(25, 3, Corazon);
    }

  
  if(Vidas == 1){
     Tv.clear_screen();  
    Tv.select_font(font8x8);
     Tv.println(20, 30, "Game Over"); 
     Tv.delay(10000);
     
  }
  
}
void DibujarLimites(){
    Tv.draw_rect(0, 0, 114, 93, WHITE);
}

void OutOfBounds(){
  if(x < 5) x = 6;
  if(x > 100) x = 100;
  if(y < 5) y = 6;
  if(y > 80) y = 70;
}

void setup() {
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Tv.select_font(font6x8);
  Tv.begin(NTSC, 120, 96);
}


void loop(){
  
  Vida();
  OutOfBounds();
  DibujarNave();
  MoverNave();
  Tv.delay(10);
  DibujarLimites();
  
  asteroide.GenerarAsteroides();
  asteroide.MoverAsteroides();
  asteroide.Colisiones();
  
  asteroide2.GenerarAsteroides();
  asteroide2.MoverAsteroides();
  asteroide2.Colisiones();

  asteroide3.GenerarAsteroides();
  asteroide3.MoverAsteroides();
  asteroide3.Colisiones();

  asteroide4.GenerarAsteroides();
  asteroide4.MoverAsteroides();
  asteroide4.Colisiones();

}
