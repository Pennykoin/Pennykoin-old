// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2016-2017 BXC developers
// Copyright (c) 2017 Royalties developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 136; // addresses start with "Pk"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(1000000000000);

const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                   = 0;
const size_t   ZAWY_DIFFICULTY_V2                            = 1;
const uint8_t  ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION      = 0;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; // size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 2;

// COIN - number of smallest units in one coin
const uint64_t COIN                                          = UINT64_C(100); // pow(10, 6)
const uint64_t MINIMUM_FEE                                   = UINT64_C(1); // pow(10, 4)
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE; // pow(10, 4)

const uint64_t DIFFICULTY_TARGET                             = 180; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 240; // blocks
const size_t   DIFFICULTY_WINDOW_V1                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_WINDOW_V2                          = DIFFICULTY_WINDOW;
const size_t   DIFFICULTY_CUT                                = 30; // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_CUT_V2                             = DIFFICULTY_CUT;
const size_t   DIFFICULTY_LAG                                = 15; // !!!
const size_t   DIFFICULTY_LAG_V1                             = DIFFICULTY_LAG;
const size_t   DIFFICULTY_LAG_V2                             = DIFFICULTY_LAG;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const uint64_t MIN_TX_MIXIN_SIZE                            = 7;
const uint64_t MAX_TX_MIXIN_SIZE                            = 7;

const uint64_t DEPOSIT_MIN_AMOUNT                            = 25000 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 43800; // ~3 months
const uint32_t DEPOSIT_MAX_TERM                              = DEPOSIT_MIN_TERM; // ditto 
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; // rate is constant
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 1; // percentage rate for DEPOSIT_MAX_TERM
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR                             = 0; // early depositor multiplier
const uint32_t END_MULTIPLIER_BLOCK                          = 10; // block at which the multiplier ceases to be applied

const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT                  = (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); // seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); // seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint64_t UPGRADE_HEIGHT                                = 1;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
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
const uint64_t ICO_BLOCK_REWARD	                             = (UINT64_C(0) * parameters::COIN); // 18.4 billion ICO
const uint64_t MIN_BLOCK_REWARD                              = (UINT64_C(10) * parameters::COIN);
const uint64_t REWARD_HALVING_INTERVAL                       = (UINT64_C(132000));

const char     CRYPTONOTE_NAME[]                             = "pennykoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001809f49029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd088071210108f03d181bff7e9a1657cfc944a57095390701da99f47e449a65c3913b739e60";
const uint32_t GENESIS_NONCE                                 = 70;
const uint64_t GENESIS_TIMESTAMP                             = 0;
const uint8_t  TRANSACTION_VERSION_1                         = 1;
const uint8_t  TRANSACTION_VERSION_2                         = 2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         = 1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         = 2;
const uint8_t  BLOCK_MINOR_VERSION_0                         = 0;
const uint8_t  BLOCK_MINOR_VERSION_1                         = 1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         = 1000;

const int      P2P_DEFAULT_PORT                              = 53280;
const int      RPC_DEFAULT_PORT                              = 53281;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "0000000000000000000000000000000000000000000000000000000000000000";

const std::initializer_list<const char*> SEED_NODES = {
  "seed2.pennykoin.com:53280",
  "seed3.pennykoin.com:53280",
  "pk.youpool.io:53280",
  "PK.hashpool.frl:53280"
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
  { 4216, "4c2c769b66b43e1d07f1f9233c089ebf8a6ebfd221513bf66078d672b2a25396" }

};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
