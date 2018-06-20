#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED



#endif // STAFF_H_INCLUDED
void AddStaff(GtkWidget *wid,gpointer data);
void FindStaff(GtkWidget *wid,gpointer data);
void ChangeStaff(GtkWidget *wid,gpointer data);
void QueryStaff(GtkWidget * wid,gpointer data);
void DeleteStaff(GtkWidget * wid , gpointer data);
void StaticStaff(gboolean tag,pipe *pipes);


typedef struct statstaff{
    char profession[40];
    int pjNum;
    float Ratio;
    struct statstaff * next;
}statstaff;








