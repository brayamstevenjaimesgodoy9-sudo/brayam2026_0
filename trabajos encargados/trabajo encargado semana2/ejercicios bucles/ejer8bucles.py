num = int(input("Ingrese un número entero positivo: "))
contador = 0

while num > 0:
    num //= 10
    contador += 1

print("Cantidad de dígitos:", contador)
