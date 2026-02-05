horas = int(input("Ingrese horas trabajadas: "))

extra = horas > 40

if not extra:
    salario = horas * 16
    print("Tu salario normal es:", salario)
else:
    horaextra = horas - 40
    salario = (horas * 16) + (horaextra * 0.20)
    print("Tu salario tiene aumento extra:", salario)
