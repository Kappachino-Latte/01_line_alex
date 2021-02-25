#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

	int x, y;
	
	if (x0 > x1) {
    		int x_temp = x0;
    		x0 = x1;
    		x1 = x_temp;
    		
    		int y_temp = y0;
    		y0 = y1;
    		y1 = y_temp;
    		
    		x = x0;
    		y = y0;
  	}
  	else {
  		x = x0;
  		y = y0;
  	}
	
	int dx = x1 - x0;
	int dy = y1 - y0;
	
	//vertical line
	if (!dx) {
		while (y <= y1) {
			plot (s, c, x, y);
			y++;
		}
	}
	
	//horizontal
	else if (!dy) {
		while (x <= x1) {
			plot (s, c, x, y);
			x++;
		}
	}
	
	//slope = 1
	else if (dy == dx) {
		while (x <= x1) {
			plot (s, c, x, y);
			x++;
			y++;
		}
	}
	
	//slope = -1
	else if (-dy == dx) {
		while (x <= x1) {
			plot (s, c, x, y);
			x++;
			y--;
		}
	}
	
	int a, b, d;
	a = dy;
	b = -dx;
	
	//Octant 1 and 5, 0 < m < 1
	if ((dx > dy) && (dy > 0)) {
		d = (2 * a) + b;
		while (x <= x1) {
			plot (s, c, x, y);
			if (d > 0) {
				y++;
				d += 2*b;
			}
		x++;
		d += 2*a;
		}
	}
	
	//Octant 2 and 6, 1 < m < infinity 
	else if (dy > dx) {
		d = (2 * b) + a;
		while (y <= y1) {
		plot (s, c, x, y);
			if (d < 0) {
				x++;
				d += 2*a;
			}
		y++;
		d += 2*b;
		}
	}
			
	//Octant 8 and 4, -1 < m < 0
	else if (dx > -dy) {
		d = (2 * a) - b;
		while (x <= x1) {
			plot (s, c, x, y);
			if (d < 0) {
				y--;
				d -= 2*b;
			}
		x++;
		d += 2*a;
		}
	}
	
	//Octant 7 and 3, -infinity < m < -1
	else {
		d = (2 * -b) + a;
		while (y >= y1) {
		plot (s, c, x, y);
			if (d > 0) {
				x++;
				d += 2*a;
			}
		y--;
		d -= 2*b;
		}
	}
}
