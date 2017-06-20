#!/bin/sh

rm -rf build
mkdir build
for toolhead in Single Flexy Moar Dually GunnisonDual
do
  make clean
  make TOOLHEAD=$toolhead || exit
  mv *.hex build
done

echo
echo
echo
echo Firmware hex files built in "`pwd`/build":
ls build
echo