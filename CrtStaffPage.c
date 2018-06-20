#include"InfoAndType.h"
#include"LoadAndExit.h"
#include"Staff.h"
#include "Util.h"

void CreateAddStaffPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;

    GtkWidget * CSNo;
    GtkWidget * CNo;
    GtkWidget * SNo;
    GtkWidget * name;
    GtkWidget * old;;
    GtkWidget * status;
    GtkWidget * profession;
    GtkWidget * classNo;
    GtkWidget * talent;
    GtkWidget * task;
    GtkWidget * tel;
    GtkWidget * que;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/AddStaffPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    CNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    SNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    name = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    old = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    status = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    profession = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
    classNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry8"));
    talent = GTK_ENTRY(gtk_builder_get_object(builder,"entry9"));
    task = GTK_ENTRY(gtk_builder_get_object(builder,"entry10"));
    tel = GTK_ENTRY(gtk_builder_get_object(builder,"entry11"));
    que = GTK_ENTRY(gtk_builder_get_object(builder,"entry12"));

	pipes->widget[0]= CSNo;
	pipes->widget[1]= CNo;
	pipes->widget[2]= SNo;
	pipes->widget[3]= name;
	pipes->widget[4]= old;
	pipes->widget[5]= status;
	pipes->widget[6]= profession;
	pipes->widget[7]= classNo;
	pipes->widget[8]= talent;
	pipes->widget[9]= task;
	pipes->widget[10]= tel;
	pipes->widget[11]= que;

    pipes->n = 12;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddStaff),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    chang_background(button_clear, 770, 480, "image/Project/Addbg.jpg");
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}

void CreateChangeStaffPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * button_query;

    GtkWidget * addwindow;

    GtkWidget * CSNo;
    GtkWidget * CNo;
    GtkWidget * SNo;
    GtkWidget * name;
    GtkWidget * old;;
    GtkWidget * status;
    GtkWidget * profession;
    GtkWidget * classNo;
    GtkWidget * talent;
    GtkWidget * task;
    GtkWidget * tel;
    GtkWidget * que;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/ChangeStaffPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    CNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    SNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    name = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    old = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    status = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    profession = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
    classNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry8"));
    talent = GTK_ENTRY(gtk_builder_get_object(builder,"entry9"));
    task = GTK_ENTRY(gtk_builder_get_object(builder,"entry10"));
    tel = GTK_ENTRY(gtk_builder_get_object(builder,"entry11"));
    que = GTK_ENTRY(gtk_builder_get_object(builder,"entry12"));

	pipes->widget[0]= CSNo;
	pipes->widget[1]= CNo;
	pipes->widget[2]= SNo;
	pipes->widget[3]= name;
	pipes->widget[4]= old;
	pipes->widget[5]= status;
	pipes->widget[6]= profession;
	pipes->widget[7]= classNo;
	pipes->widget[8]= talent;
	pipes->widget[9]= task;
	pipes->widget[10]= tel;
	pipes->widget[11]= que;

    pipes->n = 12;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(ChangeStaff),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(FindStaff),pipes);
    chang_background(button_ensure, 770, 510, "image/Project/Addbg.jpg");
	gtk_widget_show_all(addwindow);
}

void QueryStaffSwitch(GtkWidget *wid,gpointer data){
    pipe*A = (pipe *)data;
    gtk_clist_clear(A->widget[9]);
    int flag = 0;
    if(gtk_toggle_button_get_active(A->widget[4])){
       flag = 1;
       if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0){Msg(1,"请输入学号！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[5])){
        flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0){Msg(1,"请输入姓名！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[6])){
       flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0){Msg(1,"请输入专业！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
       flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0){Msg(1,"请输入特长！");return ;}
    }
    if(flag==0){Msg(1,"请至少选择一种方式查询");return ;}
    QueryStaff(wid,A);
}

void DeleteStaffEnsure(GtkWidget* wid,gpointer data);
static GtkWidget * t;
void CreateQueryStaffPage(){
    //button
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * button_delete;
    //check
    GtkWidget * SNoCk;
    GtkWidget * NameCk;
    GtkWidget * ProfessionCk;
    GtkWidget * TalentCk;
    GtkWidget * AndOrCk;

    //window
    GtkWidget * addwindow;
    //输入域
    GtkWidget * SNo;
    GtkWidget * Name;
    GtkWidget * Profession;
    GtkWidget * Talent;

    GtkWidget * Scroll;

    GtkWidget * clist;
    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/QueryStaffPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    SNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    Name = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    Profession = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    Talent = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));

    //获得check
    SNoCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));
    NameCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton2"));
    ProfessionCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton3"));
    TalentCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton4"));
    AndOrCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton5"));
    //
    printf("OK");
    //创建Clist
    clist=gtk_clist_new(11);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"项目编号");
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"学号");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"姓名");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"年龄");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"类别");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"学院专业");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"班级");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"本人特长");
    gtk_clist_set_column_title(GTK_CLIST(clist),8,"承担任务");
    gtk_clist_set_column_title(GTK_CLIST(clist),9,"联系电话");
    gtk_clist_set_column_title(GTK_CLIST(clist),10,"贡献排名");
    gtk_clist_column_titles_show(GTK_CLIST(clist));
    gtk_clist_set_column_auto_resize(clist,0,TRUE);    gtk_clist_set_column_auto_resize(clist,1,TRUE);
    gtk_clist_set_column_auto_resize(clist,2,TRUE);    gtk_clist_set_column_auto_resize(clist,3,TRUE);
    gtk_clist_set_column_auto_resize(clist,4,TRUE);    gtk_clist_set_column_auto_resize(clist,5,TRUE);
    gtk_clist_set_column_auto_resize(clist,6,TRUE);    gtk_clist_set_column_auto_resize(clist,7,TRUE);
    gtk_clist_set_column_auto_resize(clist,8,TRUE);    gtk_clist_set_column_auto_resize(clist,9,TRUE);
    gtk_clist_set_column_auto_resize(clist,10,TRUE);
    Scroll = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow1"));
    gtk_container_add(GTK_CONTAINER(Scroll),clist);

	pipes->widget[0]= SNo;
	pipes->widget[1]= Name;
	pipes->widget[2]= Profession;
	pipes->widget[3]= Talent;

    pipes->n = 4;
    pipes->widget[4]= SNoCk;
    pipes->widget[5]= NameCk;
    pipes->widget[6]= ProfessionCk;
    pipes->widget[7]= TalentCk;
    pipes->widget[8]= AndOrCk;
    pipes->widget[9] = clist;
    t = addwindow;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(QueryStaffSwitch),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	button_delete = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_delete),"clicked",G_CALLBACK(DeleteStaffEnsure),clist);
    chang_background(button_ensure, 900, 600, "image/Annual/Querybg.jpg");

	gtk_widget_show_all(addwindow);
}

