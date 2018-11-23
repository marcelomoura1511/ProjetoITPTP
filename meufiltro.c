#include "meufiltro.h"

void inicializarWidgetsMeuFiltro() {
	//widgets das opcoes de filtro
	widgetControleNivel = 	gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 30, 1);
	widgetMisturarCanais = gtk_check_button_new_with_label("Misturar canais");
	g_signal_connect(G_OBJECT(widgetControleNivel), "value-changed", G_CALLBACK(funcaoAplicar), NULL);
}

void adicionarWidgetsMeuFiltro(GtkWidget *container) {

	GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
	gtk_container_add(GTK_CONTAINER(container), vbox);
	gtk_container_add(GTK_CONTAINER(vbox), widgetControleNivel);
	gtk_container_add(GTK_CONTAINER(vbox), widgetMisturarCanais);
}

Imagem meuFiltro(Imagem origem,Imagem imagemFundo) {

    if(img.h == imagemFundo.h && img.w == imagemFundo.w){
    Imagem destino = alocarImagem(origem);
	Imagem fundo = alocarImagem(imagemFundo);
    //k e j variacoes do valor atribuido na imagem digital a cor deseja para o chorma key
    k = 230;
    j = 255;
    for(int r = 0;r<10;r++){
        for(int y = 0;y<10;y++){
            for(int i = k;k<j;i++){
                for(int a = 0;a<img.h;a++){
                    for(int b = 0;b<img.w;b++){
                        if(img.m[a][b][0] == y && img.m[a][b][1] == i && img.m[a][b][2] == r){
                            img.m[a][b][0] = imagemFundo.m[a][b][0];
                            img.m[a][b][1] = imagemFundo.m[a][b][1];
                            img.m[a][b][2] = imagemFundo.m[a][b][2];
                        }
                    }


                }
            }
        }
    }
}




if(img.h>imagemFundo.h && img.m>imagemFundo.m){
     int e = imagemFundo.w;
     int p = imagemFundo.h;
    Imagem destino = alocarImagem(origem);
    Imagem imagemFundo = alocarImagem(imagemFundo);
    Imagem alocarImagemDimensao(e, p, 3);
    k = 230;
    j = 255;
    for(int r = 0;r<10;r++){
        for(int y = 0;y<10;y++){
            for(int i = k;k<j;i++){
                for(int a = 0;a<img.h;a++){
                    for(int b = 0;b<img.w;b++){
                        if(img.m[a][b][0] == y && img.m[a][b][1] == i && img.m[a][b][2] == r){
                            img.m[a][b][0] = imagemFundo.m[a][b][0];
                            img.m[a][b][1] = imagemFundo.m[a][b][1];
                            img.m[a][b][2] = imagemFundo.m[a][b][2];
                        }
                    }


                }
            }
        }
    }
}






