struct LinearCongruentialGenerator
{
  unsigned long m; /* modulus */
  unsigned long c; /* increment */
  unsigned long a; /* multiplier */
  unsigned long x; /* value in sequence */
};

unsigned long prime(unsigned long);

unsigned long getNextRandomValue(struct LinearCongruentialGenerator*);

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  struct LinearCongruentialGenerator lcg;
  lcg.m = m;
  lcg.c = c;
  lcg.a = prime(m);
  lcg.x = c;

  if(0 >= lcg.m || 0 >= lcg.a || lcg.a >= m || 0 >= c || c >= m)
  {
    lcg.m = 0;
    lcg.a = 0;
    lcg.c = 0;
    lcg.x = 0;
  }

  return lcg;
}

unsigned long prime(unsigned long n)
{
  unsigned long divisor = 2;
  unsigned long product = 1;
  unsigned long primeFactor = 1;
  unsigned long a = n;
  if(n == 1)
  {
    return 0;
  }
  while(n >= divisor * divisor)
  {
    while(n % divisor == 0)
    {
      n = n / divisor;
      primeFactor = divisor;
    }
    product *= primeFactor;
    primeFactor = 1;
    divisor++;
  }
  if(a % 4 == 0)
  {
    return 1 + 2 * (product * n);
  }
  return 1 + (product * n);
}

unsigned long getNextRandomValue(struct LinearCongruentialGenerator* lcg)
{
  unsigned long m = lcg->m;
  unsigned long c = lcg->c;
  unsigned long a = lcg->a;
  unsigned long x = lcg->x;

  lcg->x = ( a * x + c ) % m;

  return x;
}