void DeleteStaffEnsure(GtkWidget* wid,gpointer data){
    GtkWidget*clist = (GtkWidget * )data;

    GtkWidget*dialog = gtk_dialog_new_with_buttons ("删除列表中的数据", t,GTK_DIALOG_MODAL,
                                          GTK_STOCK_DELETE, GTK_RESPONSE_OK,GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,NULL);
    GtkWidget * label = gtk_label_new ("          确定要删除列表中的所有数据吗？         \n                (子项也将会被删除！)    ");
    gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), label);
    gtk_widget_show_all (dialog);
    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_OK){
        DeleteStaff(NULL,clist);
        gtk_clist_clear(clist);
    }
    gtk_widget_destroy (dialog);
}
static void Changeto1(GtkWidget *wid,gpointer data);
static void Changeto2(GtkWidget *wid,gpointer data);
void StaticStaff(gboolean tag,pipe *pipes);
void CreateStaticStaffPage(){
    //check
    GtkWidget * SNoCk;

    //window
    GtkWidget * addwindow;
    //comboBox
    GtkWidget * combobox1;
    GtkWidget * combobox2;

    GtkWidget * scroll;
    //按钮
    GtkWidget * eventbox;
    GtkWidget * image;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/StaticStaffPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);

    //获得check
    SNoCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));
    //获得COMBOBOX
    combobox1 = GTK_COMBO_BOX(gtk_builder_get_object(builder,"comboboxtext1"));
    combobox2 = GTK_COMBO_BOX(gtk_builder_get_object(builder,"comboboxtext2"));
    chang_background(combobox2, 850, 550, "image/Staff/static/bg.jpg");
    //scroll
    scroll = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow1"));
    //产生表格
    GtkWidget *clist=gtk_clist_new(2);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"学院");
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"比例");
    gtk_clist_column_titles_show(GTK_CLIST(clist));
    gtk_clist_set_column_auto_resize(clist,0,TRUE);
    gtk_clist_set_column_auto_resize(clist,1,TRUE);
    gtk_container_add(GTK_CONTAINER(scroll),clist);

    //设置按钮
    eventbox = GTK_EVENT_BOX(gtk_builder_get_object(builder,"eventbox1"));
    image = GTK_IMAGE(gtk_builder_get_object(builder,"image1"));
    gtk_image_set_from_file(image,"image/Staff/static/1.png");
    g_signal_connect (G_OBJECT (eventbox), "button_press_event",G_CALLBACK (Changeto1),NULL);
    g_signal_connect (G_OBJECT (eventbox), "button_release_event",G_CALLBACK (Changeto2),NULL);
    pipes->widget[0] = SNoCk;
    pipes->widget[1] = combobox1;
    pipes->widget[2] = combobox2;
    pipes->widget[3] = clist;
    pipes->widget[4] = image;
    gtk_widget_show_all(addwindow);
}

static void Changeto1(GtkWidget *wid,gpointer data){
    printf("1.");
    GtkWidget * image = pipes->widget[4];
    gtk_image_clear(image);
    printf("2.");
    gtk_image_set_from_file(image,"image/Staff/static/2.png");
}
static void Changeto2(GtkWidget *wid,gpointer data){
    gtk_image_clear(pipes->widget[4]);
    gtk_image_set_from_file(pipes->widget[4],"image/Staff/static/1.png");
    gboolean tag = gtk_toggle_button_get_active(pipes->widget[0]);
    gtk_clist_clear(pipes->widget[3]);
    StaticStaff(tag,pipes);
}








