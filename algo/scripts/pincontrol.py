import RPi.GPIO as GPIO
import rospy
from std_msgs.msg import String
from std_msgs.msg import Bool




pumppin = 26
rackelpin = 16
schetkapin = 6
turbinapin = 5
magnitpin = 25

GPIO.setmode(GPIO.BCM)
GPIO.setup(pumppin, GPIO.OUT)
GPIO.setup(schetkapin, GPIO.OUT)
GPIO.setup(rackelpin, GPIO.OUT)
GPIO.setup(turbinapin, GPIO.OUT)
GPIO.setup(magnitpin, GPIO.IN)


def callback(data):
    if data == 'pumpon':
        GPIO.output(pumppin, GPIO.HIGH)
    elif data == 'pumpoff':
        GPIO.output(pumppin, GPIO.LOW)
    elif data == 'rackelon':
        GPIO.output(rackelpin, GPIO.HIGH)
    elif data == 'rackeloff':
        GPIO.output(rackelpin, GPIO.LOW)
    elif data == 'schetkaon':
        GPIO.output(schetkapin, GPIO.HIGH)
    elif data == 'schetkaoff':
        GPIO.output(schetkapin, GPIO.LOW)
    elif data == 'turbinaon':
        GPIO.output(turbinapin, GPIO.HIGH)
    elif data == 'turbinaoff':
        GPIO.output(turbinapin, GPIO.LOW)

def main():
    rospy.init_node('distancemeter')
    pubmagnit = rospy.Publisher("magnit", Bool, queue_size=100)
    rospy.Subscriber('motorcomand', String, callback)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        pubmagnit.publish(GPIO.input(magnitpin))
        rate.sleep()





if __name__ == "__main__":
    main()