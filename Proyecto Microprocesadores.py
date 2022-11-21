import serial # pip install pyserial

archivo = open("Datos.txt","w")
archivo1 = open("Datos1.txt","w")
serialArduino = serial.Serial('COM3',9600)

datos = []
datos1 = []
contador = 0

while (contador != 20+6):
    distancias = serialArduino.readline().decode("ascii")
    print(distancias)
    datos.append(distancias)
    contador += 1

archivo.writelines(datos)
archivo.close()

archivo = open("Datos.txt","r")
for x in archivo:
        xf = x.replace("La distancia es: ", "")
        cm = xf.replace(" cm", "")
        group = cm.replace("Grupo:\n", "")
        j = group.replace("Javier Prado - 21486\n", "")
        a = j.replace("Angel Perez - 21298\n","")
        b = a.replace("Bryan Espana - 21550\n", "")
        des = b.replace("Programa para calcular el tiempo que viaja un sonido y la distancia que recorre\n","")
        datos1.append(des)
        
archivo1.writelines(datos1) 
archivo1.close()
archivo.close()

exit()
    


    