
# Day - 2

### memcpy (15m)
* **기능** : src가 가리키는 곳부터 n 바이트 만큼 dest가 가리키는 곳에 복사

* **헤더파일** : string.h

* **형태**

```c
void *memcpy(void *dest, const void *src, size_t n)
void *memcpy(데이터가 복사될 곳의 주소, 복사할 데이터가 위치한 주소,  복사할 바이트 )
```

* **return**<br/>
dest<br/>

* **설명**<br/>
```c
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
    //void * 형태의 dest와 src를 unsigned char 형태로 변형
		count++;
	}
	return (dest);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
https://hand-over.tistory.com/49<br/>
https://modoocode.com/77<br/>
https://m.blog.naver.com/PostView.nhn?blogId=cestlavie_01&logNo=220903294178&proxyReferer=https:%2F%2Fwww.google.com%2F<br/>
https://www.it-note.kr/64<br/>

### memccpy (10m)
* **기능** : 특정 문자까지 데이터 복제

* **헤더파일** : string.h

* **형태**

```c
void *memccpy(void *dest, const void *src, int c, size_t n)
void *memccpy(데이터가 복사될 곳의 시작 주소, 데이터를 복사할 곳의 시작 주소, 찾을 문자, 바이트 수)
```

* **return**<br/>
성공시: 찾을 문자의 다음 주소<br/>
실패시: 0<br/>

* **설명**<br/>

```c
#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest) = *((unsigned char *)src + count);
    //형변환 후 데이터 복사 진행
		dest++;
		if (*((unsigned char *)src + count) == (unsigned char)c)
			return (dest);
      //
		count++;
	}
	return (0);
}
```

* **오류**<br/>
아래 사진에서 a를 src, b를 dest라 가정한다. 이 경우는 dest와 src의 메모리가 겹치 경우를 전제로 진행하게되며 src와 dest의 주소가 변함에 따라 src는 변형된 dest의 값을 참조하게 되며 src와 dest의 메모리가 1 바이트 차이가 나게될 경우 같은 값으로 초기화가 진행된다. <br/>
![스크린샷, 2020-12-23 20-02-36](https://user-images.githubusercontent.com/48250370/102989957-e5847080-4559-11eb-87a7-afd0e8282142.png)<br/>

* **참고자료**<br/>
https://www.it-note.kr/66<br/>

### memccpy (30m)
* **기능** : src가 가리키는 곳부터 n 바이트만큼 dest가 가리키는 곳에 복사

* **헤더파일** : string.h

* **형태**

```c
void *memmove(void *dest, const void *src, size_t n)
void *memmove(데이터가 복사될 곳의 주소, 복사할 데이터가 위치한 주소,  복사할 바이트 )
```

* **return**<br/>
dest<br/>

* **설명**<br/>
이전 memcpy 함수에서 설명했듯이 dest와 src 사이에서 발생할 수 있는 overlap 현상을 방지하기위해 구현
되었다. src와 dest 주소값을 비교하여 다르게 계산을 진행한다.<br/>
```c
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	tmp = dest;
  //overlap 현상을 방지하기위해 조건 설정 필요
	if (dest < src)
	{
		while (count < n)
		{
			*(tmp + count) = *((unsigned char *)src + count);
			count++;
		}
		return (dest);
	}
  //dest의 주소값이 src의 주소값보다 뒤에 있는 경우 진행(dest와 src의 메모리가 겹치는 경우 해당)
	while (count++ < n)
		*(tmp + n - count) = *((unsigned char *)src + n - count);
	return (dest);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
https://blog.naver.com/sharonichoya/220510332768<br/>

### memchr (10m)
* **기능** : 특정 문자가 위치 찾기

* **헤더파일** : string.h

* **형태**

```c
void *memchr(const void *s, int c, size_t n)
void *memchr(문자열의 시작 주소, 찾을 문자, 바이트 수)
```

* **return**<br/>
성공시: 문자를 찾은 메모리의 주소<br/>
실패시: 0<br/>

* **설명**<br/>

```c
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	count;

	count = 0;
	while (count++ < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
https://modoocode.com/92<br/>
https://badayak.com/4309<br/>

### memcmp (30m)
* **기능** : 입력받은 두 문자열을 비교

* **헤더파일** : string.h

* **형태**

```c
int memcmp(const void *s1,const void *s2, size_t n)
int memcmp(문자열1, 문자열2, 바이트 수)
```

* **return**<br/>
n이 0인 경우: 0<br/>
그 외: 비교한 두 문자열의 데이터 차이<br/>

* **설명**<br/>

```c
#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			count;
	int				result;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)//|| (*tmp1 == 0 && *tmp2 == 0))
		return (0);
	count = 0;
	while (count++ < n)
	{
		if (*tmp1 != *tmp2)
			break ;
		tmp1++;
		tmp2++;
	}
	return ((int)(*tmp1 - *tmp2));
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
https://modoocode.com/84<br/>
https://ehpub.co.kr/memcmp-%ED%95%A8%EC%88%98/<br/>
https://reakwon.tistory.com/88<br/> 

### 학습 내용에 대한 개인적인 총평
> 오늘 구현함수들은 바이트단위의 메모리 연산을 위주로 기능하게 된다. 구현에 있어 man 명령어를 사용하여 함수의 설명과 기본형태, return 값에 대> 해 정리하였지만 입력받는 주소값의 경우가 NULL 인 경우에 대한 자세한 설명이 부족하다고 많이 느꼈다. 이후 additional 함수 구현에 있어 현재 > 작성하고 있는 함수들을 이용하는데 있어 좀더 세부적인 테스트 케이스를 수집하여 이를 테스트 프로그램할 필요성이 있다.

### 다음 학습 계획
1. strlen, strlcpy, strlcat, strchr, strrchr, strnstr, strncmp, atoi ...<br/>
2. makefile<br/>
3. 기본함수 예외처리 추가 확인<br/>
