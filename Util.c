#include "InfoAndType.h"
#include"Util.h"

void Msg(int mode,char * msg){
    GtkWidget* dialog ;
    GtkMessageType type ;
    char *message = msg;
    switch(mode){
    case 1 :
        type = GTK_MESSAGE_ERROR ; break;
    case 2 :
        type = GTK_MESSAGE_INFO ; break;
    }
    dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    type ,GTK_BUTTONS_OK,message);
    gtk_window_set_position(dialog,GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


void ClearWindow(GtkWidget * wid,gpointer data){
    pipe * A = (pipe *)data;
    for(int i = 0;i<A->n;i++){
     gtk_entry_set_text(A->widget[i],"");
    }
}

void FreeAllPoint(point * head){
    while(head!=NULL){
        point * tmp = head;
        head = head->next;
        free(tmp);
    }
}
int Correspond1(char * Main,char *beTest){
    if(strlen(Main)<strlen(beTest)) return 0;
    char c;int flag = 1;
    for(int i = 0;beTest[i]!='\0'&&Main[i]!='\0';i++){
        c = beTest[i];
        if(c=='*') continue;
        else if(c!=Main[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}
//中文模糊查询
int Correspond2(char * Main,char *beTest){
    if(strcmp(Main,"")==0||strcmp(beTest,"")==0) return 0;
    if(strstr(Main,beTest)!=NULL) return 1;
    char block[5];int i = 0;int count = 0;
    int suc = 0;int total = 0;
    while(beTest[i++]!='\0'){
        if(count <=1){
            block[count++] = beTest[i];
        }
        else{
            block[count] = '\0';
            count = 0;
            total ++;
            if(strstr(Main,block)!=NULL) suc ++;

        }
    }
    double a = (double)suc;
    double b= (double)total;
    if(a/b>=0.6) return 1;
    else return 0;
}
//备份数据
void BeiFen(char * filename){
    FILE * fa1,*fa2;
    fa1 = fopen("data/annual.bin","rb");
    struct dataa da;
    char file[40];
    //备份年度信息
    strcpy(file,filename);strcat(file,"/annual.bin");
    fa2 = fopen(file,"wb");
    while(fread(&da,1,sizeof(struct dataa),fa1)!=0){
        fwrite(&da,1,sizeof(struct dataa),fa2);
    }
    fclose(fa1);fclose(fa2);
    //备份项目信息
    fa1 = fopen("data/project.bin","rb");
    strcpy(file,filename);strcat(file,"/project.bin");
    fa2 = fopen(file,"wb");
    struct datap dp;
    while(fread(&dp,1,sizeof(struct datap),fa1)!=0){
        fwrite(&dp,1,sizeof(struct datap),fa2);
    }
    fclose(fa1);fclose(fa2);
    //备份人员信息
    fa1 = fopen("data/staff.bin","rb");
    strcpy(file,filename);strcat(file,"/staff.bin");
    fa2 = fopen(file,"wb");
    struct datas ds;
    while(fread(&ds,1,sizeof(struct datas),fa1)!=0){
        fwrite(&ds,1,sizeof(struct datas),fa2);
    }
    fclose(fa1);fclose(fa2);
}
//恢复信息
void HuiFu(char * filename){
    FILE * fa1,*fa2;
    char file[40];
    strcpy(file,filename);
    strcat(file,"/annual.bin");
    fa1 = fopen(file,"rb");
    fa2 = fopen("data/annual.bin","wb");
    struct dataa da;
    while(fread(&da,1,sizeof(struct dataa),fa1)!=0){
        fwrite(&da,1,sizeof(struct dataa),fa2);
    }
    fclose(fa1);fclose(fa2);

    strcpy(file,filename);
    strcat(file,"/project.bin");
    fa1 = fopen(file,"rb");
    fa2 = fopen("data/project.bin","wb");
    struct datap dp;
    while(fread(&dp,1,sizeof(struct datap),fa1)!=0){
        fwrite(&dp,1,sizeof(struct datap),fa2);
    }
    fclose(fa1);fclose(fa2);

    strcpy(file,filename);
    strcat(file,"/staff.bin");
    fa1 = fopen(file,"rb");
    fa2 = fopen("data/staff.bin","wb");
    struct datas ds;
    while(fread(&ds,1,sizeof(struct datas),fa1)!=0){
        fwrite(&ds,1,sizeof(struct datas),fa2);
    }
    fclose(fa1);fclose(fa2);
}





