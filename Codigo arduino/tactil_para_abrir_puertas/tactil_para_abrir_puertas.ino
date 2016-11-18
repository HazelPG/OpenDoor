//Se Importan las Librerias 
#include <UTFT.h>
#include <URTouch.h>
UTFT    myGLCD(ITDB32WC,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);
extern uint8_t BigFont[];

//variables para el eje X & Y 
int x, y;

void Botones()
{
  //boton abrir puerta
  for (x=0; x<1; x++)
  {//(margen izquierda)(margen derecha)(ancho)(alto)
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (35+(81*60), 10, 50+(x*60), 60);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (35+(81*60), 10, 50+(x*60), 60);
    myGLCD.print("Puerta Abrir", 67, 25);  
  }
  //boton cerrar puerta
  for (x=0; x<1; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (35+(81*60), 70, 50+(x*60), 120);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (35+(81*60), 70, 50+(x*60), 120);
    myGLCD.print("Puerta Cerrar", 65, 86);
  }
  //boton abrir garaje
  for (x=0; x<1; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (35+(81*60), 130, 50+(x*60), 180);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (35+(81*60), 130, 50+(x*60), 180);
    myGLCD.print("Garaje Abrir", 65, 149);
  }
  //boton cerrar garaje
  for (x=0; x<1; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (35+(81*60), 190, 50+(x*60), 240);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (35+(81*60), 190, 50+(x*60), 240);
    myGLCD.print("Garaje Cerrar", 65, 212);
  }
}


//funcion para el area tactil, se le pasa como parametro las coordenadas en las que va a recibir la informacion
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
    myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}



void setup()
{
//configuracion inicial
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);
  //configuracion de los pines de salida
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  Botones();  
 
  
}

void loop()
{  
   //Codigo para Pantalla
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      //boton abrir puerta principal
      if ((y>=10) && (y<=60))  
      {
        if ((x>=60) && (x<=261))  
        { 
          //(margen izquierda)(margen superior)(ancho)(alto)
          waitForIt(50, 10,  286, 300);
          digitalWrite(12,HIGH);
          delay(1570);
          digitalWrite(12,LOW);
        }
      }
       //boton cerrar puerta principal
      if ((y>=70) && (y<=120))  
      {
        if ((x>=60) && (x<=261))
        {
          waitForIt(50, 70, 286, 300);
          digitalWrite(13,HIGH);
          delay(1570);
          digitalWrite(13,LOW);
        } 
      }
      //boton abrir garaje
      if ((y>=130) && (y<=180)) 
      {
        if ((x>=60) && (x<=261))  
        {  waitForIt(50, 130, 286, 300);
           digitalWrite(10,HIGH);
           delay(2000);
           digitalWrite(10,LOW); 
        }
      }
      //boton cerrar garaje
      if ((y>=190) && (y<=240))  
      {
        if ((x>=60) && (x<=261)) 
        {  waitForIt(50, 190, 286, 300);
           digitalWrite(11,HIGH);
           delay(1650);
           digitalWrite(11,LOW); 
        }
      } 
    }
  }
}

