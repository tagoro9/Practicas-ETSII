#!/usr/bin/env ruby

require 'test/unit'
require 'lib/html'

class TestHtml < Test::Unit::TestCase
   def test_first_approach
      test_page = Html.new { html}
      puts test_page
   end
end
