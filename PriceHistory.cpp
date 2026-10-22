#include "PriceHistory.h"


namespace stockbuddy {
	PriceHistory::PriceHistory(size_t size) : m_arrSize{size} {
		if (size > 0) {
			m_pArr = new double [m_arrSize] {};
		}
	}

	PriceHistory::~PriceHistory() {
		delete[] m_pArr;
	}

	PriceHistory::PriceHistory(const PriceHistory& other) :m_arrSize{other.m_arrSize} {
		if (other.m_pArr != nullptr) {
			m_pArr = new double[m_arrSize];
			for (size_t i=0; i<m_arrSize; ++i) {
				m_pArr[i] = other.m_pArr[i];
			}
		}
	}

	PriceHistory::PriceHistory(PriceHistory&& other) noexcept :m_arrSize{other.m_arrSize} {
		m_pArr = other.m_pArr;
		other.m_pArr = {};
		other.m_arrSize = {};
	}

	PriceHistory& PriceHistory::operator=(const PriceHistory& other) {
		if (this != &other) {
			delete[] m_pArr;
			if (other.m_pArr != nullptr) {
				m_arrSize = other.m_arrSize;
				m_pArr = new double[m_arrSize];
				for (size_t i = 0; i < m_arrSize; ++i) {
					m_pArr[i] = other.m_pArr[i];
				}
			}
		}
		return *this;
	}

	PriceHistory& PriceHistory::operator=(PriceHistory&& other) noexcept {
		if (this != &other) {
			delete[] m_pArr;
			m_arrSize = other.m_arrSize;
			m_pArr = other.m_pArr;
			other.m_pArr = {};
			other.m_arrSize = {};
		}
		return *this;
	}

	void PriceHistory::set(size_t index, double value) {
		if (index < m_arrSize) {
			m_pArr[index] = value;
		}
	}

	double PriceHistory::get(size_t index) const {
		if (m_arrSize> index) {
			return m_pArr[index];
		}
		else {
			return 0;
		}
	}

	double PriceHistory::sum() const {
		if (m_pArr != nullptr) {
			double sum{};
			for (size_t i=0; i<m_arrSize; ++i) {
				sum += m_pArr[i];
			}
			return sum;
		}
	}
	size_t PriceHistory::size() const {
		return m_arrSize;
	}
}
