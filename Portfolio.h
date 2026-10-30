#ifndef STOCKBUDDY_PORTFOLIO_H
#define STOCKBUDDY_PORTFOLIO_H

#include <iostream>
#include "Asset.h"
#include "watchlist.h"

namespace stockbuddy {
	class Portfolio {
		int m_assetQty{};
		int m_assetArrSize{};
		Asset** m_assetArr{};
		Broker* m_broker{};
		///Deletes all assets, releases array of pointers, puts the instance in safe empty state.
		void setEmpty(); 
		///Allocates new array of pointers with double the current capacity, or 4 if it's empty, and move the addresses of the current array to the new array.
		void grow();
	public:
		Portfolio() = default;
		Portfolio(const Portfolio&);
		Portfolio& operator=(const Portfolio&);
		Portfolio(Portfolio&&) noexcept;
		Portfolio& operator=(Portfolio&&) noexcept;
		virtual ~Portfolio();
		/// stores a dynamically created copy of the asset, obtained by calling the asset's clone(), at the end of the array; if the array is full, the array grows first
		Portfolio& add(const Asset* asset);
		///Returns `m_assetQty`
		size_t size() const;
		///Returns the address of the asset at `parameter` position
		const Asset* operator[](size_t index) const;
		///Returns the sum of the values of all assets stored
		double totalValue() const;
		void display(std::ostream& os) const;
		void setBroker(Broker* broker);
		Broker* broker() const;
	};

}




#endif

