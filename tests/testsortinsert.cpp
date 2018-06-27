#include "catch.hpp"
#include <inser.h>



SCENARIO("SORT_INSERT") {
	int nums1[] = { 9,1,7,2,5,8,3,6,4 };
	int nums_proverka1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	inser(nums1, nums1+9);
	for (int i = 0; i < 9; ++i) {
		REQUIRE(nums1[i] == nums_proverka1[i]);
	}
}
