n = int(input("Ingrese un número positivo: "))
factorial = 1

for i in range(1, n + 1):
    factorial *= i

print("El factorial es:", factorial)
