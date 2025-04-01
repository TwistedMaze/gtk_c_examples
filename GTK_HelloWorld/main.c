#include <gtk/gtk.h>


/*
Definição de função callback: 
Uma função callback é uma função passada a outra função como argumento, que é então invocado dentro da função externa para completar algum tipo de rotina ou ação.
(fonte: Mozilla Developer Network Web Docs
url: https://developer.mozilla.org/pt-BR/docs/Glossary/Callback_function
*/

//funcao callback que imprime "Hello World" no terminal
void print_hello(GtkWidget *widget,
                 gpointer data)
{ 
  //funcao da biblioteca GTK equivalente a funcao printf
  g_print("Hello World\n"); //imprime "Hello World" no terminal
}


//funcao callback que configura a janela principal e os seus widgets 
void
activate(GtkApplication *app,
         gpointer user_data)
{
  //declaracao da janela
  GtkWidget *window;

  //declaracao de um botao
  GtkWidget *button;

  //inicializacao da janela principal associada à aplicação
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Hello"); //definição do titulo da janela principal
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200); //definição das dimensões da janela principal

  //inicialização do botão com etiqueta "hello world"
  button = gtk_button_new_with_label("Hello World");
  //associacao do evento "clicked" à funcao callback:
  //quando o botão é clicado, a janela emite o sinal "clicked";
  //o sinal "clicked" é apanhado pela aplicação, que de seguida chama a função print_hello 
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  
  //associação do botão como widget filho do widget janela
  gtk_window_set_child(GTK_WINDOW(window), button);

  //exibição da janela no ecrã da aplicação
  gtk_window_present(GTK_WINDOW(window));
}

/**
 * Funcao principal de uma aplicacao GTK.
 * Passos para construir uma aplicação GTK:
 * 1 - declarar a aplicação(GtkApplication)
 * 2 - inicializar a aplicação
 * 3 - associar o sinal de ativacao a uma funcao callback que configura a aplicação
 * 4 - correr a aplicaçãp
 * 5 - limpar a memoria quando a aplicação termina
 */
int main(int argc,
         char **argv)
{
  // Declaração do objeto da aplicação.
  GtkApplication *app;
  // Variável para armazenar o estado de saída da aplicação.
  int status;

  // Passo 1: Criar uma nova aplicação GTK com um identificador único.
  app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  // Passo 2 ocorre na funcao activate.
  //  Passo 3: Associar o sinal "activate" da aplicação à função de ativação.
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  // Passo 4: Executar a aplicação e aguardar por eventos.
  status = g_application_run(G_APPLICATION(app), argc, argv);

  // Passo 5: Libertar os recursos utilizados pela aplicação
  g_object_unref(app);

  return status;
}
