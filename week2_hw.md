
# Circular Queue 구현하기

queue.h에 선언된 함수 주석을 읽어보고 queue.c 파일에 구현할것.

아래의 명령어들로 테스트 코드들을 업데이트할 수 있습니다.

upstream으로 gomjellie레포지토리 추가
```sh
git remote add upstream https://github.com/gomjellie/2021-winter-mentoring
```

upstream에서 패치해오기
```sh
git fetch upstream
```

fetch해온 것을 병합하기
```
git merge upstream/main
```

## 채점 방법

1. 채점스크립트 hw2.sh의 실행권한을 줍니다. chmod +x ./hw2.sh 

2. ./hw2.sh 로 실행합니다.

3. 정상적으로 코드가 작성되었다면 아래와같이 뜹니다.

```
queue test0 pass
queue test1 pass
queue expand test pass
```

4. 문제가 있다면 테스트 코드 몇번 라인을 통과하지 못했는지 뜹니다.
