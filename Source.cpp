#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//I have listed some interesting things while studying c++
	//-----------------------------------------------------------------------------------------------
	//Fun Fact 1:
	//C++ does not do any boundary checks for raw arrays
	int array[6] = {0};
	array[10] = 1;		//It is stored 20bytes after the element of array[5]'s offset
	array[-3] = 2;		
	cout << array[10] << " " << array[-3] << '\n';	//This prints 1 2...Well... it does compile!

	//-----------------------------------------------------------------------------------------------
	//Fun Fact 2: Another way for calling an element
	//Guess what 5[array]  is
	array[5] = 10;
	cout << "5[array] is " << 5[array] << " and array[5] is " << array[5] << '\n';
	cout << "5[array] is equivalent to array[5]!" << '\n';

	//-----------------------------------------------------------------------------------------------
	/*Fun Fact 3: How a float is stored in c++
	Float is 4 bytes(32 bits).

	 s	 exp	    xxx
	|1|---8---|------23------|

	i) The leftmost bit(s) tells the sign of the number
	ii) The next 8 bits(exp) determines the power of 2
	iii) Rightmost 23 bits(xxx) is the number after the decimal point

	How it is constructed : 
	(-1)^s * (1.xxx) * 2^(exp - 127)
	*/

	//-----------------------------------------------------------------------------------------------
	//Fun Fact 4: Having some fun with pointers
	int i = 5;
	float f = *(float*)&i;
	//(*float) pretends it is a float pointer while pointing to the address of i
	//*(*float) dereferences the pointer 

	//Fun Fact 5 : Having fun with pointers in array
	//Similarly, we could play with it in an array
	int arr[5] = {0};
	arr[3] = 128;
   
	((short*)arr)[7] += 1;
	
   cout << arr[3];
	/* Surprisingly, arr[3] becomes 65664 from 128. How?????
	If we expand arr[3] into bits,
   arr[3] : 80 00 00 00
   If we do ((short*)arr)[7] += 1, arr[3] would change to
   arr[3] : 80 00 01 00
   However, it is stored as little endian format, which means the number we get is 0x 00 01 00 80 = 65664
	
   I have heard that this type of array manipulation is not recommended
   , but it was a fun way to learn how pointers of difffernt types work.
	*/
	return 0;
}