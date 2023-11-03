from turtle import *

def curve2():
    for i in range(180):
        right(1)
        forward(1)

#FIRST HOUSE
speed(0)
penup()
goto(-300,-150)     #define starting point
pendown()
for i in range(4):      #patrat
    forward(250)
    left(90)


penup()
goto(-360,100)       #define roof starting point
pendown()
forward(370)            #dach
left(150)
forward(213)
left(60)
forward(213)


penup()
goto(-250, -150)         #define door starting point
right(30)
pendown()
right(90)               #tur
forward(130)
right(90)
forward(65)
right(90)
forward(130)

penup()
goto(-155, 30)        #fenster
pendown()
for i in range(4):
    forward(70)
    left(90)
penup()
goto(-155, -5)
left(90)                        #horizontal line
pendown()
forward(70)

penup()
goto(-120, 30)
right(90)
pendown()
forward(70)

#SECOND HOUSE
penup()
goto(100,-250)
left(90)
pendown()
for i in range(2):          #higher house
    forward(200)
    left(90)
    forward(350)
    left(90)

penup()
goto(70, 100)
pendown()
for i in range(3):      #dach
    forward(260)
    left(120)

penup()
goto(145, -250)     #curved door
left(90)
pendown()
forward(100)
curve2()
forward(100)
#speed(3)

penup()
goto(170, -35)      #lower window
pendown()
circle(30)

penup()
goto(170, 45)       #upper window
pendown()
circle(30)

