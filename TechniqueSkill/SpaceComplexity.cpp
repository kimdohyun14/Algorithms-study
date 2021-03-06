/*
	#공간 복잡도란?
	프로그램을 실행시킨 후 완료하는 데 필요로 하는 자원 공간의 양
	알고리즘이 사용하는 메모리 공간

	총 공간 요구 = 고정 공간 요구 + 가변 공간 요구

	고정 공간
		입력과 출력의 횟수나 크기와 관계없는 공간의 요구 (코드 저장 공간, 단순 변수, 고정 크기의 변수, 상수)

	가변 공간
		해결하려는 문제의 특정 인스턴스에 의존하는 크기를 가진 구조화 변수들을 위해서 필요로 하는 공간
		함수가 순환 호출을 할 경우 요구되는 추가 공간
		동적으로 필요한 공간

	#시간 복잡도와 공간 복잡도
	시간 복잡도는 얼마나 빠르게 실행되는지?
	공간 복잡도는 얼마나 많은 자원이 필요한지?

	좋은 알고리즘은 시간도 적게 걸리면서 자원의 사용도 적은 것이 좋다.
	다만, 둘의 관계는 tradeOff 관계이므로 적절히 타협해서 사용하는 것이 좋다.

	#코딩사이트에서 메모리 제한
	int 1,000,000 -> 4MB (기준)
	int a[1000][1000] -> 4MB
	long long -> 4MB * 2 = 8MB
	char -> 4MB / 4 = 1MB

	512MB 메모리 제한이면
	512 * 1000 * 1000 => 512 * 1000 * 1000 / 4 = 128,000,000 (1억 2천 8백만)

	256MB 메모리 제한이면
	256 * 1000 * 1000 => 256 * 1000 * 1000 / 4 = 64,000,000 (6천 4백만)

	128MB 메모리 제한이면
	128 * 1000 * 1000 => 128 * 1000 * 1000 / 4 = 32,000,000 (3천 2백만)

	동적으로 메모리를 사용하는 vector,set,map 등의 STL 자료구조들은 조금 복잡하다.
	그래서 보통 최악의 경우 자료구조에 몇개 정도의 데이터가 들어가는지 계산하면 되고,
	set, map등 복잡한 자료구조의 경우 단순히 데이터 외에도 여러 변수들이 같이 저장되므로 여유를 줘야한다.
*/

#include <iostream>
using namespace std;

// 공간 복잡도 O(N)
// n이 1이하일 때까지 함수가 재귀적으로 호출되므로 스택에는 n부터 1까지 모두 쌓이게 된다.
int factorial(int n)
{
	if (n > 1) return n * factorial(n - 1);
	else return 1;
}

// 공간 복잡도 O(1)
int factorial(int n)
{
	int fac = 1;
	for (int i = 1; i <= n; i++)
	{
		fac = fac * i;
	}
	return fac;
}
