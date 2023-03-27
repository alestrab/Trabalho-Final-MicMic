# Trabalho-Final-MicMic
Trabalho 7 da Disciplina de Microntroladores e Microprocessadores, Período 2022/2 - Engenharia Física - UFSCar;\
Grupo D, Professor da Disciplina: Dr. Ricardo Menotti

Integrantes|RA
------|:----:
Alexandre Strabello|770076
Gabriel Lemes Molizane Almeida|770097
Sarah Brennda Bispo Almeida|770161

## Objetivos Gerais:
Girassol - Desenvolver um sistema para maximizar a intensidade luminosa em uma placa solar através da movimentação da mesma em dois eixos. 

### Objetivos Específicos:
Construir um suporte com um grau de liberdade em modelo 3D, com fácil adição de um segundo eixo de rotação;\
Desenvolvimento de um código para microcontrolador controlando dois servomotores em função da tensão de saída da placa solar;
 
## Materiais:

2 servomotores SG92R para controle dos eixos de rotação da placa solar; (por questão de disponibilidade foi utilizado um servomotor MG90S)

Mini Placa Solar ZW 110X69, tensão de operação 5 V, 1W;

Impressora 3D disponível no Espaço Maker do DC UFSCar;

Como microcontrolador foi utilizado um [Franzino](https://embarcados.com.br/franzino-open-hardware-de-baixo-custo/). O funcionamento do mesmo é o mesmo que um Arduino UNO, apenas necessita de uma placa externa para comunicação serial e não possui pinos de saída 3.3V.

## Plano de Trabalho

O projeto será separado com base nas quatro semanas disponíveis para sua realização;

### Primeira Semana:
Análise de viabilidade, quais componentes serão necessários, especificações sobre suas dimensões, assim como qual microcontrolador será utilizado;\
Também será construído uma primeira versão para controle de rotação em um único eixo em modelo 3D, onde será estudada a possibilidade de construção do mesmo em impressora 3D no laboratório maker do DC UFSCar;

### Segunda Semana:
Aperfeiçoamento do modelo e agendamento para impressão; \
Construção da segunda parte do modelo para controle no segundo eixo;\
Início do desenvolvimento do código para controle dos servomotores;

### Terceira Semana:
Impressão da segunda parte do suporte;\
Instalação e montagem do sistema da placa solar com os servomotores e demais componentes;\
Testes do código para controle e correções de bugs;

### Quarta Semana:
Correções de problemas;\
Elaboração de vídeo ou apresentação para a entrega final do projeto;

## Metodologia

Enquanto parte dos integrantes focam no desenvolvimento do suporte para fixação da placa e instalação dos servomotores, os outros membros serão responsáveis pela implementação do código para controle da rotação.

A inclinação da placa pode ser alterada em 45° para os dois lados, tal que será feito uma rotina para variar de 5° em 5° a inclinação enquanto faz a leitura da tensão na placa e verifica se houve redução ou não da mesma. Quando o movimento reduzir a intensidade luminosa, o mesmo irá parar de se movimentar nessa direção.

Em seguida, irá iniciar o movimento no segundo eixo, que pode rotacionar a placa em 360°, seguindo mesmo critério, movimentação em passo constante até identificar o pico de intensidade luminosa na placa.

## Realização do Plano de Trabalho

### Construção do modelo 3D

![Alt text](https://github.com/alestrab/Trabalho-Final-MicMic/blob/main/Imagens/Materiais/modelinho.png)

Utilizou-se o software Sketchup para construção dos suportes e sistemas para rotação da placa solar. O modelamento das engrenagens foi feito com base em objetos já existentes em um banco de projetos do aplicativo, enquanto o suporte foi pensado de acordo com alguns diagramas construidos inicialmente em papel. No total temos três grandes áreas, que seriam o controle de inclinação (em vermelho), o suporte para fixação da placa (em azul), além do suporte para o eixo de rotação (em amarelo).

Tanto o controle de inclinação quanto o suporte de fixação foram impressos em um laboratório do departamento de Física da universidade, contudo, por ordens dos responsáveis do local, não foi possível realizar a impressão do último componente. Verificou-se também que o eixo de rotação não poderia ser implementado utilizando um servomotor, tal como fora planejado.

O servomotor comprado apresenta limitação de rotação, podendo realizar no máximo um giro de 180°. Quando comparado com as engrenagens colocadas, a rotação máxima seria de 45°, muito inferior ao planejado de 360º. Como esse problema só foi identificado durante a implementação do controle de inclinação, não houve tempo para alteração do modelo, de modo que foi deixado de lado o controle de rotação.


### Montagem do aparato

![Alt text](https://github.com/alestrab/Trabalho-Final-MicMic/blob/main/Imagens/Circuitos/circuito.png)

Os códigos escritos para o funcionamento do sistema necessitam que o cabo de sinal do servmotor esteja contectado no pino D10 do Franzino, enquanto o painel solar precisa estar no pino A2 do mesmo. Além disso, o servomotor deve ser ligado em 5 V, o que é feito através da mesma placa, utilizando os pinos de 5 V e GND; e o painel solar também deve ser aterrado na mesma placa. Essa, por sua vez, também deve ser alimentada por uma fonte de tensão contínua de 12 V.

Feito a impressão e o acabamento dos modelos 3D, deve-se acoplar a engrenagem chanfrada ao suporte do painel solar utilizando dois parafusos com 1,4 mm de raio. Em seguida, coloca-se a menor engrenagem no eixo do servomotor, parafusando se necessário, e encaixa-se esse motor na base.

Antes de acoplar a engrenagem do painel solar à engrenagem do servomotor, deve-se implementar o código do arquivo "teste_servo.cpp" no Franzino, com tudo devidamente conectado, como descrito anteriormente. Esse código tem como objetivo configurar o motor em sua posição de 90°. Feito isso, alinha-se o furo da engrenagem do painel com os furos do suporte, deixando a superfície plana do painel solar aproximadamente paralaela à base. Ao fazer isso, as engrenagens já irão se acoplar. Por fim, coloca-se o cilindro adequado passando pelos três furos. Assim, basta conectar o painel solar na placa como descrito anteriormente e implementar o código do arquivo "Girassol.cpp" para que o sistema funcione adequadamente.

### Funcionamento do sistema

Primeiramente é importante ressaltar que a explicação que se segue é aquela utilizada para o sistema com apenas um eixo. O caso de dois eixos seria análogo, modificando como seriam pegos os pontos de iluminação, e tendo de controlar dois servomotores. 

A fim de fazer o painel solar se direcionar para o máximo de intensidade luminosa, utilizaram-se dois modos de funcionamento:

1. Ajuste local:
Nesse caso, dada uma posição inicial, o sistema procura o máximo local de intensidade. Para isso, comparam-se as intensidades luminosas em três pontos: o primeiro é aquele em que o sistema já se encontra, enquanto os outros dois são aqueles adjacentes a esse dado um passo, por exemplo de 5°. Comparando os três valores, o painel irá se direcionar para aquele com maior intensidade. Quando a posição de maior intensidade é a inicial, utiliza-se um atraso maior para a próxima análise. Esse modo de funcionamento, entretanto, só permite encontrar máximos locais.

2. Scan:
Para encontrar o máximo de intensidade geral é necessário fazer uma varredura de 0° a 180°, e é isso que esse modo faz. A rotina de scan só se ativa a cada intervalo de tempo, por exemplo 2 min. Nela, é feito um scan da intensidade luminosa no intervalo citado, e em seguida rotaciona-se o servomotor na posição do máximo.

Para a regulagem do intervalo de tempo entre as rotinas, utilizou-se a biblioteca disponível em https://github.com/khoih-prog/TimerInterrupt . Além disso, durante os testes observou-se um problema nas medidas do painel solar, apresentando ruídos consideráveis. Para lidar com isso, cada medição foi então substituída por um conjunto de 50 medições realizadas em intervalos de 1 ms, cuja média era definida como a medição desejada. Isso foi suficiente para evitar os ruídos encontrados e, portanto, foi implementado em ambos os modos de funcionamento.
