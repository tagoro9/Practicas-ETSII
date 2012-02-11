#!/usr/bin/env ruby

require_relative '../lib/rc4'
require 'test/unit'

class TestRc4 < Test::Unit::TestCase
  def test_code
   rc4 = Rc4.new("2 5")
   rc4.code("1 34")
   puts rc4
  end
  
  def test_reverse_code
    rc4= Rc4.new("2 5")
    rc4.code("145 44")
    puts rc4
    rc4.code(rc4.to_s)
    puts rc4
  end
  
  def test_seed_change
    rc4 = Rc4.new("2 5")
    rc4.seed=("5 2")
    rc4.code("12 45")
    puts rc4
    rc4.code(rc4.to_s)
    puts rc4
  end
  
end
