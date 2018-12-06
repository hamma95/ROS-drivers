#define motorA1 6    // Marche avant du premier moteur
#define motorA2 10   // Marche arrière du premier moteur
#define motorB1 3   // Marche avant du deuxième moteur
#define motorB2 9     // Marche arrièredu deuxième moteur


//Bluetooth (HC-06 JY-MCU) State pin on pin 2 of Arduino


//Useful Variables

int vSpeed = 120;   // Default speed, from 0 to 255
int vSpeed2 = 130;


void setup() {

  // Set pins as outputs:
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  //Stop car when connection lost or bluetooth disconnected
 

  /***********************Forward****************************/
  //If state is equal with letter 'F', car will go forward!
  if (state == 'F') {
    analogWrite(motorA1, vSpeed); analogWrite(motorA2,0);
    analogWrite(motorB1, vSpeed2);      analogWrite(motorB2, 0);
  }
  /***************************Left*****************************/
  //If state is equal with letter 'L', wheels will turn left
  else if (state == 'R') {
    analogWrite(motorA1, vSpeed2);         analogWrite(motorA2,0);
    analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed2);
  }
  /***************************Right*****************************/
  //If state is equal with letter 'R', wheels will turn right
  else if (state == 'L') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed2);
    analogWrite(motorB1, vSpeed2);   analogWrite(motorB2, 0);
  }
  /************************Stop*****************************/
  //If state is equal with letter 'S', stop the car
  else if (state == 'S') {
    analogWrite(motorA1, 0);  analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);  analogWrite(motorB2, 0);




  }
}

