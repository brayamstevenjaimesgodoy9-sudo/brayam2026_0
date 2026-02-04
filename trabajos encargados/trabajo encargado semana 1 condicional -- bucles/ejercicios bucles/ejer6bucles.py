num = int(input("Ingrese un número positivo: "))

while num < 0:
    num = int(input("Número inválido. Intente nuevamente: "))

print("Número válido:", num)
