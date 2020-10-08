import time
import botbook_gpio as gpio
import rospy
from std_msgs.msg import Float32

triggerPin = 22 # <1>
echoPin = 27
s0Pin = 0
s1Pin = 0
s2Pin = 0
s3Pin = 0

v=(331.5+0.6*20) # m/s

gpio.mode(triggerPin, "out")
gpio.mode(s0Pin, "out")
gpio.mode(s1Pin, "out")
gpio.mode(s2Pin, "out")
gpio.mode(s3Pin, "out")

gpio.mode(echoPin, "in")
gpio.interruptMode(echoPin, "both")

gpio.write(triggerPin, gpio.LOW)
gpio.write(s0Pin, gpio.LOW)
gpio.write(s1Pin, gpio.LOW)
gpio.write(s2Pin, gpio.LOW)
gpio.write(s3Pin, gpio.LOW)

time.sleep(0.5)

def readDistanceCm():


    gpio.write(triggerPin, gpio.HIGH)
    time.sleep(1/1000.0/1000.0)
    gpio.write(triggerPin, gpio.LOW)

    t = gpio.pulseInHigh(echoPin) # s

    d = t*v
    d = d/2
    return d        # cm

def setGate(i):
    if i & 1 == 1:
        gpio.write(s0Pin, gpio.HIGH)
    else:
        gpio.write(s0Pin, gpio.LOW)
    if i & 2 == 2:
        gpio.write(s1Pin, gpio.HIGH)
    else:
        gpio.write(s1Pin, gpio.LOW)
    if i & 4 == 4:
        gpio.write(s2Pin, gpio.HIGH)
    else:
        gpio.write(s2Pin, gpio.LOW)
    if i & 8 == 8:
        gpio.write(s0Pin, gpio.HIGH)
    else:
        gpio.write(s0Pin, gpio.LOW)


def main():
    rospy.init_node('distancemeter')
    pubbackcenter = rospy.Publisher("backcenter", Float32, queue_size=1)
    pubbackright= rospy.Publisher("backright", Float32, queue_size=1)
    pubbackleft = rospy.Publisher("backleft", Float32, queue_size=1)
    pubrightcenter= rospy.Publisher("rightcenter", Float32, queue_size=1)
    pubrightforward = rospy.Publisher("rightforward", Float32, queue_size=1)
    pubrightback = rospy.Publisher("rightback", Float32, queue_size=1)
    publeftcenter = rospy.Publisher("leftcenter", Float32, queue_size=1)
    publeftforward = rospy.Publisher("leftforward", Float32, queue_size=1)
    publeftback = rospy.Publisher("leftback", Float32, queue_size=1)
    pubforwardcenter = rospy.Publisher("forwardcenter", Float32, queue_size=1)
    pubforwardright = rospy.Publisher("forwardright", Float32, queue_size=1)
    pubforwardleft = rospy.Publisher("forwardleft", Float32, queue_size=1)

    array = [pubbackcenter, pubbackright, pubbackleft, pubrightcenter, pubrightforward, pubrightback,
             publeftcenter, publeftforward, publeftback, pubforwardcenter, pubforwardright, pubforwardleft]
    i = 0
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        setGate(i)
        d = readDistanceCm()
        array[i].publish(d)# <2>
        rate.sleep()
        i += 1
        if i > 11:
            i = 0


if __name__ == "__main__":
    main()
