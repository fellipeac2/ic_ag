
#Introdução

GAL - Genetic Algothrms Library

Essa aplicação tem como intuito servir de base para a primeira implentação de agoritmos genéticos da disciplina
Inteligência Computacional ministrada pelo professor Celso Camilo para a Escola de Engenharia Elétrica, Mecânica
e de Computação da Universidade Federal de Goiás.

#Instalação

1º Passo (clona esse repositório git):

$ git clone https://github.com/fellipeac2/ic_ag.git

2º Passo (entre no diretório ic_ag baixado):

$ cd ic_ag


3º Passo (Utilizando git ocorre a perca dos timestamps dos arquivos revisionados, no entanto, o building system do gnu, i.e. Autotools, requer
timestamps originais e/ou atualizadas para que não seja preciso reproduzir os arquivos de Makefile, assim siga o passo seguinte):

$ touch *

4º Passo (compilação):

$ ./configure && make


5º Passo (caso tudo der certo do passo 3, rodar o executavel sample_ga dentro do diretório src):

$ ./src/sample_ga

6º Passo (repita o passo anterior até encontrar valores de minimos que represente ser os melhores pontos de minização da função
F6

#OBS.:

Não aconselha-se instalar a aplicação nos repositórios de super usuário da máquina, isto é, não execute 
$ sudo make install
Pois essa aplicação ainda não encontra-se completa e espera-se o incremento de novas classes para novos tipos de representação
tal como representação matricial.
