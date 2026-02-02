import random

numero = random.randint(1, 100)

while True:
    intento = int(input("Adivina el número (1-100): "))

    if intento > numero:
        print("Demasiado alto.")
    elif intento < numero:
        print("Demasiado bajo.")
    else:
        print("¡Correcto! Adivinaste el número.")
        break
