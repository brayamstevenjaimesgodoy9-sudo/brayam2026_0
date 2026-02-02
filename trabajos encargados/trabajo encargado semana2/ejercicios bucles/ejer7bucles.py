num = int(input("Ingrese un número entero: "))
suma = 0

while num != 0:
    suma += num % 10
    num //= 10

print("La suma de los dígitos es:", suma)
