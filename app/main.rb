require 'lib/golf_pixel_array.rb'





################################################################################
# 1. SETUP :
################################################################################
def setup(args)
  # Setup :
  width           = 64
  height          = 64
  args.state.pa1  = Golf::PixelArray.new( 512, 232,       # x and y position
                                          width, height,  # width and height
                                          4 )             # scale

  args.state.pa2  = Golf::PixelArray.new( 600, 600,
                                          width>>2, height>>2,
                                          1 )

  # Set some pixels :
  height.times do |y|
    width.times do |x|
      args.state.pa1.sp x, y, (1+(32*x).sin)*127, 127, (1-(16*x).sin)*127
    end
  end

  # Get a pixel :
  puts args.state.pa1.gp 32, 32

  # Copy some pixels :
  args.state.pa2.cp 0, 0,
                    args.state.pa1,
                    32, 32, 16, 16

  args.state.setup_done = true
end





################################################################################
# 2. MAIN LOOP :
################################################################################
def tick(args)
  setup(args) unless args.state.setup_done

  # !!! DON'T FORGET TO RENDER THE PIXEL ARRAY !!!
  args.state.pa1.render(args)
  #args.state.pa2.render(args)
  # !!! DON'T FORGET TO RENDER THE PIXEL ARRAY !!!

end
