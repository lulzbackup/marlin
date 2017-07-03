#!/bin/sh

#Uncomment following line to generate binaries without timestamps
#MAKEOPTS="-f Makefile-with-no-timestamp"

rm -rf build
mkdir build
for toolhead in Single Kanyu_Flexy Opah_Moar JaveLong_Dual Yellowfin_Dual Angelfish_Aero
do
  make clean
  make $MAKEOPTS TOOLHEAD=$toolhead || exit
  mv *.hex build
done

echo
echo
echo
echo Firmware hex files built in "`pwd`/build":
ls build
echo