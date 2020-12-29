# strchr
```c
char *strchr(const char *s, int c)
```

strchr 함수는 s에서 특정 문자를 찾는 기능이다.<br/>
입력받는 매개변수는 아래와 같다.<br/>

##### 1. s : 문자를 찾을 메모리의 시작 주소
##### 2. c : 찾을 문자

### 반환값
c를 찾은 경우 : c의 메모리 주소<br/>
c를 찾지 못한 경우 : 0

## 입력값에 따른 결과값
#### 기본
```
s : aabaa | c : b
s : aa.baa ('.' : return address)
```
#### s가 NULL인 경우
```
s : NULL | c : -
segmentation fault
```
#### s가 NULL이 아니고 c가 0인 경우
```
s : aaca | c : c
s : aa.ca ('.' : return address)
```
## 주의사항
결과값 3번째의 경우 c가 0인 경우에도 반환되는 s의 주소값이 바뀌는 점을 유의해야 한다. 이 경우 반환되는 주소값을 통해 c가 있는 지 s에서 찾아보는 과정이 실행된 후 c가 0<br/>
