#!/bin/bash

[ ! -d ./bin ] && mkdir bin
[ ! -d ./obj ] && mkdir obj
[ ! -d ./obj/Enemies ] && mkdir obj/Enemies
[ ! -d ./obj/Character ] && mkdir obj/Character
[ ! -d ./obj/Obstacles ] && mkdir obj/Obstacles
[ ! -d ./obj/Phases ] && mkdir obj/Phases
[ ! -d ./obj/System ] && mkdir obj/System
[ ! -d ./Save ] && mkdir Save

if [ ! -d sfml ]
then
  echo "Instalando dependências =)"
  wget https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz
  tar -xvf SFML-2.5.1-linux-gcc-64-bit.tar.gz
  mv SFML-2.5.1 sfml
  rm SFML-2.5.1-linux-gcc-64-bit.tar.gz
fi