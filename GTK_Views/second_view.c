#include "second_view.h"

void on_back_to_main(GtkButton *button, gpointer user_data) {
    GtkStack *stack = GTK_STACK(user_data);
    gtk_stack_set_visible_child_name(stack, "main");
}

GtkWidget *second_view_create(GtkStack *stack) {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    GtkWidget *label = gtk_label_new("This is the Second View");
    GtkWidget *button = gtk_button_new_with_label("Back to Main View");

    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main), stack);
    gtk_widget_add_css_class(box, "second-view");  // Apply CSS class
    gtk_box_append(GTK_BOX(box), label);
    gtk_box_append(GTK_BOX(box), button);

    return box;
}
