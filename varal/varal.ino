#define leituraAnalogica A0 //Atribui o pino A0 a variável velocidade_motor
#define motorB_PWM 10 //Controle de velocidade do motor A
#define motorB_EN 8 //Controle de direção do motor A
#define ldrLeitura A1 //Atribui o pino A1 a variável ldrLeitura

int velocidade = 127; //variável para controle de velocidade de rotação dos motores,sendo 0 o valor de velocidade mínimo e 255 o valor de velocidade máxima.
int ldrValor = 0; // variavel ldr valor

void setup(){ 
  //Configura os motores como saída
  pinMode(motorB_PWM, OUTPUT);
  pinMode(motorB_EN, OUTPUT);
  pinMode(ldrLeitura, INPUT);

  //Configura o sensor de chuva
  Serial.begin(9600); //Incia a comunicação serial
  pinMode(leituraAnalogica, INPUT); //Define leituraAnalogica como entrada
}

void loop(){
    ldrValor=analogRead(ldrLeitura);//Lê o valor do sensor ldr e armazena na variável valorldr
    Serial.print("Valor lido pelo LDR = ");//Imprime na serial a mensagem Valor lido pelo LDR
    Serial.println(ldrValor);//Imprime na serial os dados de valorldr
    ParaMotor();
    MotorSentidoHorario(); //Chama a função para rotação do motor no sentido horário
//    delay(5000); //Aguarda 5000 milissegundos
//    MotorSentidoAntiHorario(); //Chama a função para rotação do motor no sentido anti-horário
//    delay(5000); //Aguarda 5000 milissegundos
}

void MotorSentidoHorario(){
  ParaMotor();
  digitalWrite(motorB_EN, HIGH); //Motor A. HIGH = HORARIO
  analogWrite(motorB_PWM, velocidade); //PWM do motor 
}

void MotorSentidoAntiHorario(){
  ParaMotor();
  digitalWrite(motorB_EN, LOW); //Motor A. LOW = ANTI-HORÁRIO
  analogWrite(motorB_PWM, velocidade); //PWM do motor 
}

void ParaMotor(){
  int valorAnalogico = analogRead(leituraAnalogica); //Realiza a leitura analógica do sensor e armazena em valorAnalogico
  //Serial.println(valorAnalogico);
  if(valorAnalogico < 900){
//    Serial.println("Status: Chuva detectada");
    velocidade = 0;
  } else {
//    Serial.println("Status: Chuva não detectada");
  }
}
