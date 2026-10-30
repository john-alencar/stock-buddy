#ifndef STOCKBUDDY_ASSET_H
#define STOCKBUDDY_ASSET_H

#include <string>
#include <iostream>
#include "DynArray.h"

namespace stockbuddy {
	enum class Zone {
		Cheap,
		Fair,
		Rich
	};
	class Asset {
		std::string m_ticker{};
		std::string m_name{};
	public:
		Asset(const char* ticker, const char* name);
		virtual ~Asset() = default;
		Asset(const Asset&) = default;
		Asset& operator=(const Asset&) = default;
		const std::string& ticker() const;
		const std::string& name() const;
		///Returns total value of the holding (shares * price)
		virtual double value() const = 0;
		///Returns `PEG` or `-1` if N/A
		virtual double peg() const = 0;
		virtual Zone zone() const = 0;
		///Returns address of a dynamically created copy of the current instance
		virtual Asset* clone() const = 0;
		///Inserts into `ostream` param a description of the current instance
		virtual void display(std::ostream& os) const = 0;
	};
	class Stock: public Asset {
		int m_qty{};
		double m_price{};
		double m_trailingPE{};
		double m_earningGrowthPercent{};
		double m_cheapPE{};
		DynArray<double> m_priceHistory{};
		int m_sizePriceHistory{};
	public:
		Stock(const char* ticker, const char* name, int qty, double price, double trailingPE, double earningGrowthPercent, double cheapPE);
		double value() const override;
		double peg() const override;
		Zone zone() const override;
		Asset* clone() const override;
		void display(std::ostream& os) const override;
		void addPrice(double price);
		///Returns num. of past prices stored
		int historyCount() const;
		///Insert into the stream all prices separated by space
		void displayHistory(std::ostream& os) const;
	};
	class DividendStock: public Stock {
		double m_yield{};
	public:
		DividendStock(const char* ticker, const char* name, int qty, double price, double trailingPE, double earningGrowthPercent, double cheapPE, double yield);
		double dividendIncome() const;
		Asset* clone() const override;
		void display(std::ostream& os) const override;
	};
	class Etf: public Asset {
		int m_qty{};
		double m_price{};
		double m_trailingPE{};
		double m_cheapPE{};
		double m_MER{}; //percent
	public:
		Etf(const char* ticker, const char* name, int qty, double price, double trailingPE, double cheapPE, double MER);
		double value() const override;
		double peg() const override;
		Zone zone() const override;
		Asset* clone() const override;
		void display(std::ostream& os) const override;
	};
	const char* toString(Zone zone); ///helper to return string(char*) of zone.
}

#endif

