import serial
import time

# Define the Arduino's serial port and baud rate
arduino_port = 'COM3'  # Change this to your Arduino's serial port
baud_rate = 9600

# Create a serial connection to the Arduino
arduino = serial.Serial(arduino_port, baud_rate, timeout=1)

def move_stepper(angle):
    # Send the target angle to the Arduino
    arduino.write(str(angle).encode())

# Example usage:
move_stepper(90)  # Move to 90 degrees
time.sleep(1)  # Wait for the motor to reach the position
move_stepper(-90)  # Move to -90 degrees
time.sleep(1)  # Wait for the motor to reach the position

# Close the serial connection when done
arduino.close()
