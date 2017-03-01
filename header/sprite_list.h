#ifndef SPRITE_LIST_H
#define SPRITE_LIST_H

#include <sstream>
#include <fstream>
#include "object.h"
//int page;
int resource_number=0;
void getRC(const char* str){

int d=20;
int i=0;
int r=0;
int inc=0;

std::ifstream is(str);
int  x=sizeof(is);
char arr[x];unsigned int c=0;char t;
while (is.get(t)) {
  arr[c]=t; c++;t++;
}
is.close();
std::string word="";

for(i=0;i<=x;i++){
///////////////////////////////:START COND
if(arr[i]=='_'){
value.push_back(" ");
for(r=i;r<=i+d;r++){
if(arr[r+1]==' ' || arr[r+1]==':'){break;}
word+=arr[r+1];}
std::string txt(word);
value[inc]=txt;
txt="";word="";inc++;
}
//////
}
resource_number=value.size();


}





void define_pages(){

  if(page.empty()){page.push_back(Page());}

//std::cout<<"RR"<<resource_number/16<<std::endl;
  if(resource_number/16>0){

	page[0].end=resource_number/list[0].dock*list[0].dock;

  }
	else if(resource_number%16>0){page[0].end++;}
//std::cout<<"PAGE/ "<<page[0].end<<std::endl;
	}
//  void print_sprites


void print_pages(){
if(!menu.empty()){
  for( unsigned int u=1;u<menu.size();u++){
menu[u].onClick();
//std::cout<<"Menu vector size: "<<menu.size()<<std::endl;
if(menu[u].clicked){
  menu[0].position(menu[u].ins.x,menu[u].ins.y+10);
  page[0].index=u;
menu[u].clicked=false;
}
}
}else if(menu.empty()){
   std::stringstream ss;
  std::string str = " ";
 page[0].end=4;
  for( int u=0;u<page[0].end;u++){
	  ss.str("");

  if(u==0){ss<<"_";}
    else{ss << u;}
menu.push_back(Menu(ss.str().c_str(),"font/font.ttf",30,'w',false));
if(u==1){menu[1].ins.x=list[0].ins.x;
menu[1].ins.y=list[0].ins.y+list[0].ins.h+5;
menu[1].position(menu[1].ins.x,menu[1].ins.y);
menu[0].ins.x=menu[1].ins.x;
menu[0].ins.y=menu[1].ins.y+10;
  page[0].index=1;
}
else if(u>=2){
  menu[u].ins.x=menu[u-1].ins.x+menu[u-1].ins.w+5;
  menu[u].ins.y=list[0].ins.y+list[0].ins.h+5;
  menu[u].position(menu[u].ins.x,menu[u].ins.y);
}
if(menu[u].ins.x>=list[0].ins.x+list[0].ins.w){
  menu[u].ins.x=list[0].ins.x+5;
  menu[u].ins.y+=menu[u-1].ins.y+menu[u-1].ins.h+5;
}



}
}

}

#endif
