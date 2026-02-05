compra = int(input("Ingresar el monto de las compras: "))

if compra >= 1000:
    resul = compra * 0.20
    print("La compra tiene descuento de 20%, solo pagarás:", resul)
else:
    print("La compra no tiene descuento:", compra, "no es suficiente para el descuento")
