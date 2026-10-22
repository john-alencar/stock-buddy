#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <cstddef>

namespace stockbuddy {
	/// Stores a dynamically allocated array of type `T`	
	template <typename T>
	class DynArray {
		T* m_pArr{};
		size_t m_arrSize{};
		void resize(int newsize) {
			T* temp = new T[newsize]{};
			size_t count = m_arrSize;
			if (static_cast<size_t>(newsize) < count) { count = static_cast<size_t>(newsize); }
			for (size_t i = 0; i < count; ++i) {
				temp[i] = m_pArr[i];
			}
			m_arrSize = static_cast<size_t>(newsize);
			delete[] m_pArr;
			m_pArr = temp;
			temp = nullptr;
		}
	public:
		DynArray(int size = 1) : m_arrSize{ size } {
			if (size > 0) {
				m_pArr = new T[m_arrSize]{};
			}
		}
		~DynArray() {
			delete[] m_pArr;
		}
		DynArray(const DynArray& other) :m_arrSize{ other.m_arrSize } {
			if (other.m_pArr != nullptr) {
				m_pArr = new T[m_arrSize];
				for (size_t i = 0; i < m_arrSize; ++i) {
					m_pArr[i] = other.m_pArr[i];
				}
			}
		}
		DynArray(DynArray&& other) noexcept :m_arrSize{ other.m_arrSize } {
			m_pArr = other.m_pArr;
			other.m_pArr = {};
			other.m_arrSize = {};
		}
		DynArray& operator=(const DynArray& other) {
			if (this != &other) {
				delete[] m_pArr;
				m_pArr = nullptr;
				m_arrSize = other.m_arrSize;
				if (other.m_pArr != nullptr) {
					m_pArr = new T[m_arrSize];
					for (size_t i = 0; i < m_arrSize; ++i) {
						m_pArr[i] = other.m_pArr[i];
					}
				}
			}
			return *this;
		};
		DynArray& operator=(DynArray&& other) noexcept {
			if (this != &other) {
				delete[] m_pArr;
				m_pArr = nullptr;
				m_arrSize = other.m_arrSize;
				m_pArr = other.m_pArr;
				other.m_pArr = {};
				other.m_arrSize = {};
			}
			return *this;
		}
		/// Does nothing if the index is out of range.
		void set(size_t index, T value) {
			if (index < m_arrSize) {
				m_pArr[index] = value;
			}
		}
		/// Returns 0 if the index is out of range.
		T get(size_t index) const {
			if (m_arrSize > index) {
				return m_pArr[index];
			}
			else {
				return 0;
			}
		}
		///If the position is beyond the end of the array, the array is resized to include it. If negative, always return the first element.
		T& operator[](int index) {
			if (index < 0) {
				index = 0;
			}
			size_t idx = static_cast<size_t>(index);
			if (idx >= m_arrSize) {
				resize(index + 1);
			}
			if (index < 0) {
				index = 0;
			}
			return m_pArr[idx];
		}
		const T& operator[](int index) const {
			T elem{};

		}

		T sum() const {
			T sum{};
			if (m_pArr != nullptr) {
				for (size_t i = 0; i < m_arrSize; ++i) {
					sum += m_pArr[i];
				}
			}
			return sum;
		}
		size_t size() const {
			return m_arrSize;
		}
	};
}

#endif
