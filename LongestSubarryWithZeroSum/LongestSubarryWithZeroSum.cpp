// LongestSubarryWithZeroSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

extern int LongestSubarrayWith0Sum(const std::vector<int>& A, size_t index);

int LongestSubarray(const std::vector<int>& vec, size_t index, int sum)
{
	if (index == vec.size())
	{
		if (sum == 0)
			return 1;

		return -1;
	}

	if (sum == 0)
	{		// sum is 0, at least 1 subarray is found. We treat the rest of
		    //  array as whole array and try to get see if there are matches.
			//  so we (recursively) call the LongestSubarrayWith0Sum function
		int n = LongestSubarrayWith0Sum(vec, index);
		if (n < 0)	// there are no matching subarray in the rest of the array
			        //  return 1
			return 1;
		return 1 + n;	// more matching sub arrays found
	}

	int n = -1;
	for (size_t i = index; i < vec.size(); ++i)
	{	// for each element, it gets the max of the length of the matching subarray
		n = std::max(n, LongestSubarray(vec, i + 1, sum - vec[index]));
	}

	if (n < 0)
		return n; // no matching subarray found, return -1

	return n + 1;  // natching subarray found, add 1 to the length of the subarray
}

// Use this function for recursiveness purpose
int LongestSubarrayWith0Sum(const std::vector<int>& A, size_t index)
{
	if (index == A.size())
		return 0;

	int nCount = -1;
	for (size_t i = index; i < A.size(); ++i)
	{	// from each index, we found the length of the matching subarray,
		//  store the biggist length
		nCount = std::max(nCount, LongestSubarray(A, i + 1, 0 - A[i]));
	}

	return nCount;
}

int LongestSubarrayWithZeroSum(std::vector<int>& A)
{
	return LongestSubarrayWith0Sum(A, 0);
}

int main()
{
	while (true)
	{
		int count = 0;
		std::cout << "Number of elements in the array: ";
		std::cin >> count;
		if (count <= 0)
			break;

		std::vector<int> vec(count);
		std::cout << "The array: ";
		for (int i = 0; i < count; ++i)
			std::cin >> vec[i];

		std::cout << "The longest subarry with zero sum is: " << LongestSubarrayWithZeroSum(vec) << std::endl;
	}
}
