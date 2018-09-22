#pragma once

#include <vector>
#include <cstddef>
#include <cstdint>

namespace CryptoNote {
	class ISerializer;

	class DepositIndex {
	public:
		using DepositAmount = int64_t;
		using DepositInterest = uint64_t;
		using DepositHeight = uint32_t;
		DepositIndex();
		explicit DepositIndex(DepositHeight expectedHeight);
		void pushBlock(DepositAmount amount, DepositInterest interest);
		void popBlock();
		void reserve(DepositHeight expectedHeight);
		size_t popBlocks(DepositHeight from);
		DepositAmount depositAmountAtHeight(DepositHeight height) const;
		DepositAmount fullDepositAmount() const;
		DepositInterest depositInterestAtHeight(DepositHeight height) const;
		DepositInterest fullInterestAmount() const;
		DepositHeight size() const;
		void serialize(ISerializer& s);

	private:
		struct DepositIndexEntry {
			DepositHeight height;
			DepositAmount amount;
			DepositInterest interest;

			void serialize(ISerializer& s);
		};

		using IndexType = std::vector<DepositIndexEntry>;
		IndexType::const_iterator upperBound(DepositHeight height) const;
		IndexType index;
		DepositHeight blockCount;
	};
}
