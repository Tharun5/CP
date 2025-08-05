# Modular Arithmetic and Modular Inverse

## 1️⃣ Modular Arithmetic

In modular arithmetic, all results “wrap around” a given number M.

Basic Operations

**Operation** &emsp;&emsp; **Formula**<br>
Addition &emsp; - &emsp; (a + b) % M<br>
Subtraction	&emsp; - &emsp; (a - b + M) % M<br>
Multiplication &emsp; - &emsp;	(a * b) % M<br>
Division &emsp; - &emsp;	(a * inverse(b)) % M<br>

❗ Division is NOT direct; you must use a modular inverse.


## 2️⃣ Modular Inverse

The modular inverse of a modulo M is a number x such that:<br>
(a * x) mod M = 1
<br><br>
Existence Rule
	-	The inverse of a (mod M) exists only if:<br>
gcd(a, M) = 1 &emsp;

i.e., a and M are co-prime or relatively prime.

⸻

Example

M = 7
a = 3<br>
3 * 5 % 7 = 15 % 7 = 1 → inverse(3) = 5

If a shares a factor with M (e.g., a=4, M=10), no inverse exists.



## 3️⃣ Why Competitive Programming Uses 1e9+7
Prime Modulus → Every number 1..M-1 has an inverse.

Large value → Prevents overflow.

Supports Fermat’s Little Theorem for efficient inverse computation.

Other common primes: 998244353.


## 4️⃣ Fermat’s Little Theorem

If M is prime and a is NOT divisible by M:

a^{M-1} = 1 (mod M)

From this:

a^{M-2} = a^{-1} (mod M)

This gives us a fast way to compute modular inverse using binary exponentiation.


``` cadence 
Modular Exponentiation Code

def mod_pow(a, b, M):
    res = 1
    while b > 0:
        if b % 2:
            res = (res * a) % M
        a = (a * a) % M
        b //= 2
    return res

# Modular inverse using Fermat's Little Theorem (only if M is prime)

def mod_inverse(a, M):
    return mod_pow(a, M-2, M)

```


## 5️⃣ Extended Euclidean Algorithm (Inverse for Non-Prime M)

If M is not prime, you can use the Extended Euclidean Algorithm to find the inverse.

``` cadence 
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def mod_inverse_euclid(a, M):
    g, x, _ = extended_gcd(a, M)
    if g != 1:
        return None  # Inverse doesn't exist if gcd != 1
    else:
        return (x % M + M) % M

```

## 6️⃣ Applications of Modular Arithmetic

#### 1. Modular Exponentiation
Fast power calculation using binary exponentiation.<br>
Used in cryptography, combinatorics, and competitive programming.


#### 2. Modular Inverse
Division in modular arithmetic:<br>
a / b mod M = (a * b^{-1}) mod M


#### 3. nCr % M (Combinatorics)

Precompute factorials fact[i] and inverse factorials inv_fact[i]:<br>
nCr = fact[n] * inv_fact[r] * inv_fact[n-r] mod M


#### 4. Modular Linear Equations

Solve equations of the form:<br>
a * x = b mod M


#### 5. Avoiding Overflow

When multiplying large numbers:<br>
(a * b) mod M


## 7️⃣ Example Modular Inverses (M = 7)

a	| inverse(a)

1	 1

2	 4

3	 5

4	 2

5	 3

6	 6

Note: 0 has no inverse.


## 8️⃣ Key Takeaways
Always check if modulus M is prime for safe inverse calculations.

Use Fermat’s Little Theorem for inverse only if M is prime.

If M is not prime → use Extended Euclidean Algorithm for inverse.

Avoid division directly; always replace it with multiplication by inverse.
