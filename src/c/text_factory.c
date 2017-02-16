#include <pebble.h>
#include "text_factory.h"


//===================================CONTENT_TEXT=====↓↓↓======================================================
void set_text_by_row(int row, TextLayer * text_layer)
{
    switch(row){
     case 0:
         text_layer_set_text(text_layer, "First text");
      break;
      case 1:
          text_layer_set_text(text_layer, "Agree,/Appear,/Believe,/Belong,/Concern,/Consist,/Contain,/Depend,/Deserve,/Disagree,/Dislike,/Doubt,/feel (=have an opinion),/fit,/hate,/hear,/imagine,/impress,/include,/involve,/know,/like,/love,/matter,/mean,/measure (=be long),/mind,/need,/owe,/own,/prefer,/promise,/realise,/recognize,/remember,/seem,/sound,/suppose,/surprise,/understand,/want,/weigh (=have weight),/wish,/be,/have,/see,/taste (also: smell,/ feel,/ look),/think,/");
      break;
         case 2:
         text_layer_set_text(text_layer, "The API documentation describes all the possible MenuLayerCallbacks that can be associated with a MenuLayer, but the ones we will be using for a simple example will be:");
      break;
         case 3:
         text_layer_set_text(text_layer, "For the draw_row_handler(), we will need to be able to alter what is drawn in the row depending on which row it is. This can be done by switching the cell_index->row property. You can use the presented GContext however you like for any of the SDK drawing functions, but to keep things simple we will use the pre-made drawing functions provided by the SDK. With these two last points combined, the draw_row_callback() function transforms into this beast:");
      break;
         case 4:
         text_layer_set_text(text_layer, "So that’s how to setup a basic MenuLayer. An extended application like those mentioned previously will use char[] buffers to store each row’s text, modified in a in_received signature AppMessage callback, and calling menu_layer_reload_data() in that AppMessage callback, thus updating the MenuLayer with the new data.");
      break;
         case 5:
         text_layer_set_text(text_layer, "So that’s how to setup a basic MenuLayer. An extended application like those mentioned previously will use char[] buffers to store each row’s text, modified in a in_received signature AppMessage callback, and calling menu_layer_reload_data() in that AppMessage callback, thus updating the MenuLayer with the new data.");
      break;
      }
}
//===================================CONTENT_BITMAP=====↓↓↓======================================================
void set_image_by_row(int row, BitmapLayer *image_layer, GBitmap **content_image)
{
   GBitmap **pImage = content_image;
   GBitmap *image = NULL;
    switch(row){
       case 0:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE);
         break;
       case 1:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE_1);
         break;
       case 2:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE_2);
         break;
       case 3:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE_3);
         break;
       case 4:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE_4);  
         break;
       case 5:
         image = gbitmap_create_with_resource(RESOURCE_ID_TEST_IMAGE_5);
         break;
      }
  *content_image = image;
  bitmap_layer_set_bitmap(image_layer, *content_image);
}
//=======================================NAME_OF_ROWS===↓↓↓=======================================================
void draw_row_callback (GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context) {
   //Which row is it? 
   switch(cell_index->row)
      {
      case 0:
         menu_cell_basic_draw(ctx, cell_layer, "1.LOX", "Green and crispy!", NULL);
         break;
      case 1:
         menu_cell_basic_draw(ctx, cell_layer, "2.Orange", "Peel first!", NULL);
         break;
      case 2:
         menu_cell_basic_draw(ctx, cell_layer, "3.Banana", "Can be a gun =)", NULL);
         break;
      case 3:
         menu_cell_basic_draw(ctx, cell_layer, "4.Tomato", "Exstremely versatile!", NULL);
         break;
      case 4:
         menu_cell_basic_draw(ctx, cell_layer, "5.Pear", "Teardrop shaped!", NULL);
         break;
      case 5:
         menu_cell_basic_draw(ctx, cell_layer, "6.Grape", "Bunches of 'em!'", NULL);
         break;
      case 6:
         menu_cell_basic_draw(ctx, cell_layer, "7.Melon", "Only three left!", NULL);
         break;
      
      }
}
