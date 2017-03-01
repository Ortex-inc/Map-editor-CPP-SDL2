#include "header/screen.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include "header/sound.h"
#include "header/inputHandle.h"
#include "header/object.h"
#include "header/board.h"
#include "header/draw.h"
#include "header/list.h"
#include "header/sprite_list.h"







int main(int argc, char ** argv){
setScreen("Map Editor");
super_global.push_back(Super_global());
list.push_back(List(4,4,20));

list[0].size(300,350);
list[0].position(SCREEN_WIDTH-300,5);
sprite.push_back(Sprite());

generate_btn();
tiled_map();

getRC("resource/index.medit");


define_pages();



while (!quit)
{
	input();

onClick();
draw();
gird();
list[0].gui();
hoverMouse();
print_pages();





select_sprite();
past_on_map();

list[0].range();
list[0].print();

//menu[0].surface=menu[1].surface;

	update();
}
 return 0;}
