#include"InfoAndType.h"
#include"LoadAndExit.h"
#include"Annual.h"

void AddAnnual(GtkWidget *wid,gpointer data) {
    pipe *A = (pipe *)data;

    annual * heada = ahead;
    int flag = 0;
    while(heada!=NULL) {
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;
        }
        heada = heada->next;
    }
    //将头指针归位
    heada = ahead;
    printf("Ready to typein\n");
    printf("the typeinner is %d\n",A->widget[0]);
    if(flag ==1) {
        Msg(1,"该年份已经有信息！");
        return ;
    }

    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {
        Msg(1,"请输入年份！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {
        Msg(1,"请输入投入资金！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {
        Msg(1,"请输入负责人！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {
        Msg(1,"请输入申请项目数！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {
        Msg(1,"请输入结题项目数！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {
        Msg(1,"请输入计划开始时间！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {
        Msg(1,"请输入计划结束时间！");
        return ;
    }

    annual *tmp = (annual *)malloc(sizeof(annual));
    tmp->next = NULL;
    tmp->pjhead = NULL;
    strcpy(tmp->data.CSNo,gtk_entry_get_text(A->widget[0]));
    tmp->data.moneyInput = atof(gtk_entry_get_text(A->widget[1]));
    strcpy(tmp->data.resPeople,gtk_entry_get_text(A->widget[2]));
    tmp->data.pjApplyNum = atoi(gtk_entry_get_text(A->widget[3]));
    tmp->data.pjSupportNum = 0;
    tmp->data.pjEndNum=atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(tmp->data.timgBg,gtk_entry_get_text(A->widget[5]));
    strcpy(tmp->data.timeEnd,gtk_entry_get_text(A->widget[6]));
    if(heada==NULL) {
        ahead = tmp;
        heada = tmp;
    }
    else {
        if(strcmp(heada->data.CSNo,tmp->data.CSNo)<0) {
            tmp->next = heada;
            ahead = tmp;
        }
        else {
            while(heada->next!=NULL) {
                if(strcmp(heada->next->data.CSNo,tmp->data.CSNo)<0) break;
                heada = heada->next;
            }
            tmp->next = heada->next;
            heada->next = tmp;
        }
    }
    SaveData();
    ClearWindow(NULL,A);
}

void FindAnnual(GtkWidget * wid, gpointer data) {
    pipe *A = (pipe *)data;
    annual * heada = ahead;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {
        Msg(1,"请输入年份！");
        return ;
    }
    int flag = 0;
    while(heada!=NULL) {
        printf("2m%d",A->widget[0]);
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;
            break;
        }
        heada = heada->next;
    }
    if(flag !=1) {
        Msg(1,"没有找到该年份信息！");
        return ;
    }
    printf("Founded!the point is %s\n",heada->data.CSNo);
    char money[10];
    char apply[10];
    char end[10];
    printf("4m%d",A->widget[0]);
    gcvt(heada->data.moneyInput,6,money);
    printf("5m%d",A->widget[0]);
    gtk_entry_set_text(A->widget[1],money);
    gtk_entry_set_text(GTK_ENTRY(A->widget[2]),heada->data.resPeople);
    gtk_entry_set_text(GTK_ENTRY(A->widget[3]),itoa(heada->data.pjApplyNum,apply,10));
    gtk_entry_set_text(GTK_ENTRY(A->widget[4]),itoa(heada->data.pjEndNum,end,10));
    gtk_entry_set_text(GTK_ENTRY(A->widget[5]),heada->data.timgBg);
    gtk_entry_set_text(GTK_ENTRY(A->widget[6]),heada->data.timeEnd);
}

void ChangeAnnual(GtkWidget * wid, gpointer data) {
    pipe *A = (pipe *)data;
    annual * heada = ahead;
    //提示错误
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {
        Msg(1,"请输入年份！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {
        Msg(1,"请输入投入资金！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {
        Msg(1,"请输入负责人！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {
        Msg(1,"请输入申请项目数！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {
        Msg(1,"请输入结题项目数！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {
        Msg(1,"请输入计划开始时间！");
        return ;
    }
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {
        Msg(1,"请输入计划结束时间！");
        return ;
    }

    int flag = 0;
    while(heada!=NULL) {
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;
            break;
        }
        heada = heada->next;
    }
    if(flag !=1) {
        Msg(1,"没有找到该年份信息！");
        return ;
    }
    heada->data.moneyInput=atof(gtk_entry_get_text(A->widget[1]));
    strcpy(heada->data.resPeople,gtk_entry_get_text(A->widget[2]));
    heada->data.pjApplyNum=atoi(gtk_entry_get_text(A->widget[3]));
    heada->data.pjEndNum=atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(heada->data.timgBg,gtk_entry_get_text(A->widget[5]));
    strcpy(heada->data.timeEnd,gtk_entry_get_text(A->widget[6]));
    SaveData();

}
//判断条件
int Judge(annual * cur,pipe * A) {
    int flagAnd = 1;
    int flagOr = 0;
    if(gtk_toggle_button_get_active(A->widget[5])) {
        if(Correspond1(cur->data.CSNo,gtk_entry_get_text(A->widget[0]))) {
            flagOr = 1;
        } else {
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[6])) {
        if(cur->data.moneyInput>=atof(gtk_entry_get_text(A->widget[1]))&&
                cur->data.moneyInput<=atof(gtk_entry_get_text(A->widget[2]))) {
            flagOr = 1;
        } else {
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[7])) {
        if(cur->data.pjSupportNum>=atoi(gtk_entry_get_text(A->widget[3]))&&
                cur->data.pjSupportNum<=atoi(gtk_entry_get_text(A->widget[4]))) {
            flagOr = 1;
        } else {
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[8])) {
        return flagAnd;
    } else {
        return flagOr;
    }
}
//删除的时候直接调用这条函数
//注意：
/*1.项目删除pjsupport-1
2.pipe里面传参索引相对*/
point *QueryForList(pipe * A) {
    annual * heada = ahead;
    point *head = NULL;
    point * cur = NULL;
    while(heada!=NULL) {
        if(Judge(heada,A)!=0) {
            point * tmp = (point *)malloc(sizeof(point));
            tmp->next = NULL;
            tmp->parent.adda = NULL;
            tmp->add.adda = heada;
            //处理头节点
            if(head==NULL) {
                head = tmp;
                cur = head;
            } else {
                cur->next = tmp;
                cur = cur->next;
            }
        }
        heada = heada->next;
    }
    return head;
}

void QueryAnnual(GtkWidget * wid, gpointer data) {
    pipe * A = (pipe *)data;
    point *head = QueryForList(A);
    //输出head到clist；
    GtkWidget * clist = A->widget[9];

    while(head!=NULL) {
        annual * ann = head->add.adda;
        char money[10];
        char pja[10];
        char pjs[10];
        char pje[10];
        gcvt(ann->data.moneyInput,6,money);
        itoa(ann->data.pjApplyNum,pja,10);
        itoa(ann->data.pjSupportNum,pjs,10);
        itoa(ann->data.pjEndNum,pje,10);
        char * text[] = {
            ann->data.CSNo,
            money,
            ann->data.resPeople,
            pja,pjs,pje,
            ann->data.timgBg,
            ann->data.timeEnd
        };
        gtk_clist_append(GTK_CLIST(clist),text);
        head = head->next;
    }
    FreeAllPoint(head);
}


void DeleteAnnual(GtkWidget * wid, gpointer data) {
    GtkWidget * clist = (GtkWidget *)data;
    int i = 0;
    char * ptext;
    while(gtk_clist_get_text (clist,i++,0,&ptext)) {
        annual * heada = ahead;
        project * headp = NULL;
        if(strcmp(ptext,ahead->data.CSNo)==0) {
            annual * tmp = ahead;
            project * headp = tmp->pjhead;
            ahead = ahead->next;
            free(tmp);
        }
        else {
            while(heada->next!=NULL) {
                if(strcmp(heada->next->data.CSNo,ptext)==0) {
                    annual * tmp = heada->next;
                    project * headp = tmp->pjhead;
                    heada->next = tmp->next;
                    free(tmp);
                    break;
                }
                heada = heada->next;
            }
        }
        while(headp!=NULL) {
            staff * heads = headp->sthead;
            while(heads!=NULL) {
                staff * tmp = heads;
                heads = heads->next;
                free(tmp);
            }
            project * tmp = headp;
            headp = headp->next;
            free(tmp);
        }
    }
    SaveData();
}

void outputStatic(statannual * head,pipe * data);
statannual * sortAnnualStatic(statannual *head,int i);

void StaticAnnual(GtkWidget *wid,gpointer data) {
    pipe * A = (pipe *)data;
    annual * heada = ahead;
    statannual * head = NULL;
    statannual * cur = NULL;
    char ceil[10] = {'9','9','9','9','\0'};
    char floor[10] = {'0','0','0','0','\0'};//初始值
    printf("1.\n");
    if(gtk_toggle_button_get_active(A->widget[0])) {
        if(gtk_combo_box_get_active_text(A->widget[1])==NULL||gtk_combo_box_get_active_text(A->widget[2])==NULL) {
            Msg(1,"请选择年份！");
            return ;
        }
        strcpy(floor,gtk_combo_box_get_active_text(A->widget[1]));
        strcpy(ceil,gtk_combo_box_get_active_text(A->widget[2]));
    }
    printf("2.\n");
    while(heada!=NULL) {
        if(heada!=NULL&&strcmp(heada->data.CSNo,ceil)<=0&&strcmp(heada->data.CSNo,floor)>=0){
            printf("3.\n");
            statannual * tmp = (statannual *)malloc(sizeof(statannual));
            tmp->next = NULL;
            tmp->ann = heada;
            tmp->apply = heada->data.pjApplyNum;
            project * headp = heada->pjhead;
            int good = 0;
            int  fail = 0;
            int hege = 0;
            for(tmp->people=0; headp!=NULL; headp = headp->next) {
                if(strcmp(headp->data.evaluate,"优")==0 || (strcmp(headp->data.evaluate,"良")==0))  good += 1;
                if(strcmp(headp->data.evaluate,"优")==0 || (strcmp(headp->data.evaluate,"良")==0
                                    ||strcmp(headp->data.evaluate,"中")==0 )) hege += 1;
                if(strcmp(headp->data.evaluate,"未能正常结题")==0 ) fail += 1;
                tmp->people += headp->data.people;
            }
            printf("4.\n");
            tmp->support = heada->data.pjSupportNum;
            tmp->fail = (float)(fail)/(float)(heada->data.pjSupportNum);//未结题率
            tmp->good = (float)(good)/(float)(heada->data.pjSupportNum);
            tmp->hege = (float)(hege)/(float)(heada->data.pjSupportNum);
            tmp->money = heada->data.moneyInput;
            tmp->passRatio = (float)(heada->data.pjEndNum)/(float)(heada->data.pjSupportNum);//验收通过率
            tmp->supportRatio = (float)(heada->data.pjSupportNum)/(float)(heada->data.pjApplyNum);//支持率
            if(head == NULL) {
                head = tmp;
                cur = tmp;
            }
            else {
                cur->next = tmp;
                cur = cur->next;
            }
        }
        heada = heada->next;
        printf("5.\n");
    }
    printf("6.\n");
    head = sortAnnualStatic(head,(int)(A->widget[4]));
    printf("7.\n");
    outputStatic(head,A);
    while(head!=NULL) {
        statannual * tmp = head;
        head = head->next;
        free(tmp);
    }


}

void outputStatic(statannual * head,pipe * data) {
    pipe * A = (pipe *)data;
    GtkWidget * clist = A->widget[3];
    while(head!=NULL) {
        char  pja[10];char pjs[10];char money[10];
        char sr[10]; char pr[10];char good[10];
        char hege[10];char fail[10]; char peop[10];
        printf("!!!!!%f!!!!!",head->supportRatio);
        gcvt(head->supportRatio*100.0,4,sr); strcat(sr,"%");
        gcvt(head->passRatio*100.0,4,pr); strcat(pr,"%");
        gcvt(head->good*100.0,4,good); strcat(good,"%");
        gcvt(head->hege*100.0,4,hege); strcat(hege,"%");
        gcvt(head->fail*100.0,4,fail); strcat(fail,"%");
        char *text[10] = {
            head->ann->data.CSNo,
            itoa(head->ann->data.pjApplyNum,pja,10),
            itoa(head->ann->data.pjSupportNum,pjs,10),
            gcvt(head->ann->data.moneyInput,6,money),
            sr,pr,good,hege,fail,
            itoa(head->people,peop,10)
        };
        gtk_clist_append(GTK_CLIST(clist),text);
        head = head->next;
    }
}
int judge(int mode,statannual *ffff,statannual *llll){
    switch(mode){
        case 0:return (ffff->apply - llll->apply);
        case 1:return  (ffff->support-llll->support);
        case 2:return (ffff->money * 100-llll->money*100);
        case 3:return (ffff->supportRatio-llll->supportRatio)*100;
        case 4:return (ffff->passRatio-llll->passRatio)*100;
        case 5:return (ffff->good-llll->good)*100;
        case 6:return (ffff->hege-llll->hege)*100;
        case 7:return (ffff->fail-llll->fail)*100;
        case 8:return (ffff->people-llll->people);
    }
}
statannual * sortAnnualStatic(statannual *head,int mode){
    statannual * cur = (statannual *)malloc(sizeof(statannual));
    cur->next = head;statannual * tmp = head;int length = 0;
    //获得表长
    while(tmp!=NULL){
        length++;tmp = tmp->next;

    }
    for(int i = 1;i<length;i++){
        statannual * r = cur;
        statannual * p = cur->next;statannual * q = p->next;
        for(int j = 1;j<=length-i;j++,p = p->next,q = q->next,r = r->next){
            if(judge(mode,p,q)<0){
                r->next = q;
                statannual * tmp = q->next;
                q->next = p;
                p->next = tmp;

                tmp = q;q = p;p = tmp;
            }
        }
    }
    tmp = cur->next;
    free(cur);
    return tmp;
}





















