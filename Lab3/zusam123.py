from turtle import *
import time

def curve():
    for i in range(200):
        right(1)
        forward(1)

def curve2():
    for i in range(180):
        right(1)
        forward(1)

def rechteck():
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

def herz():
    pensize(5)
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

def zwei_hauser():
    # FIRST HOUSE
    speed(0)
    penup()
    goto(-300, -150)  # define starting point
    pendown()
    for i in range(4):  # patrat
        forward(250)
        left(90)

    penup()
    goto(-360, 100)  # define roof starting point
    pendown()
    forward(370)  # dach
    left(150)
    forward(213)
    left(60)
    forward(213)

    penup()
    goto(-250, -150)  # define door starting point
    right(30)
    pendown()
    right(90)  # tur
    forward(130)
    right(90)
    forward(65)
    right(90)
    forward(130)

    penup()
    goto(-155, 30)  # fenster
    pendown()
    for i in range(4):
        forward(70)
        left(90)
    penup()
    goto(-155, -5)
    left(90)  # horizontal line
    pendown()
    forward(70)

    penup()
    goto(-120, 30)
    right(90)
    pendown()
    forward(70)

    # SECOND HOUSE
    penup()
    goto(100, -250)
    left(90)
    pendown()
    for i in range(2):  # higher house
        forward(200)
        left(90)
        forward(350)
        left(90)

    penup()
    goto(70, 100)
    pendown()
    for i in range(3):  # dach
        forward(260)
        left(120)

    penup()
    goto(145, -250)  # curved door
    left(90)
    pendown()
    forward(100)
    curve2()
    forward(100)
    # speed(3)

    penup()
    goto(170, -35)  # lower window
    pendown()
    circle(30)

    penup()
    goto(170, 45)  # upper window
    pendown()
    circle(30)

opt = int(input("welche option mochten sie sehen? (bis 1-3):  "))
def switch(opt):
    if opt == 1:
        rechteck()
    elif opt == 2:
        herz()
    elif opt == 3:
        zwei_hauser()
    elif opt == 0:
        return 0

