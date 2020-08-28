import serial
import rospy
import io

def comandSender():
    rospy.init_node('comandSender', anonymous=True)
    rate = rospy.Rate(10)
    ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0.1)
    sio = io.TextIOWrapper(io.BufferedRWPair(ser, ser))

    print(ser.name)
    sio.write(serial.unicode("^ECHOF 1\r\n"))
    sio.flush()
    x = sio.read()
    print(x)
    while 1:
        sio.write(serial.unicode("!M 150 0\r\n"))
        sio.write(serial.unicode("?HS 1\r\n"))
        sio.write(serial.unicode("?F 1\r\n"))
        sio.flush()
        x = sio.read()
        print(x)

    x = sio.read()
    print(x)
    sio.write(serial.unicode("?V\r\n"))
    sio.flush()
    x = sio.read()
    print(x)

    print(ser.is_open)
    ser.close()


if __name__ == '__main__':
    try:
        comandSender()
    except rospy.ROSInterruptException:
        pass

