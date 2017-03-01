#ifndef DRAW_H
#define DRAW_H

void draw(){

if(!button.empty()){
for(unsigned int x=0;x<button.size();x++){
button[x].print();
}
}


if(!tile.empty()){
for(unsigned int x=0;x<tile.size();x++){
tile[x].print();
}
}

if(!hov.empty()){
hov[0].print();
}




if(!menu.empty()){
for(unsigned int e=0;e<4;e++){
//SDL_SaveBMP(menu[0].surface,"s.bmp");
  menu[e].print();
}
}
}


#endif
