#include "./main_view.h"
#include "./second_view.h"
#include<gtk/gtk.h>


void load_css(void) {
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "style.css");

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );

    g_object_unref(provider);
}
void on_switch_to_second(GtkButton *button, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "second");
}

void main_view_create(GtkApplication *app) {
    load_css();
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Main View");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *stack = gtk_stack_new();
    gtk_widget_set_vexpand(stack, TRUE);

    // Create main screen
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *label = gtk_label_new("Welcome to the Main View");
    GtkWidget *button = gtk_button_new_with_label("Go to Second View");
    g_signal_connect(button, "clicked", G_CALLBACK(on_switch_to_second), stack);
    
    gtk_box_append(GTK_BOX(main_box), label);
    gtk_box_append(GTK_BOX(main_box), button);
    gtk_stack_add_named(GTK_STACK(stack), main_box, "main");

    // Add second view
    GtkWidget *second_view = second_view_create(GTK_STACK(stack));
    gtk_stack_add_named(GTK_STACK(stack), second_view, "second");

    gtk_window_set_child(GTK_WINDOW(window), stack);
    gtk_window_present(GTK_WINDOW(window));
}
