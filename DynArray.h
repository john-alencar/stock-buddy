#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <cstddef>
#include <iostream>

namespace stockbuddy {
	/// Stores a dynamically allocated array of type `T`	
	template <typename T>
	class DynArray {
		T* m_pArr{};
		int m_arrSize{};
		void resize(int newsize) {
			T* temp = new T[newsize]{};
			int count = m_arrSize;
			if (newsize < count) { count = newsize; }
			for (int i = 0; i < count; ++i) {
				temp[i] = m_pArr[i];
			}
			m_arrSize = newsize;
			delete[] m_pArr;
			m_pArr = temp;
			temp = nullptr;
		}
	public:
		DynArray(int size = 1) : m_arrSize{size < 0 ? 0 : size } {
			if (size > 0) {
				m_pArr = new T[m_arrSize]{};
			} else {
				m_pArr = {};
				m_arrSize = {};
			}
		}
		virtual ~DynArray() {
			delete[] m_pArr;
		}
		DynArray(const DynArray& other) :m_arrSize{ other.m_arrSize } {
			if (other.m_pArr != nullptr) {
				m_pArr = new T[m_arrSize];
				for (int i = 0; i < m_arrSize; ++i) {
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
					for (int i = 0; i < m_arrSize; ++i) {
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
		void set(int index, T value) {
			if (index >= 0 && index < m_arrSize) {
				m_pArr[index] = value;
			}
		}
		/// Returns 0 if the index is out of range.
		T get(int index) const {
			if (index >= 0 && m_arrSize > index) {
				return m_pArr[index];
			}
			else {
				return 0;
			}
		}
		///Returns a reference to the element at the param. position. If beyond the end of the array, the array is resized to include it. If negative, returns the first element.
		T& operator[](int index) {
			if (index < 0) {
				index = 0;
			}
			if (index >= m_arrSize) {
				resize(index + 1);
			}
			return m_pArr[index];
		}
		/// Returns a const reference to an element of the array. Provides read-only access to an element at the specified index, with bounds adjustment. The index of the element to access. Negative values are clamped to zero. Indices greater than or equal to the array size are wrapped using modulo.
		const T& operator[](int index) const {
			if (index < 0) {
				index = 0;
			}
			if (index >= m_arrSize && m_arrSize != 0) {
				index = index % m_arrSize;
			}
			return m_pArr[index];
		}

		T sum() const {
			T sum{};
			if (m_pArr != nullptr) {
				for (int i = 0; i < m_arrSize; ++i) {
					sum += m_pArr[i];
				}
			}
			return sum;
		}
		int size() const {
			return m_arrSize;
		}
		friend std::ostream& operator <<(std::ostream& os, const DynArray& arr) {
			for (int i=0; i<arr.m_arrSize;++i) {
				if (i == 0) { os << arr.m_pArr[i]; }
				else { os << " " << arr.m_pArr[i]; }
			}
			return os;
		}
	};
}

#endif
