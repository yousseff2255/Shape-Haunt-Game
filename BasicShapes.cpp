#include "BasicShapes.h"
#include "shape.h"
#include "gameConfig.h"
#include "game.h"
#include "fstream"
using namespace std;

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth, color fillcolor) :shape(r_pGame, ref)
{
	hght = r_hght;
	wdth = r_wdth;
	this->fillColor = fillcolor;
	borderColor = fillcolor;

}
Rect::~Rect() {};
void Rect::draw() 
{
	window* pW = pGame->getWind();	//get interface window

	upperLeft.x = RefPoint.x - wdth / 2;  //Calculate rectangle vertices according to the reference point
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);	
}
void Rect::Flip() {
	if (!flipped) {
		RefPoint.x -= wdth;
		flipped = true;
	}
	else {
		RefPoint.x += wdth;
		flipped = false;
	}


		
}
void Rect::Rotate() {

	int temp = hght;
	hght = wdth;
	wdth = temp;

	


}
int Rect::getheight()
{
	return hght;
}
int Rect::getwidth()
{
	return wdth;
}
void Rect::resizeUp()
{
	wdth = wdth * 2;
	hght = hght * 2;
}
void Rect::resizeDown()
{
	wdth = wdth * 0.5;
	hght = hght * 0.5;
}
void Rect::move(char key) {
	point newRef;
	switch (key) {
	case 2:                      //Down arrow
		newRef = { this->getRefPoint().x,this->getRefPoint().y + config.gridSpacing };
		if (newRef.y + hght/2 < (config.windHeight - config.statusBarHeight))
			this->setRefPoint(newRef);
		break;
	case 4:                      //Left arrow
		newRef = { this->getRefPoint().x - config.gridSpacing,this->getRefPoint().y };
		if (newRef.x - wdth / 2 > 0)
			this->setRefPoint(newRef);
		break;
	case 6:                       //right arrow
		newRef = { this->getRefPoint().x + config.gridSpacing,this->getRefPoint().y };
		if (newRef.x + wdth / 2 < config.windWidth)
			this->setRefPoint(newRef);
		break;
	case 8:                      //Up arrow
		newRef = { this->getRefPoint().x ,this->getRefPoint().y - config.gridSpacing };
		if (newRef.y - hght/2 > config.toolBarHeight)
			this->setRefPoint(newRef);
		break;

	}
}
int Rect::getblockbase() {
	return wdth;
}
int Rect::getblockheight() {
	return hght;
}
ShapeType Rect::getShapeType() const
{
	return RCT;
}
void Rect::save(ofstream& OutFile)
{
	OutFile << RCT << "\n" << hght << "\n" << wdth;
}
void Rect::load(ifstream& InFile)
{
	InFile >> wdth;
}






circle::circle(game* r_pGame, point ref, int r, color fillcolor) :shape(r_pGame, ref)
{

	rad = r;
	this->fillColor = fillcolor;
	borderColor = fillcolor;
}
circle::~circle() {};
int circle::getradius()
{
	return rad;
}
void circle::draw() 
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);

}
void circle::Flip() {
	if (!flipped) {
		RefPoint.x -= 2*rad;
		flipped = true;
	}

	else {
		RefPoint.x += 2*rad;
		flipped = false;
	}
}
void circle::Rotate() {

}
void circle::resizeUp()
{
	rad = rad * 2;
}
void circle::resizeDown()
{
	rad = rad * 0.5;
}
ShapeType circle::getShapeType() const
{
	return CRC;
}
void circle::move(char key) {
	point newRef;
	switch (key) {
	case 2:                      //Down arrow
		newRef = { this->getRefPoint().x,this->getRefPoint().y + config.gridSpacing };
		if (newRef.y + rad < (config.windHeight - config.statusBarHeight))
			this->setRefPoint(newRef);
		break;
	case 4:                      //Left arrow
		newRef = { this->getRefPoint().x - config.gridSpacing,this->getRefPoint().y };
		if (newRef.x - rad > 0)
			this->setRefPoint(newRef);
		break;
	case 6:                       //right arrow
		newRef = { this->getRefPoint().x + config.gridSpacing,this->getRefPoint().y };
		if (newRef.x + rad < config.windWidth)
			this->setRefPoint(newRef);
		break;
	case 8:                      //Up arrow
		newRef = { this->getRefPoint().x ,this->getRefPoint().y - config.gridSpacing };
		if (newRef.y - rad > config.toolBarHeight)
			this->setRefPoint(newRef);
		break;

	}
}
int circle::getblockbase() {
	return rad * 2;
}
int circle::getblockheight() {
	return rad * 2;
}
void circle::save(ofstream& OutFile)
{
	OutFile << CRC << "\n" << rad << "\n";
}
void circle::load(ifstream& InFile)
{
	InFile >> rad;
}




