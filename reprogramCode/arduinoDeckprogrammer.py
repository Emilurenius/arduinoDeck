import serial, sys, time

def selectKey():
    print('\nPress the key you want to program')
    selectedKey = 0
    while selectedKey == 0:
        keyNum = 0
        while ser.in_waiting:
            data = ser.read()
            if data:
                if keyNum > 0:
                    keyNum = keyNum*10+int(data)
                    print(keyNum)
                else:
                    keyNum = int(data)
                    print(keyNum)
        
        selectedKey = keyNum

    print(f'{selectedKey} selected')
    return selectedKey

while True:
    ser = serial.Serial(f'COM{sys.argv[1]}', int(sys.argv[2]), timeout=1)
    selectedKey = selectKey()

    buttonVal = (selectedKey).to_bytes(1, byteorder="big")
    buttonVal += input('Write macro, then press enter >> ').encode()
    buttonVal += bytes(1);
    time.sleep(0.2)
    print(buttonVal)
    ser.write(buttonVal)
    while not ser.in_waiting:
        time.sleep(0.5);
    while ser.in_waiting:
        print(ser.readline());
    ser.close()
    input('Press ENTER to program another key >> ')