/*- 
- 1 클래스의 이름은 SimpleVector라고 합니다.
- 2 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
- 3 생성자는 아래와 같이 구현 합니다.
- 4 기본 생성자는 크기가 10인 배열을 만듭니다.
- 5 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
- 6 아래와 같은 멤버함수를 구현 합니다.
- 7 push_back  인자로 받은 원소를  맨 뒤에 추가 합니다.반환값은 없습니다.
   배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
- 8 pop_back은 벡터의 마지막 원소를 제거 합니다.
    만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
- 9 size는 인자가 없고 현재 원소의 개수를 반환합니다.
- 10 capacity 현재 내부 배열의 크기를 반환합니다.
*/


// 타입에 의존하지 않는 > 가변길이 배열을 만들어야한다 > 동적할당을 해야함 >> 맴버변수에 포인터를 더해줘야한다

#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;    //현재 원소의 개수
	int currentCapacity;  // 현재 배열의 크기
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
		if (currentSize < currentCapacity) //배열의 크기가 꽉 찼는데 원소가 더 들어올경우 동작안하게 짜기
		{
			data[currentSize] = value;
			currentSize++;
			cout << "값 추가 완료! : " << value << "현재 배열 크기: " << currentSize << endl;
		}
		else 
		{
			cout << "배열 용량이 초과되었습니다!" << endl;
		}
			
	}
	void pop_back() // 만약 제거할 원소가 없다면 아무 동작도 하지 않음, if조건 나가게끔
	{
		if (currentSize > 0)
		{
			cout << "값 삭제 완료!" << data[currentSize - 1] << endl;
			currentSize--;
			cout << "현재 배열 크기" << currentSize << endl;
		}
		else
		{
			cout << "삭제할 값이 없습니다!" << endl;
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

	cout << "최종 출력 Size:" << vec.size() << endl;
	cout << "최종 출력 capacity: " << vec.capacity() << endl;
}

// 아이디어 
// 
// 
// 
// 중간에 점검할려고 붙였는데 출력결과물이 맘에 들지않는다.
// 
// 
//