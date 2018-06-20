#include "InfoAndType.h"

annual *LoadData(){
    annual * heada = NULL;
    FILE * fa,*fp,*fs;
    fa = fopen("data/annual.bin","rb");
    fp = fopen("data/project.bin","rb");
    fs = fopen("data/staff.bin","rb");
    //创建文件
    if(fa==NULL){
        fclose(fa);fclose(fp);fclose(fs);
        fa = fopen("data/annual.bin","wb");
        fp = fopen("data/project.bin","wb");
        fs = fopen("data/staff.bin","wb");
        fclose(fa);fclose(fp);fclose(fs);
        fa = fopen("data/annual.bin","rb");
        fp = fopen("data/project.bin","rb");
        fs = fopen("data/staff.bin","rb");
    }
    struct dataa da;
    annual * cur=NULL;
    while(fread(&da,1,sizeof(dataa),fa)!=0){
        annual * tmp = (annual *)malloc(sizeof(annual));
        tmp->next=NULL;tmp->pjhead = NULL;
        tmp->data = da;
        if(heada==NULL) {
            heada = tmp;
            cur = tmp;
        }
        else{
            cur->next = tmp;
            cur = cur->next;
        }
        //int pjSupportNum = 0;
        int pjSupportNum = da.pjSupportNum;
        struct datap dp;
        project * cur_p = NULL;
        for(int i = 1;i<=pjSupportNum;i++){
            fread(&dp,1,sizeof(datap),fp);
            project * tmp = (project *)malloc(sizeof(project));
            tmp->next = NULL;tmp->sthead = NULL;
            tmp->data = dp;
            if(cur->pjhead==NULL){
                cur->pjhead = tmp;
                cur_p = tmp;
            }
            else{
                cur_p->next = tmp;
                cur_p = cur_p->next;
            }
            int peoNum = cur_p->data.people;
            staff * cur_s = NULL;
            struct datas ds;
            for(int i = 1;i<=peoNum;i++){
                fread(&ds,1,sizeof(datas),fs);
                staff * tmp_s = (staff *)malloc(sizeof(staff));
                tmp_s->next = NULL;
                tmp_s->data = ds;
                if(cur_p->sthead==NULL){
                    cur_p->sthead = tmp_s;
                    cur_s = tmp_s;
                }
                else{
                    cur_s->next = tmp_s;
                    cur_s = cur_s->next;
                }
            }

        }
    }
    fclose(fa);fclose(fp);fclose(fs);
    if(heada==NULL) {Msg(1,"系统检测到没有信息，请添加信息！");return NULL;}
    else return heada;
}

void UnLoadData(){
    annual *cur_a = ahead;
    while(cur_a!=NULL){
        project * cur_p = cur_a->pjhead;
        while(cur_p!=NULL){
            staff * cur_s = cur_p->sthead;
            while(cur_s!=NULL){
                staff * tmp_s = cur_s;
                cur_s = cur_s->next;
                free(tmp_s);
            }
            project * tmp_p = cur_p;
            cur_p = cur_p->next;
            free(tmp_p);
        }
        annual * tmp_a = cur_a;
        cur_a = cur_a->next;
        free(tmp_a);
    }
}

void ExitEvent (GtkWidget* widget,gpointer data){
    UnLoadData();
    free(pipes);
    gtk_main_quit();
}
void SubExitEvent(GtkWidget * wid,gpointer data){
    gtk_widget_destroy(wid);
    window = CreateMainPage();
}
void SaveData(){
    annual * heada = ahead;
    FILE * fa,*fp,*fs;
    fa = fopen("data/annual.bin","wb");
    fp = fopen("data/project.bin","wb");
    fs = fopen("data/staff.bin","wb");

    while(heada!=NULL){
        project * headp = heada->pjhead;
        while(headp!=NULL){

            staff * heads = headp->sthead;
            while(heads!=NULL){
                fwrite(&heads->data,1,sizeof(datas),fs);
                heads = heads->next;
            }
            fwrite(&headp->data,1,sizeof(datap),fp);
            headp = headp->next;
        }
        fwrite(&heada->data,1,sizeof(dataa),fa);
        heada = heada->next;
    }
    fclose(fa); fclose(fp); fclose(fs);
}








