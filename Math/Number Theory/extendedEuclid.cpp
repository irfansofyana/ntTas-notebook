/**
* Description : find x and y such that ax + by = 1
*/

/* store x, y, and d as global variables */
void extendedEuclid(int a, int b) {
  if (b == 0) { x = 1; y = 0; d = a; return; }
  /* base case */
  extendedEuclid(b, a % b);
  /* similar as the original gcd */
  int x1 = y;
  int y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}