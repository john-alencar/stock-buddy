#include "Portfolio.h"

namespace stockbuddy {
	void Portfolio::setEmpty() {
		if (m_assetArr != nullptr) {
			for (int i=0; i<m_assetQty; ++i) {
				delete m_assetArr[i];
			}
		}
		delete[] m_assetArr;
		m_assetArr = {};
		m_assetArrSize = {};
		m_assetQty = {};
	}

	void Portfolio::grow() {
		if (m_assetArr == nullptr || m_assetArrSize == 0) {
			delete[] m_assetArr;
			m_assetArr = new Asset * [4];
			m_assetArrSize = 4;
		} else {
			int newSize = m_assetArrSize * 2;
			Asset** temp = new Asset * [newSize];
			for (int i=0; i<m_assetQty; ++i) {
				temp[i] = m_assetArr[i];
			}
			delete[] m_assetArr;
			m_assetArr = temp;
			m_assetArrSize = newSize;
		}
	}

	Portfolio::Portfolio(const Portfolio&) {
	}

	Portfolio& Portfolio::operator=(const Portfolio&) {
	}

	Portfolio::Portfolio(Portfolio&&) noexcept {
	}

	Portfolio& Portfolio::operator=(Portfolio&&) noexcept {
	}

	Portfolio::~Portfolio() {
	}

	Portfolio& Portfolio::add(const Asset* asset) {
	}

	size_t Portfolio::size() const {
	}

	const Asset* Portfolio::operator[](size_t index) const {
	}

	double Portfolio::totalValue() const {
	}

	void Portfolio::display(std::ostream& os) const {
	}

	void Portfolio::setBroker(Broker* broker) {
	}

	Broker* Portfolio::broker() const {
	}
}
