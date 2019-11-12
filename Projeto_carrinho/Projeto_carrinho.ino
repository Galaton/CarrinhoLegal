#include <Ultrasonic.h>


// definindo pinos sensor
#define esquerda_trigger 4
#define esquerda_echo 3
#define direita_trigger 12
#define direita_echo 11
#define frente_trigger 8
#define frente_echo 7

// Define os pinos de utilização do Driver L298.
#define motorA1 5    // Pin  5 of L293.
#define motorA2 6    // Pin  6 of L293.
#define motorB1 10  // Pin 10 of L293.
#define motorB2 9   // Pin 9 of L293.

// inicializando o sensor
Ultrasonic esquerda(esquerda_trigger,esquerda_echo);
Ultrasonic direita(direita_trigger,direita_echo);
Ultrasonic frente(frente_trigger,frente_echo);

void vira_direita(){
  int velocidade = 200;
  
  analogWrite(motorB1, velocidade);
  analogWrite(motorA1, velocidade);
  analogWrite(motorA2, 0);
  analogWrite(motorB2, 0);
  delay(300);
  
}
void vira_esquerda(){
  int velocidade = 200;
  
  analogWrite(motorA1, 0);
  analogWrite(motorB1, 0);
  analogWrite(motorB2, velocidade);
  analogWrite(motorA2, velocidade);
  delay(300);
}
void move_re(){
  int velocidade = 200;
  
  analogWrite(motorA1, 0);
  analogWrite(motorA2, velocidade);
  analogWrite(motorB1, velocidade);
  analogWrite(motorB2, 0);
  delay(300);
}
void move_frente(){
    int velocidade = 200;
    
    analogWrite(motorA1, velocidade);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, velocidade);
    delay(100);
}

void setup() {
  Serial.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}

void loop() {
  float dEsq,dDir,dFrent;
  long dist1,dist2,dist3;
  dEsq = esquerda.convert(esquerda.timing(),Ultrasonic::CM);
  dDir = direita.convert(direita.timing(),Ultrasonic::CM);
  dFrent = frente.convert(frente.timing(),Ultrasonic::CM);

  // validacao sensor
  //Serial.println(dEsq);
  //Serial.println(dDir);
  //Serial.println(dFrent);

  // validacao motor
  //move_frente();
   //move_re();
  //vira_esquerda();
  //vira_direita();
  
  // Controle

  
  if(dFrent > 15){
    Serial.print("frente");
    move_frente();
  }else{
    if(dDir > dEsq){
      Serial.print("direita");
      move_re();
      vira_direita();
      vira_direita();
      vira_direita();
      
    }else{
      Serial.print("esquerda");
      move_re();
      vira_esquerda();
      vira_esquerda();
      vira_esquerda();
      
    }
  }
  
  
}
