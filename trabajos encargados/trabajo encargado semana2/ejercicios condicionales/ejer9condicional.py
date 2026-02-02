num1 = int(input("Ingrese primer numero: "))
num2 = int(input("Ingrese segundo numero: "))
num3 = int(input("Ingrese tercer numero: "))

mayor = num1

if num2 > mayor:
    mayor = num2
if num3 > mayor:
    mayor = num3

print("El numero mayor es:", mayor)
