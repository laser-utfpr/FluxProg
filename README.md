# LASER FluxProg - fluxograma e robôs
O projeto INCLUSÃO DIGITAL DE JOVENS PELO ESTUDO DA ROBÓTICA tem por objetivo ensinar a lógica de programação para jovens por meio de fluxograma próprio, usando para ver o resultado da programação robôs simulados e reais.

O projeto pertence ao LASER - Laboratório Avançado de Sistemas Embarcados e Robótica, da UTFPR - Universidade Tecnológica Federal do Paraná.

As cenas do V-REP estão na pasta Scene. A programação do robô físico está na pasta Fisico.

## Executando o FluxProg
Para Linux Debian/Ubuntu, intalar as dependências e executar o script flux_prog.sh, que está dentro de Linux/FluxProg.

Para Windows, executar o arquivo fluxprog.exe, na pasta Windows/executables. Se ocorrer erro na localização das imagens, renomeie os diretórios em que o repositório foi baixado com nomes sem acento.

## Dependências

Boost
- `sudo apt-get install libboost-dev`.

CMake
- `sudo apt-get install cmake`.

V-REP, baixe a versão EDU: http://www.coppeliarobotics.com/downloads.html.

Arduino: https://www.arduino.cc/en/Main/Software.

Bibliotecas do arduino:
- Timer1 (Download pelo IDE);
- Adafruit Motor Shield library (Download pelo IDE);
- Ultrasonic by FilipeFlop (https://github.com/filipeflop/Ultrasonic).

Allegro 5 (Instruções completas em https://github.com/liballeg/allegro_wiki/wiki/Quickstart#installation)
1. `sudo add-apt-repository ppa:allegro/5.2`;
2. `sudo apt-get install liballegro*5.2 liballegro*5-dev`.