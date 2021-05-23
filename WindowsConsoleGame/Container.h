/*
FILE: container.h
PROGRAMMER: Ken Gitlitz
DESCRIPTION: Defines a trivial container. 
LIMITATIONS: No way to remove data from the container.  
WHAT YOU CAN DO (NOT REQUIRED):
Create a function that removes the top item in the container.  
This function shoud be defined as:

	bool pop(); // returns true if an item was removed, false otherwise
	            // for example, returns false if the container is empty

	USAGE:

	obj.push(3); 
	obj.push(4); 
	obj.push(5); 

	obj.pop(); // removes last item pushed into the container

	for(int i = 0; i < obj.size(); i++)
	{
		cout << obj[i] << endl; // outputs 3 and 4
	}

	// empty the container:
	while(obj.pop() == true) {  }

	cout << obj.size() << endl; // should be zero 
*/

template<class T>
class container{
private: 

	static const int BUF_SIZE = 20; 

	T _a[BUF_SIZE];
	int _size; 

public:

	container(); 

	bool remove(int element);
	bool push(T data); 
	int size(); 

	T operator[](int index); 

}; 

template<class T>
container<T>::container()
{
	_size = 0;
}

template<class T>
bool container<T>::push(T data)
{
	if (_size < BUF_SIZE) // there is room 
	{
		_a[_size] = data;

		_size++; 

		return true;
	}

	return false; // all full, no room 
}

template<class T>
bool container<T>::remove(int index)
{
	// if index < 0 OR index >= size, return false
	if (index < 0 || index >= _size) return false;

	// delete the item at index
	delete _a[index];

	// shift all items over: keep shifting while index < (size - 1)
	while (index < _size - 1){
		_a[index] = _a[index+1];
		index++;
	}

	// decrement size of the container
	_size--;

	return true; // item removed OK
}


template<class T>
int container<T>::size()
{
	return _size; 
}

template<class T>
T container<T>::operator[](int index)
{
	return _a[index]; 
}