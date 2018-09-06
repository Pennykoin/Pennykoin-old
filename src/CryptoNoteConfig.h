// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2016 SDN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 180; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 136; // addresses start with "0xc"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 6;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 3;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(1000000000000);

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 32000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 2;
// COIN - number of smallest units in one coin
const uint64_t COIN                                          = UINT64_C(100);  // pow(10, 8)
const uint64_t MINIMUM_FEE                                   = UINT64_C(1);     // pow(10, 5)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(1);     // pow(10, 5)
//const uint64_t GENESIS_BLOCK_REWARD							 = UINT64_C(0);

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 240; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 60;  // blocks
const size_t   DIFFICULTY_CUT                                = 30;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t DEPOSIT_MIN_AMOUNT                            = 25000 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 43200;
const uint32_t DEPOSIT_MAX_TERM                              = DEPOSIT_MIN_TERM;
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0;
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 1;
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); //seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 16500;
const uint32_t UPGRADE_HEIGHT_V4                             = 24400;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "pnblocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "pnndexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "pncache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "pnbcindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(12000) * parameters::COIN);
const uint64_t MIN_BLOCK_REWARD                              = (UINT64_C(10) * parameters::COIN);
const uint64_t REWARD_HALVING_INTERVAL                       = (UINT64_C(132000));

const char     CRYPTONOTE_NAME[]                             = "pennykoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001809f49029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210108f03d181bff7e9a1657cfc944a57095390701da99f47e449a65c3913b739e60";
const uint32_t GENESIS_NONCE                                 = 70;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 53280;
const int      RPC_DEFAULT_PORT                              = 53281;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000000000000";

const std::initializer_list<const char*> SEED_NODES = {
  "seed1.pennykoin.com:53280",
  "seed2.pennykoin.com:53280",
  "seed3.pennykoin.com:53280",

};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {

  { 680, "b5c5635f1de8934468b35c5e4ae48f4fc6e47ae21d85d0e1b563835f2b40f88d" },
  { 1550, "3576f6075b79223a3bbf9b7404b0a0687eb6f20b7cec0c07ddbcc6ed8ae59430" },
  { 4216, "4c2c769b66b43e1d07f1f9233c089ebf8a6ebfd221513bf66078d672b2a25396" },
  { 7279, "8a577fee7dc3e5a07829b5e2abdebe7d11efb31b25d0943d4d8e6473da8ee6bf" },
  { 13924, "66c3bcbdca9a6b62da0e081729ac08db8aa70da0f89e1870b9753053c4d33624" },
  { 24270, "c8b6d4628e8c8f3f8874631eb09a60df12fa48a3daae2ea03e1fdc03fba5799b" }
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
