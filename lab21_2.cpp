#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *a, Rect *b){
	double loc[4], side[2];
	loc[0] = (a->x >= b->x)? a->x : b->x;
	loc[1] = (a->x + a->w <= b->x + b->w)? a->x + a->w : b->x + b->w;
	loc[2] = (a->y <= b->y)? a->y : b->y;
	loc[3] = (a->y - a->h >= b->y - b->h)? a->y - a->h : b->y - b->h;
	side[0] = loc[1] - loc[0];
	side[1] = loc[2] - loc[3];
	return (side[0] > 0 && side[1] > 0)? side[0]*side[1] : 0;
}
