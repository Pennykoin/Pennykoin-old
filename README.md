# Pennykoin

   Pennykoin is a private, secure cryptocurrency forked form digital/dark/ducknote.  There was no premine or ICO, all coins are emitted as mining rewards or interest.

[![Build Status](https://travis-ci.org/Pennykoin/Pennykoin.svg?branch=jtest)](https://travis-ci.org/Pennykoin/Pennykoin)

log 
* bionic specific - remove for gen rel

##Wallet
* transfers from height list_transfers command in simplewallet can be appended with a block number and only search beyond that
* import/expor for view/spend in CLI
* import/export tracking code , import launches in tracking mode
* gettransactionsbypaymentid fix
* can generate integrated addresses pkwallet
* integrated addresses pkwallet rpc and gateway now
* can find unlocked inputs that could be optimized, still working on the optimization
* import/export electrum(mnemonics) seeds
* stripped non-english dictionaries (until PK is translated more, no use)
* WARNING- old wallets are not deterministic, so no 25 words, you can sweep your old wallet


##Security + Fixes + w/e
* ryo 51% fix for low hash coins makes making long sidechains much harder
* patched terminate error
* rebased paymentgate to xun
* ryo poisson altchain detection
* fixed hang on close error
* more detailed rpc error messages
* network speed optimization from karbo
* triangular distribution of mixins from XMR
* softcoded min mixin of 5
* hardcoded max mixin of 9 ( will scan BC to ensure there arent any larger yet.


##Daemon
* getlastblockheader includes deposit info
* /getinfo has number of gen coins
* status command for daemon
* implemented ban/unban commands and autoban (for clients with wrong version or bad handshake)
* tx info has confirmations field
* faster chain sync













