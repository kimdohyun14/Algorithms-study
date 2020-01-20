# 알고리즘 정복하기

* 좋은 개발자가 되기 위해 하루동안 학습한 알고리즘 내용이나 경험들을 기록을 통해 남긴다.
* 다양한 알고리즘을 통해서 탄탄한 기본기를 갖추는 것이 목표이다.
* 여기서의 내용은 알고리즘이여도 되고, 알고리즘을 풀 때 사용한 함수나 문법의 경험, 자료구조도 작성한다.
* 지금은 못하더라도 조급해지지 않고 꾸준히 열심히 하자!

작성하게 된 계기는 [namjunemy](https://github.com/namjunemy/TIL)의 Github를 보고 나도 작성하기로 했다.

# 다짐
* 중요한 것은 모르는 부분을 찾고자 할 때, 추가적인 검색의 비용이 들지 않도록 자세히 기록한다.
* 참고한 자료는 꼭 출처를 남기자.
* 어려워도 포기하지 말고 해보자.

# Algorithm
유한한 단계를 통해 문제를 해결하기 위한 절차나 방법을 말한다. <br>
`슈도코드` 의사코드로 흉내낸 코드 <br>
`순서도` 프로그램이나 작업의 진행흐름을 순서에 따라 여러가지 기호나 문자로 나타낸 지표

**성능 분석** <br><br>
1. `정확성` 얼마나 정확하게 동작하는가?
2. `작업량` 얼마나 적은 연산으로 원하는 결과를 얻어내는가?
3. `메모리사용량` 얼마나 적은 메모리를 사용하는가?
4. `단순성` 얼마나 단순한가?
5. `최적성` 더 이상 개선할 여지 없이 최적화되어있는가?

`시간 복잡도(TimeComplex)` 실제 걸리는 시간을 측정의 지표, 빅-오 표기법 사용 <br>
시간 복잡도를 계산할 때 가장 큰 영향력을 주는 `N`에 대한 항만을 표시한다.

![TimeComplex](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F260F4850559AB6672C45F1) <br>
출처: https://ledgku.tistory.com/33

`공간 복잡도(SpaceComplex)` 얼마나 메모리를 사용했는지에 대한 지표

## 1. 패턴 매칭 알고리즘
본문이 되는 string에서 특정한 string을 찾는 알고리즘 <br>
### 1.1. 무식한 방법(Brute Force)
본문 string을 처음부터 끝까지 차례대로 순회하면서 패턴 내의 문자들을 일일이 비교하면서 확인한다. <br>
본문의 string 길이가 M이고, 찾아야 할 패턴 string 길이가 N이면 <br>
최악의 시간 복잡도는 모든 위치에서 패턴을 비교해야하므로 `O(MN)`이 된다.
### 1.2. KMP 알고리즘
불일치가 발생한 텍스트 string 앞 부분에 어떤 문자가 있었는지 미리 알고 있으므로 불일치가 발생한 앞 부분에 대하여 다시 비교하지 않고 넘어간다. <br>

        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[] a b c d a b c e f
    
    인덱스 7에서 서로 매칭이 맞지 않기 때문에, 틀린 부분의 앞 부분에서 a b c 가 같음을 이용해서 다시 비교한다.
    
        0 1 2 3 4 5 6 7 8 9 
    T[] a b c d a b c d f f
    P[]         a b c d a b c e f (-> shift됨)
    
### 1.3. 보이어-무어 알고리즘
오른쪽에서 왼쪽으로 비교하는 생각의 전환 <br>
대부분의 상용 소프트웨어에서 채택하고 있는 알고리즘이라고 한다. <br><br>

패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하지 않는 경우 이동거리는 패턴의 길이 만큼 된다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y z w a p p l e
    P[]           a p p l e (패턴의 길이 만큼 이동)
    
패턴에 오른쪽 끝에 있는 문자가 불일치하고, 이 문자가 패턴 내에 존재하는 경우

        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[] a p p l e
    
    이 경우 아래와 같이 점프한다.
    
        0 1 2 3 4 5 6 7 8 9
    T[] f d y w a p p l e l
    P[]         a p p l e
    
    이렇게 점프한 뒤 인덱스 8부터 시작해서 4까지 하나씩 문자를 비교해서 맞는지 확인한다.
### 1.4. 카프-라빈 알고리즘

### 1.5. string 매칭 알고리즘 비교 표
찾고자 하는 string 패턴의 길이를 `M`, 총 string 길이를 `N`이라고 하면 <br>

알고리즘 종류 | 시간 복잡도
---|---
`Bruteforce` | O(MN)
`카프-라빈` | O(N)
`KMP` | O(N)
`보이어-무어` | O(N)보다 빠름, 단 최악의 경우 O(MN)
    
    

# C, C++
## 1. String
### 1.1. string::find 와 string::npos
`string::find` 찾는 문자열의 첫 번째 인덱스를 반환하는 함수 <br>
`string::npos` 찾는 문자열이 없는 경우에는 `string::npos`를 반환한다. <br>

```cpp
string str = "Hello World";
if(str.find("World") != string::npos)
{
  cout << "찾는 문자열이 있습니다. 해당 문자열의 시작 인덱스 번호는 << str.find("World") << "입니다. << endl;
}
else
{
  cout << "찾는 문자열이 없습니다." << endl;
}
```
### 1.2. C언어에서 string 처리
문자열을 배열 형태로 구현된 응용 자료형을 의미한다. <br>
문자배열에 string을 저장할 때는 항상 마지막에 끝을 표시하는 `\0` 문자를 넣어준다.

```c
char a1[] = {'a', 'b', 'c', '\0'};
char a2[] = "abc";
```
C언어에서는 string 처리를 위한 다양한 함수들을 제공한다. <br>
`strlen()` 문자열의 길이를 반환하는 함수 <br>
`strcpy()` 문자열을 복사하는 함수 <br>
`strcmp()` 문자열을 비교하는 함수 <br>

**string을 복사하는 알고리즘** <br><br>
src로부터 한 글자씩 읽어서 des에 한 글자씩 복사하는 방법
```c
void strcpy(char* des, char* src)
{
    while(*src != '\0')
    {
      *des = *src;
      src++;
      des++;
    }
    *des = '\0';
}
```
**string을 역순으로 바꾸는 방법** <br>
1. 자기 string을 직접 뒤집는 방법
2. 새로운 빈 string을 만들어서 소스의 뒤에서부터 읽어서 복사하는 방법

1번의 경우 `swap함수`를 위한 임시변수가 필요하고, Loop를 string의 길이의 반만큼 수행하면 된다. <br>
2번의 경우 뒤에서부터 읽는 방식이니, Loop를 string의 길이만큼 수행하면 된다. <br>

**string 비교** <br><br>
`strcmp()`함수를 이용한다.

strcmp에서 반환되는 값에 따라 다음과 같은 결과를 가진다. <br>
`0`이면 두 문자열은 서로 같은 문자열 <br> 
`-1`이면 문자열이 사전순으로 앞인 문자열 <br>
`1`이면 문자열이 사전순으로 뒤인 문자열 <br>

**string로 된 숫자를 정수로 변환하는 방법** <br><br>
C언어에서는 `atoi()` 함수가 제공된다. <br>

  
