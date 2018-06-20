//
// Created by tonggege on 17-8-24.
//

#ifndef PROJECTMANAGE_INFOANDTYPE_H
#define PROJECTMANAGE_INFOANDTYPE_H

#endif //PROJECTMANAGE_INFOANDTYPE_H

#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct datas{
    char SNo[12];
    char name[15];
    int old;
    char status[15];
    char profession[27];
    char classNo[10];
    char talent[60];
    char task[30];
    char tel[13];
    int que;
}datas;
typedef struct staff{
    struct datas data;
    struct staff * next;
}staff;

struct datap{
    char CNo[8];
    char pjName[60];
    float Money;
    int people;
    char timeBg[10];
    char timeEnd[10];
    char evaluate[22];
    char resPeople[15];
    char ResPeoTel[13];
    char resultType[12];
    char resultName[60];
}datap;
typedef struct project{
    struct datap data;
    struct project * next;
    struct staff * sthead;
}project;

struct dataa {
    char CSNo[8];
    float moneyInput;
    char resPeople[15];
    int pjApplyNum;
    int pjSupportNum;
    int pjEndNum;
    char timgBg[10];
    char timeEnd[10];
}dataa;
typedef struct annual{
    struct dataa data;
    struct annual * next;
    struct project * pjhead;
}annual;


typedef struct pipe{
    GtkWidget * widget[15];
    int n;
}pipe;


union Add{
    annual * adda;
    project * addp;
    staff * adds;
};
typedef struct point{
    union Add add;
    union Add parent;
    struct point * next;
}point;



extern annual * ahead;
extern GtkWidget * window;
extern pipe * pipes;
