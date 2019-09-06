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