#include"InfoAndType.h"
#include "Staff.h"

void AddStaff(GtkWidget *wid,gpointer data){
    pipe* A = (pipe *)data;

    annual * heada = ahead;
    int flag = 0;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入学号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入姓名！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入年龄！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入类别！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入学院专业！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[7]),"")==0) {Msg(1,"请输入班级！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[8]),"")==0) {Msg(1,"请输入本人特长！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[9]),"")==0) {Msg(1,"请输入承担任务！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[10]),"")==0) {Msg(1,"请输入联系电话！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[11]),"")==0) {Msg(1,"请输入项目排名！");return ;}
    //检测年份信息存在
    while(heada!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1;
            break;
        }
        heada = heada->next;
    }
    if(flag == 0 ){Msg(1,"没有查询到年份信息！");return ;}
    project * headp = heada->pjhead;int flag2 = 0;
    //检测项目信息存在
    while(headp!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[1]),headp->data.CNo)==0){
            flag2 = 1;
            break;
        }
        headp = headp->next;
    }
    if(flag2==0) {Msg(1,"没有查询到项目信息！");return ;}
    //检测信息重复
    staff * cur = headp->sthead;int flag_e = 0;
    while(cur!=NULL){
        if(strcmp(cur->data.SNo,gtk_entry_get_text(A->widget[2]))==0){
            flag_e = 1;break;
        }
        cur = cur->next;
    }
    if(flag_e == 1) {Msg(1,"该人员已有信息！");return ;}

    //创建节点
    staff * tmp = (staff * )malloc(sizeof(staff));
    tmp->next = NULL;
    strcpy(tmp->data.SNo,gtk_entry_get_text(A->widget[2]));
    strcpy(tmp->data.name,gtk_entry_get_text(A->widget[3]));
    tmp->data.old = atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(tmp->data.status,gtk_entry_get_text(A->widget[5]));
    strcpy(tmp->data.profession,gtk_entry_get_text(A->widget[6]));
    strcpy(tmp->data.classNo,gtk_entry_get_text(A->widget[7]));
    strcpy(tmp->data.talent,gtk_entry_get_text(A->widget[8]));
    strcpy(tmp->data.task,gtk_entry_get_text(A->widget[9]));
    strcpy(tmp->data.tel,gtk_entry_get_text(A->widget[10]));
    tmp->data.que = atoi(gtk_entry_get_text(A->widget[11]));
    printf("1.\n");
    staff * heads = headp->sthead;
    if(heads == NULL){
        printf("6.\n");
        headp->sthead = tmp;
        heads = tmp;
    }
    else{
        printf("7.\n");
        char * p = gtk_entry_get_text(A->widget[2]);
        if(strcmp(heads->data.SNo,p)<0){
            tmp->next = heads;
            headp->sthead = tmp;
            printf("5.\n");
        }
        else{//gtk_entry_get_text(A->widget[2])<0)
            while(heads->next!=NULL){
                if(strcmp(heads->next->data.SNo,"U200847892"))  break;
                heads = heads->next;
                printf("4.\n");
            }
            tmp->next = heads->next;
            heads->next = tmp;
            printf("2.\n");
        }
    }
    printf("3.");
    headp->data.people++;
    SaveData();
   // ClearWindow(NULL,A);
}

void FindStaff(GtkWidget *wid,gpointer data){
    pipe * A = (pipe*)data;
    annual * heada = ahead;
    project * headp = NULL;
    staff * heads = NULL;
    //处理空操作
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入学号！");return ;}

    int flag = 0;
    while(heada!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1;break;
        }
        heada = heada->next;
    }
    if(flag == 0) {Msg(1,"没有查询到该年份信息");return ;}
    int flag2 = 0;
    headp = heada->pjhead;
    while(headp!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[1]),headp->data.CNo)==0){
            flag2 = 1;break;
        }
        headp = headp->next;
    }
    if(flag2 == 0) {Msg(1,"没有查询到该年份下的项目信息");return ;}
    int flag3 = 0;
    heads = headp->sthead;
    while(heads!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[2]),heads->data.SNo)==0){
            flag3 = 1;break;
        }
        heads = heads->next;
    }
    if(flag3==0) {Msg(1,"没有查询到该年份下隶属于该项目下的人员信息！");return ;}
    printf("Ready to putin\n");
    printf("heads is %d",heads);
    char old[10];char queue[10];
    gtk_entry_set_text(A->widget[3],heads->data.name);
    gtk_entry_set_text(A->widget[4],itoa(heads->data.old,old,10));
    gtk_entry_set_text(A->widget[5],heads->data.status);
    gtk_entry_set_text(A->widget[6],heads->data.profession);
    gtk_entry_set_text(A->widget[7],heads->data.classNo);
    gtk_entry_set_text(A->widget[8],heads->data.talent);
    gtk_entry_set_text(A->widget[9],heads->data.task);
    gtk_entry_set_text(A->widget[10],heads->data.tel);
    gtk_entry_set_text(A->widget[11],itoa(heads->data.que,queue,10));
    A->widget[12] = (GtkWidget*)heads;
}

