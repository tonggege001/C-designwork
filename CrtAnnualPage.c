#include"InfoAndType.h"
#include"Util.h"
#include"Annual.h"
#include"LoadAndExit.h"

void CreateAddAnnualPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;
    GtkWidget * CSNo;
    GtkWidget * MoneyInput;
    GtkWidget * Respeople;
    GtkWidget * pjApply;
    GtkWidget * pjEnd;
    GtkWidget * timebg;
    GtkWidget * timeed;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/AddAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    chang_background(addwindow, 280, 400, "image/MainPage/background.jpg");
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyInput = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    Respeople = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApply = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjEnd = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    timebg = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    timeed = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
	pipes->widget[0]= CSNo;
	pipes->widget[1]= MoneyInput;
	pipes->widget[2]= Respeople;
	pipes->widget[3]= pjApply;
	pipes->widget[4]= pjEnd;
	pipes->widget[5]= timebg;
	pipes->widget[6]= timeed;
    pipes->n = 7;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddAnnual),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    chang_background(button_clear, 400, 530, "image/Annual/Addbg.jpg");
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}

void CreateChangeAnnualPage(){
    GtkWidget * button_query;
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;
    GtkWidget * CSNo;
    GtkWidget * MoneyInput;
    GtkWidget * Respeople;
    GtkWidget * pjApply;
    GtkWidget * pjEnd;
    GtkWidget * timebg;
    GtkWidget * timeed;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/ChangeAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyInput = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    Respeople = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApply = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjEnd = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    timebg = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    timeed = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
	pipes->widget[0]= CSNo;
	pipes->widget[1]= MoneyInput;
	pipes->widget[2]= Respeople;
	pipes->widget[3]= pjApply;
	pipes->widget[4]= pjEnd;
	pipes->widget[5]= timebg;
	pipes->widget[6]= timeed;
    pipes->n = 7;
    for(int i = 0;i<=6;i++) printf("  %d  ",pipes->widget[i]);
    //获得按钮
	button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(FindAnnual),pipes);

	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(ChangeAnnual),pipes);
    chang_background(button_ensure, 400, 530, "image/Annual/Changebg.jpg");
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}
void QueryAnnualSwitch(GtkWidget *wid,gpointer data){
    pipe*A = (pipe *)data;
    gtk_clist_clear(A->widget[9]);
    int flag = 0;
    if(gtk_toggle_button_get_active(A->widget[5])){
       flag = 1;
       if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0){Msg(1,"请输入年度编号！");return ;}

    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0){Msg(1,"请输入投入资金下限！");return ;}
        if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0){Msg(1,"请输入投入资金上限！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
       flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0){Msg(1,"请输入支持项目数下限！");return ;}
        if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0){Msg(1,"请输入支持项目数上限！");return ;}
    }
    if(flag==0){Msg(1,"请至少选择一种方式查询");return ;}
    QueryAnnual(wid,A);
}

void DeleteAnnualEnsure(GtkWidget * wid , gpointer data);
GtkWidget * t;
void CreateQueryAnnualPage(){
    //button
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * button_delete;
    GtkWidget * toggle;

    //check
    GtkWidget * CSNoCk;
    GtkWidget * MoneyCk;
    GtkWidget * pjSupportCk;
    GtkWidget * AndOrCk;

    //window
    GtkWidget * addwindow;
    //输入域
    GtkWidget * CSNo;
    GtkWidget * MoneyF;
    GtkWidget * MoneyC;
    GtkWidget * pjApplyF;
    GtkWidget * pjApplyC;

    GtkWidget * Scroll;


    GtkWidget * clist;


    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/QueryAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyF = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    MoneyC = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApplyF = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjApplyC = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    //获得check
    CSNoCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));
    MoneyCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton2"));
    pjSupportCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton3"));
    AndOrCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton4"));
    //
    printf("OK");
    //创建Clist
    clist=gtk_clist_new(8);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"年度编号");
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"投入资金");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"负责人");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"申报项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"实际支持项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"结题项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"计划开始时间");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"计划结束时间");
    gtk_clist_column_titles_show(GTK_CLIST(clist));
    gtk_clist_set_column_auto_resize(clist,0,TRUE);
    gtk_clist_set_column_auto_resize(clist,1,TRUE);
    gtk_clist_set_column_auto_resize(clist,2,TRUE);
    gtk_clist_set_column_auto_resize(clist,3,TRUE);
    gtk_clist_set_column_auto_resize(clist,4,TRUE);
    gtk_clist_set_column_auto_resize(clist,5,TRUE);
    gtk_clist_set_column_auto_resize(clist,6,TRUE);
    gtk_clist_set_column_auto_resize(clist,7,TRUE);
    Scroll = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow1"));
    gtk_container_add(GTK_CONTAINER(Scroll),clist);
    t = addwindow;
	pipes->widget[0]= CSNo;
	pipes->widget[1]= MoneyF;
	pipes->widget[2]= MoneyC;
	pipes->widget[3]= pjApplyF;
	pipes->widget[4]= pjApplyC;
    pipes->n = 5;
    pipes->widget[5]= CSNoCk;
    pipes->widget[6]= MoneyCk;
    pipes->widget[7]= pjSupportCk;
    pipes->widget[8]= AndOrCk;
    pipes->widget[9] = clist;

    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(QueryAnnualSwitch),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	button_delete = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_delete),"clicked",G_CALLBACK(DeleteAnnualEnsure),clist);

    chang_background(button_ensure, 900, 600, "image/Annual/Querybg.jpg");
	gtk_widget_show_all(addwindow);
}

