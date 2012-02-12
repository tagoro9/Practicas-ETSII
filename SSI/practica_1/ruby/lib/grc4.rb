require 'gtk2'
require_relative 'rc4'

class Rc4ui < Gtk::Window
  def initialize
    super
    @rc4 = Rc4.new "2 5"
    #Titulo de la aplicacion
    set_title "Algoritmo Rc4"
    set_icon Gdk::Pixbuf.new("image/logo.png")
    #Terminar aplicacion al cerrar ventana
    signal_connect "destroy" do
      quit
    end
    #Inicializar contenido de la ventana
    components
    #Establecer tamaño de la ventana y posicion de la ventana
    set_default_size 400,200
    set_window_position Gtk::Window::POS_CENTER
    #Mostrar ventana principal
    show_all
  end
  
  def components
    #Crear un fix donde se colocaran el resto de los widgets
    fixed = Gtk::Fixed.new
    add fixed
    #Boton salir
    btn_salir = Gtk::Button.new Gtk::Stock::QUIT
    btn_salir.signal_connect "clicked" do
      quit
    end
    #Crear los botones cifrar y about
    btn_cifrar = Gtk::Button.new "Cifrar"
    btn_cifrar.set_tooltip_text "Cifrar mensaje"
    btn_cifrar.signal_connect "clicked" do
      on_cifrar_clicked
    end
    btn_about = Gtk::Button.new Gtk::Stock::INFO
    btn_about.set_tooltip_text "Acerca del autor"
    btn_about.signal_connect "clicked" do
      on_about_clicked
    end
    #Introducir botones en el fixed
    fixed.put btn_cifrar, 100, 140
    fixed.put btn_about, 164, 140
    fixed.put btn_salir, 290, 140
    #Introducir etiquetas de los campos de texto
    lbl_seed = Gtk::Label.new "Semilla"
    lbl_message = Gtk::Label.new "Mensaje"
    lbl_result = Gtk::Label.new "Resultado"
    #Introducir etiquetas en el fixed
    fixed.put lbl_seed, 20,30
    fixed.put lbl_message, 20,60
    fixed.put lbl_result, 20,90
    #Crear los inputs para introducir la semilla, el mensaje y el resultado
    @in_seed = Gtk::Entry.new
    @in_seed.set_size_request 250,26
    @in_seed.set_text @rc4.seed.join(" ")
    @in_message = Gtk::Entry.new
    @in_message.set_size_request 250,26
    @in_message.set_text "1 34"
    @in_result = Gtk::Entry.new
    @in_result.set_size_request 250,26
    #Introducir los inputs en el fixed
    fixed.put @in_seed,120,25
    fixed.put @in_message,120,55
    fixed.put @in_result,120,85
    
  end
  
  def on_about_clicked
    about = Gtk::AboutDialog.new
    about.set_program_name "Algotirmo Rc4"
    about.set_version "0.1"
    about.set_copyright "(c) Victor Mora"
    about.run
    about.destroy
  end
  
  def on_cifrar_clicked
    #Todo esto hay que meterlo en un Thread!
    seed = @in_seed.text
    message = @in_message.text
    @rc4.seed= seed
    @rc4.code(message)
    @in_result.set_text @rc4.to_s
  end
  
  def quit
    Gtk.main_quit
    puts "App terminada"
  end
end

if __FILE__ == $0
  Gtk.init
  window = Rc4ui.new
  Gtk.main
end
