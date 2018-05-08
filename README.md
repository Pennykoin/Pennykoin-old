  



 Pennykoin is a secure, private cryptocurrency built on the cryptonote protocol ( like Monero).
Pennykoin is focused on making crypto as easy to use as paper currency. It is built on the Karbo base, but includes code from other coins as well as custom code. 
 
  This is an opensource community project, feel free to submit a pull request.
...

Building Pennykoin 

On linux ( supported on ubuntu, may work on others)

Install dependencies: 
 
     sudo apt-get update && sudo apt install build-essential pkg-config libboost-all-dev libssl-dev libzmq3-dev libunbound-dev libsodium-dev libminiupnpc-dev libunwind8-dev liblzma-dev libreadline6-dev libldns-dev libexpat1-dev cmake 


To build run "git clone https://github.com/jerrimus/Pennykoin" , then change to the Pennykoin directory, and run `make`. The resulting executables can be found in `build/release/src`.



...

Building on Windows
Dependencies: MSVC 2013 or later, CMake 2.8.6 or later, and Boost 1.55. You may download them from:

* http://www.microsoft.com/
* http://www.cmake.org/
* http://www.boost.org/

To build, change to a directory where this file is located, and run these commands: 
```
mkdir build
cd build
cmake -G "Visual Studio 12 Win64" ..
```

And then do Build.
Good luck!