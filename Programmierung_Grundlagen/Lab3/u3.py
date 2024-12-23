from turtle import *


penup()
goto(-125,-150)     #define starting point
pendown()
for i in range(4):      #patrat
    forward(250)
    left(90)


penup()
goto(-185,100)       #define roof starting point
pendown()
forward(370)            #dach
left(150)
forward(213)
left(60)
forward(213)


penup()
goto(-80, -150)         #define door starting point
right(30)
pendown()
right(90)               #tur
forward(120)
right(90)
forward(60)
right(90)
forward(120)

speed(1)
penup()
goto(20, 30)        #fenster
pendown()
for i in range(4):
    forward(70)
    left(90)




