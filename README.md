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

Para o microcontrolador, será verificada a possbilidade de utilizar uma placa Franzino construída por um dos integrantes do grupo. Contudo, já que a mesma ainda não se encontra presente, na primeira semana será utilizado um Arduino UNO.

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




