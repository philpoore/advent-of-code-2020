input = open("input.txt", "r").read().split("\n")
nums = list(map(lambda x: int(x), input))

s = set()

for num in nums:
    other=2020-num
    if (other in s):
        print("answer", other * num)
        exit
    s.add(num)