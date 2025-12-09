# Varal automático
O projeto consiste em um varal que irá recolher as roupas de maneira automática de acordo com o ambiente.

## Lista de máteriais
- [Módulo Sensor de Chuva](https://www.eletrogate.com/modulo-sensor-de-chuva)
- [Módulo Interruptor Magnético Reed Switch - KY-025](https://www.eletrogate.com/modulo-interruptor-magnetico-reed-switch)
- [Módulo Sensor de Velocidade Encoder](https://www.eletrogate.com/sensor-de-velocidade-encoder?gad_campaignid=20223015315)
- [Módulo Sensor de Luminosidade Luz LDR - 4 Pinos](https://www.eletrogate.com/modulo-sensor-de-luminosidade-luz-ldr-4-pinos?gad_campaignid=20223015315)
- [Mini Motor DC 1.5V](https://www.eletrogate.com/mini-motor-dc-15v)
- [Módulo Ponte H Dupla HG7881 (L9110S)](https://www.eletrogate.com/modulo-ponte-h-dupla-hg7881-l9110)



## Changelogs
- 18/11 - Controlamos a velocidade do motor, aprendemos a interpretar o valor analógico do sensor de chuva, adicionamos o sensor ldr e mudamos o circuito para uma protoboard maior.
- 19/11 - Conectamos sensor de velocidade, começamos a organizar o código em funções separadas para cada tipo de detecção dos sensores.
- 25/11 - Alteramos a função para detectar se o vento está forte em um determinado intervalo, adicionamos uma função para verificar a velocidade do vento e calculamos o risco chuva.
- 26/11 - Perdemos nosso Reed Switch, arrumamos lógica do motor, começamos a pensar na "maquete".
- 09/12 - Realizamos várias mudanças no código para que a detecção de chuva funcione corretamente e adicionamos a chave de fim de curso ao circuito.


# Referencias
- [Motor](https://www.blogdarobotica.com/2022/10/10/como-controlar-um-motor-dc-usando-o-mini-driver-ponte-h-l9110s/)
- [Sensor de chuva](https://www.blogdarobotica.com/2024/02/23/como-utilizar-o-sensor-de-chuva-com-arduino/)
- [Sensor de luminosidade](https://www.blogdarobotica.com/2020/09/29/utilizando-o-sensor-de-luminosidade-ldr-no-arduino/)
- [Sensor de velocidade](https://www.blogdarobotica.com/2024/03/27/como-utilizar-o-sensor-de-velocidade-encoder-com-o-arduino/)
