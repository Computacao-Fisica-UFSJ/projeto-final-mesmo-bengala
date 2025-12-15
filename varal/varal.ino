
#define PIN_SENSOR_CHUVA               A0
#define PIN_SENSOR_LUZ                 A1
#define PIN_SENSOR_VEL_VENTO           4 
#define PIN_FIM_DE_CURSO_RECOLHIDA     2
#define PIN_FIM_DE_CURSO_ESTENDIDA     3
#define PIN_MOTOR_PWM                  10
#define PIN_MOTOR_DIRECAO              8
#define PIN_MOTOR_VENTO_PWM            11
#define PIN_MOTOR_VENTO_DIRECAO        12
#define PIN_POTENCIOMETRO              A5

// --- DEFINE: PARÂMETROS ---
#define VELOCIDADE_MOTOR               255
#define LIMITE_SENSOR_CHUVA            900
#define LIMITE_LUZ_DIA                 100
#define PULSOS_VENTO_FORTE             30
#define INTERVALO_VENTO                10000UL
#define INTERVALO_LOOP                 30

// --- VARIÁVEIS GLOBAIS ---
unsigned long tempoUltimaVerificacaoVento = 0;
unsigned long tempoUltimoLoop = 0;

int contagemPulsosVento = 0;
bool estadoAnteriorSensorVento = LOW;
bool estaVentandoForte = false;

bool roupasEstendidas = true; 

int pwm_vento = 0;

void setup() {
  pinMode(PIN_SENSOR_CHUVA, INPUT);
  pinMode(PIN_SENSOR_LUZ, INPUT);
  pinMode(PIN_SENSOR_VEL_VENTO, INPUT);
  pinMode(PIN_FIM_DE_CURSO_RECOLHIDA, INPUT);
  pinMode(PIN_FIM_DE_CURSO_ESTENDIDA, INPUT);
  pinMode(PIN_POTENCIOMETRO, INPUT); 

  pinMode(PIN_MOTOR_PWM, OUTPUT);
  pinMode(PIN_MOTOR_DIRECAO, OUTPUT);
  pinMode(PIN_MOTOR_VENTO_PWM, OUTPUT);
  pinMode(PIN_MOTOR_VENTO_DIRECAO, OUTPUT);

  pararMotor();
  Serial.begin(9600);
  Serial.println("--- Sistema de Varal Iniciado ---");

}

void loop() {
  pwm_vento = analogRead(PIN_POTENCIOMETRO);
  pwm_vento = map(pwm_vento,0, 1023, 0, 255);

  digitalWrite(PIN_MOTOR_VENTO_DIRECAO, LOW);
  analogWrite(PIN_MOTOR_VENTO_PWM, pwm_vento);
  
  atualizarLeituraVento();
//
//  Serial.print("Esta ventando; ");
//  Serial.println(estaVentandoForte);

  if (millis() - tempoUltimoLoop >= INTERVALO_LOOP) {
    tempoUltimoLoop = millis();
    
    int riscoChuva = calcularRiscoChuva();
    processarDecisaoMovimento(riscoChuva);
  }
}

void processarDecisaoMovimento(int risco) {
  // Cenário 1: Risco ALTO (Recolher)
  if (risco >= 80) {
    if (roupasEstendidas) {
      Serial.println("ACAO: Risco Alto! Recolhendo roupas...");
      moverParaDentro();
    }
  }
  // Cenário 2: Risco BAIXO (Estender)
  else if (risco <= 40) {
    if (!roupasEstendidas) {
      Serial.println("ACAO: Tempo bom! Estendendo roupas...");
      moverParaFora();
    }
  }
  // Cenário 3: Risco MÉDIO (Manter como está)
  else {
    Serial.println("STATUS: Risco Médio. Aguardando...");
//    pararMotor();
  }

  if(detectouFimDeCursoEstendida() || detectouFimDeCursoRecolhida()) {
      if(detectouFimDeCursoRecolhida()){
        pararMotor();
        roupasEstendidas = false;
      } else {
        pararMotor();
        roupasEstendidas = true;
      }
    }
}

void moverParaFora() {
  if (detectouFimDeCursoEstendida()) {
    pararMotor();
    roupasEstendidas = true;
    Serial.println("STATUS: Roupas totalmente estendidas.");
  } else {
    Serial.println("Movendo para fora...");
    digitalWrite(PIN_MOTOR_DIRECAO, HIGH); 
    analogWrite(PIN_MOTOR_PWM, 0);
  }
}

void moverParaDentro() {
  if (detectouFimDeCursoRecolhida()) {
    pararMotor();
    roupasEstendidas = false;
    Serial.println("STATUS: Roupas recolhidas.");
  } else {
    Serial.println("Movendo para dentro...");
    digitalWrite(PIN_MOTOR_DIRECAO, LOW); 
    analogWrite(PIN_MOTOR_PWM, 255);
  }
}

void pararMotor() {
  Serial.println("Parando o motor...");
  digitalWrite(PIN_MOTOR_DIRECAO, LOW); 
  analogWrite(PIN_MOTOR_PWM, 0);
}

void atualizarLeituraVento() {
  int estadoAtual = digitalRead(PIN_SENSOR_VEL_VENTO);

  // Detecção de borda (apenas conta quando muda de LOW para HIGH)
  if (estadoAtual == LOW && estadoAnteriorSensorVento == HIGH) {
    contagemPulsosVento++;
  }
  estadoAnteriorSensorVento = estadoAtual;

  // Verifica intervalo de tempo
  if (millis() - tempoUltimaVerificacaoVento >= INTERVALO_VENTO) {
    estaVentandoForte = (contagemPulsosVento > PULSOS_VENTO_FORTE);
    Serial.print("Contagem de pulso: ");
    Serial.println(contagemPulsosVento);
    contagemPulsosVento = 0;
    tempoUltimaVerificacaoVento = millis();
  }
}

int calcularRiscoChuva() {
  int risco = 0;

  if (analogRead(PIN_SENSOR_CHUVA) < LIMITE_SENSOR_CHUVA) {
    risco += 100;
  }

  if (analogRead(PIN_SENSOR_LUZ) <= LIMITE_LUZ_DIA) {
    risco += 70;
  }

  if (estaVentandoForte) {
    risco += 10;
  }

  return risco;
}

bool detectouFimDeCursoRecolhida() {
  return digitalRead(PIN_FIM_DE_CURSO_RECOLHIDA) == LOW;
}

bool detectouFimDeCursoEstendida() {
  return digitalRead(PIN_FIM_DE_CURSO_ESTENDIDA) == LOW;
}
