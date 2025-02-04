#pragma once
#include "Basicshapes.h"

class Sign :public shape
{
	Rect* base;
	Rect* top;
	point topRef, baseRef;


public:
	Sign(game* r_pGame, point ref, color fillcolor);
	~Sign();
	virtual void draw() ;
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Rotate() override;
	virtual void Flip() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};



class pointerToAball : public shape


{
	Rect* Ptrbdy;
	circle* ball;
	Triangle* ptrtip;
	point ptrbdyref, ballref, ptrtipref;
public:
	pointerToAball(game* r_game, point ref, color fillcolor);
	~pointerToAball();
	virtual void draw();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	/*virtual void save(ofstream& OutFile) override;*/
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};

class Gun : public shape
{
	circle* bullet1;
	circle* bullet2;
	Rect* body;
	Triangle* hand;
	point handref, bullet1ref, bullet2ref, bodyref;
public:
	Gun(game* r_game, point ref, color fillcolor);
	~Gun();
	virtual void draw();
	
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};



class standingball : public shape
{
	Rect* stand;
	circle* ball;
	point standref, ballref;
public:
	standingball(game* r_game, point ref, color fillcolor);
	~standingball();
	virtual void draw();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};


class strawman : public shape
{
	Triangle* body;
	Rect* hand1;
	Rect* hand2;
	Triangle* Leg1;
	Triangle* Leg2;
	circle* Face;
	point bodyref, hand1ref, hand2ref, leg1ref, leg2ref, faceref;
public:
	strawman(game* r_game, point ref, color fillcolor);
	~strawman();
	virtual void draw();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};



class house : public shape
{
	Triangle* roof;
	Rect* body;
	point bodyref, roofref;

public:
	house(game* r_game, point ref, color fillcolor);
	~house();
	virtual void draw();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};



class balance : public shape
{
	Triangle* tri;
	Rect* rec;
	circle* circ;
	point triRef, recRef, circRef;
public:
	balance(game* r_game, point ref, color fillcolor);
	~balance();
	virtual void draw();
	virtual ShapeType getShapeType() const;
	virtual void move(char);
	virtual void resizeUp() override;
	virtual void resizeDown() override;
	virtual void Flip();
	virtual void Rotate() override;
	virtual int getblockbase()override;
	virtual int getblockheight()override;
	virtual void save(ofstream& OutFile) override;
	virtual void load(ifstream& Infile) override;
	void setxrange(int);
	void setyrange(int);
};