input = open("input.txt", "r").read().split("\n")
nums = list(map(lambda x: int(x), input))

s = set()

for num in nums:
    s.add(num)

for i in range(len(nums)):
    for j in range(i + 1, len(nums)):
        a = nums[i]
        b = nums[j]
        c = 2020 - a - b
        if c in s:
            print(a, b, c)
            print("answer", a * b * c)
            exit()
print("No answer")