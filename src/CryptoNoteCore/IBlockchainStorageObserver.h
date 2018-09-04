#pragma once

namespace CryptoNote {
	class IBlockchainStorageObserver {
	public:
		virtual ~IBlockchainStorageObserver() {
		}

		virtual void blockchainUpdated() = 0;
	};
}
