#include "desGui.h"

DesGui::DesGui(char* path) : _path(path) {
   _path.erase(_path.length() -5, _path.length() -1);
   builder = Gtk::Builder::create();
   builder->add_from_file(_path+"/../lib/gui/des_gui.glade");
   builder->get_widget("window",window);
   builder->get_widget("cifrar_btn",boton);
   //boton->signal_clicked().connect(sigc::ptr_fun(on_cifrar_clicked));
   boton->signal_clicked().connect(sigc::mem_fun(*this,&DesGui::on_cifrar_clicked));
   //Entradas de texto
   builder->get_widget("key_entry",key_e);
   builder->get_widget("message_entry",message_e);
   builder->get_widget("coded_entry",coded_e);
   //TextView
   builder->get_widget("textview1",text);
   //Boton debug
   builder->get_widget("debug_btn",debug);
   debug->signal_toggled().connect(sigc::mem_fun(*this,&DesGui::on_debug_toggled));
   builder->get_widget("ext_debug_btn",ext_debug);
   ext_debug->signal_toggled().connect(sigc::mem_fun(*this,&DesGui::on_ext_debug_toggled));
   //Inicializar buffers de entrada
   dat.out = text->get_buffer();
   dat.err = text->get_buffer();
   dat.entry = coded_e;
}

DesGui::~DesGui() {
}

Gtk::Window* DesGui::get_window() {
   return window;
}

string DesGui::get_working_path()
{
   char temp[100];
   string aux;
   getcwd(temp, 100) ? aux = string( temp ) : aux = string("");
   //return aux + _path.substr(1,_path.length()-1);
   return aux;
}

//*********************************
//Signal handlers
//********************************

void DesGui::cb_child_watch( GPid  pid, gint  status) {
    /* Close pid */
    g_spawn_close_pid( pid );
}

gboolean DesGui::cb_out_watch( GIOChannel *channel, GIOCondition  cond,Data *out ) {
    gchar *string;
    gsize  size;
    if( cond == G_IO_HUP )
    {
        g_io_channel_unref( channel );
        return( FALSE );
    }
    g_io_channel_read_line( channel, &string, &size, NULL, NULL );
	(out->out)->insert_at_cursor(string);
    g_free( string );
    return( TRUE );
}

gboolean DesGui::cb_err_watch( GIOChannel   *channel, GIOCondition  cond,Data *err)
{
    gchar *string;
    gsize  size;

    if( cond == G_IO_HUP )
    {
        g_io_channel_unref( channel );
        return( FALSE );
    }

    g_io_channel_read_line( channel, &string, &size, NULL, NULL );
    (err->entry)->set_text(string);
    //(err->err)->insert_at_cursor(string);
    //gtk_text_buffer_insert_at_cursor( err->err, string, -1 );
    g_free( string );

    return( TRUE );
}

void DesGui::on_debug_toggled(){
	if(debug->get_active() == false)
		ext_debug->set_active(false);
}

void DesGui::on_ext_debug_toggled(){
	if (ext_debug->get_active() == true)
		debug->set_active(true);
}

void DesGui::on_cifrar_clicked() {
	//Limpiar el buffer de texto
	(text->get_buffer())->set_text("");
	string seed = (key_e->get_text());
	string message = (message_e->get_text());
	/*Glib::RefPtr<Gtk::TextBuffer> outer = text->get_buffer();
	outer->insert_at_cursor("Helloooooo");*/
	GPid pid;
	//gchar *argv[] = { "./cli", "LALALALA","LALALALA", "s", NULL};
	char *argv[5];
	char comandoc[100];
	strncpy(comandoc,(_path + "/cli").c_str(),100);
	char seedc[100];
	strncpy(seedc,seed.c_str(),100);
	char messagec[100];
	strncpy(messagec, message.c_str(),100);
	char modec[100];
	if (debug->get_active() == true) {
		modec[0] = 'd';
		if (ext_debug->get_active() == true)
			modec[0] = 'e';
	}
	else
		modec[0] = 's';
	seed.c_str();
	argv[0] = comandoc;
	argv[1] = seedc;
	argv[2] = messagec;
	argv[3] = modec;
	argv[4] = NULL;
	gint out, err;
	GIOChannel *out_ch, *err_ch;
	gboolean    ret;
	// Spawn child process
	ret = g_spawn_async_with_pipes( NULL, argv, NULL,
									G_SPAWN_DO_NOT_REAP_CHILD, NULL,
									NULL, &pid, NULL, &out, &err, NULL );
	if( ! ret )
	{
		g_error( "SPAWN FAILED" );
		return;
	}
	 //Add watch function to catch termination of the process. This function
	 //will clean any remnants of process.
	g_child_watch_add( pid, (GChildWatchFunc)cb_child_watch, NULL);
	//Crear canales de escucha para leer de los pipes
	out_ch = g_io_channel_unix_new( out );
	err_ch = g_io_channel_unix_new( err );
	GIOCondition cond = (GIOCondition)(G_IO_IN|G_IO_HUP);
	// Add watches to channels
	g_io_add_watch( out_ch, cond, (GIOFunc)cb_out_watch, &dat);
	g_io_add_watch( err_ch, cond, (GIOFunc)cb_err_watch,&dat);
}


