# Day - 1

### memset (30h)
* **기능** : 메모리의 내용을 원하는 크기만큼 특정값으로 초기화

* **헤더파일** : memory.h , string.h

* **형태**

```c
void *memset(void *s, int c, size_t n)
void *memset(대상의 시작 주소, 설정값, 크기)
```

* **return**<br/>
초기화된 대상의 시작 주소(s)를 반환한다.<br/>

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

* **오류**<br/>
아래는 memset 함수 구현시 void 포인터 연산에 대한 이해가 부족하여 발생한 문제이다.<br/>
![memset_error](https://user-images.githubusercontent.com/48250370/102788204-9d444180-43e5-11eb-9763-561b8424c38f.png)<br/>
아래 코드의 경우 void * 형태인 s에 count를 증가시키는 연산을 실행하여도 void 는 바이트를 알 수 없어 주소를 찾아갈 수 없다.<br/>
```c
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*(s + count) = c;
		count++;
	}
	return (s);
}
```
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 따라서 설명에 나와있는 코드와 같이 s의 형변환이 필요하며 c의 경우 또한 타입을 맞춰주기 위해 동일한 타입으로 형변환한다.<br/>

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
None<br/>

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

* **오류**<br/>
아래는 memset 함수와 마찬가지로 bzero 함수 구현시 void 포인터 연산에 대한 이해가 부족하여 발생한 문제이다.<br/>
![bzero_error](https://user-images.githubusercontent.com/48250370/102789300-45a6d580-43e7-11eb-819c-eeea34b8b5b6.png)<br/>
해결 방법은 memset 함수 때와 동일하다.<br/>
```c
#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*(s + count) = 0;
		count++;
	}
}
```

* **참고자료**<br/>
https://yaaam.tistory.com/entry/CC-bzero-%EC%99%80-memset%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90

<br/>