void ChangeStaff(GtkWidget *wid,gpointer data){
    pipe* A = (pipe *)data;

    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入学号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入姓名！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入年龄！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入类别！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入学院专业！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[7]),"")==0) {Msg(1,"请输入班级！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[8]),"")==0) {Msg(1,"请输入本人特长！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[9]),"")==0) {Msg(1,"请输入承担任务！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[10]),"")==0) {Msg(1,"请输入联系电话！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[11]),"")==0) {Msg(1,"请输入项目排名！");return ;}

    staff * ss = (staff *)A->widget[12];

    strcpy(ss->data.name,gtk_entry_get_text(A->widget[3]));
    ss->data.old = atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(ss->data.status,gtk_entry_get_text(A->widget[5]));
    strcpy(ss->data.profession,gtk_entry_get_text(A->widget[6]));
    strcpy(ss->data.classNo,gtk_entry_get_text(A->widget[7]));
    strcpy(ss->data.talent,gtk_entry_get_text(A->widget[8]));
    strcpy(ss->data.task,gtk_entry_get_text(A->widget[9]));
    strcpy(ss->data.tel,gtk_entry_get_text(A->widget[10]));
    ss->data.que = atoi(gtk_entry_get_text(A->widget[11]));


    SaveData();
    A->widget[12] = NULL;
}
int Judges(staff * cur,pipe * A){
    int flagAnd = 1;int flagOr = 0;
    if(gtk_toggle_button_get_active(A->widget[4])){
        if(Correspond1(cur->data.SNo,gtk_entry_get_text(A->widget[0]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[5])){
        if(Correspond2(cur->data.name,gtk_entry_get_text(A->widget[1]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        if(Correspond2(cur->data.profession,gtk_entry_get_text(A->widget[2]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
        if(Correspond2(cur->data.talent,gtk_entry_get_text(A->widget[3]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[8])){
        return flagAnd;
    }
    else{
        return flagOr;
    }
}
//删除的时候直接调用这条函数
//注意：
/*1.项目删除pjsupport-1
2.pipe里面传参索引相对*/
point *QueryForLists(pipe * A){
    annual * heada = ahead;
    point *head = NULL;
    point * cur = NULL;
    while(heada!=NULL){
        project * headp = heada->pjhead;
        while(headp!=NULL){
            staff * heads = headp->sthead;
            while(heads !=NULL){
                if(Judges(heads,A)!=0){
                    point * tmp = (point *)malloc(sizeof(point));
                    tmp->next = NULL;tmp->parent.addp = headp;
                    tmp->add.adds = heads;
                    //处理头节点
                    if(head==NULL){
                        head = tmp;
                        cur = head;
                    }
                    else{
                        cur->next = tmp;
                        cur = cur->next;
                    }
                }

                heads = heads->next;
            }
            headp = headp->next;
        }
        heada = heada->next;
    }
    return head;
}



void QueryStaff(GtkWidget * wid,gpointer data){
    pipe * A = (pipe *)data;
    point *head = QueryForLists(A);
    //输出head到clist；
    GtkWidget * clist = A->widget[9];

    while(head!=NULL){
        staff * heads = head->add.adds;
        char old[10];char que[10];
        itoa(heads->data.old,old,10);
        itoa(heads->data.que,que,10);
        char * text[] = {
            head->parent.addp->data.CNo,
            heads->data.SNo,
            heads->data.name,
            old,
            heads->data.status,
            heads->data.profession,
            heads->data.classNo,
            heads->data.talent,
            heads->data.task,
            heads->data.tel,
            que
        };
        gtk_clist_append(GTK_CLIST(clist),text);
        head = head->next;
    }
    FreeAllPoint(head);
}
void DeleteStaff(GtkWidget* wid, gpointer data){
    GtkWidget *clist = (GtkWidget *)data;
    int i = 0;char * ptext;
    while(gtk_clist_get_text (clist,i++,1,&ptext)){
        annual * heada = ahead;
        while(heada!=NULL){
            project * headp = heada->pjhead;
            while(headp!=NULL){
                staff * heads = headp->sthead;
                if(strcmp(heads->data.SNo,ptext)==0){
                    staff * tmp = heads;
                    headp->sthead = tmp->next;
                    free(tmp);
                    headp->data.people--;
                }
                else{
                    while(heads->next!=NULL){
                        if(strcmp(heads->next->data.SNo,ptext)==0){
                            staff * tmp = heads->next;
                            heads->next = tmp->next;
                            free(tmp);
                            headp->data.people--;
                        }

                        heads = heads->next;
                    }
                }
                headp = headp->next;
            }
            heada = heada->next;
        }
    }
    SaveData();
}
statstaff *sortStaticStaff(statstaff * head);
void Putin(char *profession,project * headp);
statstaff *ExistS(statstaff * head,project * headp);
void StaticStaff(gboolean tag,pipe* A){
    char floor[10] = "0000";
    char ceil[10] = "9999";
    if(tag){
        if(strcmp(gtk_combo_box_get_active_text(A->widget[1]),"")==0||
           strcmp(gtk_combo_box_get_active_text(A->widget[2]),"")==0
           ){
            Msg(1,"请选择年份！");return ;
           }
        strcpy(floor,gtk_combo_box_get_active_text(A->widget[1]));
        strcpy(ceil,gtk_combo_box_get_active_text(A->widget[2]));
    }
    int total = 0;
    statstaff * head = NULL;
    statstaff * cur = NULL;
    annual * heada = ahead;
    while(heada!=NULL){
        //不在范围内直接跳过
        if(!(strcmp(heada->data.CSNo,floor)>=0&&strcmp(heada->data.CSNo,ceil)<=0)){
            heada = heada->next;
            continue;
        }
        project * headp = heada->pjhead;
        while(headp!=NULL){
            if(headp->sthead==NULL){
                headp = headp->next;
                continue;
            }
            total ++;//总项目数+1
            statstaff * tmp = ExistS(head,headp);
            if(tmp != NULL){

                tmp->pjNum++;
            }
            else{
                tmp = (statstaff *)malloc(sizeof(statstaff));
                tmp->next = NULL;
                tmp->pjNum = 1;
                //将排名第一的人的专业加入到tmp中
                Putin(tmp->profession,headp);
                if(head==NULL){
                    head = tmp;
                    cur = tmp;
                }
                else{
                    cur->next = tmp;
                    cur = cur->next;
                }
            }
            headp = headp->next;
        }
        heada = heada->next;
    }
    //计算相关比率
    cur = head;
    while(cur!=NULL){
        cur->Ratio = (float)(cur->pjNum)/(float)(total);
        cur = cur->next;
    }
    //排序
    head = sortStaticStaff(head);
    cur = head;
    //打印输出
    while(cur!=NULL){
        char Ratio[6];
        gcvt(cur->Ratio*100,3,Ratio);
        strcat(Ratio,"%");
        char *text[2] = {cur->profession, Ratio};
        gtk_clist_append(A->widget[3],text);
        cur = cur->next;
    }
    while(head!=NULL){
        statstaff * tmp = head;
        head = head->next;
        free(tmp);
    }
}
statstaff *ExistS(statstaff * head,project * headp){
    char * profession = NULL;
    //获得排名第一的人员的专业字符串指针；
    staff * heads = headp->sthead;
    while(heads!=NULL){
        if(heads->data.que==1){
            profession = heads->data.profession;
            break;
        }
        heads = heads->next;
    }
    while(head!=NULL){
        if(strcmp(head->profession,profession)==0){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void Putin(char *profession,project * headp){
    staff * heads = headp->sthead;
    while(heads!=NULL){
        if(heads->data.que==1){
            strcpy(profession,heads->data.profession);
            break;
        }
        heads = heads->next;
    }
}

statstaff *sortStaticStaff(statstaff * head){
    statstaff * cur = (statstaff *)malloc(sizeof(statstaff));
    cur->next = head;statstaff * tmp = head;int length = 0;
    //获得表长
    while(tmp!=NULL){
        length++;tmp = tmp->next;
    }
    for(int i = 1;i<length;i++){
        statstaff * r = cur;
        statstaff * p = cur->next;statstaff * q = p->next;
        for(int j = 1;j<=length-i;j++,p = p->next,q = q->next,r = r->next){
            if(p->Ratio<q->Ratio){
                r->next = q;
                statstaff * tmp = q->next;
                q->next = p;
                p->next = tmp;
                tmp = q;q = p;p = tmp;
            }
        }
    }
    tmp = cur->next;
    free(cur);
    return tmp;

};

















