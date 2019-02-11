# Galagduino
Pseudo-replica-prototipo en Arduino del clasico juego Galaga.

## Requerimientos.

* Cable componente de Rca
* Resistencia 1kOhms
* Resistencia 480Ohms
* Puedes usar un joystick en lugar de un teclado solo debes asiga el debido mapeo en el método:

```cpp
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
```

## Diagrama.
![Diagrama de conexiones](http://farm5.static.flickr.com/4087/5225072558_5f5f760037.jpg)


## Documentación.
Todo este prototipo fue hecho gracias a la libreria que se puede encontrar en:

https://github.com/pkendall64/arduino-tvout 

Y la documentación de funciones:

https://code.google.com/archive/p/arduino-tvout/wikis

###### Shoutouts al profe Toñito por dejarnos esta práctica para la materia de Sistemas Embebidos ll <3
