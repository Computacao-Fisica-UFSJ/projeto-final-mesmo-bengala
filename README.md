# Varal automático

## Changelogs
- 18/11 - Controlamos a velocidade do motor, aprendemos a interpretar o valor analógico do sensor de chuva, adicionamos o sensor ldr e mudamos o circuito para uma protoboard maior.
- 19/11 - Conectamos sensor de velocidade, começamos a organizar o código em funções separadas para cada tipo de detecção dos sensores.
- 25/11 - Alteramos a função para detectar se o vento está forte em um determinado intervalo, adicionamos uma função para verificar a velocidade do vento e calculamos o risco chuva.
- 26/11 - Perdemos nosso Reed Switch, arrumamos lógica do motor, começamos a pensar na "maquete".
- 09/12 - Realizamos várias mudanças no código para que a detecção de chuva funcione corretamente e adicionamos a chave de fim de curso ao circuito.
- 10/12 - Começamos a fazer a "maquete"
- 11/12 - Arrumamos lógica de parar o motor, descartamos o catavento, colamos as peças na "maquete"
- 15/12 - Finalização do projeto e apresentação

## Contextualização

Soluções inteligentes vêm sendo aplicadas com frequência no dia a dia das pessoas com o objetivo de facilitar tarefas rotineiras. Atividades como estender e recolher as roupas do varal exigem a observação constante das condições climáticas, como chuva, luminosidade e vento, o que pode gerar transtornos quando ocorrem mudanças inesperadas no tempo.

Nesse contexto, neste projeto foi desenvolvido um **Varal Automático** como uma alternativa para automatizar o processo de estender e recolher as roupas, minimizando os riscos de exposição à chuva e a condições climáticas desfavoráveis. O sistema utiliza diferentes sensores para monitorar fatores como presença de chuva, nível de luminosidade e intensidade do vento, tomando decisões automáticas de movimentação do varal de acordo com o risco identificado. Para a movimentação da estrutura, é empregado um motor controlado por um microcontrolador **Arduino Uno**, integrando sensores e atuadores em um sistema automatizado.

## Funcionamento

O **Varal Automático** automatiza o processo de estender e recolher as roupas, monitorando constantemente as condições do ambiente utilizando alguns sensores. Com as informações recebidas pelos sensores, o sistema é capaz de decidir qual ação será realizada, evitando que as roupas fiquem expostas à chuva ou fiquem recolhidas caso o clima esteja favorável, por exemplo.

### Sensores

O projeto possui três sensores principais:

- **Sensor de chuva**: detecta a presença de água, isto é, quando há uma umidade acima de um certo limite, o sistema entende que há risco de chuva alto;
- **Sensor de luminosidade (LDR)**: mede a quantidade de luz no ambiente, ou seja, valores muito baixos indicam noite ou tempo nublado;
- **Sensor de velocidade**: mede a velocidade do vento por meio da contagem de pulsos em um disco. Desse modo, caso o valor seja alto em um certo intervalo de tempo, o sistema considera que o vento está forte.

Além disso, no projeto também há duas chaves de fim de curso indicando quando o varal está **totalmente estendido** ou **totalmente recolhido**. Essas chaves são fundamentais para garantir que o motor irá parar em algum momento.

### Determinação do risco de chuva

De acordo com os valores dos sensores, o sistema realiza um cálculo do **risco de chuva** que é definido da seguinte forma:

- **Risco Alto**: se há presença de chuva (+100) ou se há baixa luminosidade (+70) e vento forte (+10);
- **Risco Baixo**: se está apenas ventando forte (+10);
- **Risco Médio**: se há somente baixa luminosidade (+70).

A soma dos valores lidos serve para orientar a decisão do sistema.

### Decisão

Com isso, após calcular o risco de chuva, o varal pode se comportar de diferentes formas:

- **Risco Alto**: as roupas são automaticamente recolhidas se estiverem estendidas;
- **Risco Baixo**: se as roupas estão recolhidas, elas serão estendidas;
- **Risco Médio**: nenhuma ação é realizada.

### Utilização

O teste do projeto é simples, rápido e não exige conhecimentos técnicos:

1. Conecte o Arduino Uno à porta USB do computador;
2. Energize o circuito conectando a bateria de alimentação na *protoboard*;
3. Verifique se todos os sensores estão corretamente posicionados: sensor de chuva e de luminosidade expostos ao ambiente e o sensor de velocidade na *protoboard*;
4. Ajuste o potenciômetro para controlar a velocidade do motor que possui o disco acoplado para controlar a velocidade do vento;
5. A partir disso, o sistema passa a funcionar corretamente e o usuário pode realizar os testes para cada caso.

**Obs**: devido às limitações mecânicas da estrutura, as chaves de fim de curso precisam ser acionadas manualmente para que o motor possa parar corretamente.

## Lista de materiais

A seguir, estão listados todos os materiais utilizados na montagem do projeto:

