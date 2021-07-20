nums = list(map(int, input()))

first_num = nums[0]

for i in range(len(nums) - 1):
    second_num = nums[i + 1]
    if first_num == 0 or second_num == 0:
        first_num = first_num + second_num
    else:
        first_num = first_num * second_num

print(first_num)
