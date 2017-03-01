#ifndef BOARD_H
#define BOARD_H
#include "inputHandle.h"

#include "sprite.h"
 int GirdW=675;
 int GirdH=450;
 int box=45;
 int x,y=0;
  int tile_num=(GirdW/box)*(GirdH/box);
int arrayY,arrayX=0;
bool generate_btn()
{
if(button.empty()){
		button.push_back(Button());
		button.push_back(Button());
	//	button.push_back(Button());

		button[0].size(0,0,104,40);
		button[1].size(108,0,132,40);
	//  button[2].size(242,0,104,40);

		button[0].position(SCREEN_WIDTH-button[0].ins.w*3,SCREEN_HEIGHT-button[0].ins.h);
		button[1].position(SCREEN_WIDTH-button[1].ins.w-20,SCREEN_HEIGHT-button[1].ins.h);
	//	button[2].position(SCREEN_WIDTH-button[2].ins.w*2,SCREEN_HEIGHT-button[2].ins.h);

}
return 0;
}

void onClick(){
	if(!button.empty()){
		for(unsigned int j=0;j<button.size();j++){
			button[j].onClick();
			}
		}
	}






void gird(){
  if(!button[0].clicked){
	for(int a=0;a<GirdH/box;a++){
		y=a;
	for(int c=0;c<GirdW/box;c++){
//std::cout<<"loop executed"<<std::endl;
		  rectangleRGBA(screen,c*box, y*box,(c+1)*box, (y+1)*box,255, 255, 255, 255);
		  if(c>=GirdW){x=0;}
      }
}
}
}
bool tiled_map(){
  //std::cout<<"Array Y: "<<arrayY<<std::endl;

if(tile.empty()){
  for( int b=0;b<tile_num;b++){
tile.push_back(Tile());
tile[b].size(0,0,box,box);
tile[b].position(arrayX*box,arrayY);
arrayX++;
if(arrayX>=GirdW/box){arrayY+=box;arrayX=0;}

if(arrayY>=GirdH){arrayY=0;arrayX=0;break;}
  }
}

//std::cout<<"tiles number"<<tile.size()<<std::endl;

return 0;
}

int hoverMouse(){

	if(hov.empty()){
	hov.push_back(Hover());
  hov[0].ins.x=SCREEN_WIDTH;
  hov[0].ins.y=SCREEN_HEIGHT;
  btnX=btnY=-1;
}
//std::cout<<hov[0].ins.x<<std::endl;;
for(int j=0;j<tile_num;j++){
tile[j].onMouse();
if(tile[j].on){
hov[0].selected=j;
	hov[0].size(box,box);
	hov[0].position(tile[j].ins.x,tile[j].ins.y);
}
}
return 0;
}


void past_on_map(){
for(unsigned int y=0;y<tile.size();y++){
  tile[y].onClick();
  if(tile[y].clicked){
    std::cout<<"tile clicked: "<<y<<std::endl;

    //  if(super_global[0].SG_sprite>0){
        std::cout<<"tile clicked: "<<y<<std::endl;
    tile[y].surface=sprite[super_global[0].SG_sprite].surface;

    std::cout<<tile[y].src<<std::endl;
    tile[y].clean();
  //}
  }
}
}

#endif
