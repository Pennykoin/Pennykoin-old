
This repo being phased out, future GUI wallet releases will be in PKCli repo.
# Pennykoin

   Pennykoin is a private, secure cryptocurrency forked form digital/dark/ducknote.  There was no premine or ICO, all coins are emitted as mining rewards or interest.

[![Build Status](https://travis-ci.org/Pennykoin/Pennykoin.svg?branch=master)](https://travis-ci.org/Pennykoin/Pennykoin)


PK has been tested to compile on Windows 8-10 with VS2013, OSX High Sierra, Ubuntu 14-18, Solus, and EL7 ( must add elrepo & epel)

  The legacy branch is tweaked to run on VPS (openvz) with very old kernels.  If you cannot get it running, please contact jerry on twitter or discord.

for ubuntu:  
     apt install screen make cmake build-essential libboost-all-dev pkg-config libssl-dev libzmq3-dev libunbound-dev libsodium-dev libminiupnpc-dev libreadline6-dev libldns-dev



If you have previously installed PK and have the blockchain downloaded, comment out line 27 of cmakelists.txt.



  If you successfully get PK to build on other systems, please update this document
