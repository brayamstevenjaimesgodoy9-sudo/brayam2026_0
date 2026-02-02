numero1 = int(input("Ingrese numero: "))

if numero1 < 0:
    print("El numero es invalido, solo positivos")
else:
    print("El numero es correcto")

if numero1 % 2 == 0:
    print(f"El numero {numero1} es par")
else:
    print(f"El numero {numero1} es impar")
