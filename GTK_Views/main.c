#include <gtk/gtk.h>
#include "main_view.h"


int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new("com.example.multiview", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(main_view_create), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
