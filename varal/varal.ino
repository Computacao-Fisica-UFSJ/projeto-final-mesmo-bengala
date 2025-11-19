#define pinRainSensor A0
#define pinEnginePWM 10
#define pinEngineDirection 8
#define pinLDRSensor A1
#define pintReedSensor 2
#define pinSpeedSensor 4

int speedEngine = 127;
int contagem = 0;


void setup(){ 
  pinMode(pinEnginePWM, OUTPUT);
  pinMode(pinEngineDirection, OUTPUT);
  pinMode(pinLDRSensor, INPUT);
  pinMode(pintReedSensor, INPUT);
  pinMode(pinSpeedSensor, INPUT);
  pinMode(pinRainSensor, INPUT);

  Serial.begin(9600);
}

void loop(){

}

void MotorSentidoHorario(){
  digitalWrite(pinEngineDirection, HIGH);
  analogWrite(pinEnginePWM, speedEngine);
}

void MotorSentidoAntiHorario(){
  digitalWrite(pinEngineDirection, LOW);
  analogWrite(pinEnginePWM, speedEngine);
}

void StopEngine(){
  speedEngine = 0;
  analogWrite(pinEnginePWM, speedEngine);
}

bool DetectedWindy(){
  int speedSensorDetected=digitalRead(pinSpeedSensor);
  
  if(speedSensorDetected == 1){
    contagem++;
    Serial.print("Numero de detecções: ");
    Serial.println(contagem);
    delay(500);
  }
}

bool DetectedRaining(){
  int rainSensorValue = analogRead(pinRainSensor);
  if(rainSensorValue < 900){
    return true;
  } else {
    return false;
  }
}

bool DetectedSunny(){
  int ldrSensorValue=analogRead(pinLDRSensor);
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(ldrSensorValue);

  if(ldrSensorValue > 100){
    return true;
  } else {
    return false;
  }
}

bool DetectedEndCourse(){
  bool isEndCourse=digitalRead(pintReedSensor);
  Serial.print("Valor reed = ");
  Serial.println(isEndCourse);

  if(isEndCourse){
    return true;
  } else {
    return false;
  }
}
