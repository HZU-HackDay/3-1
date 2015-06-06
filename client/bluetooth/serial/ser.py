#!/usr/bin/env python
# -*- coding: UTF-8 -*-
 
import time,sys
import serial
port = "/dev/ttyACM0"

class Communicate:
	def __init__(self, device):
		self.device = device
		self.Seral = serial.Serial(device)

	def send(self, msg):
		self.Seral.write(msg)
		print("Send   => " + time.strftime("%Y-%m-%d %X\t") + msg)
	
	def readLine(self):
		line = self.Seral.readline()
		print("Receive => " + time.strftime("%Y-%m-%d %X\t") + line.strip())
		return line

	def main(self):
		line = self.readLine()
		while(line):
			try:
				line = self.readLine()
			except EOFError:
				print("No data")

			self.send("homeway\n")
			
if __name__ == '__main__':
    try:
    	conn = Communicate(sys.argv[1] if len(sys.argv) > 1 else port)
    	conn.main()
    except KeyboardInterrupt:
        print("ERROR")
        exit()