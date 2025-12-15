# Varal automático

## Changelogs
- 18/11 - Controlamos a velocidade do motor, aprendemos a interpretar o valor analógico do sensor de chuva, adicionamos o sensor ldr e mudamos o circuito para uma protoboard maior.
- 19/11 - Conectamos sensor de velocidade, começamos a organizar o código em funções separadas para cada tipo de detecção dos sensores.
- 25/11 - Alteramos a função para detectar se o vento está forte em um determinado intervalo, adicionamos uma função para verificar a velocidade do vento e calculamos o risco chuva.
- 26/11 - Perdemos nosso Reed Switch, arrumamos lógica do motor, começamos a pensar na "maquete".
- 09/12 - Realizamos várias mudanças no código para que a detecção de chuva funcione corretamente e adicionamos a chave de fim de curso ao circuito.
- 10/12 - Começamos a fazer a "maquete"
- 11/12 - Arrumamos lógica de parar o motor, descartamos o catavento, colamos as peças na "maquete"

## Contextualização

Soluções inteligentes vêm sendo aplicadas com frequência no dia a dia das pessoas com o objetivo de facilitar tarefas rotineiras. Atividades como estender e recolher as roupas do varal exigem a observação constante das condições climáticas, como chuva, luminosidade e vento, o que pode gerar transtornos quando ocorrem mudanças inesperadas no tempo.

Nesse contexto, neste projeto foi desenvolvido um **Varal Automático** como uma alternativa para automatizar o processo de estender e recolher as roupas, minimizando os riscos de exposição à chuva e a condições climáticas desfavoráveis. O sistema utiliza diferentes sensores para monitorar fatores como presença de chuva, nível de luminosidade e intensidade do vento, tomando decisões automáticas de movimentação do varal de acordo com o risco identificado. Para a movimentação da estrutura, é empregado um motor controlado por um microcontrolador **Arduino Uno**, integrando sensores e atuadores em um sistema automatizado.

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


## Explicação textual do diagrama



## Foto do projeto montado


## Link para o vídeo do projeto em funcionamento


## Problemas encontrados no processo de montagem

Em relação aos problemas encontrados no processo de montagem, durante o desenvolvimento deste projeto, enfrentamos algumas dificuldades que influenciaram no processo de montagem e no funcionamento do Varal Inteligente:

- **Estrutura do projeto**: tivemos problemas para pensar em uma estrutra que fosse mais adequado para o contexto do projeto, de modo que os sensores funcionassem corretamente e o elástico gerasse uma tensão adequado ao motor;
  
- **Motor para movimentar o varal**: testando sem a utilização do elástico, o motor funcionado perfeitamente; entretanto, ao utilizar o elástico responsável por simular a tensão do varal, a força exercida foi muito alta. Com isso, o motor não conseguiu movimentar a estrutura adequadamente, ficando incostado na caixa do protótipo;

- **Parar o motor**: também tivemos um problema para parar o motor em uma das direções, uma vez que identificamos tardiamente que em uma das direções o valor da velocidade deveria ser 0 para parar o motor e na outra 255 (e não 0 também como achávamos);

- **Ativar as chaves de fim de curso**: devido à estrutura mecânica do projeto, não foi possível implementar um mecanismo eficiente para que as chaves fossem acionados automaticamente durante o movimento do varal, sendo necessário acioná-las manualmente durante os testes;

- **Contagem dos pulsos**: inicialmente, a solução utilizada seria um cata-vento acoplado no sensor de velocidade para contagem dos pulsos e medição da velocidade do vento. Porém, o cata-vento o cata-vento colidia com a caixa do protótipo e também não foi possível encontrar um ponto adequado para sua fixação. Dessa forma, a alternativa adotada foi a utilização de um **disco acoplado a um motor DC**, o qual era posicionado manualmente no sensor para simular a contagem dos pulsos. 


## Referencias
- [Motor](https://www.blogdarobotica.com/2022/10/10/como-controlar-um-motor-dc-usando-o-mini-driver-ponte-h-l9110s/)
- [Sensor de chuva](https://www.blogdarobotica.com/2024/02/23/como-utilizar-o-sensor-de-chuva-com-arduino/)
- [Sensor de luminosidade](https://www.blogdarobotica.com/2020/09/29/utilizando-o-sensor-de-luminosidade-ldr-no-arduino/)
- [Sensor de velocidade](https://www.blogdarobotica.com/2024/03/27/como-utilizar-o-sensor-de-velocidade-encoder-com-o-arduino/)
