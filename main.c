#include"InfoAndType.h"
#include "Util.h"
#include "MainPage.h"

annual * ahead = NULL;
GtkWidget * window;
pipe * pipes;

 int main(int argc,char *argv[]){
	gtk_init(&argc,&argv);

    ahead = LoadData();
	window = CreateMainPage();
    pipes = (pipe *)malloc(sizeof(pipe));
    printf("in main window is %d\n",window);


	gtk_main();

	return 0;
 }

