/*- 
- 1 Ŭ������ �̸��� SimpleVector��� �մϴ�.
- 2 Ÿ�Կ� �������� �ʰ� �����͸� ������ �ִ� �迭�� ��������� �����ϴ�.
- 3 �����ڴ� �Ʒ��� ���� ���� �մϴ�.
- 4 �⺻ �����ڴ� ũ�Ⱑ 10�� �迭�� ����ϴ�.
- 5 ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� ����ϴ�.
- 6 �Ʒ��� ���� ����Լ��� ���� �մϴ�.
- 7 push_back  ���ڷ� ���� ���Ҹ�  �� �ڿ� �߰� �մϴ�.��ȯ���� �����ϴ�.
   �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð�� �ƹ� ���۵� ���� �ʽ��ϴ�.
- 8 pop_back�� ������ ������ ���Ҹ� ���� �մϴ�.
    ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������, ���� �� ��ȯ���� �����ϴ�.
- 9 size�� ���ڰ� ���� ���� ������ ������ ��ȯ�մϴ�.
- 10 capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.
*/


// Ÿ�Կ� �������� �ʴ� > �������� �迭�� �������Ѵ� > �����Ҵ��� �ؾ��� >> �ɹ������� �����͸� ��������Ѵ�

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;    //���� ������ ����
	int currentCapacity;  // ���� �迭�� ũ��
	void resize()
	{

	}
public:
	SimpleVector()
	{
		currentCapacity = 10;
		currentSize = 0;
		data = new T[currentCapacity];
	}
	SimpleVector(int capacity)
	{
		capacity = currentCapacity;
		currentSize = 0;
		data = new T[currentCapacity];
	}
	
	void push_back(const T& value)
	{
		if (currentSize < currentCapacity) //�迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð�� ���۾��ϰ� ¥��
		{
			data[currentSize] = value;
			currentSize++;
			cout << "�� �߰� �Ϸ�! : " << value << "���� �迭 ũ��: " << currentSize << endl;
		}
		else 
		{
			cout << "�迭 �뷮�� �ʰ��Ǿ����ϴ�!" << endl;
		}
			
	}
	void pop_back() // ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ����, if���� �����Բ�
	{
		if (currentSize > 0)
		{
			cout << "�� ���� �Ϸ�!" << data[currentSize - 1] << endl;
			currentSize--;
			cout << "���� �迭 ũ��" << currentSize << endl;
		}
		else
		{
			cout << "������ ���� �����ϴ�!" << endl;
		}
	
	}
	
	int size() const 
	{
		return currentSize;
	}

	int capacity() const 
	{
		return currentCapacity;
	}

	~SimpleVector()
	{
		delete[] data;
	}
};

int main()
{
	SimpleVector<int> vec(3);

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	cout << "���� ��� Size:" << vec.size() << endl;
	cout << "���� ��� capacity: " << vec.capacity() << endl;
}

// ���̵�� 
// 
// 
// 
// �߰��� �����ҷ��� �ٿ��µ� ��°������ ���� �����ʴ´�.
// 
// 
//