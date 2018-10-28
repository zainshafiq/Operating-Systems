/*
*		C Code
*		References;
*		~https://app.schoology.com/assignment/1629062801/info
*		~https ://gist.github.com/trevortomesh/46ffd772a26a8e0ffddef7daf6f63a0a
*		~https ://gist.github.com/trevortomesh/505ef6e4e2f778047a324fa37168b138
*		~http ://math.msu.su/~vvb/2course/Borisenko/CppProjects/GWindow/xintro.html#input
*/
		
#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
		  int main(void)
	  {
		  //Declaring variables
		  Display *d;
		  Window w;
		  XEvent e;
		  Colormap screen_colormap;
		  XColor red, green, blue, black, purple, cyan, magenta, yellow, grey, orange;
		  const char *msg = "Welcome to 'Are You Actually Colour Blind' Game ~";
		  const char *msg2 = "Please click or type in the first letter for the right answer ~";
		  const char *quest = "= ?";
		  const char *win = "Correct!";
		  const char *lose = "Damnnnnn you're color blind ehhh~ Cool Beans~ (exit)";
		  const char *bye = "Nicely done XD \n";
		  int s, marks, sum;
		  d = XOpenDisplay(NULL);
		  //If can't open, print error
		  if (d == NULL)
		  {
			  fprintf(stderr, "Cannot open display\n");
			  exit(1);
		  }
		  s = DefaultScreen(d);
		  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 500, 500, 5, BlackPixel(d, s),
			  WhitePixel(d, s));
		  XSelectInput(d, w, ExposureMask | ButtonPressMask | KeyPressMask);
		  XMapWindow(d, w);
		  screen_colormap = DefaultColormap(d, s);
		  XAllocNamedColor(d, screen_colormap, "red", &red, &red);
		  XAllocNamedColor(d, screen_colormap, "blue", &blue, &blue);
		  XAllocNamedColor(d, screen_colormap, "green", &green, &green);
		  XAllocNamedColor(d, screen_colormap, "cyan", &cyan, &cyan);
		  XAllocNamedColor(d, screen_colormap, "magenta", &magenta, &magenta);
		  while (1)
		  {
			  XNextEvent(d, &e);
			  if (e.type == Expose)
			  {
				  //Creating Strings
				  XDrawString(d, w, DefaultGC(d, s), 10, 50, msg, strlen(msg));
				  XDrawString(d, w, DefaultGC(d, s), 10, 90, msg2, strlen(msg2));
				  XDrawString(d, w, DefaultGC(d, s), 50, 140, quest, strlen(quest));
				  XDrawString(d, w, DefaultGC(d, s), 50, 190, quest, strlen(quest));
				  XDrawString(d, w, DefaultGC(d, s), 50, 240, quest, strlen(quest));
				  XDrawString(d, w, DefaultGC(d, s), 50, 290, quest, strlen(quest));
				  XDrawString(d, w, DefaultGC(d, s), 50, 340, quest, strlen(quest));
				  //Rectangles
				  //Red Box Quiz (Position, Size)
				  XSetForeground(d, DefaultGC(d, s), red.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 10, 120, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), black.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 70, 120, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), purple.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 140, 120, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), cyan.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 210, 120, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), red.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 280, 120, 30, 30);
				  //Green Box Quiz (Position, Size)
				  XSetForeground(d, DefaultGC(d, s), green.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 10, 170, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), magenta.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 70, 170, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), red.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 140, 170, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), green.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 210, 170, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), blue.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 280, 170, 30, 30);
				  //Blue Box Quiz (Position, Size)
				  XSetForeground(d, DefaultGC(d, s), blue.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 10, 220, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), purple.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 70, 220, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), blue.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 140, 220, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), orange.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 210, 220, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), yellow.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 280, 220, 30, 30);
				  //Cyan Box Quiz (Position, Size)
				  XSetForeground(d, DefaultGC(d, s), cyan.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 10, 270, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), cyan.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 70, 270, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), black.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 140, 270, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), orange.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 210, 270, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), green.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 280, 270, 30, 30);
				  //Magenta Quiz (Position, Size)
				  XSetForeground(d, DefaultGC(d, s), magenta.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 10, 320, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), red.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 70, 320, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), green.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 140, 320, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), purple.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 210, 320, 30, 30);
				  XSetForeground(d, DefaultGC(d, s), magenta.pixel);
				  XFillRectangle(d, w, DefaultGC(d, s), 280, 320, 30, 30);
			  }
			  //Guide on the terminal
			  printf("\nr = red \nb = blue \ng = green \nm = magenta \nc = cyan \n");
			  //KeyPress XEvent (Choosing the answer by using the keyboard)
			  if (e.type == KeyPress)
			  {
				  printf("KeyPress: %x\n", e.xkey.keycode);
				  //If the user press r for red
				  if (e.xkey.keycode == 0x1b)
				  {
					  printf("Red \n");
					  XSetForeground(d, DefaultGC(d, s), red.pixel);
					  XFillRectangle(d, w, DefaultGC(d, s), 350, 120, 30, 30);
					  XDrawString(d, w, DefaultGC(d, s), 400, 140, win, strlen(win));
					  marks++;
				  }
				  //If the user press g for green
				  else if (e.xkey.keycode == 0x2a)
				  {
					  printf("Green \n");
					  XSetForeground(d, DefaultGC(d, s), green.pixel);
					  XFillRectangle(d, w, DefaultGC(d, s), 350, 170, 30, 30);
					  XDrawString(d, w, DefaultGC(d, s), 400, 190, win, strlen(win));
					  marks++;
				  }
				  //If the user press b for blue
				  else if (e.xkey.keycode == 0X38)
				  {
					  printf("Blue \n");
					  XSetForeground(d, DefaultGC(d, s), blue.pixel);
					  XFillRectangle(d, w, DefaultGC(d, s), 350, 220, 30, 30);
					  XDrawString(d, w, DefaultGC(d, s), 400, 240, win, strlen(win));
					  marks++;
				  }
				  //If the user press c for cyan
				  else if (e.xkey.keycode == 0X36)
				  {
					  printf("Cyan \n");
					  XSetForeground(d, DefaultGC(d, s), cyan.pixel);
					  XFillRectangle(d, w, DefaultGC(d, s), 350, 270, 30, 30);
					  XDrawString(d, w, DefaultGC(d, s), 400, 290, win, strlen(win));
					  marks++;
				  }
				  //If the user press m for magenta
				  else if (e.xkey.keycode == 0x3a)
				  {
					  printf("Magenta \n");
					  XSetForeground(d, DefaultGC(d, s), magenta.pixel);
					  XFillRectangle(d, w, DefaultGC(d, s), 350, 320, 30, 30);
					  XDrawString(d, w, DefaultGC(d, s), 400, 340, win, strlen(win));
					  marks++;
				  }
				  else
				  {
					  //Print on the terminal that the user has lost
					  printf("Damnnnnn you're color blind ehhh~ Cool Beans~ (exit) \n");
					  //Print on the game window that the user lost and exit
					  immediately
						  XDrawString(d, w, DefaultGC(d, s), 20, 400, lose, strlen(lose));
					  if (e.type == KeyPress)
						  break;
					  if (e.type == ButtonPress)
						  break;
				  }
			  }
			  //ButtonPress XEvent (Choosing the answers by clicking the mouse)
			  else if (e.type == ButtonPress)
			  {
				  //Coordinates of the place that user clicked on the window
				  printf("You pressed a button at (%i,%i)\n",
					  e.xbutton.x, e.xbutton.y);
				  //Checking the answer
				  //Clicking the red box
				  if ((e.xbutton.x >= 280 && e.xbutton.x <= 310) && (e.xbutton.y >= 120 &&
					  e.xbutton.y <= 150))
				  {
					  XDrawString(d, w, DefaultGC(d, s), 400, 140, win, strlen(win));
					  marks++;
				  }
				  //Clicking the green box
				  else if ((e.xbutton.x >= 210 && e.xbutton.x <= 240) && (e.xbutton.y >= 170
					  && e.xbutton.y <= 200))
				  {
					  XDrawString(d, w, DefaultGC(d, s), 400, 190, win, strlen(win));
					  marks++;
				  }
				  //Clicking the blue box
				  else if ((e.xbutton.x >= 140 && e.xbutton.x <= 170) && (e.xbutton.y >= 220
					  && e.xbutton.y <= 250))
				  {
					  XDrawString(d, w, DefaultGC(d, s), 400, 240, win, strlen(win));
					  marks++;
				  }
				  //Clicking the cyan box
				  else if ((e.xbutton.x >= 70 && e.xbutton.x <= 100) && (e.xbutton.y >= 270 &&
					  e.xbutton.y <= 300))
				  {
					  XDrawString(d, w, DefaultGC(d, s), 400, 290, win, strlen(win));
					  marks++;
				  }
				  //Clicking the magenta box
				  else if ((e.xbutton.x >= 280 && e.xbutton.x <= 310) && (e.xbutton.y >= 320
					  && e.xbutton.y <= 350))
				  {
					  XDrawString(d, w, DefaultGC(d, s), 400, 340, win, strlen(win));
					  marks++;
				  }
				  else
				  {
					  //Print on the terminal that you lose
					  printf("Damnnnnn you're color blind ehhh~ Cool Beans~ (exit) \n");
					  //Print on the game window that you lose and exit immediately
					  XDrawString(d, w, DefaultGC(d, s), 20, 400, lose, strlen(lose));
					  if (e.type == KeyPress)
						  break;
					  if (e.type == ButtonPress)
						  break;
				  }
			  }
			  //Checking total marks
			  if (marks >= 5)
			  {
				  //Print on the terminal that the user win
				  printf("Congratulations!! Nicely done XD \n");
				  //Print on the game window that the user win and exit immediately
				  XDrawString(d, w, DefaultGC(d, s), 20, 400, bye, strlen(bye));
				  if (e.type == KeyPress)
					  break;
				  if (e.type == ButtonPress)
					  break;
			  }
		  }
		  XCloseDisplay(d);
		  return 0;
}
	  


