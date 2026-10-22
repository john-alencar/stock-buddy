#ifndef STOCKBUDDY_PRICEHISTORY_H
#define STOCKBUDDY_PRICEHISTORY_H

#include <cstddef>

namespace stockbuddy {
	/// Stores a dynamically allocated history of prices.	
	class PriceHistory {
		double* m_pArr{};
		size_t m_ArrSize{};
	public:
		PriceHistory(size_t size);
		~PriceHistory();
		PriceHistory(const PriceHistory& other);
		PriceHistory(PriceHistory&& other) noexcept;
		PriceHistory& operator=(const PriceHistory& other);
		PriceHistory& operator=(PriceHistory&& other) noexcept;
		/// Does nothing if the index is out of range.
		void set(size_t index, double value);
		/// Returns 0 if the index is out of range.
		double get(size_t index) const;
		double sum() const;
		size_t size() const;
	};
}

#endif
