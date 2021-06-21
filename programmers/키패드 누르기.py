def solution(numbers, hand):
    answer = ''
    arr = [[0,0],[0,1],[0,2],
           [1,0],[1,1],[1,2],
           [2,0],[2,1],[2,2],
           [3,0],[3,1],[3,2]]
    isRight = False
    if hand=='right' :
        isRight = True
    l= 10
    r= 12
    for n in numbers :
        if n == 1 or n == 4 or n == 7 :
            answer=answer+'L'
            l = n
        elif n == 3 or n == 6 or n == 9 :
            answer=answer+'R'
            r = n
        else :
            if n == 0 :
                n = 11
            leftDist = abs(arr[n-1][0]-arr[l-1][0])+abs(arr[n-1][1]-arr[l-1][1])
            rightDist = abs(arr[n-1][0]-arr[r-1][0])+abs(arr[n-1][1]-arr[r-1][1])
            if rightDist < leftDist :
                r = n
                answer=answer+'R'
            elif leftDist < rightDist :
                l = n
                answer=answer+'L'
            else :
                if isRight :
                    r = n
                    answer=answer+'R'
                else :
                    l = n
                    answer=answer+'L'

    return answer
