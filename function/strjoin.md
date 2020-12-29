# strjoin
```c
char strjoin(char const *s1, char const *s2)
```

strjoin 함수는 입력 받은 두 문자열을 이은 새로운 문자열을 만드는 기능이다.<br/>
입력받는 매개변수는 아래와 같다.<br/>

##### 1. s1 : 문자열 1의 시작 주소
##### 2. s2 : 문자열 2의 시작 주소

### 반환값
생성된 문자열의 시작 주소<br/>

## 입력값에 따른 결과값
#### 기본
```
s1 : aaa | s2 : bbbsdfs
.aaabbbsdfs ('.' : return address)
```
#### s1이나 s2가 NULL인 경우
```
s1 : NULL or S2 : NULL
0x0
```
## 주의사항
예외처리의 경우 두가지 패턴으로 구현이 가능하다. 우선 s1나 s2가 NULL로 들어오는 경우를 예외로 처리하여 0을 반환하는 방법과 따로 예외처리를 <br/>
