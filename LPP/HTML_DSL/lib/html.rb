#!/usr/bin/env ruby

class Html

   attr_accessor :p

   def initialize(&b)
      @p = [[]]
      instance_eval &b
   end
  
   def to_s
      @p[-1].to_s
   end

   def build_attr(h)
       return "" if h.nil? or h.empty?
       h.inject(""){ |text,y| text << %{ #{y[0]}="#{y[1]}"}}
   end

   def method_missing(tag,*args)
      text = ""
      if block_given?
         @p.push []
         yield
         text = @p.pop.join(' ')
      else
         text = args.shift
      end
      text_attr = build_attr(args.shift)
      text = "<#{tag}#{text_attr}>\n#{text}\n</#{tag}>"
      @p[-1].push(text)
      text
   end
end


if __FILE__ == $0
   q= Html.new {  
     html {
       head(:dir => "chazam", :lang => "spanish") { title "My wonderful home page" }
       body do
         h1 "Welcome to my home page!", :class => "chuchu", :lang => "spanish"
         b "My hobbies:"
         ul do
           li "Juggling"
           li "Knitting"
           li "Metaprogramming"
         end #ul
       end # body
     }
   }
   puts q
end
