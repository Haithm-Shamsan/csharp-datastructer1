#pragma once
#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

template<class T>
class clsMyStackArr:clsMyQueueArr<T>
{
protected:
	clsMyQueueArr<int>_MyList;
	public:

		void push(T Item)
		{
			_MyList.push(Item);

		}

		T Top()
		{
			return _MyList.front();

		}

		T Bottom()
		{
			return _MyList.back();

		}
	
};

