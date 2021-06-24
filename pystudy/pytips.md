- 시간 / 메모리 측정 코드

  ~~~python
  import time as t
  s_time = t.time() #측정 시작
  ######CODES#######
  e_time = t.time()
  print("time:", e_time-s_time) #출력
  ~~~

- py 입력 받기

  ~~~python
  mydata = list(map(int, input().split()))
  print(mydata)
  #[5, 6, 7, 8, 9]
  a,b,c = map(int, input().split())
  print(a)
  print(b)
  print(c)
  #a,b,c
  
  ##빠른 입력
  import sys
  data=sys.stdin.readline().rstrip()
  ~~~

- 아스키 코드 변환

  ~~~python
  ord("A")	# 65, 아스키 코드 반환
  chr(65)		# A, 숫자에 맞는 아스키 코드 반환
  ~~~

  