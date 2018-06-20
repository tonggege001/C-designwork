#include"InfoAndType.h"
#include"CrtAnnualPage.h"
#include"CrtProjectPage.h"
#include"CrtStaffPage.h"
#include"LoadAndExit.h"


GtkWidget * check;

void ShowAddPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    printf("Ready to destroy Window");
    printf("window is %d\nqqq\n",window);
    gtk_widget_destroy(window);
    printf("Destroyed!\n");
    if(gtk_toggle_button_get_active(check[0])){
        printf("Ready to Create Annual Page!\n");
        CreateAddAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateAddProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateAddStaffPage();
    }

}
void ShowChangePage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateChangeAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateChangeProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateChangeStaffPage();
    }
}
void ShowQueryPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateQueryAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateQueryProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateQueryStaffPage();
    }
}
static void buttonPress(GtkWidget * wid,gpointer data);
static void buttonRelease(GtkWidget * wid,gpointer data);
void ShowBeiFenPage(GtkWidget *button, gpointer data){
    gtk_widget_destroy(window);
    GtkWidget * addwindow;
    GtkWidget * eventbox[2];
    GtkWidget * image[4];
    GtkWidget * filechooser1;
    GtkWidget * filechooser2;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/BeiFenPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
    addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    filechooser1 = GTK_FILE_CHOOSER(gtk_builder_get_object(builder,"filechooserbutton1"));
    filechooser2 = GTK_FILE_CHOOSER(gtk_builder_get_object(builder,"filechooserbutton2"));

    for(int i = 0;i<=3;i++){
        char name[10] = "image";char num[5];
        strcat(name,itoa(i+1,num,10));
        image[i] = GTK_IMAGE(gtk_builder_get_object(builder,name));
        char file[20] = "image/beifen/"; itoa(2*i+1,num,10);strcat(file,num);strcat(file,".png");
        gtk_image_set_from_file (image[i],file);
    }
    for(int i = 0;i<=1;i++){
        char name[10] = "eventbox";char num[5];
        eventbox[i] = GTK_EVENT_BOX(gtk_builder_get_object(builder,strcat(name,itoa(i+1,num,10))));
        g_signal_connect(G_OBJECT(eventbox[i]),"button_press_event",G_CALLBACK(buttonPress),NULL);
        g_signal_connect(G_OBJECT(eventbox[i]),"button_release_event",G_CALLBACK(buttonRelease),NULL);
    }
    chang_background(eventbox[0], 360, 170, "image/beifen/bg.jpg");
    pipes->widget[0] = eventbox[0];pipes->widget[2] = image[0];
    pipes->widget[1] = eventbox[1];pipes->widget[3] = image[1];
    pipes->widget[4] = image[2];pipes->widget[5] = image[3];
    pipes->widget[6] = filechooser1;pipes->widget[7] = filechooser2;
    pipes->widget[10] = addwindow;
    gtk_widget_show_all(addwindow);
}
static void buttonPress(GtkWidget * wid,gpointer data){
    if(wid==pipes->widget[0]){
        gtk_image_clear(pipes->widget[2]);
        gtk_image_set_from_file(pipes->widget[2],"image/beifen/2.png");
    }
    else if(wid == pipes->widget[1]){
        gtk_image_clear(pipes->widget[3]);
        gtk_image_set_from_file(pipes->widget[3],"image/beifen/4.png");
    }
}
static void buttonRelease(GtkWidget * wid,gpointer data){
    if(wid==pipes->widget[0]){
        gtk_image_clear(pipes->widget[2]);
        gtk_image_set_from_file(pipes->widget[2],"image/beifen/1.png");
        char * save = gtk_file_chooser_get_current_folder(pipes->widget[6]);
        BeiFen(save);
        Msg(1,"恭喜，备份成功！");
    }
    else if(wid == pipes->widget[1]){
        gtk_image_clear(pipes->widget[3]);
        gtk_image_set_from_file(pipes->widget[3],"image/beifen/3.png");
        char * take = gtk_file_chooser_get_current_folder(pipes->widget[7]);
        HuiFuEnsure(wid,NULL);
    }
}
//给出是否要恢复信息的确认
void HuiFuEnsure(GtkWidget* wid,gpointer data){
    GtkWidget*dialog = gtk_dialog_new_with_buttons ("恢复信息", pipes->widget[10],GTK_DIALOG_MODAL,
                                          GTK_STOCK_OK, GTK_RESPONSE_OK,GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,NULL);
    GtkWidget * label = gtk_label_new ("          确定要恢复信息吗？         \n                  (原有信息将会被覆盖！)    ");
    gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), label);
    gtk_window_set_position(dialog,GTK_WIN_POS_CENTER);
    gtk_widget_show_all (dialog);
    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_OK){
        char * take = gtk_file_chooser_get_current_folder(pipes->widget[7]);
        HuiFu(take);
        Msg(1,"信息恢复成功，请重启程序！");
    }
    gtk_widget_destroy (dialog);
}

void ShowStaticPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateStaticAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateStaticProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateStaticStaffPage();
    }
}
gboolean window_drag(GtkWidget *widget, GdkEventButton *event, GdkWindowEdge edge);
static int drag = 0;
void ShowTuoguanPage(GtkWidget *button, gpointer data){
    gtk_widget_destroy(window);
    //托管页面必须释放节点，然后调用gtk_main_quit
    //编写托管界面
    GtkWidget * addwindow;
    GtkWidget * image;
    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/Tuoguan.glade", NULL)) {
		printf("connot load file!");return ;
	}
    addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    printf("  %d  ",addwindow);
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(ExitEvent),NULL);

    //实现拖动小图标（棒呆了……）
    gtk_widget_add_events(addwindow, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(addwindow), "button-press-event", G_CALLBACK(window_drag), NULL);

    image = GTK_IMAGE(gtk_builder_get_object(builder,"image1"));
    gtk_image_set_from_file (image,"image/Tuoguan.png");

    GdkPixbuf *pixbuf = NULL;
    GdkBitmap *bitmap = NULL;
    GdkPixmap *pixmap = NULL;
    gtk_widget_set_app_paintable(addwindow, TRUE);
    gtk_widget_realize(addwindow);
    pixbuf = gdk_pixbuf_new_from_file("image/Tuoguan.png", NULL); // gdk 函数读取 png 文件
    gdk_pixbuf_render_pixmap_and_mask(pixbuf, &pixmap, &bitmap, 128); // alpha 小于 128 认为透明
    gtk_widget_shape_combine_mask(addwindow, bitmap, 0, 0); // 设置透明蒙板
    gdk_window_set_back_pixmap(addwindow->window, pixmap, FALSE); // 设置窗口背景
    g_object_unref(pixbuf);
    g_object_unref(bitmap);
    g_object_unref(pixmap);

    gtk_widget_show_all(addwindow);
}
gboolean window_drag(GtkWidget *widget, GdkEventButton *event, GdkWindowEdge edge){
    if (event->button == 1){
        gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                   event->button,event->x_root, event->y_root, event->time);
    }
    if(event->type==GDK_2BUTTON_PRESS){
        window = CreateMainPage();
        gtk_widget_destroy(widget);
    }
    return FALSE;
}





