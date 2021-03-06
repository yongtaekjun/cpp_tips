// number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <set>
#include <iostream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <bitset>


#include "test_number_format.h"
using namespace std;




#include <stdio.h>
#define LEN 9

void quick_sort(int num[], int start, int end);
void display_array(int num[], int len);

void test_quick_sort(void) {

	int testArr[] = { 45,24,54,37, 123, 88, 66, 35, 9,18 };

	display_array(testArr, LEN);

	quick_sort(testArr, 0, LEN - 1);
}

void quick_sort(int numbers[], int start, int end) {
	int left, right, pivot;
	int tempValue; 
	char stopper;

	if (start >= end) return;

	left = start + 1;
	right = end;
	pivot = numbers[start]; // you can decide any where.
//	cout << "P: " << pivot << endl;
//	for (int i = 0; i < start; i++) cout << "\t"; cout << "\tS" << start << "\n";
//	for (int i = 0; i < left ; i++) cout << "\t"; cout << "\tL" << left << "\n";
//	for (int i = 0; i < right; i++) cout << "\t"; cout << "\tR" << right << "\n";
//	for (int i = 0; i < end;   i++) cout << "\t"; cout << "\tE" << end << "\n";

	//cout << "S: " << start << " E: " << end << " P: " << pivot << " L: " << left << " R: " << right <<"\n";

	do {
		cout << "P: " << pivot << endl;
		for (int i = 0; i < start; i++) cout << "\t"; cout << "\tS" << start << "\n";
		for (int i = 0; i < left; i++) cout << "\t"; cout << "\tL" << left << "\n";
		for (int i = 0; i < right; i++) cout << "\t"; cout << "\tR" << right << "\n";
		for (int i = 0; i < end; i++) cout << "\t"; cout << "\tE" << end << "\n";
		display_array(numbers, LEN);
		while (numbers[left] < pivot) left++;
		while (numbers[right] > pivot) right--;
		// swap left and right
		if (left < right) {
			tempValue = numbers[right];
			numbers[right] = numbers[left];
			numbers[left] = tempValue;
		}
		getc(stdin);
	} while (left < right);

	numbers[start] = numbers[right];
	numbers[right] = pivot;

	// display pivot
	display_array (numbers, LEN);  
	quick_sort(numbers, start, right - 1);
	quick_sort(numbers, right + 1, end); 
}


void display_array(int num[], int len) {
	int i;
	for (i = 0; i<len; i++) {
		cout << std::setw(8) << num[i] ;
	}
	cout << "\n\n";
}


int test_display_number_as_binary () {
	int input;

	std::cout << "Enter decimal number: ";
	std::cin >> input;

	std::cout << " Oct: " << std::oct << input << "\n";
	std::cout << "Decimal: " << std::dec << input << "\n";
	std::cout << "Hexa Decimal: " << std::hex << input << "\n";
	std::cout << "Bynary: " << bitset<8>(input) << "\n";
	return 0;
}


int main()
{
	test_quick_sort();
    return 0;
}
/*

Algorithm for Quick Sorting

Summary : Define a certain number(pivot value) and grouping smaller numbers and bigger.
1. Define a pivot value from the group values (array, vector, list, map ,.... )
2. Define start and end index as a range;
   (S: Start, E: End, L: Left, R: Right, P: Pivot )

S   L                   P                           R
45, 39, 98, 15, 52, 44, 33, 28, 40, 38, 77, 68, 11, 43

3. Increase Left  index while the value[  Left ] < Pivot
4. Decrease Right index while the value[ Right ] > Pivot

S   L                   P                       R
45, 39, 98, 15, 52, 44, 33, 28, 40, 38, 77, 68, 11, 43

5. Swapping Left and Right
S   L                   P                       R
45, 11, 98, 15, 52, 44, 33, 28, 40, 38, 77, 68, 39, 43

6. Goto step 3 while Value[Left] > Value[Right]

S    --->L               P   R<------------------
45, 11, 98, 15, 52, 44, 33, 28, 40, 38, 77, 68, 39, 43

S        L               P   R
45, 11, 28, 15, 52, 44, 33, 98, 40, 38, 77, 68, 39, 43

S        ------> L      P   R
45, 11, 28, 15, 52, 44, 33, 98, 40, 38, 77, 68, 39, 43

11, 28, 98, 15, 52, 44, 33, 39, 40, 38, 77, 68, 45, 43

11, 28, 33, 15, 52, 44, 98, 39, 40, 38, 77, 68, 45, 43

Left will stay 52, Right 15,

Swap the value[right] and pivot when left < Right
eg: 15 <---> 33.

11, 28, 15, 33, 52, 44, 98, 39, 40, 38, 77, 68, 45, 43

Then, the left group of pivot has smaller value and other side has bigger.

Sort again against left group and right group each;
If total element for sort is 1, then it is done.

Caution: 
1. Except the pivot as a target.
2. That is why I set the pivot = value[start];
*/