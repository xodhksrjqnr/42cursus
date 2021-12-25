# Philosophers

## 목적

스레드와 프로세스에 대해 이해하고, 자원을 차지하는 과정에서 발생할 수 있는 교착상태를 해결해보자.

- **Mandatory** : thread를 이용해 철학자 문제를 해결
- **Bonus** : process를 이용해 철학자 문제를 해결

## 규칙

- 모든 전역 변수 금지
- 입력 인자에 대한 설명
	- **`number_of_philosophers`** : 입력되는 철학자(또느 fork)의 수
	- **`time_to_die`** : milliseconds 단위로, 철학자가 음식을 먹지 않았을 때 죽는 시간
	- **`time_to_eat`** : milliseconds 단위로, 철학자가 식사하는데 걸리는 시간(단, 이 시간 동안은 철학자가 fork 두 개를 가지고 있어야 함)
	- **`time_to_sleep`** : milliseconds 단위로, 철학자가 잠자는데 걸리는 시간
	- **`number_of_times_each_philosopher_must_eat`** : 필수가 아닌 옵션(입력), 각 철학자가 먹어야하는 횟수로 모든 철학자가 해당 횟수만큼 먹은 경우 프로그램이 종료됨. (그 외의 경우는 철학자가 한 명이라도 죽지 않는 이상 프로그램은 지속되어야 함)
- 모든 철학자는 1번부터 **`number_of_philoshophers`**까지의 번호가 할당됨
- n번째 철학자는 n - 1번과 n + 1번 철학자 사이에 앉아 있음(마지막 철학자의 옆에는 첫번째 철학자가 존재)
- 철학자의 상태에 변화가 생긴 경우 아래와 같은 양식으로 변화에 대한 출력이 발생해야 함
	- **`timestamp_in_ms X has taken a fork`**
	- **`timestamp_in_ms X is eating`**
	- **`timestamp_in_ms X is sleeping`**
	- **`timestamp_in_ms X is thinking`**
	- **`timestamp_in_ms X died`**
- 상태 변화에 대한 출력은 서로 겹치거나 섞여서 출력되면 안됨(스레드나 프로세스 사용시 발생할 수 있는 문제)
- 철학자가 죽고 10ms 이내에 죽었음을 알리는 출력이 나와야 함
- 철학자의 기아 상태 회피

## Mandatory

Thread와 mutex를 이용해 철학자 문제를 해결해보자.

>### 1. Main 함수

- **데이터 저장을 위한 배열 생성**
- **입력 데이터를 숫자로 변환(setting)하여 생성한 배열에 저장**
- **사용할 변수에 대해 메모리 할당**
- **철학자 문제 절차 시작(running)**

#### 1-1. 배열 생성

입력받은 데이터를 저장할 long 타입의 Input 배열을 할당 후, 메모리 할당이 정상적으로 되었는지 확인합니다. 각 시간이 얼만큼 큰수가 들어올지 모른다는 점에서 이 부분은 개인적으로 명확한 기준을 가지고 구현을 진행하시면 될 것 같습니다.

#### 1-2. 데이터 변환

Setting 함수를 호출하여 input 배열에 입력된 데이터를 변환하여 저장합니다.

#### 1-3. 변수에 대한 메모리 할당

사용할 thread와 철학자의 정보를 저장할 객체의 배열에 메모리 할당을 진행합니다.

#### 1-4. 메인 절차 호출

 만들어진 데이터를 이용해 running 함수를 호출하여 thread 생성 및 요구사항 처리를 진행합니다.

```c
#include "philo.h"

static int	init(pthread_t **t, t_philo **p, int **flag, long n)
{
	char	*msg;

	msg = 0;
	*t = malloc(n * sizeof(pthread_t));
	*p = malloc(n * sizeof(t_philo));
	*flag = malloc(n * sizeof(int));
	if (!*t || !*p || !*flag)
	{
		if (!*t)
			free(*t);
		if (!*p)
			free(*p);
		if (!*flag)
			free(*flag);
		msg = "malloc error";
	}
	return (error(msg));
}

int	main(int ac, char **av)
{
	//스레드 객체 배열
	pthread_t	*threads;
	//철학자 정보 객체 배열
	t_philo		*philos;
	//철학자 식사 여부 판단
	int			*flag;
	long		*input;

	input = malloc(5 * sizeof(long));
	if (!input)
		return (error("malloc error"));
	//setting으로 데이터 변환, init으로 메모리 할당
	if (setting(ac, av, input) && init(&threads, &philos, &flag, input[0]))
		running(input, threads, philos, flag);
	return (0);
}
```

>### 2. Setting 함수

- **입력 개수 유효성 판단**
- **생성 배열 초기화(memset)**
- **각 입력값에 대한 변환(convert)**
- **Error message(msg) 확인**

#### 2-1. 입력 개수 유효성

입력 인자 중에서 **`number_of_times_each_philosopher_must_eat`**의 경우 선택 옵션이기 때문에 입력 인자의 수는 5개 또는 6개인 경우만 유효합니다.

#### 2-2. 생성 배열 초기화

이전에 생성했던 input 배열에 쓰레기값이 남아있을 수 있기 때문에 초기화를 진행합니다.

#### 2-3. 변환

입력 인자들의 자료형은 char 형입니다. 숫자로 바꾸기위해 적절한 처리를 진행하며, 도중에 숫자가 아닌 문자가 발견된 경우 현재 입력 인자는 유효하지 않은 인자로 오류 메시지를 출력해야 합니다.

