import serial

porta = '/dev/ttyACM0'
baud = 9600

ser = serial.Serial(porta, baud)

while True:
    try:
        linha = ser.readline().decode().strip()
        with open('/home/Grupo4/Dinamometro/peso.txt', 'w') as f:
            f.write(linha)
        print(f"Peso: {linha} kg")
    except Exception as e:
        print(f"Erro: {e}")