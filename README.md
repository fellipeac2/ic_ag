
#Introdução

GAL - Genetic Algothrms Library

Essa aplicação tem como intuito servir de base para a primeira implentação de agoritmos genéticos da disciplina
Inteligência Computacional ministrada pelo professor Celso Camilo para a Escola de Engenharia Elétrica, Mecânica
e de Computação da Universidade Federal de Goiás.

#Instalação

Passo 0 (caso não possui instalado no seu linux os programas autotools, instale-os e construa-os):
$ wget https://ftp.gnu.org/gnu/automake/automake-1.15.tar.gz
$ tar -xzvf automake-1.15.tar.gz
$ cd automake-1.15
$ ./configure
$ make
$ sudo make install

1º Passo (clona esse repositório git):

$ git clone https://github.com/fellipeac2/ic_ag.git

2º Passo (entre no diretório ic_ag baixado):

$ cd ic_ag

3º Passo (compilação):

$ ./configure && make


4º Passo (caso tudo der certo do passo 3, rodar o executavel sample_ga dentro do diretório src):

$ ./src/sample_ga

5º Passo (repita o passo anterior até encontrar valores de minimos que represente ser os melhores pontos de minização da função
F6

#OBS.:

Não aconselha-se instalar a aplicação nos repositórios de super usuário da máquina, isto é, não execute 
$ sudo make install
Pois essa aplicação ainda não encontra-se completa e espera-se o incremento de novas classes para novos tipos de representação
tal como representação matricial.
