#ifndef ANNUAL_H_INCLUDED
#define ANNUAL_H_INCLUDED



#endif // ANNUAL_H_INCLUDED
void AddAnnual(GtkWidget *wid,gpointer data);
void FindAnnual(GtkWidget * wid , gpointer data);
void ChangeAnnual(GtkWidget* wid, gpointer data);
void DeleteAnnual(GtkWidget * wid , gpointer data);
void QueryAnnual(GtkWidget * wid , gpointer data);
void StaticAnnual(GtkWidget *wid,gpointer data);

typedef struct statannual{
    annual * ann;
    int apply;
    int support;
    float money;
    float supportRatio;
    float passRatio;
    float good;
    float hege;//合格率
    float fail;//未结题率
    int people;
    struct statannual * next;
}statannual;
