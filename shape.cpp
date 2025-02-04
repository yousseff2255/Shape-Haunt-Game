#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
	flipped = false;
	rotated = 0;
}
shape::~shape() {};

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
point shape::getRefPoint() {
	return RefPoint;
}


bool shape::GetFlipStatus() {
	return flipped;
}

void shape::setxrange(int base) {
	min_x = RefPoint.x - (base / 2);
	max_x = RefPoint.x + (base / 2);
}
void shape::setyrange(int height) {
	min_y = RefPoint.y - (height / 2);
	max_y = RefPoint.y + (height / 2);
}
int shape::getxmax()const {
	return max_x;
}
int shape::getymax()const {
	return max_y;
}
int shape::getxmin()const {
	return min_x;
}
int shape::getymin()const {
	return min_y;
}
void shape::setcolor(color c) {
	fillColor = c;
}
int shape::getrotated() const{
	return rotated;
}
int shape::getsize()const {
	return size; 
}
bool shape::returnsaved()const {
	return saved;
}

