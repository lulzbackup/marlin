#!/bin/sh

#Uncomment following line to generate binaries without timestamps
#MAKEOPTS="-f Makefile-with-no-timestamp"

rm -rf build
mkdir build
for toolhead in Oliveoil_SingleExtruder Kanyu_Flexystruder Opah_Moarstruder Javelin_DualExtruder Longfin_FlexyDually Yellowfin_DualExtruder Angelfish_Aero
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