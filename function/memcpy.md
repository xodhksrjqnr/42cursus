# memcpy
```c
void *memcpy(void *dest, const void *src, size_t n)
```

memcpy 함수는 메모리 단위로 dest에 src를 복사하는 기능이다.<br/>
입력받는 매개변수는 아래와 같다.<br/>

##### 1. dest : 복사될 메모리의 시작 주소
##### 2. src  : 복사(참조)할 메모리의 시작 주소
##### 3. n    : 복사할 메모리의 길이(바이트 수)

### 반환값
dest <br/>

## 입력값에 따른 결과값
#### 기본
```
dest : "aaaaaa" | src : "bbbb" | n : 3,4
dest : .bbbaaa ('.' : return address)
dest : .bbbbaa ('.' : return address)
```
#### n이 0인 경우
```
dest : "aaaaaa" | src : - | n : 0
dest : .aaaaaa ('.' : return address)

dest : NULL | src : - | n : 0
0x0
```
#### dest와 src가 모두 NULL인 경우
```
dest : NULL | src : NULL | n : !0
0x0
```
#### dest나 src가 NULL이고 n이 0이 아닌 경우
```
dest : NULL | src : !NULL | n : !0
segmentation fault

dest : !NULL | src : NULL | n : !0
segmentation fault
```
#### dest나 src보다 n이 긴 경우
```
dest : "aaa" | src : "bbbbb" | n : 5 (dest와 src 이후로는 0으로 초기화되었다고 가정)
dest : .bbbbb ('.' : return address)
```
## 주의사항
memcpy의 경우 예외처리에 신경써야한다. 입력값에 따른 결과값중 dest와 src가 모두 NULL이고 n이 0이 아닌 경우에는 0이 리턴되야 한다.<br/>

memcpy는 중복된 문자열에서는 의도한 바와는 다른 결과가 출력된다. 중복된 문자열이란 일정 범위의 메모리를 dest와 src가 가리키고 있는 경우를 말한다. 아래 사진을 통해 좀 더 이해해보자.<br/>

<p align="center">
  <img src = "https://user-images.githubusercontent.com/48250370/103249931-dc116300-49b4-11eb-9988-5fe43e77e98f.png" width="500">
</p>
