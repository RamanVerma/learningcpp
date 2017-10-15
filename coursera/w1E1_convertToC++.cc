/* Week 1 Exercise 1
 * Convert this program to C++
 * * change to C++ io
 * * change to one line comments
 * * change defines of constants to const
 * * change array to vector<>
 * * inline any short function
 *
 * #include <stdio.h>
 * #define N 40
 *
 * void sum(int*p, int n, int d[])
 * {
 * int i;
 * *p = 0;
 * for(i = 0; i < n; ++i)
 * *p = *p + d[i];
 * }
 *
 * int main()
 * {
 * int i;
 * int accum = 0;
 * int data[N];
 * for(i = 0; i < N; ++i)
 * data[i] = i;
 * sum(&accum, N, data);
 * printf("sum is %d\n", accum);
 * return 0;
 * }
 */

#include <iostream>
#include <vector>

const int N=40;
using namespace std;

/*
 * adds up the elements of a vector of integers
 * @param p [in, out] pointer to int variable to store the sum
 * @param d [in] const reference to vector containing int data
 */
void
sum(int *p, const vector<int>& d)
{
	*p = 0;
	for (auto i = d.begin(); i != d.end(); i++) {
		*p += *i;
	}
}

int
main()
{
	int accum = 0;
	vector<int> data;
	for (int i = 0; i < N; i++) {
		data.push_back(i);
	}
	sum(&accum, data);
	cout << "Sum is " << accum << endl;
	return 0;
}
