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

Imagem meuFiltro(Imagem origem,Imagem fundo) {
    Imagem destino = alocarImagem(origem);
    if(origem.h == fundo.h && origem.w == fundo.w){
        printf("entrou 1\n");
        for(int a = 0;a<origem.h;a++){
            for(int b = 0;b<origem.w;b++){
                if(origem.m[a][b][0] >= 0 && origem.m[a][b][0] <= 80  && origem.m[a][b][1] >= 100 && origem.m[a][b][1] <= 255  && origem.m[a][b][3] >= 0 && origem.m[a][b][3] <= 80){
                    destino.m[a][b][0] = fundo.m[a][b][0];
                    destino.m[a][b][1] = fundo.m[a][b][1];
                    destino.m[a][b][2] = fundo.m[a][b][2];
                }
            }
        }
    }
    if(origem.h>fundo.h || origem.m>fundo.m){
        printf("entrou 2\n");
        int e = origem.w;
        int p = origem.h;
        for(int a = 0;a<origem.h;a++){
            for(int b = 0;b<origem.w;b++){
                if(origem.m[a][b][0] >= 0 && origem.m[a][b][1] == 255 && origem.m[a][b][3] == 0){
                    destino.m[a][b][0] = 255;
                    destino.m[a][b][1] = 0;
                    destino.m[a][b][2] = 0;
                }else{
                    destino.m[a][b][0] = origem.m[a][b][0];
                    destino.m[a][b][1] = origem.m[a][b][1];
                    destino.m[a][b][2] = origem.m[a][b][2];
                }
            }
        }
    }
    return destino;
}






