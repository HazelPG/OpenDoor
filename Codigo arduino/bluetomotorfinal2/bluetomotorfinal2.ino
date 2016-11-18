
void setup(){
   Serial1.begin(9600);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(11,OUTPUT);
  
}
 
void loop(){

 
  while (Serial1.available()>0)//Declaramos un sentencia, Mientras el puerto Serial este disponible se empieza el ciclo 
  { 
    char dato= Serial1.read(); //Declaramos una variable de tipo carácter y Seo lee la variale enviada desde el Bluetooth.
   
    switch(dato)
    {
    case 'a': //Si en el caso de ser A la varible enviada, entonces:
      {
        digitalWrite(13,HIGH);//La señal será alta, encenderá el LED.
        digitalWrite(12,LOW);//La señal será alta, encenderá el LED.
        delay(1650);
        digitalWrite(13,LOW);//La señal será alta, encenderá el LED.
        break;
        
        
      }
        
    case 'b': //Si en el caso de ser A la variable enviada, entonceS:
      { digitalWrite(12,HIGH);//La señal será alta, encenderá el LED.
        digitalWrite(13,LOW);//La señal será alta, encenderá el LED.
        delay(1600);
        digitalWrite(12,LOW);//La señal será alta, encenderá el LED.
        break;
      }

     case 'c': //Si en el caso de ser A la varible enviada, entonces:
      {
        digitalWrite(11,HIGH);//La señal será alta, encenderá el LED.
        digitalWrite(10,LOW);//La señal será alta, encenderá el LED.
        delay(1650);
        digitalWrite(11,LOW);//La señal será alta, encenderá el LED.
        break;   
      }

   case 'd': 
      {
        digitalWrite(10,HIGH);//La señal será alta, encenderá el motor
        digitalWrite(11,LOW);//La señal será baja y apagara el motor
        delay(1650);
        digitalWrite(10,LOW);//La señal será baja y apagara el motor
        break;   
      }    
    }    
  }
}   
  

