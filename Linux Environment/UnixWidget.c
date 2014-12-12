#include <gtk/gtk.h>
#include <sys/types.h>
#include<stdio.h>
#include<stdlib.h>

gint settings(GtkWidget *widget,gpointer data)  
{  
    char* arg_list[] = {
	"gnome-control-center",
	NULL

	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("unity-control-center", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint sysinfo(GtkWidget *widget,gpointer data)  
{  
       char* arg_list[] = {
	"sysinfo",
	NULL

	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("hardinfo", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint gimp(GtkWidget *widget,gpointer data)  
{  
    char* arg_list[] = {
	"gimp",
	NULL

	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("gimp", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint calculator(GtkWidget *widget,gpointer data)  
{  
    char* arg_list[] = {
	"gcalctool",
	NULL

	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("xcalc", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint terminal(GtkWidget *widget,gpointer data)  
{  
 
      char* arg_list[] = {
	"gnome-terminal",
	NULL

	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("gnome-terminal", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint editor(GtkWidget *widget,gpointer data)  
{  
    char* arg_list[] = {
	"gedit",
	NULL
	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("subl", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint filebrowser(GtkWidget *widget,gpointer data)  
{  

    char* arg_list[] = {
	"nautilus",
	"--browser",
	NULL
	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("nautilus", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	} 
    return(TRUE);
}
gint firefox(GtkWidget *widget,gpointer data)  
{  
 	char* arg_list[] = {
	"firefox",
	NULL
	}; 
        pid_t child_pid;
	child_pid = fork ();
	if (child_pid != 0)
        {
	return child_pid;
        }
	else 
	{
	execvp ("firefox", arg_list);
	fprintf (stderr, "an error occurred in execvp\n");
	exit(0);
	}
  
    return(TRUE);
}


void destroy(GtkWidget *widget,gpointer data)  
{  
    gtk_main_quit();  
}  

int main( int argc, char *argv[] )  
{  
    
	
    GtkWidget *window;  
    GtkWidget *button;
    GtkWidget *table;    
    gtk_init (&argc, &argv);
  
    window=gtk_window_new (GTK_WINDOW_TOPLEVEL);  
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(destroy), NULL);  
    gtk_container_set_border_width (GTK_CONTAINER(window), 10);
    table = gtk_table_new (5, 2, TRUE);
    gtk_table_set_col_spacings((GtkTable *)table,10);
    gtk_table_set_row_spacings((GtkTable *)table,10);
    gtk_container_add (GTK_CONTAINER (window), table);

    //firefox button
    button = gtk_button_new_with_label ("Firefox");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(firefox), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 1, 0, 1);
    gtk_widget_show (button); 

    //terminal button
    button = gtk_button_new_with_label ("Terminal");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(terminal), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 2, 0, 1);
    gtk_widget_show (button);

    //kwrite button
    button = gtk_button_new_with_label ("Editor");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(editor), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 1, 1, 2);
    gtk_widget_show (button);

    //Calculator button
    button = gtk_button_new_with_label ("Calculator");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(calculator), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 2, 1, 2);
    gtk_widget_show (button);

    //Gimp button
    button = gtk_button_new_with_label ("Image Editor");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(gimp), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 1, 2, 3);
    gtk_widget_show (button);

    //Filebrowser button
    button = gtk_button_new_with_label ("File Explorer");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(filebrowser), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 2, 2, 3);
    gtk_widget_show (button);


    //Settings button
    button = gtk_button_new_with_label ("Settings");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(settings), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 1, 3, 4);
    gtk_widget_show (button);

    //sysinfo button
    button = gtk_button_new_with_label ("System Info");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(sysinfo), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 1, 2, 3, 4);
    gtk_widget_show (button);

    //quit button
    button = gtk_button_new_with_label ("Quit");
    g_signal_connect (G_OBJECT(button), "clicked",G_CALLBACK(destroy), NULL); 
    gtk_table_attach_defaults (GTK_TABLE(table), button, 0, 2, 4, 5);
    gtk_widget_show (button);

    gtk_widget_show(table); 
    gtk_widget_show (window);     
    gtk_main();     
    return(0);  
}  
