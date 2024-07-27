# Line Bird

### Project Description

The project utilizes GLUT, the OpenGL Utility Toolkit, which provides a window system-independent framework for developing OpenGL applications. 
OpenGL itself is a versatile, cross-platform API used for rendering 2D and 3D vector graphics.

By leveraging GLUT’s extensive library functions, the project offers a similar gameplay experience to the original Flappy Bird.

In this implementation, the game incorporates fundamental physical principles, such as gravitational law, to enhance the gaming experience. 
The mechanics are designed to closely resemble those of Flappy Bird, with simple and intuitive rules. Players control a bird navigating through moving pipe obstacles, 
aiming to pass through gaps without colliding with the pipes.

Developed in C++, the game features various graphical enhancements to increase visual appeal, including background buildings, 
clouds, grass, flowers, and a dynamic day-night cycle. This case study explores how simpler motion techniques and modifications contribute 
to creating an engaging and visually appealing game environment. The game supports single-player mode and is controlled via keyboard inputs.



### Objectives
```
We made this game or project so that we could give our best in possible ways and show what
we learned. The objectives of this project are:

- To play the famous game flappy bird in computer.
- To make it user friendly.
    - To provide an easy interface.
    - To entertain people in their leisure time.

```

### Proposed System
```
The proposed system is designed to give a minimalistic and simplistic look and feel to the GUI
for Flappy Bird with lots and lots of new graphics. The control of the system is done with a
simple ↑ keystroke or by clicking the mouse.
```

### Game play

Game play is very simple in Flappy Dot. The player has to move the bird through the pipelines
without colliding. If the bird collides with the pipelines the game will come to an end and the
final score will be displayed. If the bird lands on the base of the game it will also come to an
end. The basic idea for the player is to keep the bird untouched from any obstacles.


#### CONCEPT USED

OpenGL is a cross-language, cross-platform application programming interface for rendering
2D and 3D vector graphics. The API is typically used to interact with a graphics processing
unit, to achieve hardware-accelerated rendering. OpenGL libraries and various GL and GLU
commands were used in this project. These are as follows :

```
-> glColor: Set the current color.
-> glBegin and glEnd: Delimit the vertices of a primitive or a group of like primitives.
-> glVertex: These functions specify a vertex.
-> glReadPixels: Reads a block of pixels from the framebuffer.
-> glRasterPos: Specify the raster position for pixel operations.
-> glutBitmapCharacter: renders a bitmap character using OpenGL
-> glClear(): Clears buffers to preset values.
-> glFlush(): Forces execution of OpenGL functions in finite time.
-> glMatrixMode: Specifies which matrix is the current matrix.
-> glLoadIdentity: Replaces the current matrix with the identity matrix.
-> gluOrtho2D: Defines a 2-D orthographic projection matrix.
```
GLUT provides high-level utilities to simplify OpenGL programming, especially in
interacting with the Operating System (such as creating a window, handling key and mouse
inputs). The following GLUT functions were used in the project:

```
-> glutBitmapCharacter: renders a bitmap character using OpenGL
-> glutInit: Initializes GLUT, must be called before other GL/GLUT functions. It takes
the same arguments as the main().
-> glutInitWindowSize: Specifies the initial window width and height, in pixels.
-> glutInitWindowPosition: Positions the top-left corner of the initial window at (x, y).
-> glutCreateWindow: Creates a window with the given title.
-> glutDisplayFunc: Registers the callback function for handling window-paint event.
The OpenGL graphic system calls back this handler when it receives a window re-
paint request.
-> glutMainLoop: Enters the infinite event-processing loop, i.e, put the OpenGL
graphics system to wait for events, and trigger respective event handlers.
-> glutTimerFunc: Registers a timer callback to be triggered in a specified number of
milliseconds.
-> glutReshapeWindow: Requests a change to the size of the current window.
-> glutCreateMenu: Creates a new pop-up menu.
```
Various other GLUT functions like glutAddMenuEntry, glutAttachMenu, glutReshapeFunc,
glutSpecialFunc, etc. are also used in the project code.


#### User Defined Functions
```
1. void Circle(float X, float Y, float r, int S, int Q): To draw all the circles including the
sun, moon and the flaps of the bird.

2.void Flap(float Y): It is used to draw the flaps of the bird.

3.void Bird(float Y): It is used to draw the bird including of circle its eyes ,body and lips.

4.void Rand(): This function is used to create the random values which are further used to
give the random positioning of the pipes.

5.void PIPE1(int X) : This function is used to create the pipe including of its two aligned
together.

6.void PIPE2(int X): This function is used to create the pipe including of its two aligned
together.

7.void PIPE3(int X): This function is used to create the pipe including of its two aligned
together.

8.void PIPE4(int X): This function is used to create the pipe including of its two aligned
together.

9.void GameCheck(int X): This function is used to check the status of the game whether the
bird touches the pole or if it doesn’t then it increases the count of the score.

10 .void SUN_MOON(float X, float Y): This function is used to create the sun and moon.

11.void Cloud(int X, int Y): This function is used to create the clouds in the sky.

12.void drawString(float x, float y, float z, string CH): To display text with

GLUT_BITMAP_TIMES_ROMAN_24 style and size.

13.void drawStringsmall(float x, float y, float z, string CH): To display text with

GLUT_BITMAP_HELVETICA_12 style and size.

14.void BACK(): This function is for background including buildings, grass , flowers,
mountain.

15.void display(): This is the main display function for displaying all the graphics

16.void Jump(int btn, int state, int x, int y): This is using glutMouseFunc() by clicking the
mouse the position of the bird increases by 2 pixels.

17.void Start(unsigned char key, int x, int y): The function glutKeyboardFunc() calls this
to start the game;

18.void myinit(): This function is used in initialising the matrix mode, gluOrtho2D(- 10 , 10 , -
10 , 10 ).

19.int main(int argc, char** argv): This function is used to declare the display, mouse and
keyboard function and creates the window for application.