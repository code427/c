#include<stdio.h>
#include<stdlib.h>

#include"app_gnome.h"

static GtkWidget* app;
static GtkWidget* toolbar;
GtkWidget* create_main_window();
void quit_app(GtkWidget* window, gpointer data ){
//database_end();
gtk_main_quit();
}

static GnomeUIInfo filemenu[]={
GNOMEUIINFO_MENU_NEW_ITEM("New CD", NULL,NULL,NULL),
GNOMEUIINFO_SEPARATOR,
GNOMEUIINFO_MENU_EXIT_ITEM(NULL,NULL),
GNOMEUIINFO_END
};

static GnomeUIInfo menubar[]={
GNOMEUIINFO_MENU_FILE_TREE(filemenu),
GNOMEUIINFO_END };
GtkWidget* create_main_window()
{
app=gnome_app_new("GnomeCD","CD Database");

gtk_window_set_position(GTK_WINDOW(app),GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(app),540,480);
gnome_app_create_menus(GNOME_APP(app),menubar);
toolbar=gtk_toolbar_new();
gnome_app_add_toolbar(GNOME_APP(app),GTK_TOOLBAR(toolbar),"toolbar",BONOBO_DOCK_ITEM_BEH_EXCLUSIVE,BONOBO_DOCK_TOP,1,0,0);
gtk_container_set_border_width(GTK_CONTAINER(toolbar),1);
gtk_toolbar_insert_stock(GTK_TOOLBAR(toolbar),"gtk-add","Add new CD",NULL,NULL,NULL,-1);
gtk_signal_connect(GTK_OBJECT(app),"destroy",GTK_SIGNAL_FUNC(quit_app),NULL);
return app;
}
gint main(gint argc,gchar* argv[])
{
gnome_program_init("CdDatabase","0.1",LIBGNOMEUI_MODULE,argc,argv,GNOME_PARAM_APP_DATADIR,"",NULL);
GtkWidget * main_window=create_main_window();
gtk_widget_show_all(main_window);
gtk_main();

}
