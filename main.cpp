#include <iostream>

using namespace std;

class MyIntArray
{
public:
	MyIntArray()
	{
		m_size = 0;
		m_data = nullptr;
		m_arraysCount++;
	}
	MyIntArray(unsigned int size)
	{
		SetSize(size);
		m_arraysCount++;
	}
	MyIntArray(unsigned int size, unsigned int defData)
	{
		SetSize(size);
		for (int i = 0; i < size; i++)
			m_data[i] = defData;
		m_arraysCount++;
	}
	~MyIntArray()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
		}
		m_arraysCount--;
	}

	void SetSize(unsigned int size)
	{ 
		if (m_data != nullptr)
			delete[] m_data;
		
		m_size = size;
		m_data = new int[m_size];
	}
	void SetData(unsigned int pos, int data)
	{
		if (pos >= 0 && pos < m_size)
		{
			m_data[pos] = data;
		}
	}
	static const int GetArraysCount() { return m_arraysCount; }

private:
	int* m_data;
	unsigned int m_size;

	static int m_arraysCount ;
};
//Static variable initialization
int MyIntArray::m_arraysCount = 0;

int main()
{
	MyIntArray arr1;
	arr1.SetSize(2);
	arr1.SetData(0, 10);
	arr1.SetData(1, 30);

	MyIntArray arr2(2);
	arr2.SetData(0, 40);
	arr2.SetData(1, 50);

	MyIntArray arr3(5, 60);

	cout << MyIntArray::GetArraysCount() << endl;
	{
		MyIntArray arr4;
		cout << MyIntArray::GetArraysCount() << endl;
	}
	cout << MyIntArray::GetArraysCount() << endl;

	return 0;
}
