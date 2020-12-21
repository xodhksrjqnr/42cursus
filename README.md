# Day - 1

<br/>

> **학습 날짜 : 2020-12-21(월)**
>
> **학습시간 : 14:00 ~ 21:00(자가)**
>
> **학습 범위 및 주제 : libft**
> * memset
> * bzero
>
> **동료 학습 방법 : x**
>
> **학습 목표 : libft 를 풀기위한 기초지식을 습득하고 습득한 지식을 통해 프로그램 개발**

<br/>

## 상세 학습 내용

### memset (1h)
* **기능** : 메모리의 내용을 원하는 크기만큼 특정값으로 초기화

* **헤더파일** : memory.h , string.h

* **형태**

```c
void *memset(void *s, int c, size_t n)
void *memset(대상의 시작 주소, 설정값, 크기)
```

* **return**<br/>
성공시 : 초기화된 대상의 시작 주소(s)를 반환한다.<br/>
실패시 : null(확인 필요)<br/>

* **설명**<br/>
아래는 memset 함수를 구현한 예제이다.
```c
#include <stddef.h> //size_t 타입을 사용하기 위한 헤더

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count; //size_t의 경우 부호 없는 정수 자료형이므로 이와 동일하게 타입을 설정

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s + count) = (unsigned char)c;
                 //포인터 연산을 위해 void * -> unsigned char * / int -> unsigned char 로 형변환
                 //count를 이용해 주소를 연산하여 s의 시작 주소를 변경하지 않고 그대로 유지
		count++;
	}
	return (s);
}
```

* **참고자료**<br/>
https://dojang.io/mod/page/view.php?id=287<br/>
https://blockdmask.tistory.com/441<br/>

### bzero (30m)
* **기능** : 메모리의 내용을 원하는 크기만큼 0으로 초기화

* **헤더파일** : strings.h

* **형태**

```c
void bzero(void *s, size_t n)
void bzero(대상의 시작 주소, 크기)
```

* **return**<br/>
성공시 : None<br/>
실패시 : None<br/>

* **설명**<br/>
bzero 함수의 경우 이전에서 설명한 memset 함수에서 매개변수 c를 0으로 넘겨준 것과 같다.<br/>
(= memset(void *s, 0, size_t n) )

```c
#include <stddef.h> //size_t 타입을 사용하기 위한 헤더

void	ft_bzero(void *s, size_t n)
{
	size_t		count; //size_t의 경우 부호 없는 정수 자료형이므로 이와 동일하게 타입을 설정

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s + count) = 0;
                 //포인터 연산을 위해 void * -> unsigned char * 로 형변환
		count++;
	}
}
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; memset 함수와의 차이는 return 값이 없으며 무조건 0으로 대상을 초기화 한다는 점이다.

* **참고자료**<br/>
https://yaaam.tistory.com/entry/CC-bzero-%EC%99%80-memset%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90

<br/>

## 학습 내용에 대한 개인적인 총평

> 오늘은 스터디를 진행하며 libft subject에서 사용된 애매한 표현과 이해가 잘 안되는 부분에 대해 논의를 진행하여 이에 대해 이해하는
> 것에 중점을 두었다. 이후 memset, bzero 함수를 구현하며 각 함수의 기능 및 연산 과정에 대해 이해할 수 있었다. 하지만, void 포인터를
> 연산하기위해 unsigned char 형으로 형변환 점에 있어 좀 더 깊은 이해가 필요하며, size_t 타입에 대한 정리가 필요하다.

<br/>

## 다음 학습 계획

1. size_t 타입에 대한 이해 및 정리
2. unsigned char 형으로 형변환하는 점에 대한 이해 및 정리
3. 위 두가지 경우를 연결하여 memset의 int c 매개변수에 0이외의 값을 넣는 경우 발생하는 문제 정리
4. memcpy, memccpy, memmove, memchr 함수 구현(예상)

<br/>
