#include <pebble.h>
#include "content_menu.h"
#include "text_factory.h"
#include "clock.h"

Window *content_window;
GBitmap *content_image;
TextLayer* content_text_layer;
BitmapLayer *content_image_layer;
static ScrollLayer *content_scroll_layer;

int selected_main_menu_item;

// void tick_handler1(struct tm *myTick, TimeUnits units_changed){
   
//    strftime(time_format, sizeof(time_format), "%H:%M", myTick);
//    text_layer_set_text(text_timeL, time_format);
   
// }

void select_click_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
   selected_main_menu_item = cell_index->row;
   window_stack_push(content_window, false);
}

static void content_window_load(Window *window)
{
   Layer *content_window_root_layer = window_get_root_layer(content_window);
   clock_init(content_window_root_layer);
  
   content_scroll_layer = scroll_layer_create(GRect(0, 16, 144, 168));
   scroll_layer_set_click_config_onto_window(content_scroll_layer, content_window);
   
//==========↓↓↓================IMAGE==============↓↓↓=====================
      
   content_image_layer= bitmap_layer_create(GRect(0,0,144,250));
   
   content_image = get_image_by_row(selected_main_menu_item);
   bitmap_layer_set_bitmap(content_image_layer, content_image);
   
   // bitmap_layer_set_bitmap(content_image_layer, content_image);
   bitmap_layer_set_compositing_mode(content_image_layer, GCompOpSet);
   scroll_layer_add_child(content_scroll_layer, bitmap_layer_get_layer(content_image_layer));
   
 //==========↑↑↑================IMAGE==============↑↑↑=====================  
   
   content_text_layer = text_layer_create(GRect(0, 800, 144, 2000)); 
   
   set_text_by_row(selected_main_menu_item, content_text_layer);
   
   scroll_layer_add_child(content_scroll_layer, text_layer_get_layer(content_text_layer));
   layer_add_child(content_window_root_layer, scroll_layer_get_layer(content_scroll_layer));
   
                              GSize max_size;
                                 max_size.w =144;
                                 max_size.h = text_layer_get_content_size(content_text_layer).h+1000;
                              text_layer_set_size(content_text_layer, max_size);
                              scroll_layer_set_content_size(content_scroll_layer, GSize(144, max_size.h));
} 

static void content_window_unload(Window *window) {
   text_layer_destroy(content_text_layer);
   gbitmap_destroy(content_image);
   bitmap_layer_destroy(content_image_layer);
   scroll_layer_destroy(content_scroll_layer);
   clock_clear();
} 

void init_content_menu()
{
   content_window = window_create();
   
      window_set_window_handlers(content_window, (WindowHandlers){
      .load = content_window_load,
      .unload = content_window_unload,
   });
}

void clear_content_menu()
{
   window_destroy(content_window);
}

