#include "Processing.h"

namespace stockbuddy {
	void displayIf(const Asset** items, size_t count, bool(* cond)(const Asset*), std::ostream& os) {
	}

	bool isCheap(const Asset* a) {
	}

	bool isGrowthBargain(const Asset* a) {
	}

	template <typename T>
	void sortItems(T** items, size_t count, bool(* before)(const T*, const T*)) {
	}
}
