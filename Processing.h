#ifndef STOCKBUDDY_PROCESSING_H
#define STOCKBUDDY_PROCESSING_H

#include <iostream>
#include <cstddef>
#include "Asset.h"

namespace stockbuddy {
	///Goes through the first `n` addresses stored in the array received as the first parameter and inserts into the stream the description of each asset that the condition received as the third parameter returns true, one asset per line. Null pointers are skipped.
	void displayIf(const Asset** items, size_t count,
		bool (*cond)(const Asset*), std::ostream& os);
	bool isCheap(const Asset* asset);
	///Returns true if the asset received as a parameter exists, is not in the cheap zone, and its PEG ratio is greater than 0 and at most 1
	bool isGrowthBargain(const Asset* asset); 
	///receives the address of an array, the number of elements in it, and a pointer to a comparison function that receives two elements and returns true if the first one should be placed before the second one.
	template <typename T>
	void sortItems(T** items, size_t count, bool (*before)(const T*, const T*));
}



#endif
