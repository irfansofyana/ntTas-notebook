def millerTest(d, n):
	lon = int(math.log(n))
	# b = min(n-2, 2*lon*lon)
	a = random.randrange(2, n-2)
	x = power(a, d, n)
	if (x == 1 or x == n-1):
		return True
	while (d != n-1):
		x = (x *x) % n
		d *= 2
		if (x == 1):
			return False
		if (x == n-1):
			return True
	return False

def isPrime(n, k):
	if (n <= 1 or n == 4):
		return False
	if (n <= 3):
		return True

	d = n-1
	while (d % 2 == 0):
		d /= 2

	for i in range(0, k):
		if (not(millerTest(d, n))):
			return False
	return True
# factorization a number in O(n^1/3)
def fastFactorization(n):
	res = 1
	for pf in primes:
		if (pf * pf * pf > n):
			break
		cnt = 1
		while (n%pf == 0):
			n /= pf
			cnt+=1
		res *= (cnt)
	sqt = int(math.sqrt(n))
	if (isPrime(n, 10)):
		res *= 2
	elif (sqt * sqt == n and isPrime(sqt, 10)):
		res *= 3
	elif (n != 1):
		res *= 4
	return res