#### 2-4. 유효성 최종 판단

이전 과정을 거치며 갱신된 msg를 확인 후 오류가 존재하면 해당 오류를 출력 후 생성했던 배열을 free해준 뒤 프로그램을 종료합니다.

```c
#include "philo.h"

static int	convert(char *str, long *input, int cur)
{
	//입력 인자의 구성이 모두 숫자인 경우만 끝까지 반복
	while ('0' <= *str && *str <= '9')
	{
		//변환
		input[cur] = input[cur] * 10 + (*str - 48);
		str++;
	}
	//입력 인자가 유효한 경우
	if (!*str)
		return (1);
	return (0);
}

int	setting(int ac, char **av, long *input)
{
	char	*msg;
	int		i;

	msg = 0;
	i = 0;
	//입력 인자 개수 유효성
	if (!(ac == 5 || ac == 6))
		msg = "invlid arguments";
	//생성 배열 초기화
	memset(input, 0, 5 * sizeof(long));
	//선택 옵션이 안 들어온 경우 -1로 초기화하여 이후 반복 횟수 판단
	if (ac == 5)
		input[4] = -1;
	//입력 인자에 대한 변환 진행, 이미 이전 과정에서 msg가 갱신된 경우는 진행할 필요 없음
	while (*(++av) && !msg)
		if (!convert(*av, input, i++))
			msg = "invalid arguments";
	//입력 인자 중 유효하지 않는 경우
	if (msg)
		free(input);
	return (error(msg));
}
```

>### 3. Error 함수

입력받은 문자열이 `NULL`인 경우 1을, 아닌 경우 문자열을 출력 후 0을 반환하는 간단한 기능입니다. 여기서 입력받은 문자열은 에러 메시지를 나타냅니다.

```java
#include "philo.h"

int	error(char *msg)
{
	if (!msg)
		return (1);
	printf("%s\n", msg);
	return (0);
}
```

>### 4. Running 함수

- 사용할 변수들에 대한 메모리 할당 및 mutex 생성
- 각 철학자에 대한 정보 생성 및 스레드 생성
- 철학자 행동
- 모든 스레드가 종료될 때까지 대기

#### 4-1. 스레드 생성

**`pthread_create`**에 인자로 담아주기위해 철학자에 대한 정보를 초기화해주어야 합니다. 철학자의 정보는 다음과 같습니다.

- **name** : 철학자 번호
- **t_die** : 먹지 않고 버틸 수 있는 시간
- **t_eat** : 먹는 시간
- **t_sleep** : 잠자는 시간
- **must_eat** : 먹어야하는 횟수
- **mutex** : mutex 관련 함수의 인자로 활용할 객체

철학자 정보에 대한 초기화가 끝났으면 이제 스레드 생성을 진행해야 하며, 다음과 같은 인자가 필요합니다.

**`pthread_create(스레드 객체, 스레드 옵션, 스레드가 수행할 함수, 수행할 함수의 인자)`**

#### 4-2. 행동

철학자가 규칙에 따라 행동을 수행하는 파트입니다. 행동은 eat, sleep, think가 존재하며, 일정시간동안 철학자가 굶게되는 경우 die가 출력됩니다. (구현중)

#### 4-3. 대기

모든 스레드의 작업이 종료될 때까지 기다리는 단계입니다. 특정 스레드가 먼저 끝나 메인문이 종료되어 프로그램 전체가 종료되는 것을 방지하기 위함압니다. while문을 이용해 **`threads`** 에 대해 **`pthread_join`**이 모두 수행될 때까지 반복합니다.

```java
#include "philo.h"

//철학자에 대한 정보 초기화
static void	set_philo_info(t_philo *philo, int *flag, long *data
, pthread_mutex_t *mutex)
{
	philo->t_die = data[1];
	philo->t_eat = data[2];
	philo->t_sleep = data[3];
	philo->must_eat = data[4];
	philo->flag = flag;
	philo->mutex = mutex;
}

//철학자의 행동 과정
static void	*behavior(void *data)
{
	t_philo	*philo;
	long	i;
	int		flag;

	philo = (t_philo *)data;
	i = 0;
	flag = philo->must_eat;
	//철학자가 의무적으로 먹어야하는 횟수만큼 진행, 선택을 안한 경우 무한히 반복
	while (i < philo->must_eat || flag == -1)
	{
		eating(philo, i);
		if (flag != -1)
			i++;
	}
	return (0);
}

int	running(long *input, pthread_t *threads, t_philo *philos, int *flag)
{
	pthread_mutex_t	mutex;
	int				i;
	char			*msg;

	msg = 0;
	//mutex 초기화
	if (pthread_mutex_init(&mutex, NULL))
		msg = "init error";
	i = -1;
	while (++i < input[0] && !msg)
	{
		philos[i].name = i + 1;
		flag[i] = 0;
		//철학자 객체 정보 저장
		set_philo_info(&philos[i], flag, input, &mutex);
		//철학자 스레드 생성
		if (pthread_create(&threads[i], NULL, behavior, &philos[i]))
			msg = "thread create error";
	}
	i = -1;
	//모든 스레드가 작업을 완료할 때까지 대기
	while (++i < input[0] && !msg)
		pthread_join(threads[i], NULL);
	//mutex 제거
	if (msg && pthread_mutex_destroy(&mutex))
		msg = "mutex_destroy error";
	return (error(msg));
}
```