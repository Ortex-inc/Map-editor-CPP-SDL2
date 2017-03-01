 #include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "inputHandle.h"
class Source {
	public:
	SDL_Surface *surface;

	Source(const char*src){
	surface=NULL;
	surface=IMG_Load(src);
}
}btn("src/button.png"),dark("src/dark.png");;



class Menu{

	public:
Uint8 r,b,g;
int oldY;
bool clicked;
const char * fontPath;
SDL_Color color;
char c;
const char* label;
SDL_Rect ins,dim;
		SDL_Surface*surface=NULL;
		SDL_Texture *texture=NULL;
		TTF_Font *font=NULL;

		Menu(const char * label,const char * fontPath,int size ,char c,bool bold){
				TTF_Init();
				TTF_Font *font=NULL;
				switch(c)
				{
					case'r':r=205;g=51;b=51;break;
				 case't':r=135;g=206;b=235;break;
					default:r=255;g=255;b=255;break;
				}

				clicked=false;
					oldY=0;
					SDL_Color color={r,g,b};
				this->fontPath=fontPath;
				this->label=label;
				font = TTF_OpenFont(this->fontPath, size);
				if(bold){TTF_SetFontStyle(font,TTF_STYLE_BOLD);}
				surface=TTF_RenderText_Solid(font,this->label,color);
ins.w=dim.w=this->surface->w;
ins.h=dim.h=this->surface->h;


}
void position(int,int);
void onClick();
void print();
};
void Menu::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
	this->dim.x=0;
	 this->dim.y=0;
	 this->oldY=this->ins.y+2;
}


void Menu::onClick(){
  if(ins.x<=btnX && ins.x+dim.w>=btnX && ins.y<=btnY && ins.y+dim.h>=btnY ){
      //onClick code
    clicked=true;
  this->ins.y=this->oldY;
    //MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
      }
      else if (btnX==-1 && btnY==-1){
        clicked=false;
      this->ins.y=this->oldY-2;}
}


void Menu::print(){
	SDL_Texture *texture=SDL_CreateTextureFromSurface(screen,surface);
	SDL_RenderCopy(screen,texture,&dim,&ins);
	SDL_DestroyTexture(texture);
}

class Button{
public:
	SDL_Texture *texture;
	SDL_Rect dim,ins;
	bool clicked;
	short oldY;
	Button(){
texture=SDL_CreateTextureFromSurface(screen,btn.surface);
clicked=false;
}

		void position(int,int);
		void size(int,int,int,int);
		void onClick(void);
		void print(void);
};

	void Button::position(int x,int y){
		this->ins.x=x;
		this->ins.y=y;
		this->oldY=this->ins.y+2;
	}
	void Button::size(int x,int y,int w,int h){
		this->dim.x=x;
		this->dim.y=y;

		this->dim.w=this->ins.w=w;
		this->dim.h=this->ins.h=h;

	}

	void Button::onClick(){
		if(ins.x<=btnX && ins.x+dim.w>=btnX && ins.y<=btnY && ins.y+dim.h>=btnY ){
				//onClick code
			clicked=true;
				this->ins.y=this->oldY;
			//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
				}
				else if (btnX==-1 && btnY==-1){clicked=false;
				this->ins.y=this->oldY-2;
			}

	}

	void Button::print(){
		SDL_RenderCopy(screen,texture ,&dim,&ins);
	}

/////////////////////////////////////::::

class Sprite{
public:
	SDL_Texture *texture;
	SDL_Surface *surface;
	SDL_Rect dim,ins;
	bool clicked;
	short oldY;
	const char * src;
  int index;
	Sprite(){
		surface=NULL;
		texture=NULL;
		surface=IMG_Load(this->src);
				texture=SDL_CreateTextureFromSurface(screen,surface);
index=0;
dim.x=dim.y=0;
ins.w=ins.h=dim.w=dim.h=45;
		clicked=false;

	}