void DeleteAnnualEnsure(GtkWidget * wid , gpointer data){
    GtkWidget*clist = (GtkWidget * )data;

    GtkWidget*dialog = gtk_dialog_new_with_buttons ("删除列表中的数据", t,GTK_DIALOG_MODAL,
                                          GTK_STOCK_DELETE, GTK_RESPONSE_OK,GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,NULL);
    GtkWidget * label = gtk_label_new ("          确定要删除列表中的所有数据吗？         \n                (子列表也将会被删除！)    ");
    gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), label);
    gtk_widget_show_all (dialog);
    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_OK){
        DeleteAnnual(NULL,clist);
        gtk_clist_clear(clist);
    }
    gtk_widget_destroy (dialog);

}
void Changeto(GtkWidget * wid,gpointer data);


static GtkWidget * eventbox[9];
static GtkWidget * addwindow;

static GtkWidget * scrollwindow;

static GtkWidget * checkMethod;

static GtkWidget * combobox1;
static GtkWidget * combobox2;

static GtkWidget * image[9];

static GtkWidget * clist;
static int imageTest;

char filea[40];
void CreateStaticAnnualPage(){


    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/StaticAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);

    checkMethod = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));

    combobox1 = GTK_COMBO_BOX(gtk_builder_get_object(builder,"comboboxtext1"));
    combobox2 = GTK_COMBO_BOX(gtk_builder_get_object(builder,"comboboxtext2"));
    chang_background(combobox2, 850, 540, "image/Annual/staticbg.jpg");
    //创建表格
    clist=gtk_clist_new(10);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"年度编号");
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"申报项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"支持项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"投入资金");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"支持率");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"验收通过率");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"优良率");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"合格率");
    gtk_clist_set_column_title(GTK_CLIST(clist),8,"未结题率");
    gtk_clist_set_column_title(GTK_CLIST(clist),9,"参与人数");

    gtk_clist_column_titles_show(GTK_CLIST(clist));    gtk_clist_set_column_auto_resize(clist,8,TRUE);
    gtk_clist_set_column_auto_resize(clist,0,TRUE);    gtk_clist_set_column_auto_resize(clist,9,TRUE);
    gtk_clist_set_column_auto_resize(clist,1,TRUE);    gtk_clist_set_column_auto_resize(clist,2,TRUE);
    gtk_clist_set_column_auto_resize(clist,3,TRUE);    gtk_clist_set_column_auto_resize(clist,4,TRUE);
    gtk_clist_set_column_auto_resize(clist,5,TRUE);    gtk_clist_set_column_auto_resize(clist,6,TRUE);
    gtk_clist_set_column_auto_resize(clist,7,TRUE);
    scrollwindow = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow1"));
    gtk_container_add(GTK_CONTAINER(scrollwindow),clist);

    for(int i = 0;i<9;i++){
        char aa[10];char num[10];
        strcpy(aa,"image");strcat(aa,itoa(i+1,num,10));
        image[i] = GTK_IMAGE(gtk_builder_get_object(builder,aa));
        strcpy(filea,"image/Annual/");strcat(filea,itoa(i*2+1,num,10));
        strcat(filea,".png");
        gtk_image_set_from_file(image[i],filea);

    }
    for(int i = 0;i<9;i++){
        char evn[10];char num[3];
        strcpy(evn,"eventbox");strcat(evn,itoa(i+1,num,10));
        eventbox[i] = GTK_EVENT_BOX(gtk_builder_get_object(builder,evn));
        g_signal_connect (G_OBJECT (eventbox[i]), "button_press_event",G_CALLBACK (Changeto), NULL);
    }
    pipes->widget[0] = checkMethod;
    pipes->widget[1] = combobox1;
    pipes->widget[2] = combobox2;
    pipes->widget[3] = clist;


    gtk_widget_show_all(addwindow);
}

void changePix(){
    gtk_image_clear(image[imageTest]);
    char num[10];
    strcpy(filea,"image/Annual/");strcat(filea,itoa(imageTest*2+1,num,10));
    strcat(filea,".png");
    gtk_image_set_from_file(image[imageTest],filea);
}

void Changeto(GtkWidget * wid,gpointer data){
    pipe * A = (pipe *)data;
    for(int i = 0;i<9;i++){
        if(wid==eventbox[i]){
            printf("ready to change!\n");
            changePix();char num[10];
            imageTest = i;
            gtk_image_clear(image[i]);
            strcpy(filea,"image/Annual/");strcat(filea,itoa(2*i+2,num,10));
            strcat(filea,".png");
            gtk_image_set_from_file(image[i],filea);
            pipes->widget[4] = i;
            printf("ready to change!2\n");
            gtk_clist_clear(pipes->widget[3]);
            StaticAnnual(NULL,pipes);
        }
    }
}




