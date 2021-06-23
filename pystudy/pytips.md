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
  ~~~

  