
/******************************************************************************

 이번 프로젝트는 정수형 벡터 클래스 vector를 이용하여 대량의 정수형 값을 저장하고 있다가
 검색, 삭제, 추가 등의 기능을 수행하는 Conatiner 클래스를 작성하는 것이다.

 프로그램의 전체 구성도와 실행결과는 아래와 같다.

******************************************************************************/

// 대량의 데이터를 순서적으로 저장하고 있는 컨테이너 클래스
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Container {
private:
	vector<T> v;

public:
	void push(T value);	// value를 컨테이너에 삽입
	void add(T inc);		// 컨테이너에 삽입된 모든 원소에 inc를 더함
	bool get(int index, T& value);// 컨테이너의 index(배열처럼 0부터 시작) 위치에 있는 원소 값을 반환
	int  find(T value);	// value 값을 가진 원소의 인덱스를 리턴함
	bool remove(T value);	// value 값을 가진 원소를 삭제하고 true 리턴, 존재하지 않으면 false
	void print();			// 컨테이너에 삽입된 모든 원소를 순서적으로 출력
};

template<class T>
void Container<T>::push(T value) {
	v.push_back(value);
}


template<class T>
void Container<T>::add(T inc) {

	for (int i = 0; i < v.size(); i++) {
		v[i] += inc;
	}
}

template<class T>
bool Container<T>::get(int index, T& value) {
	//index의 값이 0보다 적거나 또는 벡터v의 원소의 개수와 같거나 크면
	if (index < 0 || index >= v.size())
		return false;
	else {
		//index 위치의 벡터v의 원소를 value에 저장하고
		value = v[index];
		return true; // 반환
		// 컨테이너의 index는 벡터의 index와 동일한 의미를 가진다.
	}
}

template<class T>
int Container<T>::find(T value) {
	/*
	for문을 이용하여
		value와 동일한 벡터 v의 원소를 만나면
			그 원소의 인덱스 값을 반환한다.
	value와 동일한 값을 찾지 못할 경우 -1을 리턴함
	*/

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == value)
			return i;
	}

	return -1;
}

template<class T>
bool Container<T>::remove(T value) {
	/* 벡터의 특정 원소를 삭제하기 위해선 iterator을 이용해야 한다.
	따라서 vector v의 iterator it 변수를 선언하고
	for 문을 이용하여 loop 돌면서 각각의 it에 대해
		*it와 value가 같은 값인 it를 찾아서
			v.erase(it)를 호출하여 해당 원소를 삭제하고,
			바로 true 리턴
	동일한 값을 하나도 찾지 못할 경우 false 반환
	*/ 

	for (auto it = v.begin(); it != v.end(); it++) {
		if (*it == value) {
			v.erase(it);
			return true;
		}
	}

	return false;
}

template<class T>
void Container<T>::print() {
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}

void test_int(int size) {
	Container<int> c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push(min + i);
	cout << "push: ";
	c.print();

	int value=0;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size / 2 << "): " << c.get(size / 2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	cout << "find(" << max << "): " << c.find(max) << endl;
	cout << "find(" << min - 1 << "): " << c.find(min - 1) << endl << endl;

	cout << "remove(" << mid << "): " << c.remove(mid) << endl;
	c.print();

	cout << "remove(" << max + 1 << "): " << c.remove(max + 1) << endl;
	c.print();

	c.add(100);
	cout << "add(100): ";
	c.print();
}



void test_string(int size) {

	/*
	위 템플릿 클래스를 활용하여 string 형으로 구체화된 Container 클래스 객체 변수 c를 선언하라.
		이 클래스는 문자열을 저장할 수 있는 container이다.
	*/
	Container<string> c;

		int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push("abc" + to_string(min + i));
	cout << "push: ";
	c.print();

	string value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size / 2 << "): " << c.get(size / 2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	value = "abc" + to_string(max);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl;
	value = "abc" + to_string(min - 1);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl << endl;

	value = "abc" + to_string(mid);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	value = "abc" + to_string(max + 1);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	c.add("def");
	cout << "add(\"def\"): ";
	c.print();

}


int main()
{
	cout << "Enter the number of elements : ";
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
	cout << endl << "STRING Test" << endl << endl;
	test_string(size);
	return 0;
}

/******************************************************************************
  프로그램 실행 결과
 ******************************************************************************
Enter the number of elements : 5

INTEGER Test

push: [0]105 [1]106 [2]107 [3]108 [4]109

get(2): true : 107
get(5): false : 107
get(-1): false : 107

find(109): 4
find(104): -1

remove(107): true
[0]105 [1]106 [2]108 [3]109

remove(110): false
[0]105 [1]106 [2]108 [3]109

add(100): [0]205 [1]206 [2]208 [3]209
******************************************************************************/