Triangle::Triangle(game* r_pGame, point ref, int r_base, int r_height, color fillcolor) :shape(r_pGame, ref)
{
	base = r_base;
	height = r_height;
	vertix1.x = RefPoint.x - 0.5 * base;
	vertix1.y = RefPoint.y + 0.5 * height;
	vertix2.x = RefPoint.x + 0.5 * base;
	vertix2.y = RefPoint.y + 0.5 * height;
	vertix3.x = RefPoint.x;
	vertix3.y = RefPoint.y - 0.5 * height;
	nrefr = RefPoint;
	this->fillColor = fillcolor;
	borderColor = fillcolor;

}
Triangle::~Triangle() {};
void Triangle::draw()
{
	window* pW = pGame->getWind(); //get interface window
	pW->SetPen(fillColor, config.penWidth);
	pW->SetBrush(fillColor);
	

	pW->DrawTriangle(vertix1.x, vertix1.y, vertix2.x, vertix2.y, vertix3.x, vertix3.y, FILLED);
}
int Triangle::getbase()
{
	return base;
}
int Triangle::getheight()
{
	return height;
}
void Triangle::Flip() {
			 RefPoint.x -= 2*(RefPoint.x - axis);
			 vertix1.x -= 2 * (vertix1.x - axis);
			 vertix2.x -=2* (vertix2.x - axis);
			 vertix3.x -= 2* (vertix3.x - axis);
			 if (!flipped)
				 flipped = true;
			 else
				 flipped = false;
	
}
void Triangle::Rotate() {
	int x1, y1, x2, y2, x3, y3;
	int nx1, ny1, nx2, ny2, nx3, ny3;


	x1 = vertix1.x - RefPoint.x;
	y1 = vertix1.y - RefPoint.y;

	x2 = vertix2.x - RefPoint.x;
	y2 = vertix2.y - RefPoint.y;

	x3 = vertix3.x - RefPoint.x;
	y3 = vertix3.y - RefPoint.y;

	nx1 = -y1;
	ny1 = x1;

	nx2 = -y2;
	ny2 = x2;

	nx3 = -y3;
	ny3 = x3;

	vertix1.x = nrefr.x + nx1;
	vertix1.y = nrefr.y + ny1;

	vertix2.x = nrefr.x + nx2;
	vertix2.y = nrefr.y + ny2;

	vertix3.x = nrefr.x + nx3;
	vertix3.y = nrefr.y + ny3;


}
int Triangle::getblockbase() {
	return base;
}
int Triangle::getblockheight() {
	return height;
}
ShapeType Triangle::getShapeType() const
{
	return TRI;
}
void Triangle::move(char key) {
	point newRef;
	switch (key) {
	case 2:                      //Down arrow
		newRef = { this->getRefPoint().x,this->getRefPoint().y + config.gridSpacing };
			this->setRefPoint(newRef);

			vertix1.y += config.gridSpacing;
			vertix2.y += config.gridSpacing;
			vertix3.y += config.gridSpacing;
		break;
	case 4:                      //Left arrow
		newRef = { this->getRefPoint().x - config.gridSpacing,this->getRefPoint().y };
			this->setRefPoint(newRef);

			vertix1.x -= config.gridSpacing;
			vertix2.x -= config.gridSpacing;
			vertix3.x -= config.gridSpacing;

		break;
	case 6:                       //right arrow
		newRef = { this->getRefPoint().x + config.gridSpacing,this->getRefPoint().y };
			this->setRefPoint(newRef);
			vertix1.x += config.gridSpacing;
			vertix2.x += config.gridSpacing;
			vertix3.x += config.gridSpacing;
		break;
	case 8:                      //Up arrow
		newRef = { this->getRefPoint().x ,this->getRefPoint().y - config.gridSpacing };
			this->setRefPoint(newRef);

			vertix1.y -= config.gridSpacing;
			vertix2.y -= config.gridSpacing;
			vertix3.y -= config.gridSpacing;
		
		break;

	}
}
void Triangle::dbah()
{
	base = base * 2;
	height = height * 2;
}
void Triangle::hbah()
{
	base = base * 0.5;
	height = height * 0.5;
}
void Triangle::resizeUp()
{

	int x1, y1, x2, y2, x3, y3;
	int nx1, ny1, nx2, ny2, nx3, ny3;


	x1 = vertix1.x - RefPoint.x;
	y1 = vertix1.y - RefPoint.y;

	x2 = vertix2.x - RefPoint.x;
	y2 = vertix2.y - RefPoint.y;

	x3 = vertix3.x - RefPoint.x;
	y3 = vertix3.y - RefPoint.y;

	nx1 = 2*x1;
	ny1 = 2*y1;

	nx2 = 2*x2;
	ny2 = 2*y2;

	nx3 = 2*x3;
	ny3 = 2*y3;

	vertix1.x = nrefr.x + nx1;
	vertix1.y = nrefr.y + ny1;

	vertix2.x = nrefr.x + nx2;
	vertix2.y = nrefr.y + ny2;

	vertix3.x = nrefr.x + nx3;
	vertix3.y = nrefr.y + ny3;
	
}
void Triangle::resizeDown()
{
	int x1, y1, x2, y2, x3, y3;
	int nx1, ny1, nx2, ny2, nx3, ny3;


	x1 = vertix1.x - RefPoint.x;
	y1 = vertix1.y - RefPoint.y;

	x2 = vertix2.x - RefPoint.x;
	y2 = vertix2.y - RefPoint.y;

	x3 = vertix3.x - RefPoint.x;
	y3 = vertix3.y - RefPoint.y;

	nx1 = 0.5 * x1;
	ny1 = 0.5 * y1;

	nx2 = 0.5 * x2;
	ny2 = 0.5 * y2;

	nx3 = 0.5 * x3;
	ny3 = 0.5 * y3;

	vertix1.x = nrefr.x + nx1;
	vertix1.y = nrefr.y + ny1;

	vertix2.x = nrefr.x + nx2;
	vertix2.y = nrefr.y + ny2;

	vertix3.x = nrefr.x + nx3;
	vertix3.y = nrefr.y + ny3;

}
void Triangle::setnrefr(point newref) {
	nrefr = newref;
}
void Triangle::setAxis(int ax) { axis = ax; }
void Triangle::save(ofstream& OutFile)
{
	OutFile << TRI << "\n" << base << "\n" << height;
}
void Triangle::load(ifstream& InFile)
{
	InFile >> base;
}