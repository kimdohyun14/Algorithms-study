#include <iostream>
#include <algorithm>
using namespace std;

// �ݹ� �Լ� ������ �Լ� ��ü�� ����Ͽ� ����

struct Functor1
{
	void operator()(int n)
	{
		cout << n << " ";
	}
};

struct Functor2
{
	void operator()(int n)
	{
		cout << n * n << " ";
	}
};

struct Functor3
{
	void operator()(int n)
	{
		cout << "���� : " << n << endl;
	}
};

int main()
{
	int arr[5] = { 10,20,30,40,50 };

	for_each(arr, arr + 5, Functor1()); // �ӽ� �Լ� ��ü(Functor1())�� ����� �Լ��� ����
	cout << endl << endl;

	for_each(arr, arr + 5, Functor2()); // �Լ��� �ƴ� �Լ� ��ü�� �����ߴٴ� ���� ����Ʈ
	cout << endl << endl;

	for_each(arr, arr + 5, Functor3());
	cout << endl << endl;

	return 0;
}