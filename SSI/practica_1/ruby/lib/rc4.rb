class Array
  def swap(i,j)
    self[i], self[j] = self[j], self[i]
    self
  end
end

class Rc4 
  Size = 256;
  attr_accessor :s, :k
  attr_reader :seed, :message
  
  def initialize(seed)
    @s, @k, @seed, @message = [],[], seed.split(" "), []
    initialize_seed
  end
  
  def code(message)
    initialize_seed
    i,j, @message = 0,0, [] 
    message.split(" ").each{|k|
      i = (i+1) % Size
      j = (j + s[i]) % Size
      s.swap(i,j)
      @message.push k.to_i ^ s[(s[i] + s[j]) % Size]
    }
  end
  
  def seed= value
    @seed= value.split(" ")
  end
  
  def to_s
    @message.join(" ")
  end
  
  private
  def initialize_seed
    raise "Error Seed size too long. Max length = #{Size}" if seed.size > Size
    Size.times{|i|
      @s[i] = i
      @k[i]= @seed[i % @seed.size].to_i
    }
    j = 0
    Size.times{|i|
      j = (j + s[i] + k[i]) % Size
      s.swap(i,j)
    }    
  end
  
end