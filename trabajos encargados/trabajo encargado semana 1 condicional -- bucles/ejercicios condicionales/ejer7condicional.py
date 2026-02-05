num = int(input("Ingrese un numero: "))

print("Ingrese los numeros:")
numero7 = int(input())
numero8 = int(input())

operador = input("Ingrese el operador deseado +, -, *, /: ")

if operador == '+':
    print("La suma es:", numero7 + numero8)

elif operador == '-':
    print("La resta es:", numero7 - numero8)

elif operador == '*':
    print("La multiplicacion es:", numero7 * numero8)

elif operador == '/':
    if numero8 != 0:
        print("La division es:", numero7 / numero8)
    else:
        print("El numero no puede ser cero")

else:
    print("Operacion no valida")
