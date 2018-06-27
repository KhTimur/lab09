#include "catch.hpp"
#include <merge_sort.h>

SCENARIO("SORT_MERGE") {	
	int nums3[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	merge_sort(nums3, nums3+9);
	int j=0;
	for (int i = 0; i < 9; ++i) {
		if(nums3[i] == nums_proverka3[i])
			j++;
	}
	REQUIRE(j==9);
}
