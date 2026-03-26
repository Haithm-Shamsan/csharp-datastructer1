#pragma once
#include <iostream>

using namespace std;



template <class T>
class clsDynamicArray
{

protected:
	int _Size = 0;
	T* _TempArray;
public:
	T* OrignalArray;

	clsDynamicArray(int Size = 0)
	{
		if (Size == 0)
			Size = 0;

		_Size = Size;
		OrignalArray=new T[_Size];
	}
	~clsDynamicArray()
	{
		delete[] OrignalArray;
	}

	bool SetItem(int index, T vlaue)
	{
		if (index >= _Size || _Size < 0)
			return false;

		OrignalArray[index] = vlaue;
	}
	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0 ? true : false;
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout<<OrignalArray[i]<<" ";
		}
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];
		
		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}

		_Size = NewSize;

		delete[] OrignalArray;
		OrignalArray = _TempArray;






	}

	T Getitem(int ItemNumber)
	{
		return OrignalArray[ItemNumber];
	}

	void Revers()
	{
		T* _TempArray = new T[_Size];
		int counter = 0;

		for (int i = _Size-1; i >= 0; i--)
		{
			_TempArray[counter] = OrignalArray[i];
			counter++;
		}
	  delete[]	OrignalArray;
	  OrignalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OrignalArray;
		OrignalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index<0 || Index>_Size)
			return false;
		
		_Size--;

		_TempArray = new T[_Size];

		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}
		
		for (int i = Index+1; i < _Size+1; i++)
		{
			_TempArray[i - 1] = OrignalArray[i];
		}
		
		
		delete[] OrignalArray;
		OrignalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		 DeleteItem(0);
	}

	void DeleteLastItem()
	{
		 DeleteItem(_Size-1);
	}

	int Find(T value)
	{
		

		for (int i = 0; i < _Size; i++)
		{
			if (OrignalArray[i]==value)
			{
				return i;
			}
		}
		return -1;
		
	}

	bool DeleteItem(T value)
	{
		int item = Find(value);

		if (item == -1)
		{
			return false;
		}		

		DeleteItemAt(item);
		return true;
	 
	}

	bool InsertAt(int index, T value)
	{
		if (index<0 || index>_Size)
			return false;

		_Size++;
		_TempArray = new T[_Size];

		for (int i = 0; i < index+1; i++)
		{
			_TempArray[i] = OrignalArray[i];
		}

        _TempArray[index] = value;
		for (int i = index; i < _Size-1; i++)
		{
			

			_TempArray[i+1] = OrignalArray[i];

		}

		
		delete[] OrignalArray;
		OrignalArray = _TempArray;

	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	bool InsertBefore(int index, T value)
	{
		if (index<1)
		{
			return InsertAt(0, value);
		}
		else
		{
			return InsertAt(index-1, value);
		}
	}

	void InsertAtEnd(T value)
	{
		InsertAt(_Size , value);
	}

	bool InsertAfter(int index, T value)
	{
		
		if (index >= _Size)
		{
			return InsertAt(_Size-1 , value);
		}
			return InsertAt(index+1, value);
		
	}

};


