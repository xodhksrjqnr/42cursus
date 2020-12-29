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

