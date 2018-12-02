#include "meufiltro.h"
#include "RGBtoHSV.h"

void inicializarWidgetsMeuFiltro() {
    widgetControleNivelH =   gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 60, 1);
    widgetControleNivelS =   gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
    widgetControleNivelV =   gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
    gtk_widget_set_sensitive (widgetControleNivelH, FALSE);
    gtk_widget_set_sensitive (widgetControleNivelS, FALSE);
    gtk_widget_set_sensitive (widgetControleNivelV, FALSE);
    g_signal_connect(G_OBJECT(widgetControleNivelH), "value-changed", G_CALLBACK(funcaoAplicar), NULL);
    g_signal_connect(G_OBJECT(widgetControleNivelS), "value-changed", G_CALLBACK(funcaoAplicar), NULL);
    g_signal_connect(G_OBJECT(widgetControleNivelV), "value-changed", G_CALLBACK(funcaoAplicar), NULL);
    labelH = gtk_label_new("H");
    labelS = gtk_label_new("S");
    labelV = gtk_label_new("V");
}

void adicionarWidgetsMeuFiltro(GtkWidget *container) {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_set_border_width(GTK_CONTAINER(vbox), 20);
    gtk_container_add(GTK_CONTAINER(container), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), labelH, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(vbox), widgetControleNivelH);
    gtk_box_pack_start(GTK_BOX(vbox), labelS, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(vbox), widgetControleNivelS);
    gtk_box_pack_start(GTK_BOX(vbox), labelV, FALSE, FALSE, 0);
    gtk_container_add(GTK_CONTAINER(vbox), widgetControleNivelV);
}

Imagem meuFiltro(Imagem origem,Imagem fundo, GdkRGBA cor) {
    gtk_widget_set_sensitive (widgetControleNivelH, TRUE);
    gtk_widget_set_sensitive (widgetControleNivelS, TRUE);
    gtk_widget_set_sensitive (widgetControleNivelV, TRUE);

    struct RGB corFundoRGB ={(int) cor.red,(int) cor.green,(int) cor.blue};
    struct HSV corFundo = RGBToHSV(corFundoRGB);

    int nivelH=(int) gtk_range_get_value(GTK_RANGE(widgetControleNivelH));
    int nivelS=((int) gtk_range_get_value(GTK_RANGE(widgetControleNivelS)))/100;
    int nivelV=((int) gtk_range_get_value(GTK_RANGE(widgetControleNivelV)))/100;
    printf("%f, %f, %f", corFundo.H, corFundo.S, corFundo.V);
    Imagem destino = alocarImagem(origem);
    for(int a = 0;a<origem.h;a++){
        for(int b = 0;b<origem.w;b++){
            struct RGB rgb ={origem.m[a][b][0],origem.m[a][b][1],origem.m[a][b][0]};
            struct HSV hsv = RGBToHSV(rgb);
            if(nivelS!=0 || nivelV!=0){
                if(hsv.H >= corFundo.H-10-nivelH && hsv.H <= corFundo.H+10+nivelH && hsv.S >= nivelS && hsv.V >= nivelV){
                    destino.m[a][b][0] = fundo.m[a][b][0];
                    destino.m[a][b][1] = fundo.m[a][b][1];
                    destino.m[a][b][2] = fundo.m[a][b][2];
                }
            }else if((hsv.H >= corFundo.H-10-nivelH && hsv.H <= corFundo.H+10+nivelH && hsv.S >= 0.15 && hsv.V > 0.15) || (corFundo.S<=0.2 && corFundo.V>=0.9 && hsv.S<=0.2 && hsv.V>=0.7)){
                destino.m[a][b][0] = fundo.m[a][b][0];
                destino.m[a][b][1] = fundo.m[a][b][1];
                destino.m[a][b][2] = fundo.m[a][b][2];
            }else{
                destino.m[a][b][0] = origem.m[a][b][0];
                destino.m[a][b][1] = origem.m[a][b][1];
                destino.m[a][b][2] = origem.m[a][b][2];
            }
        }
    }
    return destino;
}






