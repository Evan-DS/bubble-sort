#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_ARRAY_SIZE = 1;		
int myLength = 0;							
int arraySize = DEFAULT_ARRAY_SIZE;		

float* myArray;

template <typename T>
T bubbleSort4(T* array, int length)
{
	if (length % 2 == 0)
	{
		T val1 = array[length / 2];
		T val2 = array[length / 2 - 1];
		T medianVal = (val2 + val1) / 2;
		return medianVal;
	}
	else
	{
		return array[length / 2];
	}
}

template <typename T>
void bubbleSort3(T* array, int length, bool ascending)
{
	if (length <= 1)
	{
		return;
	}

	{
		for (int y = 0; y < (length - 1); y++)
		{
			if (array[y - 1] > array[y] && ascending == true)
			{
				T temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
			}
			else if (array[y + 1] > array[y] && ascending == false)
			{
				T temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
			}
		}
	}

	bubbleSort3(array, length - 1, ascending);
}


template <typename T>
void bubbleSort2(T* array, int length)
{
	if (length <= 1)
	{
		return;
	}

	{
		for (int y = 0; y < (length - 1); y++)
		{
			if (array[y + 1] > array[y])
			{
				T temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
			}
		}
	}

	bubbleSort2(array, length - 1);
}

template <typename T>
void bubbleSort1(T* array, int length)
{
	for (int x = 0; x < (length - 1); x++)
	{
		for (int y = 0; y < (length - 1) - x; y++)
		{
			if (array[y + 1] > array[y])
			{
				T temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
			}
		}
	}
}

template <typename T>

void resizeArray(T*& array, int& length, int size)
{
	length++;

	if (length == size)
	{
		T* tempArray = new T[size + 1];

		for (int x = 0; x < length; x++)
		{
			tempArray[x] = array[x];
		}

		delete[] array;
		array = tempArray;

		size += 1;
	}
}

int main()
{
	string input;
	float newInput;

	while (input != "end")
	{
		cout << "Please input a number...\n";
		cin >> input;
		newInput = atof(input.c_str);
		cout << "Type \"end\" to stop inputting values.\n\n";

		resizeArray(myArray, myLength, arraySize);
		myArray[myLength] = newInput;
	}

	//bubbleSort3(myArray, myLength, false);
	//cout << bubbleSort4(myArray, myLength) << endl;

	for (int z = 0; z < myLength; z++)
	{
		cout << myArray[z] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}