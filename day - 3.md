# Day - 3

### strlen (1m)
* **기능** : 입력받은 문자열의 길이 반환

* **헤더파일** : string.h

* **형태**

```c
size_t strlen(const char *s)
size_t strlen(대상 문자열의 시작 주소)
```

* **return**<br/>
문자열의 길이<br/>

* **설명**<br/>
```c
#include <stddef.h>

size_t		ft_strlen(const char *s)
{
	size_t		size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### tolower (1m)
* **기능** : 입력받은 문자가 대문자인 경우 소문자로 변환

* **헤더파일** : ctype.h

* **형태**

```c
int tolower(int c)
int tolower(문자)
```

* **return**<br/>
대문자인 경우 : 소문자 반환<br/>
그 외 : 입력 받은 문자 반환<br/>

* **설명**<br/>
```c
int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### toupper (1m)
* **기능** : 입력받은 문자가 소문자인 경우 대문자로 변환

* **헤더파일** : ctype.h

* **형태**

```c
int toupper(int c)
int toupper(문자)
```

* **return**<br/>
소문자인 경우 : 대문자 반환<br/>
그 외 : 입력 받은 문자 반환<br/>

* **설명**<br/>
```c
int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
```

* **오류**<br/>
noen<br/>

* **참고자료**<br/>
man<br/>

### isprint (1m)
* **기능** : 입력받은 문자가 출력 가능한 문자인지 판단

* **헤더파일** : ctype.h

* **형태**

```c
int isprint(int c)
int isprint(문자)
```

* **return**<br/>
출력가능한경우 : 0이 아닌 문자<br/>
출력불가능한경우 : 0<br/>

* **설명**<br/>
```c
int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
```

* **오류**<br/>
함수명 오류로 인한 컴파일 에러(isprint -> ft_isprint)<br/>

* **참고자료**<br/>
man<br/>

### isascii (1m)
* **기능** : 입력받은 문자가 아스키코드 범위 내에 있는지 판단

* **헤더파일** : ctype.h

* **형태**

```c
int isascii(int c)
int isascii(문자)
```

* **return**<br/>
범위내 : 0이 아닌 문자<br/>
범위밖 : 0

* **설명**<br/>
```c
int		ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### isalnum (1m)
* **기능** : 입력받은 문자가 알파벳이나 숫자인지를 판단

* **헤더파일** : ctype.h

* **형태**

```c
int isalnum(int c)
int isalnum(문자)
```

* **return**<br/>
알파벳이나 숫자인 경우 : 0이 아닌 문자<br/>
그 외 : 0

* **설명**<br/>
```c
int		ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### isdigit (1m)
* **기능** : 입력받은 문자(아스키코드)가 자인지를 판단

* **헤더파일** : ctype.h

* **형태**

```c
int isdigit(int c)
int isdigit(문자)
```

* **return**<br/>
숫자인 경우 : 0이 아닌 문자<br/>
그 외 : 0

* **설명**<br/>
```c
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### isalpha (1m)
* **기능** : 입력받은 문자가 알파벳인지를 판단

* **헤더파일** : ctype.h

* **형태**

```c
int isalpha(int c)
int isalpha(문자)
```

* **return**<br/>
알파벳인 경우 : 0이 아닌 문자<br/>
그 외 : 0

* **설명**<br/>
```c
int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### atoi (10m)
* **기능** : 문자를 숫자로 변환

* **헤더파일** : stdlib.h

* **형태**

```c
int atoi(const char *nptr)
int atoi(상수 문자열의 시작 주소)
```

* **return**<br/>
성공시 : 문자열 중 조건을 만족한 숫자 반환<br/>
실패시 : 0

* **설명**<br/>
```c
int		ft_atoi(const char *s)
{
	long long		total;
	int				flag;

	while (*s == ' ' || *s == '\t')
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}
	total = 0;
	while (*s >= '0' && *s <= '9')
		total = total * 10 + *s++ - 48;
	if (flag == 1)
		total *= -1;
	return ((int)total);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### strdup (5m)
* **기능** : 입력받은 문자열을 새로 할당한 메모리에 복사

* **헤더파일** : string.h

* **형태**

```c
char *strdup(const char *s)
char *strdup(복사할 상수 문자열의 시작 주소)
```

* **return**<br/>
성공시 : 복사된 문자열의 시작 주소<br/>
실패시 : 0

* **설명**<br/>
```c
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;
	int		size;

	size = 0;
	while (*(s + size))
		size++;
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### strchr (5m)
* **기능** : 문자열에서 입력받은 문자가 있는지 판단

* **헤더파일** : string.h

* **형태**

```c
char *strchr(const char *s, int c)
char *strchr(상수 문자열의 시작 주소, 찾으려는 문자(아스키코드))
```

* **return**<br/>
찾은 경우 : 문자열에서 발견된 위치의 주소 반환<br/>
찾지 못한 경우 : 0<br/>
찾고자하는 문자가 null인 경우 : 문자열의 마지막 주소(null 위치) 반환

* **설명**<br/>
```c
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### strrchr (5m)
* **기능** : 문자열에서 입력받은 문자가 마지막으로 나타나는 위치 파악

* **헤더파일** : string.h

* **형태**

```c
char *strrchr(const char *s, int c)
char *strrchr(상수 문자열의 시작 주소, 찾으려는 문자(아스키코드))
```

* **return**<br/>
찾은 경우 : 문자열에서 발견된 위치의 주소 반환<br/>
찾지 못한 경우 : 0<br/>
찾고자하는 문자가 null인 경우 : 문자열의 마지막 주소(null 위치) 반환

* **설명**<br/>
```c
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*location;

	location = NULL;
	while (*s)
	{
		if (*s == c)
			location = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (location);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
man<br/>

### calloc (5m)
* **기능** : malloc 함수와 거의 동일하며 malloc과는 다르게 할당된 메모리를 0으로 초기화

* **헤더파일** : stdlib.h

* **형태**

```c
void *calloc(size_t nmemb, size_t size)
void *calloc(할당할 바이트 수, 바이트 크기)
```

* **return**<br/>
성공시 : 0으로 초기화된 메모리의 시작 주소<br/>
실패시 : 0

* **설명**<br/>
```c
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	void	*tmp;
	size_t	count;

	if (!(result = malloc(nmemb * size)) || nmemb * size == 0)
		return (0);
	count = 0;
	tmp = result;
	while (count < nmemb * size)
	{
		*((unsigned char *)tmp + count) = 0;
		count++;
	}
	return (result);
}
```

* **오류**<br/>
none<br/>

* **참고자료**<br/>
https://dojang.io/mod/page/view.php?id=530

### 학습 내용에 대한 개인적인 총평
> 오늘 구현함수들은 바이트단위의 메모리 연산을 위주로 기능하게 된다. 구현에 있어 man 명령어를 사용하여 함수의 설명과 기본형태, return 값에 대> 해 정리하였지만 입력받는 주소값의 경우가 NULL 인 경우에 대한 자세한 설명이 부족하다고 많이 느꼈다. 이후 additional 함수 구현에 있어 현재 > 작성하고 있는 함수들을 이용하는데 있어 좀더 세부적인 테스트 케이스를 수집하여 이를 테스트 프로그램할 필요성이 있다.

### 다음 학습 계획
1. strlen, strlcpy, strlcat, strchr, strrchr, strnstr, strncmp, atoi ...<br/>
2. makefile<br/>
3. 기본함수 예외처리 추가 확인<br/>
