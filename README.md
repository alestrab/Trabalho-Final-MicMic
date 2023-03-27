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

Como microcontrolador foi utilizado um Franzino. 

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

Utilizou-se software Sketchup para construção dos suportes e sistemas para rotação da placa solar. O modelamento das engrenagens foi feito com base em objetos já existentes em um banco de projetos do aplicativo, enquanto o suporte foi pensado de acordo com alguns diagramas construidos inicialmente em papel.

O suporte para placa com controle de rotação foi impresso em um laboratório do departamento de Física da universidade, contudo, verificou-se que o segundo eixo de rotação não poderia ser implementado utilizando o servomotor planejado.
O servomotor apresenta limitação de rotação, podendo realizar no máximo um giro de 180°. Quando comparado com as engrenagens colocadas, o segundo eixo conseguiria ao máximo realizar uma rotação de 45º, muito inferior ao planejado. Como esse problema só foi identificado durante os testes do primeiro eixo, não houve tempo para alteração do modelo. Assim, abandonou-se a utilização do segundo eixo e focou-se apenas no primeiro.'

### Montagem do aparato

Os códigos escritos para o funcionamento do sistema necessitam que o cabo de sinal do servmotor esteja contectado no pino A10 do Franzino, enquanto o painel solar precisa estar no pino A2 do mesmo. Além disso, o servomotor deve ser ligado em 5 V, o que é feito através da mesma placa, utilizando os pinos de 5 V e GND; e o painel solar também deve ser aterrado na mesma placa.

Feito a impressão e o acabamento dos modelos 3D, coloca-se a menor engrenagem no eixo do motor, parafusando se necessário. Em seguida, deve-se implementar o código "teste_servo.cpp" no Franzino com o servomotor conectado como descrito anteriormente. Esse código serve para garantir que o eixo esteja na posição de 90°.






