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
dest : "aaaaaa" | src : "bbbb" | n : 0,3,4
aaaaaa
bbbaaa
bbbbaa
```
#### dest의 범위를 넘어선 n 값이 들어온 경우
```

```
#### dest와 src에 NULL이 들어온 경우
```

```
## 주의사항
none<br/>
