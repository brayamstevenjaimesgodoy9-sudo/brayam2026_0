print("Ingrese un dia para una frase del dia")
print("1: Lunes")
print("2: Martes")
print("3: Miercoles")
print("4: Jueves")
print("5: Viernes")
print("6: Sabado")
print("7: Domingo")

opcion = int(input())

if opcion == 1:
    print("Lunes:")
    print("Feliz lunes y que tengas suerte")

elif opcion == 2:
    print("Martes:")
    print("Este dia tendras buen momento")

elif opcion == 3:
    print("Miercoles:")
    print("Gran dia, ten voluntad")

elif opcion == 4:
    print("Jueves:")
    print("Un dia bien hermoso y calido")

elif opcion == 5:
    print("Viernes:")
    print("Este dia tendras mayor calidad de vida")

elif opcion == 6:
    print("Sabado:")
    print("Este dia es un buen descanso")

elif opcion == 7:
    print("Domingo:")
    print("Este dia es un buen dia de capacitacion")

else:
    print("Dia no valido")
