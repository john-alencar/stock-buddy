#include "SmartPortfolio.h"

namespace stockbuddy {
	SmartPortfolio::SmartPortfolio(const SmartPortfolio& other) {
	}

	SmartPortfolio& SmartPortfolio::add(const Asset* asset) {

	}

	SmartPortfolio& SmartPortfolio::add(std::unique_ptr<Asset> asset) {
	}

	size_t SmartPortfolio::size() const {
	}

	double SmartPortfolio::totalValue() const {
	}

	void SmartPortfolio::display(std::ostream& os) const {
	}

	void SmartPortfolio::swap(SmartPortfolio& other) noexcept {
	}

	std::unique_ptr<Asset> cloneUnique(const Asset& asset) {
	}
}
