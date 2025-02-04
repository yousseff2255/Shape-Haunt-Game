//Header file for Basic shapes in the game
#pragma once
#include "shape.h"



class Rect:public shape
{
	int hght, wdth;	//height and width of the recangle
	
	point upperLeft, lowerBottom;
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth, color fillcolor);
	virtual void draw() ;
	virtual void Rotate() override;
	int getheight();
	int getwidth();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp();
	virtual void resizeDown();
	virtual void Flip() override;
	virtual int getblockheight()override;
	virtual int getblockbase()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	~Rect();
};




class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
	

public:
	circle(game* r_pGame, point ref, int r, color fillcolor);	//add more parameters for the constructor if needed
	virtual void draw()  override ;
	virtual void Flip();
	virtual void Rotate() override;
	int getradius();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp();
	virtual void resizeDown();
	virtual int getblockheight()override;
	virtual int getblockbase()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	~circle();
};



class Triangle : public shape
{
	int base, height;
	point vertix1,vertix2,vertix3,nrefr;


public:
	Triangle(game* r_pGame, point ref, int r_base, int r_height, color fillcolor);
	virtual void draw() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	int getheight();
	int getbase();
	void dbah();
	void hbah();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	void setAxis(int);
	void setnrefr(point);
	virtual int getblockheight()override;
	virtual int getblockbase()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	~Triangle();
};