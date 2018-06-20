#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED



#endif // PROJECT_H_INCLUDED
void AddProject(GtkWidget *wid,gpointer data);
void FindProject(GtkWidget *wid,gpointer data);
void ChangeProject(GtkWidget *wid,gpointer data);
void QueryProject(GtkWidget* wid, gpointer data);
point *QueryForListp(pipe * A);
void DeleteProject(GtkWidget * wid , gpointer data);
void StaticProject(int i,gboolean tag,pipe * A);




typedef struct statproject{
    char name[15];
    char SNo[15];
    char profession[35];
    char pjname[60];
    int total;
    int goodnum;
    int failnum;
    float good;
    float fail;
    float pass;
    struct statproject * next;

}statproject;
