package main

import "fmt"

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetLongest(vec []int, start int) int {
	sum := 0
	longest := 0
	for i := start; i < len(vec); i++ {
		sum += vec[i]
		if sum == 0 {
			longest = i - start + 1
		}
	}

	return longest
}

func LongestSubarrayWithZeroSum(A []int) int {
	longest := 0

	for i := 0; i < len(A); i++ {
		longest = max(longest, GetLongest(A, i))
	}

	return longest
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the array: ")

		fmt.Println("The longest subarray with zeor sum is ", LongestSubarrayWithZeroSum(vec))
	}
}
