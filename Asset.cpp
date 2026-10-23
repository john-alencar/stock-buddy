#include "Asset.h"

namespace stockbuddy {
	Asset::Asset(const char* ticker, const char* name)
		:m_ticker{ ticker ? ticker : "" }, m_name{name ? name: ""} {
	}

	const std::string& Asset::ticker() const {
		return m_ticker;
	}

	const std::string& Asset::name() const {
		return m_name;
	}

	Stock::Stock(const char* ticker, const char* name, int qty, double price, double trailingPE,
		double earningGrowthPercent, double cheapPE)
		:Asset(ticker, name), m_qty{ qty }, m_price{ price }, m_trailingPE{ trailingPE }, m_earningGrowthPercent{ earningGrowthPercent }, m_cheapPE{ cheapPE } {
	};

	double Stock::value() const {
		return m_price * m_qty;
	}

	double Stock::peg() const {
		if (m_earningGrowthPercent > 0) {
			return m_trailingPE / m_earningGrowthPercent;
		}
		else return -1;
	}

	Zone Stock::zone() const {
		if (m_trailingPE <= m_cheapPE) {
			return Zone::Cheap;
		}
		else if (m_trailingPE <= m_cheapPE * 1.25) {
			return Zone::Fair;
		} 
		return Zone::Rich;
	}

	Asset* Stock::clone() const {
		return new Stock(*this);
	}

	void Stock::display(std::ostream& os) const {
	}

	void Stock::addPrice(double price) {
	}

	int Stock::historyCount() const {
	}

	void Stock::displayHistory(std::ostream& os) const {
	}

	DividendStock::DividendStock(const char* ticker, const char* name, int qty, double price, double trailingPE,
		double earningGrowthPercent, double cheapPE, double yield) {
	}

	double DividendStock::dividendIncome() const {
	}

	Asset* DividendStock::clone() const {
		return new DividendStock(*this);
	}

	void DividendStock::display(std::ostream& os) const {
		Stock::display(os);
	}

	Etf::Etf(const char* ticker, const char* name, int qty, double price, double MER) {
	}

	double Etf::value() const {
	}

	double Etf::peg() const {
	}

	Zone Etf::zone() const {
	}

	Asset* Etf::clone() const {
		return new Etf(*this);
	}

	void Etf::display(std::ostream& os) const {
	}

	const char* toString(Zone zone) {
		if (zone == Zone::Cheap) return "CHEAP";
		if (zone == Zone::Fair) return "FAIR";
		return "RICH";
	}
}
