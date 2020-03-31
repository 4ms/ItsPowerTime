#!/usr/bin/env bash

#apt-get update
#apt-get install -y gcc-arm-none-eabi
#sudo apt-get install -y build-essential autotools-dev autoconf pkg-config libusb-1.0-0 libusb-1.0-0-dev libftdi1 libftdi-dev git libc6:i386 libncurses5:i386 libstdc++6:i386 cowsay figlet language-pack-en

echo "Downloading gcc-arm-none-eabi-9-2019-q4-major"
cd /home/vagrant
#wget -nv https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux.tar.bz2
echo "Decompressing gcc-arm-none-eabi-9-2019-q4-major"
#tar jxf *.tar.bz2
echo "Adding it to the PATH"
echo "export PATH=/home/vagrant/gcc-arm-none-eabi-9-2019-q4-major/bin:\$PATH" >> /home/vagrant/.bashrc

