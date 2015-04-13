scan = input().split()

for i in range(len(raw)):
	scan[i] = int(scan[i])

n = scan[0]
numbers = scan[1 : n+1]
quest = scan[n+1 :]

numbers.sort()
numbers.reverse()

def out(a, b)
	print(("第 %d 大的數字是 %d") % (a, b))

for j in query:
	if j != 0:
		out(j, numbers[j-1])
	else:
		break