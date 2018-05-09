  
### Pennykoin - Make Crypto Great Again


 Pennykoin is a secure, private cryptocurrency built on the cryptonote protocol ( like Monero).
Pennykoin is focused on making crypto as easy to use as paper currency. It is built on the Karbo base, but includes code from other coins as well as custom code. 
 
  This is an opensource community project, feel free to submit a pull request. 

 ___

Building Pennykoin 

On linux ( supported on ubuntu, may work on others)

Install dependencies: 
 
     sudo apt-get update && sudo apt install build-essential pkg-config libboost-all-dev libssl-dev libzmq3-dev libunbound-dev libsodium-dev libminiupnpc-dev libunwind8-dev liblzma-dev libreadline6-dev libldns-dev libexpat1-dev cmake git


To build run "git clone https://github.com/jerrimus/Pennykoin" , then change to the Pennykoin directory, and run `make`. The resulting executables can be found in `build/release/src`.

 While not nessecary to build, I reccomend installing a newer cmake from [this PPA](https://launchpad.net/~george-edison55/+archive/ubuntu/cmake-3.x)

 ___

Building on Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* https://www.visualstudio.com/vs/older-downloads/   Get VS2013 community.
 
* https://cmake.org/download/    Get  	cmake-3.11.1-win64-x64.msi .
 
* https://dl.bintray.com/boostorg/release/1.67.0/binaries/   Get boost_1_67_0-msvc-12.0-64.exe .

To build, clone this git, then make a build directory, then enter that directory.  
Inside the build directory run 
    cmake.exe -DBOOST_ROOT=C:\boost_1_67_0 -DBOOST_LIBRARYDIR=C:\boost_1_67_0\stage\lib -G "Visual Studio 12 Win64" .. 
 ___

  Then open cryptonote.sln in VS, and build all.