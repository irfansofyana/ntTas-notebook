// calculate a * b % mod. mod may fit in 64-bit, 
// but a*b might exceed. two ways, one using 
// fast exponentiation style which is safe but 
// slower, or using long double as written below (safe enough i guess)

long long mul(long long a, long long b, long long mod) {
  long double res = a;
  res *= b;
  long long c = (long long)(res / mod);
  a *= b;
  a -= c * mod;
  a %= mod;
  if (a < 0) a += mod;
  return a;
}
