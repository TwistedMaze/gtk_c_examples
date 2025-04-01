#include <gtk/gtk.h>
#include "gtk_callbacks.h"


/*
Definição de função callback: 
Uma função callback é uma função passada a outra função como argumento, que é então invocado dentro da função externa para completar algum tipo de rotina ou ação.
(fonte: Mozilla Developer Network Web Docs
url: https://developer.mozilla.org/pt-BR/docs/Glossary/Callback_function
*/

static void
activate(GtkApplication *app,
         gpointer user_data)
{
  //declaracao da janela
  GtkWidget *window;
  //declaracao de um botão
  GtkWidget *button;
  
  //declaracao de uma grelha para organizar a disposicao
  //de widgets na janela
  GtkWidget *grid;

  //inicializacao da janela e definicao das suas propriedades
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello");
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  //inicializacao da grelha
  grid = gtk_grid_new();
  //associacao da grelha à janela
  gtk_window_set_child(GTK_WINDOW(window), grid);

  //inicializacao do botão
  button = gtk_button_new_with_label("Hello World");
  //associacao do evento "clicked" à função callback print_hello
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  
  //associacao do botão à grelha
  gtk_grid_attach(GTK_GRID(grid), button, 0, 199, 1, 1);

  //inicializacao de um segundo botao
  button = gtk_button_new_with_label("Button 2");
  //associacao do botão à grelha
  gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);
  
  //exibição da janela no ecrã da aplicação
  gtk_window_present(GTK_WINDOW(window));
}

int main(int argc,
         char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
