LongestSubarryWithZeroSum: LongestSubarryWithZeroSum.o
	g++ -g -o LongestSubarryWithZeroSum.exe LongestSubarryWithZeroSum.o -pthread    

LongestSubarryWithZeroSum.o: LongestSubarryWithZeroSum/LongestSubarryWithZeroSum.cpp
	g++ -g  -c -pthread LongestSubarryWithZeroSum/LongestSubarryWithZeroSum.cpp
