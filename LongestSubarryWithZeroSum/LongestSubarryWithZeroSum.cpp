// LongestSubarryWithZeroSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int LongestSubarray(const std::vector<int>& A, size_t index)
{
	int longest = 0;
	int sum = 0;
	for (size_t i = index; i < A.size(); ++i)
	{
		sum += A[i];
		if (sum == 0)
			longest = static_cast<int>(i - index + 1);
	}

	return longest;
}

int LongestSubarrayWithZeroSum(std::vector<int>& A)
{
	int longest = 0;
	for (size_t i = 0; i < A.size(); ++i)
		longest = std::max(longest, LongestSubarray(A, i));

	return longest;
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
