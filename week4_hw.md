
# Priority Queue 구현하기

hash_table.h에 선언된 함수 주석을 읽어보고 hash_table.c 파일에 구현할것.

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

1. 채점스크립트 hw4.sh의 실행권한을 줍니다. chmod +x ./hw4.sh 

2. ./hw4.sh 로 실행합니다.

3. 정상적으로 코드가 작성되었다면 아래와같이 뜹니다.

```
test 0 pass
test 1 pass
test 2 pass
```

테스트 0번: 해쉬테이블 alloc, free함수가 작동하면 통과합니다.
테스트 1번: 해쉬테이블에 삽입 조회해서 정확한 결과가 나오면 통과합니다.
테스트 1번: 해쉬테이블에 넣지 않은 키값을 조회했을때 NULL값이 나오면 통과합니다.

4. 문제가 있다면 테스트 코드 몇번 라인을 통과하지 못했는지 뜹니다.
