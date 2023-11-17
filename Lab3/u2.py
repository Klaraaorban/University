import time
from turtle import *
pensize(5)
def curve():
    for i in range(200):
        right(1)
        forward(1)
speed(1)

fillcolor('red')
begin_fill()
left(130)
forward(130)
speed(0)

curve()
left(140)

curve()
speed(1)

forward(130)
end_fill()
time.sleep(1)
