# strlcat
```c
size_t strlcat(char *dest, const char *src, size_t size)
```

strlcat 함수는 dest 뒤에 src를 복사하여 붙이는 기능이다.<br/>
입력받는 매개변수는 아래와 같다.<br/>

##### 1. dest : 복사될 문자열의 시작 주소
##### 2. src  : 복사할 문자열의 시작 주소
##### 3. size : 복사할 바이트 수

### 반환값
dest의 길이가 size보다 크거나 같은 경우 : size + src 길이<br/>
dest의 길이가 sizq보다 작은 경우 : dest + src 길이

## 입력값에 따른 결과값
#### 기본
```
dest : aaaaa | src : bbb | size : 3
dest : aaaaa
6

dest : aaaaa | src : bbb | size : 1
dest : aaaaa
4
```
#### size가 dest나 src보다 클 때
```
dest : aaaaa | src : bbb | size : 7
dest : aaaaab
8

dest : aaaaa | src : bbb | size : 10
dest : aaaaabbb
8
```
#### dest나 src가 NULL인 경우
```
dest : NULL or src : NULL | size : -
segmentation fault
```
## 주의사항
strlcat 또한 널값 자리를 보장하는 함수이다. 이에 따라 입력받은 size에서 미리 널값의 자리를 생각하고 코드를 구현해야 한다.<br/>

앞서도 많이 언급했듯이 dest 문자열의 마지막에 null이 없는 경우가 들어올 수 있다. 이 경우 dest의 길이를 while문과 주소 연산(dest++)등을 이용해 구할 경우 abort error가 발생할 위험이 있다.
```
while (*dest)
{
    dest++;
    count++;
}
```
위와 같은 경우 dest는 널값이 없어 while문이 

참고자료 : https://stackoverflow.com/questions/45937212/c-zsh-abort-error<br/>
