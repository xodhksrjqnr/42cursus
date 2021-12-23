#Philosophers

>### 목적

스레드와 프로세스에 대해 이해하고, 자원을 차지하는 과정에서 발생할 수 있는 교착상태를 해결해보자.

-  **Mandatory** : thread를 이용해 철학자 문제를 해결
-  **Bonus** : process를 이용해 철학자 문제를 해결

>### 규칙

- 모든 전역 변수 금지
- 입력 인자에 대한 설명
	- **number of philosophers** : 입력되는 철학자(또느 fork)의 수
	- **time to die** : milliseconds 단위로, 철학자가 음식을 먹지 않았을 때 죽는 시간
	- **time to eat** : milliseconds 단위로, 철학자가 식사하는데 걸리는 시간(단, 이 시간 동안은 철학자가 fork 두 개를 가지고 있어야 함)
	- **time to sleep** : milliseconds 단위로, 철학자가 잠자는데 걸리는 시간
	- **number of times each philosopher must eat** : 필수가 아닌 옵션(입력), 각 철학자가 먹어야하는 횟수로 모든 철학자가 해당 횟수만큼 먹은 경우 프로그램이 종료됨. (그 외의 경우는 철학자가 한 명이라도 죽지 않는 이상 프로그램은 지속되어야 함)
- 모든 철학자는 1번부터 **number of philoshophers**까지의 번호가 할당됨
- n번째 철학자는 n - 1번과 n + 1번 철학자 사이에 앉아 있음(마지막 철학자의 옆에는 첫번째 철학자가 존재)
- 철학자의 상태에 변화가 생긴 경우 아래와 같은 양식으로 변화에 대한 출력이 발생해야 함
	- timestamp_in_ms X has taken a fork
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died
- 상태 변화에 대한 출력은 서로 겹치거나 섞여서 출력되면 안됨(스레드나 프로세스 사용시 발생할 수 있는 문제)
- 철학자가 죽고 10ms 이내에 죽었음을 알리는 출력이 나와야 함
- 철학자의 기아 상태 회피

>### Mandatory

thread와 mutex를 이용해 철학자 문제를 해결해보자.
