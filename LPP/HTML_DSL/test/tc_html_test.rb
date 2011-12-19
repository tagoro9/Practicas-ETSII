#!/usr/bin/env ruby

require 'test/unit'
require 'lib/html'

class TestHtml < Test::Unit::TestCase
   def test_first_approach
      test_page = Html.new { html}
   end

   def test_standard_page
      test_page = HTML.new {  
         html {
            head(:dir => "chazam", :lang => "spanish") { title "My wonderful home page" }
            body do
               h1 "Welcome to my home page!", :class => "chuchu", :lang => "spanish"
               b "My hobbies:"
               ul do
                  li "Juggling"
                  li "Knitting"
                  li { i "Sleeping" } 
                  li "Metaprogramming"
               end #ul
            end # body
         }
      }
   end
end
