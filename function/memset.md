# memset
```c
void *memset(void *s, int c, size_t n)
```

memset 함수는 메모리를 입력 받은 값으로 초기화하는 기능이다.<br/>
입력받는 매개변수는 아래와 같다.<br/>

##### 1. s : 초기화 시킬 메모리의 시작 주소
##### 2. c : 초기화 값
##### 3. n : 초기화 시킬 메모리의 길이(바이트 수)

매개변수를 이용해 초기화를 진행한 뒤 초기화가 완료된 s의 주소를 다시 반환하게된다.<br/>

memset은 메모리를 1byte씩 읽고 초기화 과정을 진행하며 이 과정에서 형변환을 필요로 한다.
```c
*((unsigned char *)s) = (unsigned char)c;
```
형변환이 unsigned char로 이루어지는 이유는 다음과 같다.

- void 형의 경우 다양한 형을 받을 수 있다.
- char 형이 1byte의 크기를 가진다.
- char 형의 경우 부호 비트를 고려한다.

즉, void 타입의 경우 다양한 형의 매개변수를 받을 수 있어 형에 상관없이 메모리를 읽고 초기화할 필요가 있다. 따라서, 1byte씩 읽고 쓰기위해 1byte 크기를 지닌 char형을 사용한다.

그렇다면 unsigned char와 char의 차이점에 대해 알아보자. 간단하게 설명하면 메모리를 읽는 방식의 차이로 char는 부호를 고려하고 unsigned char는 부호를 고려하지 않는다는 점이다. 아래 사진은 좀 더 가시적으로 설명하고 있다.<br/>
<p align="center">
  <img src = "https://user-images.githubusercontent.com/48250370/103212492-3e834880-494e-11eb-8f03-836c4b3e3489.png" width="600">
</p><br/>
사진에서 알 수 있듯이 char (signed char)의 경우 가장 앞 비트를 부호 비트로 사용하게 되어 결과적으로 -128 ~ 127의 범위를 갖게 된다. 반면, unsigned char의 경우 0~255의 범위를 갖게 된다.

## 반환값
s(초기화 시킨 메모리의 시작 주소)

## 입력값에 따른 결과값
#### 기본<br/>
s : aaaaa | c : 0 | n : 0,3<br/>
aaaaa<br/>
000aa<br/>
#### s의 범위를 넘어선 n 값이 들어온 경우<br/>
s : aaaaa | c : 0 | n : 7<br/>
00000.00 ('.' : 기존 s의 범위)<br/>
#### s가 NULL이 들어온 경우
s : NULL | c : - | n : -<br/>
segmentation fault
#### c가 정수형 타입의 범위를 넘어선 경우
s : - | c : 9223372036854775808 | n : -<br/>
compile error<br/>

## 주의사항
위의 결과값들은 입력받은 s의 타입이 (char &#42;)인 경우이다. 만약, s의 타입이 (int &#42;)라면 n이 0인 경우를 제외하고 의도하지 않은 결과가 출력된다.
