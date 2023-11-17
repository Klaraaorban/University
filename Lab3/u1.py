from turtle import *
import time
speed(1)
for i in range(2):
    forward(200)
    left(90)
    forward(100)
    left(90)

penup()
forward(75)
left(90)
forward(37)
pendown()
for j in range(2):
    forward(25)
    right(90)
    forward(50)
    right(90)

time.sleep(1)
