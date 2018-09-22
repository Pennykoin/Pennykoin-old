

#pragma once

#include <string>

#include "CryptoNoteCore/Currency.h"

namespace CryptoNote {

bool validateAddress(const std::string& address, const CryptoNote::Currency& currency);

}
