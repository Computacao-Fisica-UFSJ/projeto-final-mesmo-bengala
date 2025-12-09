#define pinRainSensor A0
#define pinEnginePWM 10
#define pinEngineDirection 8
#define pinLDRSensor A1
#define pinEndCourse 2
#define pinSpeedSensor 4

unsigned long lastWindOccurrence = 0;
unsigned long windInterval = 10000UL;
int speedEngine = 127;
int windCount = 0;
bool isWindy = false;

bool clothesOut = false;


void setup(){ 
  pinMode(pinEnginePWM, OUTPUT);
  pinMode(pinEngineDirection, OUTPUT);
  pinMode(pinLDRSensor, INPUT);
  pinMode(pinEndCourse, INPUT);
  pinMode(pinSpeedSensor, INPUT);
  pinMode(pinRainSensor, INPUT);

  if(!DetectedRaining()) {
    clothesOut = true;
  }

  Serial.begin(9600);
}

void loop(){
  DetectWindSpeed();

  int rainRisk = DetermineRainRisk();

  // Risco alto de chuva:
  if(rainRisk >= 100) {
    Serial.println("Risco Alto de chuva!");

    // Verifica se as roupas estão do lado de fora do varal:
    if(clothesOut) {
      Serial.println("Recolhendo as roupas...");

      if(!DetectedEndCourse()) {
        MotorSentidoAntiHorario();
      }
    
      if(DetectedEndCourse()) {
        StopEngine();
        clothesOut = false;
        Serial.println("Roupas recolhidas! Motor Parado.");
      }
    }

    else {
      StopEngine();
    }
  }

  // Risco baixo de chuva:
  else if(rainRisk <= 40) {
    Serial.println("Risco Baixo de chuva!");

    // Verifica se as roupas estão do lado de fora do varal:
    if(!clothesOut) {
      Serial.println("Estendendo as roupas...");

      if(!DetectedEndCourse()) {
        MotorSentidoHorario();
      }

      if(DetectedEndCourse()) {
        StopEngine();
        clothesOut = true;
        Serial.println("Roupas estendidas. Motor Parado.");
      }
    }

    else {
      StopEngine();
    }
  }

  // Risco médio de chuva:
  else {
    Serial.println("Risco Médio de chuva!");
    StopEngine();
  }

  delay(30);
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
  analogWrite(pinEnginePWM, 0);
}

void DetectWindSpeed() {
  int speedSensorDetected = digitalRead(pinSpeedSensor);
  
  if (speedSensorDetected == HIGH) {
    windCount++;
  }
}

bool DetectedWindy(){
  if(millis() - lastWindOccurrence >= windInterval) {
    lastWindOccurrence = millis();

    Serial.print("Pulsos de vento em 10s: ");
    Serial.println(windCount);
    
     // Verifica se há uma ocorráncia de vento forte:
     if(windCount > 5) {
       isWindy = true;
     }

     else {
      isWindy = false;
     }

     windCount = 0;
  }
  
  return isWindy;
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
  bool isEndCourse=digitalRead(pinEndCourse);
  Serial.print("Valor chave fim de curso = ");
  Serial.println(isEndCourse);

  if(isEndCourse == LOW){
    return true;
  } else {
    return false;
  }
}.


int DetermineRainRisk() {
  short rainRisk = 0;

  // Se o sensor de chuva detectou a ocorrência de chuva, o risco é máximo:
  if(DetectedRaining()) {
    rainRisk += 100;  

  }
  // Se o céu está nublado ou escuro, o risco é médio:
  if(!DetectedSunny()) {
    rainRisk += 40;
  }

  // Se há ventos fortes, o risco é baixo:
  if(DetectedWindy()) {
    rainRisk += 10;
  }

  Serial.print("Risco de chuva: ");
  Serial.println(rainRisk);

  return rainRisk;
}
