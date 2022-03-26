import serial, sys, time, json

with open('./keyMaptest.json') as f:
    data = json.load(f)

print(data)

for k, v in data.items():
    ser = serial.Serial(f'COM{sys.argv[1]}', int(sys.argv[2]), timeout=1)
    buttonVal = (int(k)).to_bytes(1, byteorder="big")
    buttonVal += v.encode()
    buttonVal += bytes(1);
    print(buttonVal)
    ser.write(buttonVal)
    time.sleep(1)
    while ser.in_waiting:
        print(ser.readline());
    ser.close()