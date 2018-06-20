#include"InfoAndType.h"
#include"ShowPage.h"
#include"LoadAndExit.h"
#include"Util.h"
#include"Customized.h"



static GtkWidget * check[3];

static GtkWidget * eventbox[6];
static GtkWidget * image[6];

static char filea[30];
void on_press_event(GtkWidget *wid,gpointer data);
void on_release_event(GtkWidget *wid,gpointer data);

/*创建主界面*/
GtkWidget *CreateMainPage(){

	GtkBuilder *builder = gtk_builder_new();

	if ( !gtk_builder_add_from_file(builder,"config/MainPage.glade", NULL)) {
		printf("connot load file!");return NULL;
	}
	//获得窗体
	window = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(ExitEvent),NULL);
    GtkWidget * imagetitle = GTK_IMAGE(gtk_builder_get_object(builder,"image7"));
    gtk_image_set_from_file(imagetitle,"image/MainPage/title.png");
	//获得检查框
	printf("1");
	check[0] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton1"));
	check[1] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton2"));
	check[2] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton3"));
    //获得按钮
    chang_background(check[0], 280, 400, "image/MainPage/background.jpg");
    //创建图片按钮
    for(int i = 0;i<6;i++){
        char aa[10];char num[10];
        strcpy(aa,"image");strcat(aa,itoa(i+1,num,10));
        image[i] = GTK_IMAGE(gtk_builder_get_object(builder,aa));
        strcpy(filea,"image/MainPage/");strcat(filea,itoa(i*2+1,num,10));
        strcat(filea,".png");
        gtk_image_set_from_file(image[i],filea);

    }
    //为图片按钮绑定事件
    for(int i = 0;i<6;i++){
        char evn[10];char num[3];
        strcpy(evn,"eventbox");strcat(evn,itoa(i+1,num,10));
        eventbox[i] = GTK_EVENT_BOX(gtk_builder_get_object(builder,evn));
        g_signal_connect (G_OBJECT (eventbox[i]), "button_press_event",G_CALLBACK(on_press_event), NULL);
        g_signal_connect (G_OBJECT (eventbox[i]), "button_release_event",G_CALLBACK(on_release_event), NULL);

    }
	gtk_widget_show_all(window);
	return window;
}
//按钮点击事件
void on_press_event(GtkWidget *wid,gpointer data){
    for(int i =0 ;i<6;i++){
        if(wid==eventbox[i]){
            char num[10];
            gtk_image_clear(image[i]);
            strcpy(filea,"image/MainPage/");strcat(filea,itoa(2*i+2,num,10));
            strcat(filea,".png");
            gtk_image_set_from_file(image[i],filea);
        }
    }
}
void on_release_event(GtkWidget *wid,gpointer data){
    for(int i =0 ;i<6;i++){
        if(wid==eventbox[i]){
            char num[10];
            gtk_image_clear(image[i]);
            strcpy(filea,"image/MainPage/");strcat(filea,itoa(2*i+1,num,10));
            strcat(filea,".png");
            gtk_image_set_from_file(image[i],filea);
            switch(i) {
            //响应不同事件
            case 0:ShowAddPage(eventbox[i],check);break;
            case 1:ShowChangePage(eventbox[i],check);break;
            case 2:ShowQueryPage(eventbox[i],check);break;
            case 3:ShowStaticPage(eventbox[i],check);break;
            case 4:ShowTuoguanPage(eventbox[i],check);break;
            case 5:ShowBeiFenPage(eventbox[i],check);break;
            }
        }
    }
}