		void position(int,int);
		void size(int,int,int,int);
		void onClick(void);
		void clean();
		void print(void);
};

	void Sprite::position(int x,int y){
		this->ins.x=x;
		this->ins.y=y;
		this->oldY=this->ins.y+2;
	}
	void Sprite::size(int x,int y,int w,int h){
		this->dim.x=x;
		this->dim.y=y;

		this->dim.w=this->ins.w=w;
		this->dim.h=this->ins.h=h;

	}

	void Sprite::onClick(){
		if(ins.x<=btnX && ins.x+ins.w>=btnX && ins.y<=btnY && ins.y+ins.h>=btnY ){
				//onClick code
			clicked=true;
				this->ins.y=this->oldY;
			//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
				}
				else {clicked=false;
				this->ins.y=this->oldY-2;
			}

	}

	void Sprite::print(){
		SDL_RenderCopy(screen,texture ,&dim,&ins);
	}
	void Sprite::clean(){
    surface=NULL;
	surface=IMG_Load(this->src);
		texture=SDL_CreateTextureFromSurface(screen,surface);

	}
//////////////////////////////////////////////////////////////::::::::::::::::::::::
class Tile{
public:
	SDL_Texture *texture;
	SDL_Surface *surface;
	SDL_Rect dim,ins;
	bool clicked,on;
	bool busy;
	short oldY;
	const char * src;
	Tile(){
		busy=false;
		surface=NULL;
		texture=NULL;
		//surface=IMG_Load(this->src);
				texture=SDL_CreateTextureFromSurface(screen,dark.surface);

		clicked=false;on=false;

	}

		void position(int,int);
		void size(int,int,int,int);
    void onMouse(void);

		void onClick(void);
		void clean();
		void print(void);
};

	void Tile::position(int x,int y){
		this->ins.x=x;
		this->ins.y=y;
		this->oldY=this->ins.y+2;
	}
	void Tile::size(int x,int y,int w,int h){
		this->dim.x=x;
		this->dim.y=y;

		this->dim.w=this->ins.w=w;
		this->dim.h=this->ins.h=h;

	}

	void Tile::onMouse(){
		if(ins.x<=hovX && ins.x+ins.w>=hovX && ins.y<=hovY && ins.y+ins.h>=hovY ){
				//onClick code
			on=true;
				this->ins.y=this->oldY;
			//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
				}
				else {on=false;
				this->ins.y=this->oldY-2;
			}

	}
  void Tile::onClick(){
    if(ins.x<=btnX && ins.x+ins.w>=btnX && ins.y<=btnY && ins.y+ins.h>=btnY ){
        //onClick code
      clicked=true;
        this->ins.y=this->oldY;
      //MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
        }
        else {clicked=false;
        this->ins.y=this->oldY-2;
      }

  }


	void Tile::print(){
		SDL_RenderCopy(screen,texture ,&dim,&ins);
	}
	void Tile::clean(){
	//surface=IMG_Load(this->src);
		texture=SDL_CreateTextureFromSurface(screen,surface);

	}
  class Hover{
public:
SDL_Rect ins;
bool pop_up;
short selected;
Hover(){ins.x=ins.y=0;selected=0;}
    void position(int,int);
    void size(int,int);
    void print();
  };


  void Hover::size(int w,int h){

	  this->ins.w=w;
	  this->ins.h=h;
	  }

	    void Hover::position(int x,int y){

	  this->ins.x=x;
	  this->ins.y=y;
	  }


  void Hover::print(){
	  SDL_SetRenderDrawColor(screen,180,180,180,160);
   SDL_RenderFillRect(screen, &this->ins);
 }

class Super_global{
	public:
int SG_map;
int SG_sprite;
  Super_global(){
    SG_map=SG_sprite=0;
  }
};

class List{
public:
  SDL_Rect ins;
int column;
int row;
int marge;
int begin,end;
int dock;
List(int column,int row,int marge){
this->column=column;
this->row=dock=row;
this->marge=marge;


}
void position(int,int);
void size(int,int);
void gui();
void range();
void print();
};

class Page{
public:
  int begin;
  int end;
  int index;
  Page(){this->begin=this->index=this->end=0;}

};
