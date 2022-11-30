import serial # pip install pyserial

archivo = open("Datos.txt","w") #Archivo que guarda todo el contenido
archivo1 = open("Datos1.txt","w")#archivo que guarda solo los datos de distancia
serialArduino = serial.Serial('COM3',9600) #Puerto COM y velocidad de transmisión

datos = []#Arreglo que guarda todo el contenido
datos1 = []#Arreglo que guarda solo los datos de distancia
contador = 0

while (contador != 500+6):#Se recibe 500 datos y 6 de basura
    distancias = serialArduino.readline().decode("ascii")#Se decodifica el dato
    print(distancias)#Se imprime el dato
    datos.append(distancias)#Se guarda el dato en el arreglo
    contador += 1

archivo.writelines(datos)#Se guarda todo el contenido en el archivo
archivo.close()#Se cierra el archivo

archivo = open("Datos.txt","r")#Se abre el archivo en modo lectura
for x in archivo:
        #borramos los caracteres de basura
        xf = x.replace("La distancia es: ", "")
        cm = xf.replace(" cm", "")
        group = cm.replace("Grupo:\n", "")
        j = group.replace("Javier Prado - 21486\n", "")
        a = j.replace("Angel Perez - 21298\n","")
        b = a.replace("Bryan Espana - 21550\n", "")
        des = b.replace("Programa para calcular el tiempo que viaja un sonido y la distancia que recorre\n","")
        #agregamos los datos a un arreglo de distancia
        datos1.append(des)
        
archivo1.writelines(datos1)#Se guarda solo los datos de distancia en el archivo 
archivo1.close()#Se cierra el archivo
archivo.close()#Se cierra el archivo

exit()#Se cierra el programa
    


    