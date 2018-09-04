#include "WalletFactory.h"

#include "NodeRpcProxy/NodeRpcProxy.h"
#include "Wallet/WalletGreen.h"
#include "CryptoNoteCore/Currency.h"

#include <stdlib.h>
#include <future>

namespace PaymentService {
	WalletFactory WalletFactory::factory;

	WalletFactory::WalletFactory() {
	}

	WalletFactory::~WalletFactory() {
	}

	CryptoNote::IWallet* WalletFactory::createWallet(const CryptoNote::Currency& currency, CryptoNote::INode& node, System::Dispatcher& dispatcher) {
		CryptoNote::IWallet* wallet = new CryptoNote::WalletGreen(dispatcher, currency, node);
		return wallet;
	}
}