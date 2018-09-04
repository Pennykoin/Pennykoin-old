
#include "WalletUtils.h"

#include "CryptoNote.h"

namespace CryptoNote {

bool validateAddress(const std::string& address, const CryptoNote::Currency& currency) {
  CryptoNote::AccountPublicAddress ignore;
  return currency.parseAccountAddressString(address, ignore);
}

}
