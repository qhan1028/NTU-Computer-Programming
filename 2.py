words = input()

def examination(s):
	return s == s[::-1]

success = False

for i in range(1, len(words)):
	if examination(words[0:i]) and examination(words[i:]):
		print(("yes, %s = %s + %s") % (words, words[0:i], words[i:]))
		success = True
		break

if not success:
	print(("no, %s is not a palindrome.") % (words))
