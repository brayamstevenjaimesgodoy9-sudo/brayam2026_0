a, b = 0, 1

print("Serie Fibonacci:")
for _ in range(20):
    print(a, end=" ")
    a, b = b, a + b
