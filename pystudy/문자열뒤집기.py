cards = list(map(int, input()))

first_card = cards[0]

ans = 0
is_flipping = False
for i in range(1, len(cards)):
    if cards[i] != first_card:
        if not is_flipping:
            ans += 1
            is_flipping = True
    else:
        is_flipping = False


print(ans)
