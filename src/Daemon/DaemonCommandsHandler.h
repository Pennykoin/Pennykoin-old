#pragma once

#include "Common/ConsoleHandler.h"
#include "CryptoNoteProtocol/ICryptoNoteProtocolQuery.h"
#include <Logging/LoggerRef.h>
#include <Logging/LoggerManager.h>
#include "Rpc/JsonRpc.h"
#include "Rpc/RpcServer.h"

namespace CryptoNote {
	class core;
	class Currency;
	class NodeServer;
	class ICryptoNoteProtocolQuery;
}

class DaemonCommandsHandler
{
public:
	 DaemonCommandsHandler(CryptoNote::core& core, CryptoNote::NodeServer& srv, Logging::LoggerManager& log, const CryptoNote::ICryptoNoteProtocolQuery& protocol, CryptoNote::RpcServer* prpc_server);

	bool start_handling() {
		m_consoleHandler.start();
		return true;
	}

	void stop_handling() {
		m_consoleHandler.stop();
	}

private:

	Common::ConsoleHandler m_consoleHandler;
	CryptoNote::core& m_core;
	CryptoNote::NodeServer& m_srv;
	Logging::LoggerRef logger;
	Logging::LoggerManager& m_logManager;

	 const CryptoNote::ICryptoNoteProtocolQuery& protocolQuery;
  CryptoNote::RpcServer* m_prpc_server;
  
  std::string get_commands_str();
  std::string get_mining_speed(uint32_t hr);
  float get_sync_percentage(uint64_t height, uint64_t target_height);
	bool print_block_by_height(uint32_t height);
	bool print_block_by_hash(const std::string& arg);
	uint64_t calculatePercent(const CryptoNote::Currency& currency, uint64_t value, uint64_t total);

	bool exit(const std::vector<std::string>& args);
	bool help(const std::vector<std::string>& args);
	bool print_pl(const std::vector<std::string>& args);
	bool show_hr(const std::vector<std::string>& args);
	bool hide_hr(const std::vector<std::string>& args);
	bool print_bc_outs(const std::vector<std::string>& args);
	bool print_cn(const std::vector<std::string>& args);
	bool print_bc(const std::vector<std::string>& args);
	bool print_bci(const std::vector<std::string>& args);
	bool set_log(const std::vector<std::string>& args);
	bool print_block(const std::vector<std::string>& args);
	bool print_tx(const std::vector<std::string>& args);
	bool print_pool(const std::vector<std::string>& args);
	bool print_pool_sh(const std::vector<std::string>& args);
	  bool print_ban(const std::vector<std::string>& args);
  bool ban(const std::vector<std::string>& args);
  bool unban(const std::vector<std::string>& args);
	bool print_stat(const std::vector<std::string>& args);
	bool start_mining(const std::vector<std::string>& args);
	bool status(const std::vector<std::string>& args);
	bool stop_mining(const std::vector<std::string>& args);
};
