#include <iostream>
#include "Processing.h"

namespace stockbuddy {
	void displayIf(const Asset** items, size_t count, bool(* cond)(const Asset*), std::ostream& os) {
		for (size_t i = 0; i<count; ++i) {
			if (items[i] && cond(items[i])) {
				items[i]->display(os);
				os << '\n';
			}
		}
	}

	bool isCheap(const Asset* asset) {
		return (asset && asset->zone() == Zone::Cheap);
	}

	bool isGrowthBargain(const Asset* asset) {
		return (asset && asset->zone() != Zone::Cheap && asset->peg() > 0 && asset->peg() <= 1);
	}

	template <typename T>
	void sortItems(T** items, size_t count, bool(* before)(const T*, const T*)) {
		
	
	}
}