| Material  | Objetivo |
| ------------- |:-------------:|
| Arduino Uno      | Processar as informações do sensor e emitir o alerta sonoro     |
| Módulo Sensor de Chuva (Código: E13-001)      | Detectar a presença de água, permitindo identificar situações de chuva     |
| Módulo Sensor de Velocidade / *Encoder* (Código: B22-004)      | Medir a velocidade do vento por meio da contagem de pulsos gerados pelo sensor      |
| Bateria de 9V              | Fonte de alimentação para o circuito               |
| *Plug* P4 para Bateria de 9V              | Conectar o Arduino e a Bateria de 9V                |
| Fios de conexão               | Interligar os componentes do arduino               |
| Módulo Sensor de Luminosidade LDR – 4 Pinos (Código: G39-003)               | Medir o nível de luminosidade, permitindo diferenciar entre dia e noite               |
| Módulo Ponte H Dupla HG7881 (L9110S) (Código: B8-005)              | Controlar o sentido de rotação e a velocidade dos motores               |
| *Protoboard*               | Montar e conectar os componentes eletrônicos               |
| Kit Motor DC 3-6V + Roda               | Movimentar o varal, permitindo recolher e estender as roupas               |
| Kit Motor DC 3-6V               | Responsável por movimentar o disco utilizado para contar os pulsos gerados pelo sensor de velocidade               |
| Potenciômetro                 | Controlar a velocidade do motor que simula o vento       |
| Módulo Chave Fim de Curso (2 unidades)               | Detectar os limites físicos de movimentação do varal (totalmente estendido ou recolhido)      |
| Elástico | Utilizado para simular a corda do varal                        |
| Caixa de papelão              | Montar a estrutura do varal               |

- [Módulo Sensor de Chuva](https://www.eletrogate.com/modulo-sensor-de-chuva)
- [Módulo Interruptor Magnético Reed Switch - KY-025](https://www.eletrogate.com/modulo-interruptor-magnetico-reed-switch)
- [Módulo Sensor de Velocidade Encoder](https://www.eletrogate.com/sensor-de-velocidade-encoder?gad_campaignid=20223015315)
- [Módulo Sensor de Luminosidade Luz LDR - 4 Pinos](https://www.eletrogate.com/modulo-sensor-de-luminosidade-luz-ldr-4-pinos?gad_campaignid=20223015315)
- [Mini Motor DC 1.5V](https://www.eletrogate.com/mini-motor-dc-15v)
- [Módulo Ponte H Dupla HG7881 (L9110S)](https://www.eletrogate.com/modulo-ponte-h-dupla-hg7881-l9110)

## Diagrama da montagem
![diagrama](https://github.com/user-attachments/assets/113df968-485f-4d3a-86e0-ad0e9e830497)


## Explicação textual do diagrama
O diagrama é composto por um Arduino que gerencia a lógica e os sensores enquanto uma bateria de 9V fornece a energia para uma Ponte H acionar os motores. O sistema controla dois motores DC com funções distintas, sendo que o motor principal é responsável pelo mecanismo de estender e recolher o varal e é acionado com base nos dados do sensor de chuva, do LDR e da intensidade do vento monitorada através de um sensor de velocidade acoplado ao segundo motor. O movimento desse motor principal é limitado fisicamente por dois botões de fim de curso, enquanto o segundo motor atua exclusivamente simulando o vento sobre a roupa com sua rotação ajustada manualmente por um potenciômetro.


## Foto do projeto montado
<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/888faff2-c6e0-4203-83e6-6803b6a8b418" />


## Link para o vídeo do projeto em funcionamento
[Drive](https://drive.google.com/file/d/1X3wDZVni7so4rn0NJkup3wqUERlA63Jf/view?usp=sharing)

## Problemas encontrados no processo de montagem

Em relação aos problemas encontrados no processo de montagem, durante o desenvolvimento deste projeto, enfrentamos algumas dificuldades que influenciaram no processo de montagem e no funcionamento do Varal Inteligente:

- **Estrutura do projeto**: tivemos problemas para pensar em uma estrutura que fosse mais adequada para o contexto do projeto, de modo que os sensores funcionassem corretamente e o elástico gerasse uma tensão adequada ao motor;
  
- **Motor para movimentar o varal**: testando sem a utilização do elástico, o motor funcionou perfeitamente; entretanto, ao utilizar o elástico responsável por simular a tensão do varal, a força exercida foi muito alta. Com isso, o motor não conseguiu movimentar a estrutura adequadamente, ficando encostado na caixa do protótipo;

- **Parar o motor**: também tivemos um problema para parar o motor em uma das direções, uma vez que identificamos tardiamente que em uma das direções o valor da velocidade deveria ser 0 para parar o motor e na outra 255 (e não 0 também como achávamos);

- **Ativar as chaves de fim de curso**: devido à estrutura mecânica do projeto, não foi possível implementar um mecanismo eficiente para que as chaves fossem acionadas automaticamente durante o movimento do varal, sendo necessário acioná-las manualmente durante os testes;

- **Contagem dos pulsos**: inicialmente, a solução utilizada seria um cata-vento acoplado no sensor de velocidade para contagem dos pulsos e medição da velocidade do vento. Porém, o cata-vento colidia com a caixa do protótipo e também não foi possível encontrar um ponto adequado para sua fixação. Dessa forma, a alternativa adotada foi a utilização de um **disco acoplado a um motor DC**, o qual era posicionado manualmente no sensor para simular a contagem dos pulsos. 


## Referencias
- [Motor](https://www.blogdarobotica.com/2022/10/10/como-controlar-um-motor-dc-usando-o-mini-driver-ponte-h-l9110s/)
- [Sensor de chuva](https://www.blogdarobotica.com/2024/02/23/como-utilizar-o-sensor-de-chuva-com-arduino/)
- [Sensor de luminosidade](https://www.blogdarobotica.com/2020/09/29/utilizando-o-sensor-de-luminosidade-ldr-no-arduino/)
- [Sensor de velocidade](https://www.blogdarobotica.com/2024/03/27/como-utilizar-o-sensor-de-velocidade-encoder-com-o-arduino/)
