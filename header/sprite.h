#ifndef SPRITE_H
#define SPRITE_H



void select_sprite(){

if(!sprite.empty()){
for(unsigned int a=0;a<sprite.size();a++)
{
sprite[a].onClick();
if(sprite[a].clicked){
  std::cout<<"sprite clicked: "<<a<<std::endl;
  std::cout<<"sprite src: "<<sprite[a].src<<std::endl;
  super_global[0].SG_sprite=a;
  sprite[a].clicked=false;
}}
}}

#endif
