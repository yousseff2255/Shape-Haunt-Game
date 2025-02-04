#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth = 1590, windHeight = 621,	//Window width and height
		wx = 5, wy = 5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight = 60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 60,			//Width of each icon in toolbar
		statusBarHeight = 50,	//Status Bar Height
		hearts_beg_pos_factor = 32, hearts_width = 35, hearts_height = 35,
		XscorePosition = 1400, YscorePosition = 5,
		XlevelPosition = 1400, YlevelPosition = 35,
		ScoreLength = 80,LevelLength=80, XtimePostiion = 1150, YtimePosition = 35, timeLength = 100;
	
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN,	//background color of the status
	        TextColor = BLACK;
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0/3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;
	struct {
		int sidelength = 50;
	}blocks;
	struct {
		int standlength = 80; int standwidth = 10;
	}stand;
	struct {
		int ballradius = 25;
	}ball;

	struct {
		int tipheight = 44;
		int tipwidth = 50;
	}tip;
	struct {
		int bdylength = 80;
		int bdywidth = 15;
	}bdy;
	struct {
		int bodyheight = 100;
		int bodywidth = 100;
		int legheight = 35;
		int legwidth = 20;
		int handwidth = 20;
		int handlength = 60;
		int faceradius = 35;
	}strawman;
	struct{
		int BodyLength = 100;
		int BodyWidth = 25;
		int BulletRadius = 10;
		int GetBase = 40;
		int GetHeight = 50;
	}Gun;
	struct {
		int bodyheight = 100;
		int bodyLength = 80;
		int roofheight = 45;
		int roofwidth = 100;
	}house;

	struct {
		int getradius = 25;
		int getTRIBase = 50;
		int getTRIheight = 50;
		int	GetRectHeight = 100;
		int getRectWidth = 10;
	}balance;


}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,		//Sign shape item
	ITM_PTR,
	ITM_HOUSE,
	ITM_MAN,
	ITM_GUN,
	ITM_BALL,
	ITM_BAL,
	ITM_HINT,
	ITM_ROT,
	ITM_FLP,
	ITM_INC,
	ITM_DEC,
	ITM_DEL,
	ITM_SAVE,
	ITM_LOAD,
	ITM_REF,
	ITM_LVL,


	ITM_EXIT,
	//Exit item
//TODO: Add more items names here
	

	ITM_CNT	,	//no. of toolbar items ==> This should be the last line in this enum
	ITM_NULL
};




