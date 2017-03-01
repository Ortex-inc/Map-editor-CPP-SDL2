#ifndef LIST_H
#define LIST_H

void List::position(int x,int y){

this->ins.x=x;
this->ins.y=y;
}

void List::size(int w,int h){
	this->ins.w=w;
	this->ins.h=h;
	}

void List::gui(){
	//Uint32 color(screen->format,20,20,20,25);	
//roundedRectangleColor(screen, ins.x, ins.y, ins.w+ins.x, ins.h+ins.y,0,color);

roundedRectangleRGBA(screen, ins.x, ins.y, ins.w+ins.x, ins.h+ins.y, 0, 255,255,255,250);
roundedRectangleRGBA(screen, ins.x+5, ins.y+5, ins.w+ins.x-5, ins.h+ins.y-5, 0, 255,255,255,250);


	}
void List::range(){

	begin=0;
	end=2;


	if(!sprite.empty() && !value.empty() ){
  for(unsigned  int y=0;y<value.size();y++){
  sprite.push_back(Sprite());
  sprite[y].src=value[y].c_str();
  //std::cout<<value[y]<<std::endl;
  sprite[y].clean();
  }
  }


	for( int x=list[0].begin;x<list[0].end;x++){
    if(x==0){
sprite[x].ins.x=list[0].ins.x+10;
sprite[x].ins.y=list[0].ins.y+10;
}
else{

  sprite[x].ins.x=sprite[x-1].ins.x+sprite[x-1].ins.w+10;
  sprite[x].ins.y=sprite[0].ins.y;

}
if(sprite[x].ins.x>=list[0].ins.x+list[0].ins.w){sprite[x].ins.x=sprite[0].ins.x;
  sprite[x].ins.y+=sprite[0].ins.y+sprite[0].ins.h+10;
}
  }


}

	void List::print(){

 if(!sprite.empty()){

 for(int e=list[0].begin;e<=list[0].end;e++){
	 if(e==0){

		 sprite[e].ins.x=list[0].ins.x+10;
		 sprite[e].ins.y=list[0].ins.y+10;
	 }
	 else{
	 sprite[e].ins.x=sprite[e-1].ins.x+sprite[e-1].ins.w+10;
	 sprite[e].ins.y=sprite[e-1].ins.y;
 }
	sprite[e].print();
 }
}
 }
#endif
